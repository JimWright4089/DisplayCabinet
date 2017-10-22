//----------------------------------------------------------------------------
//
//  $Workfile: DisplayCabinet$
//
//  $Revision: X$
//
//  Project:    DisplayCabinet
//
//                            Copyright (c) 2017
//                              James A Wright
//                            All Rights Reserved
//
//  Modification History:
//  $Log:
//  $
//
//----------------------------------------------------------------------------
//  gcc -o cabinet cabinet.c -lwiringPi -lmosquitto

#include <asm/ioctl.h>
#include <errno.h>
#include <fcntl.h>
#include <getopt.h>
#include <linux/i2c-dev.h>
#include <math.h>
#include <signal.h>
#include <stdarg.h>
#include <stdlib.h>
#include <string.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/time.h>
#include <sys/ioctl.h>
#include <memory.h>
#include <mosquitto.h>
#include <stdio.h>
#include <stdint.h>
#include <wiringPi.h>
#include <wiringPiI2C.h>

//----------------------------------------------------------------------------
//  Global Defines
//----------------------------------------------------------------------------
#define MAX_FRAMES             10
#define MAX_SHELFS             16
#define MAX_CHANNEL             8

#define SETTING_SOLID_BLACK   0
#define SETTING_SOLID_BLUE    1
#define SETTING_SOLID_GREEN   2
#define SETTING_SOLID_ORANGE  3
#define SETTING_SOLID_PURPLE  4
#define SETTING_SOLID_RED     5
#define SETTING_SOLID_WHITE   6
#define SETTING_SOLID_YELLOW  7
#define SETTING_MOVING_ALIEN  8
#define SETTING_MOVING_FIRE   9
#define SETTING_MOVING_LAVA  10
#define SETTING_MOVING_OCEAN 11
#define SETTING_MOVING_STARS 12
#define SETTING_MOVING_SWAMP 13
#define MAX_SOLIDS            8
#define MAX_SETTINGS         14

//----------------------------------------------------------------------------
//  Global Varibles
//----------------------------------------------------------------------------
const int WAIT_TIME = 100;
const uint8_t FEATHER_ADDRESS = 0x43;  // i2C addresses

//----------------------------------------------------------------------------
//  Global Varibles
//----------------------------------------------------------------------------
uint8_t gRunning = 1;
uint8_t gShelfSetting[] = {
  SETTING_SOLID_BLACK, SETTING_SOLID_BLACK,
  SETTING_SOLID_BLACK, SETTING_SOLID_BLACK,
  SETTING_SOLID_BLACK, SETTING_SOLID_BLACK,
  SETTING_SOLID_BLACK, SETTING_SOLID_BLACK,
  SETTING_SOLID_BLACK, SETTING_SOLID_BLACK,
  SETTING_SOLID_BLACK, SETTING_SOLID_BLACK,
  SETTING_SOLID_BLACK, SETTING_SOLID_BLACK,
  SETTING_SOLID_BLACK, SETTING_SOLID_BLACK };
uint16_t gCount;
int gFileI2C = 0;
double gAmps = 0.0;
double gOldAmps = 0.0;
struct mosquitto *gMQTTServer;

//----------------------------------------------------------------------------
//  Purpose:
//    Init the I2C port
//
//  Notes:
//      None
//
//----------------------------------------------------------------------------
void InitI2C()
{
  char *filename = (char*)"/dev/i2c-1";

  //----- OPEN THE I2C BUS -----
  if ((gFileI2C = open(filename, O_RDWR)) < 0)
  {
    printf("Failed to open the fridge i2c bus");
    return;
  }

  if (ioctl(gFileI2C, I2C_SLAVE, FEATHER_ADDRESS) < 0)
  {
    printf("Failed to acquire bus access and/or talk to fridge temp sensor.\n");
    return;
  }
}
//----------------------------------------------------------------------------
//  Purpose:
//     Publish the message
//
//  Notes:
//      None
//
//----------------------------------------------------------------------------
void MQTTPublish(char* topic, uint8_t* packet, uint8_t packetLen)
{
  int returnCode = mosquitto_publish(gMQTTServer, NULL,
    topic, packetLen, packet, 0, 0);

  if (0 != returnCode)
  {
    char data[10];
    printf("publish failed=%d", returnCode);
  }
}

//----------------------------------------------------------------------------
//  Purpose:
//    Call back for the Connection
//
//  Notes:
//      None
//
//----------------------------------------------------------------------------
void ConnectCallback(struct mosquitto *mosq, void *obj, int rc)
{
  printf("rc: %d\n", rc);
}

//----------------------------------------------------------------------------
//  Purpose:
//    Call back for the Connection
//
//  Notes:
//      None
//
//----------------------------------------------------------------------------
void DisconnectCallback(struct mosquitto *mosq, void *obj, int result)
{
  gRunning = false;
}

