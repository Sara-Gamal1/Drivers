/******************************************************************************
 *
 * Module: TIMER
 *
 * File Name: timer.h
 *
 * Description: Header file for the AVR GPIO driver
 *
 * Author: Sara Gamal
 *
 *******************************************************************************/

#ifndef TIMER_H_
#define TIMER_H_

#include <std_types.h>

/*******************************************************************************
 *                                Definitions                                  *
 *******************************************************************************/
extern uint64 g_ticks;

#define TIMER0_OVF (*((volatile char *)0x10))
#define TIMER0_COMPA (*((volatile char *)0x00E))
#ifndef fcpu
#define fcpu 16000000
#endif
/*******************************************************************************
 *                               Types Declaration                             *
 *******************************************************************************/

typedef enum
{
    NO_CLOCK,
    FCPU,
    F_CPU_8,
    F_CPU_64,
    F_CPU_256,
    F_CPU_1024
} Timer_F_CLK;

typedef enum
{
    NORMAL = 0,
    OVERFLOW = 0,
    COMPARE_MATCH = 1,
    FAST_PWM = 2
} Timer_Mode;

typedef enum
{
    POLLING_MODE,
    INTERRUPT_MODE
} Process_Mode;

typedef enum
{
    NORMAL_COMPARE,
    SET_COMPARE,
    TOGGLE_COMPARE,
    CLEAR_COMPARE,
    NON_INVERTING_COMPARE,
    INVERTING_COMPARE
} COM_Mode;

typedef struct
{
    uint8 initial_value;     //
    uint8 compare_value;     //
    Timer_F_CLK timer_clock; //
    Timer_Mode timer_mode;   //
    COM_Mode com_mode;
    Process_Mode mode;
} Timer0_ConfigType;

/*******************************************************************************
 *                              Functions Prototypes                           *
 *******************************************************************************/

/*
 * Description :
 * intialize timer zero with given configrations
 */
void TIMER0_init(Timer0_ConfigType *Config_Ptr);

/*
 * Description :
  *set the callback function address

 */
void TIMER0_setCallBack(void (*a_ptr)(void));

/*
 * Description :
  *set the callback function address
*used when you want more than one callback function

 */
void TIMER0_setCallBack_m(void (*a_ptr)(void), uint64 delay_ms);
/*
 * Description :
 *De-initialize the timer
 */
void TIMER0_deinit();

/*
 * Description :
 *cause delay with amout of time= millis millseconds
 */
void _delay_ms(uint64 millis);
/*
 * Description :
 *cause delay with amout of time= millis millseconds
 */
void _delay_us(uint64 micros);

#endif /* TIMER_H_ */
