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
#include "Common.h"

//----------------------------------------------------------------------------
//  Global Defines
//----------------------------------------------------------------------------
#define PIN1        5
#define PIN2       11

//----------------------------------------------------------------------------
//  Class attributes
//----------------------------------------------------------------------------
Adafruit_NeoPixel_ZeroDMA mStrip1(MAX_LEDS, PIN1, NEO_GRB);
Adafruit_NeoPixel_ZeroDMA mStrip2(MAX_LEDS, PIN2, NEO_GRB);
int mPin = 0;
int mLineCount = 0;
uint32 mShelfs[MAX_UNITS*MAX_SHELFS][MAX_LEDS];
uint16 mShelfSettings[MAX_UNITS*MAX_SHELFS];

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
  mStrip1.begin();
  mStrip1.setBrightness(170);
  mStrip1.show();
  mStrip2.begin();
  mStrip2.setBrightness(170);
  mStrip2.show();
  
  pinMode(14, OUTPUT);
  pinMode(15, OUTPUT);
  pinMode(16, OUTPUT);
  pinMode(17, OUTPUT);
  pinMode(18, OUTPUT);
  pinMode(19, OUTPUT);

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
  mShelfSettings[11] = ANIM_OCEAN;
  mShelfSettings[12] = ANIM_SWAMP;
  mShelfSettings[13] = ANIM_ALIEN;
  mShelfSettings[14] = ANIM_OCEAN;
  mShelfSettings[15] = ANIM_SWAMP;
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
  SetColors();
  for(int i=0; i<MAX_LEDS; i++) 
  {
    mStrip1.setPixelColor(i, mShelfs[mPin][i]);
    mStrip2.setPixelColor(i, mShelfs[mPin+MAX_SHELFS][i]);
  }
  mStrip1.show();
  mStrip2.show();

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
  }

  // Set the pins after waiting due to the stripts are not done painting yet.
  delay(20);
  SetPins(mPin);
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
  
  digitalWrite(14, bit0);  
  digitalWrite(15, bit1);  
  digitalWrite(16, bit2);  
  digitalWrite(17, bit0);  
  digitalWrite(18, bit1);  
  digitalWrite(19, bit2);  
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


