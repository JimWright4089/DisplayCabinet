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
#include <Adafruit_NeoPixel_ZeroDMA.h>
#include <Wire.h>
#include "Common.h"

//----------------------------------------------------------------------------
//  Global Defines
//----------------------------------------------------------------------------
#define PIN1        5
#define PIN2       11

const double MAX_AVERAGE = 32.0;

//----------------------------------------------------------------------------
//  Class attributes
//----------------------------------------------------------------------------
Adafruit_NeoPixel_ZeroDMA mStrip1(MAX_LEDS, PIN1, NEO_GRB);
Adafruit_NeoPixel_ZeroDMA mStrip2(MAX_LEDS, PIN2, NEO_GRB);        //  <----  Power 
int mPin = 0;                                                      //     Strip 1           Strip 2
int mLineCount = 0;                                                // O O O O O O O O    O O O O O O O O 
uint32 mShelfs[MAX_UNITS*MAX_SHELFS][MAX_LEDS];                    // 0 1 2 3 4 5 6 7    0 1 2 3 4 5 6 7
uint16 mShelfSettings[MAX_UNITS*MAX_SHELFS];
int mSensorPin = A0;
double mTotal=0.0;
uint8 mSendData[sizeof(double)];
uint8 mLocation = 0;

//----------------------------------------------------------------------------
//  Purpose:
//      Set up the Ardiuno
//
//  Notes:
//      None
//
//----------------------------------------------------------------------------
void setup() 
{
  Serial.begin(115200);

  Wire.begin(0x43);             
  Wire.onReceive(ReceiveEvent); 
  Wire.onRequest(RequestEvent);
  
  mStrip1.begin();
  mStrip1.setBrightness(200);
  mStrip1.show();
  mStrip2.begin();
  mStrip2.setBrightness(200);
  mStrip2.show();
  
  pinMode( 6, OUTPUT);
  pinMode( 9, OUTPUT);
  pinMode(10, OUTPUT);

  // Set up  the shelfs for testing
  mShelfSettings[ 0] = SOLID_BLUE;
  mShelfSettings[ 1] = SOLID_GREEN;
  mShelfSettings[ 2] = SOLID_ORANGE;  
  mShelfSettings[ 3] = SOLID_PURPLE;
  mShelfSettings[ 4] = SOLID_YELLOW;
  mShelfSettings[ 5] = SOLID_RED;
  mShelfSettings[ 6] = SOLID_WHITE;
  mShelfSettings[ 7] = ANIM_FIRE;
  mShelfSettings[ 8] = ANIM_LAVA;
  mShelfSettings[ 9] = ANIM_STARS;
  mShelfSettings[10] = ANIM_ALIEN;
  mShelfSettings[11] = SOLID_YELLOW;
  mShelfSettings[12] = SOLID_RED;
  mShelfSettings[13] = SOLID_GREEN;
  mShelfSettings[14] = ANIM_OCEAN;
  mShelfSettings[15] = ANIM_SWAMP;
  
  for(int i=0;i<16;i++)
  {
    mShelfSettings[ i] = SOLID_BLACK;
  }
}

//----------------------------------------------------------------------------
//  Purpose:
//      Idle Loop
//
//  Notes:
//      None
//
//----------------------------------------------------------------------------
void loop() 
{
  mTotal -= mTotal/MAX_AVERAGE;
  double newAmount = (double)analogRead(mSensorPin)*0.42;
  mTotal += newAmount/MAX_AVERAGE;

  memcpy(mSendData,&mTotal,sizeof(double));

  // Move to the next channel
  mPin++;
  if(mPin>=8)
  {
    mPin = 0;

    // Change the line of the animated images.
    mLineCount++;
    if(mLineCount>=MAX_LINES)
    {
      mLineCount = 0;
    } 
    Serial.print("amp=");
    Serial.println(mTotal);
  }

  SetColors();
  for(int i=0; i<MAX_LEDS; i++) 
  {
    mStrip1.setPixelColor(i, mShelfs[mPin][i]);
    mStrip2.setPixelColor(i, mShelfs[mPin+MAX_SHELFS][i]);
  }
  
  // Set the pins after waiting due to the stripts are not done painting yet.
  delay(100);
  SetPins(mPin);
  mStrip1.show();
  mStrip2.show();
}

