#include <timer.h>
#include <common_macros.h>
#include <gpio.h>

#include <timer_reg.h>
#include <avr/interrupt.h>
#define max_count 10
uint64 g_ticks = 0;
Timer0_ConfigType prev;
Timer0_ConfigType TIMER0;

bool is_intialized = false;
static volatile void (*timer0_callback)(void);
uint64 F_clk;
uint64 ticks = -1;
int count = 0; // count of callback functions
uint64 delays[max_count];
uint64 times[max_count];
static volatile void (*callbacks[max_count])(void);

ISR(TIMER0_OVF_vect)
{

    g_ticks++;
    if (g_ticks == ticks)
    {

        (*timer0_callback)();
        ticks = -1;
        TIMER0_init(&prev);
    }
    for (int i = 0; i < count; i++)
    {
        if (delays[i] == g_ticks)
        {
            (*callbacks[i])();
            delays[i] = g_ticks + times[i];
        }
    }
}
/*
 * Description :
 * intialize timer zero with given configrations
 */

void TIMER0_init(Timer0_ConfigType *Config_Ptr)
{
    TIMER0.initial_value = Config_Ptr->initial_value;
    TIMER0.compare_value = Config_Ptr->compare_value;
    TIMER0.timer_clock = Config_Ptr->timer_clock;
    TIMER0.timer_mode = Config_Ptr->timer_mode;
    TIMER0.com_mode = Config_Ptr->com_mode;
    TIMER0.mode = Config_Ptr->mode;

    // intialize clock
    switch (Config_Ptr->timer_clock)
    {
    case NO_CLOCK:
        CLEAR_BIT(TCCR0B, 0);
        CLEAR_BIT(TCCR0B, 1);
        CLEAR_BIT(TCCR0B, 2);
        break;
    case FCPU:
        CLEAR_BIT(TCCR0B, 2);
        CLEAR_BIT(TCCR0B, 1);
        SET_BIT(TCCR0B, 0);
        F_clk = fcpu;
        break;
    case F_CPU_8:
        CLEAR_BIT(TCCR0B, 0);
        SET_BIT(TCCR0B, 1);
        CLEAR_BIT(TCCR0B, 2);
        F_clk = fcpu / 8;
        break;

    case F_CPU_64:
        CLEAR_BIT(TCCR0B, 2);
        SET_BIT(TCCR0B, 1);
        SET_BIT(TCCR0B, 0);
        F_clk = fcpu / 64;
        break;
    case F_CPU_256:
        SET_BIT(TCCR0B, 2);
        CLEAR_BIT(TCCR0B, 1);
        CLEAR_BIT(TCCR0B, 0);
        F_clk = fcpu / 256;
        break;
    case F_CPU_1024:
        SET_BIT(TCCR0B, 0);
        CLEAR_BIT(TCCR0B, 1);
        SET_BIT(TCCR0B, 2);
        F_clk = fcpu / 1024;
        break;
    }
    switch (Config_Ptr->com_mode)
    {
    case NORMAL:
        is_intialized = true;
        CLEAR_BIT(TCCR0A, 0);
        CLEAR_BIT(TCCR0A, 1);

        CLEAR_BIT(TCCR0B, 3);
        CLEAR_BIT(TCCR0A, 6);
        CLEAR_BIT(TCCR0A, 7);
        if (Config_Ptr->mode == INTERRUPT_MODE)
        {
            SET_BIT(TIMSK0, 0);
            SET_BIT(SREG, 7);
        }

        break;

    case COMPARE_MATCH:
        is_intialized = false;
        CLEAR_BIT(TCCR0A, 0);
        SET_BIT(TCCR0A, 1);
        CLEAR_BIT(TCCR0B, 3);
        if (Config_Ptr->com_mode == SET_COMPARE)
        {
            SET_BIT(TCCR0A, 7);
            SET_BIT(TCCR0A, 6);
        }
        else if (Config_Ptr->com_mode == CLEAR_COMPARE)
        {
            SET_BIT(TCCR0A, 7);
            CLEAR_BIT(TCCR0A, 6);
        }
        else
        {
            CLEAR_BIT(TCCR0A, 7);
            SET_BIT(TCCR0A, 6);
        }
        //   SET_BIT(TIMSK0, 1);
        if (Config_Ptr->mode == INTERRUPT_MODE)
        {
            SET_BIT(TIMSK0, 1);
            SET_BIT(SREG, 7);
        }
        break;

    case FAST_PWM:
        is_intialized = false;
        SET_BIT(TCCR0A, 0);
        SET_BIT(TCCR0A, 1);
        CLEAR_BIT(TCCR0B, 3);
        if (Config_Ptr->com_mode == NON_INVERTING_COMPARE)
        {
            SET_BIT(TCCR0A, 7);
            CLEAR_BIT(TCCR0A, 6);
        }
        else
        {
            SET_BIT(TCCR0A, 6);
            SET_BIT(TCCR0A, 7);
        }
        break;
    }
    // put compare value at OCR0A
    OCR0A = Config_Ptr->compare_value;
    /// put initial value in counter
    TCNT0 = Config_Ptr->initial_value;

    if (Config_Ptr->timer_clock == NO_CLOCK)
        is_intialized = false;
}
/*
 * Description :
 *set the callback function address.
 */
