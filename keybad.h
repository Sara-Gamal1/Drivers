/******************************************************************************
 *
 * Module: KEYBAD
 *
 * File Name: keybad.h
 *
 * Description: Header file for the keybad driver
 *
 * Author: Sara Gamal
 *
 *******************************************************************************/

#ifndef KEYBAD_H_
#define KEYBAD_H_

#include <std_types.h>
#include <gpio.h>
/*******************************************************************************
 *                                Definitions                                  *
 *******************************************************************************/

#define Keypad_Port_Out PORTD_ID
#define Keypad_Port_In PORTD_ID
#define N_Col 4
#define N_Row 4

/*******************************************************************************
 *                              Functions Prototypes                           *
 *******************************************************************************/

/*
 * Description :
 * return key pressed in keybad
 * if no key is pressed function will continue until a key is pressed .
* if no key is pressed function will continue until a key is pressed .
 * default is to take first 4/3  pins in port  as input(columns) and second  4    pins as output(rows) .

 */
uint8 Keypad_GetPressedKey();
#endif /* KEYBAD_H_ */
