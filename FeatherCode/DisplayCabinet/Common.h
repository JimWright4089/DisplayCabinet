//----------------------------------------------------------------------------
//
//  $Workfile: Common.h$
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
#ifndef COMMON_H
#define COMMON_H

//----------------------------------------------------------------------------
//  Global Typedefs
//----------------------------------------------------------------------------
typedef unsigned char uint8;
typedef unsigned short uint16;
typedef unsigned long uint32;
typedef unsigned long uint32_t;

//----------------------------------------------------------------------------
//  Global Constants
//----------------------------------------------------------------------------
const uint8  MAX_LEDS            = 46;
const int    MAX_LINES           = 62;
const int    MAX_SHELFS          =  8;
const int    MAX_UNITS           =  2;

const int SOLID_BLACK  =  0;
const int SOLID_BLUE   =  1;
const int SOLID_GREEN  =  2;
const int SOLID_ORANGE =  3;
const int SOLID_PURPLE =  4;
const int SOLID_YELLOW =  5;
const int SOLID_RED    =  6;
const int SOLID_WHITE  =  7;
const int ANIM_FIRE    =  8;
const int ANIM_LAVA    =  9;
const int ANIM_STARS   = 10;
const int ANIM_ALIEN   = 11;
const int ANIM_OCEAN   = 12;
const int ANIM_SWAMP   = 13;

const uint32 COLOR_WHITE   = 0x00FFFFFF;
const uint32 COLOR_YELLOW  = 0x00FFFF00;
const uint32 COLOR_RED     = 0x00FF0000;
const uint32 COLOR_PURPLE  = 0x008F008F;
const uint32 COLOR_ORANGE  = 0x00FF3000;
const uint32 COLOR_GREEN   = 0x0000FF00;
const uint32 COLOR_BLUE    = 0x000000FF;
const uint8 COLOR_BLACK    = 0x00000000;

//----------------------------------------------------------------------------
//  Global Arrays
//----------------------------------------------------------------------------
extern const uint32_t gFireData[62][46];
extern const uint32_t gLavaData[62][46];
extern const uint32_t gOceanData[62][46];
extern const uint32_t gSwampData[62][46];
extern const uint32_t gAlienData[62][46];
extern const uint32_t gStarsData[62][46];
#endif

