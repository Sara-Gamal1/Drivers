/******************************************************************************
 *
 * Module: 7_SEGMENT
 *
 * File Name: 7_segment.h
 *
 * Description: Header file for the AVR 7_segment driver
 *
 * Author: Sara Gamal
 *
 *******************************************************************************/

#ifndef _7_SEGMENT_h
#define _7_SEGMENT_h

#include <std_types.h>
#include <gpio.h>
/*******************************************************************************
 *                                Definitions                                  *
 *******************************************************************************/
#define SEGMENT_PORT PORTD_ID
#define COMMON_ANODE // put COMMON_ANODE OR COMMON_CATHODE

/*******************************************************************************
 *                              Functions Prototypes                           *
 *******************************************************************************/
/*
 * Description :
 *intiliaze 7_segment.
 * make SEGMENT_PORT outputport
 * must be called before any Display
 */
void segment_init();
/*
 * Description :
 *Display number 0 on 7 segment
 */
void Display0();
/*
 * Description :
 *Display number 1 on 7 segment
 */
void Display1();
/*
 * Description :
 *Display number 2 on 7 segment
 */
void Display2();
/*
 * Description :
 *Display number 3 on 7 segment
 */
void Display3();
/*
 * Description :
 *Display number 4 on 7 segment
 */
void Display4();
/*
 * Description :
 *Display number 5 on 7 segment
 */
void Display5();
/*
 * Description :
 *Display number 6 on 7 segment
 */
void Display6();
/*
 * Description :
 *Display number 7 on 7 segment
 */
void Display7();

/*
 * Description :
 *Display number 8 on 7 segment
 */
void Display8();

/*
 * Description :
 *Display number 9 on 7 segment
 */
void Display9();

/*
 * Description :
 *Display character A on 7 segment
 */
void DisplayA();
/*
 * Description :
 *Display character B on 7 segment
 */
void DisplayB();
/*
 * Description :
 *Display character C on 7 segment
 */
void DisplayC();
/*
 * Description :
 *Display character D on 7 segment
 */
void DisplayD();
/*
 * Description :
 *Display character E on 7 segment
 */
void DisplayE();

/*
 * Description :
 *Display character F on 7 segment
 */
void DisplayF();
/*
 * Description :
 *turn off all leds
 */
void segment_off();

#endif /* _7_SEGMENT_h */