//----------------------------------------------------------------------------
//  Purpose:
//      Change the channels of the 74HC155
//
//  Notes:
//      None
//
//----------------------------------------------------------------------------
void SetPins(int pins)
{
  int bit0 = ((pins>>2)&01)==1?HIGH:LOW;
  int bit1 = ((pins>>1)&01)==1?HIGH:LOW;
  int bit2 = (   (pins)&01)==1?HIGH:LOW;
  
  digitalWrite( 6, bit0);  
  digitalWrite( 9, bit1);  
  digitalWrite(10, bit2);  
}

//----------------------------------------------------------------------------
//  Purpose:
//      Set the array for displaying LEDs
//
//  Notes:
//      None
//
//----------------------------------------------------------------------------
void SetColors()
{
  for(int i=0;i<MAX_SHELFS*MAX_UNITS;i++)
  {
    SetLEDs(i,mShelfSettings[i]);
  }
}

//----------------------------------------------------------------------------
//  Purpose:
//      Set all of the LEDs in a row of the Shelf Array
//
//  Notes:
//      None
//
//----------------------------------------------------------------------------
void SetLEDs(int index, int color)
{
  for(int i=0;i<MAX_LEDS;i++)
  {
    switch(color)
    {
      case(SOLID_BLUE):
        mShelfs[index][i] = COLOR_BLUE; 
        break;
      case(SOLID_GREEN):
        mShelfs[index][i] = COLOR_GREEN; 
        break;
      case(SOLID_ORANGE):
        mShelfs[index][i] = COLOR_ORANGE; 
        break;
      case(SOLID_PURPLE):
        mShelfs[index][i] = COLOR_PURPLE; 
        break;
      case(SOLID_YELLOW):
        mShelfs[index][i] = COLOR_YELLOW; 
        break;
      case(SOLID_RED):
        mShelfs[index][i] = COLOR_RED; 
        break;
      case(SOLID_WHITE):
        mShelfs[index][i] = COLOR_WHITE; 
        break;
      case(ANIM_FIRE):
        mShelfs[index][i] = gFireData[mLineCount][i]; 
        break;
      case(ANIM_LAVA):
        mShelfs[index][i] = gLavaData[mLineCount][i]; 
        break;
      case(ANIM_STARS):
        mShelfs[index][i] = gStarsData[mLineCount][i]; 
        break;
      case(ANIM_ALIEN):
        mShelfs[index][i] = gAlienData[mLineCount][i]; 
        break;
      case(ANIM_OCEAN):
        mShelfs[index][i] = gOceanData[mLineCount][i]; 
        break;
      case(ANIM_SWAMP):
        mShelfs[index][i] = gSwampData[mLineCount][i]; 
        break;
      default:
        mShelfs[index][i] = COLOR_BLACK; 
        break;
    }
  }
}

//----------------------------------------------------------------------------
//  Purpose:
//      Get bytes from I2C
//
//  Notes:
//      None
//
//----------------------------------------------------------------------------
void ReceiveEvent(int howMany)
{
  while(0 < Wire.available()) // loop through all but the last
  {
    uint8_t ch = Wire.read();

    if(0xED == ch)
    {
      mLocation = 0;
    }
    else
    {
      mShelfSettings[mLocation] = ch; 
      mLocation++;
      if(mLocation >= MAX_SHELFS*MAX_UNITS)
      {
        mLocation=0;
      }
    }
  }
}

//----------------------------------------------------------------------------
//  Purpose:
//      Send the amps over as a double
//
//  Notes:
//      None
//
//----------------------------------------------------------------------------
void RequestEvent()
{
  Wire.write(mSendData,sizeof(double));
}