void TIMER0_setCallBack(void (*a_ptr)(void))
{
    timer0_callback = (volatile void *)a_ptr;
}
/*
 * Description :
 *De-initialize the timer
 */
void TIMER0_deinit()
{
    is_intialized = false;
    TCNT0 = 0;
    TCCR0A = 0;
    TCCR0B = 0;
    OCR0A = 0;
    CLEAR_BIT(TIMSK0, 0);

    CLEAR_BIT(TIMSK0, 1);

    CLEAR_BIT(TIMSK0, 2);
}

/*
 * Description :
 *cause delay with amout of time= millis millseconds
 */
void _delay_ms(uint64 millis)
{
    prev.initial_value = TIMER0.initial_value;
    prev.compare_value = TIMER0.compare_value;
    prev.timer_clock = TIMER0.timer_clock;
    prev.timer_mode = TIMER0.timer_mode;
    prev.com_mode = TIMER0.com_mode;
    prev.mode = TIMER0.mode;

    Timer0_ConfigType t = {
        0,
        0,
        F_CPU_1024,
        NORMAL,
        NORMAL_COMPARE,
        POLLING_MODE};
    TIMER0_init(&t);

    if (TIMER0.mode == INTERRUPT_MODE)
    {

        double v = millis * F_clk / 255000.0;
        int y = v;
        double u = v - y;
        TCNT0 = 255 - u * 255;
        ticks = y;
        ticks += g_ticks;
    }
    else
    {
        double v = millis * F_clk / 255000.0;
        int y = v;
        double u = v - y;
        TCNT0 = 255 - u * 255;
        ticks = y;

        for (g_ticks = 0; g_ticks <= ticks; g_ticks++)
        {
            while (READ_BIT(TIFR0, 0) == 0)
                ;

            SET_BIT(TIFR0, 0);
        }

        TIMER0_init(&prev);
    }
}
/*
 * Description :
  *set the callback function address
*used when you want more than one callback function

 */
void TIMER0_setCallBack_m(void (*a_ptr)(void), uint64 delay_ms)
{
    if (count == max_count)
        return;
    float v = delay_ms * F_clk / 255000.0;
    int y = v;

    delays[count] = y;
    delays[count] += g_ticks;
    times[count] = y;
    callbacks[count] = (volatile void *)a_ptr;
    count++;
}

void _delay_us(uint64 micros)
{
    prev.initial_value = TIMER0.initial_value;
    prev.compare_value = TIMER0.compare_value;
    prev.timer_clock = TIMER0.timer_clock;
    prev.timer_mode = TIMER0.timer_mode;
    prev.com_mode = TIMER0.com_mode;
    prev.mode = TIMER0.mode;

    Timer0_ConfigType t = {
        0,
        0,
        F_CPU_1024,
        NORMAL,
        NORMAL_COMPARE,
        POLLING_MODE};
    TIMER0_init(&t);

    if (TIMER0.mode == INTERRUPT_MODE)
    {

        double v = micros * F_clk / 255000000.0;
        int y = v;
        double u = v - y;
        TCNT0 = 255 - u * 255;
        ticks = y;
        ticks += g_ticks;
    }
    else
    {
        double v = micros * F_clk / 255000000.0;
        uint64 y = v;
        double u = v - y;
        TCNT0 = 255 - u * 255;
        ticks = v;

        for (g_ticks = 0; g_ticks <= ticks; g_ticks++)
        {
            while (READ_BIT(TIFR0, 0) == 0)
                ;

            SET_BIT(TIFR0, 0);
        }

        TIMER0_init(&prev);
    }
}