//----------------------------------------------------------------------------
//  Purpose:
//    Call back for the messages
//
//  Notes:
//      None
//
//----------------------------------------------------------------------------
void MessageCallback(struct mosquitto *mosq, void *obj, const struct mosquitto_message *msg)
{
  int unitID = msg->topic[4] - '1';
  int shelfID = msg->topic[11] - '1';
  int index = (unitID*MAX_CHANNEL) + shelfID;
  char payload[20];

  for (int i = 0; i < 20; i++)
  {
    payload[i] = 0x00;
  }

  memcpy(payload, msg->payload, msg->payloadlen);
  int theColor = atoi(payload);

  gShelfSetting[index] = theColor;

  printf("message:%s %d %d %d %d %s\n", msg->topic,unitID,shelfID,index,theColor,payload);
}

//----------------------------------------------------------------------------
//  Purpose:
//    Set up the signals to intercept the cntl-C
//
//  Notes:
//      None
//
//----------------------------------------------------------------------------
static void CTRLCHandler(int signum)
{
  printf("ctrl c\n");
  (void)(signum);
  gRunning = 0;
}

//----------------------------------------------------------------------------
//  Purpose:
//    Set up the signals to intercept the cntl-C
//
//  Notes:
//      None
//
//----------------------------------------------------------------------------
static void SetupHandlers(void)
{
    struct sigaction sa =
    {
        .sa_handler = CTRLCHandler,
    };

    sigaction(SIGINT, &sa, NULL);
    sigaction(SIGTERM, &sa, NULL);
}

//----------------------------------------------------------------------------
//  Purpose:
//    Main Loop
//
//  Notes:
//      None
//
//----------------------------------------------------------------------------
int main(int argc, char *argv[])
{
  int whichChannel = 0;
  wiringPiSetupGpio();
  double dstart, dstop, diff;
  int mid1 = 0;
  int mid2 = 0;
  char id[50];
  int rc;
  uint8_t doubleData[sizeof(double)];
  char message[50];

  InitI2C();
  SetupHandlers();

  usleep(30000000);

  snprintf(id, 50, "JimsCabinet01");
  gMQTTServer = mosquitto_new(id, true, NULL);
  printf("mosq:%d\n", gMQTTServer);
  mosquitto_connect_callback_set(gMQTTServer, ConnectCallback);
  mosquitto_disconnect_callback_set(gMQTTServer, DisconnectCallback);
  mosquitto_message_callback_set(gMQTTServer, MessageCallback);

  rc = mosquitto_connect(gMQTTServer, "127.0.0.1", 1883, 600);
  printf("Connect:%d\n",rc);
  rc = mosquitto_subscribe(gMQTTServer, &mid1, "unit1/#", 0);
  printf("unit1/#:%d\n",rc);
  rc = mosquitto_subscribe(gMQTTServer, &mid2, "unit2/#", 0);
  printf("unit2/#:%d\n",rc);

  while (gRunning)
  {
    rc = mosquitto_loop(gMQTTServer, 1, 1);

    message[0] = 0xED;
    for (int i = 0; i < 16; i++)
    {
      message[1 + i] = gShelfSetting[i];
    }

    //----- WRITE BYTES -----
    int length = 17;			//<<< Number of bytes to write
    if (write(gFileI2C, message, length) != length)		//write() returns the number of bytes actually written, if it doesn't match then an error occurred (e.g. no response from the device)
    {
      /* ERROR HANDLING: i2c transaction failed */
      printf("Failed to write to the i2c bus.\n");
    }
    for (int i = 0; i < 16; i++)
    {
      printf("%d ", gShelfSetting[i]);
    }
    printf("\n");

    usleep(WAIT_TIME);

    //----- READ BYTES -----
    length = sizeof(double);			//<<< Number of bytes to read
    if (read(gFileI2C, doubleData, length) != length)		//read() returns the number of bytes actually read, if it doesn't match then an error occurred (e.g. no response from the device)
    {
      //ERROR HANDLING: i2c transaction failed
      printf("Failed to read from the i2c bus.\n");
    }
    else
    {
      memcpy(&gAmps, doubleData, sizeof(double));
    }

    if (gOldAmps != gAmps)
    {
      printf("Amps: %f\n", gAmps);
      sprintf(message,"%f", gAmps);
      MQTTPublish("allamps", message, strnlen(message,60));
      gOldAmps = gAmps;
    }

    usleep(1000000 / MAX_FRAMES);
  }

  mosquitto_disconnect(gMQTTServer);
  mosquitto_destroy(gMQTTServer);
  mosquitto_lib_cleanup();

  return 0;
}

