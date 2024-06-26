#include <gpio.h>
#include <common_macros.h>
#include <gpio_reg.h>
/*
 * Description :
 * Setup the direction of the required pin input/output.
 * If the input port number or pin number are not correct, The function will not handle the request.
 */
void GPIO_setupPinDirection(uint8 port_num, uint8 pin_num, GPIO_PinDirectionType direction)
{
    switch (port_num)
    {
    case PORTB_ID:
        if (pin_num >= NUM_OF_PINS_PER_PORT_B || pin_num < 0)
        {
            // do Nothing
        }
        else
        {
            if (direction == HIGH)
            {
                SET_BIT(DDRB, pin_num);
            }
            else
            {
                CLEAR_BIT(DDRB, pin_num);
            }
        }
        break;
    case PORTC_ID:
        if (pin_num >= NUM_OF_PINS_PER_PORT_C || pin_num < 0)
        {
            // do Nothing
        }
        else
        {
            if (direction == HIGH)
            {
                SET_BIT(DDRC, pin_num);
            }
            else
            {
                CLEAR_BIT(DDRC, pin_num);
            }
        }
        break;
    case PORTD_ID:
        if (pin_num >= NUM_OF_PINS_PER_PORT_D || pin_num < 0)
        {
            // do Nothing
        }
        else
        {
            if (direction == HIGH)
            {
                SET_BIT(DDRD, pin_num);
            }
            else
            {
                CLEAR_BIT(DDRD, pin_num);
            }
        }
        break;
    }
}

/*
 * Description :
 * Write the value Logic High or Logic Low on the required pin.
 * If the input port number or pin number are not correct, The function will not handle the request.
 * If the pin is input, this function will enable/disable the internal pull-up resistor.
 */
void GPIO_writePin(uint8 port_num, uint8 pin_num, uint8 value)
{

    switch (port_num)
    {
    case PORTB_ID:
        if (pin_num >= NUM_OF_PINS_PER_PORT_B || pin_num < 0)
        {
            // do Nothing
        }
        else
        {
            if (value == HIGH)
            {
                SET_BIT(PORTB, pin_num);
            }
            else
            {
                CLEAR_BIT(PORTB, pin_num);
            }
        }
        break;
    case PORTC_ID:
        if (pin_num >= NUM_OF_PINS_PER_PORT_C || pin_num < 0)
        {
            // do Nothing
        }
        else
        {
            if (value == HIGH)
            {
                SET_BIT(PORTC, pin_num);
            }
            else
            {
                CLEAR_BIT(PORTC, pin_num);
            }
        }
        break;
    case PORTD_ID:
        if (pin_num >= NUM_OF_PINS_PER_PORT_D || pin_num < 0)
        {
            // do Nothing
        }
        else
        {
            if (value == HIGH)
            {
                SET_BIT(PORTD, pin_num);
            }
            else
            {
                CLEAR_BIT(PORTD, pin_num);
            }
        }
        break;
    }
}

/*
 * Description :
 * Read and return the value for the required pin, it should be Logic High or Logic Low.
 * If the input port number or pin number are not correct, The function will return Logic Low.
 */
uint8 GPIO_readPin(uint8 port_num, uint8 pin_num)
{
    uint8 pin_value = LOW;
    if (port_num == PORTB_ID || port_num == PORTC_ID || port_num == PORTD_ID)
    {
        switch (port_num)
        {
        case PORTB_ID:
            if (pin_num >= NUM_OF_PINS_PER_PORT_B || pin_num < 0)
            {
                // do Nothing
            }
            else
            {
                pin_value = READ_BIT(PINB, pin_num);
            }
            break;
        case PORTC_ID:
            if (pin_num >= NUM_OF_PINS_PER_PORT_C || pin_num < 0)
            {
                // do Nothing
            }
            else
            {
                pin_value = READ_BIT(PINC, pin_num);
            }
            break;
        case PORTD_ID:
            if (pin_num >= NUM_OF_PINS_PER_PORT_D || pin_num < 0)
            {
                // do Nothing
            }
            else
            {
                pin_value = READ_BIT(PIND, pin_num);
            }
            break;
        }
    }
    return pin_value;
}

/*
 * Description :
 * Setup the direction of the required port all pins input/output.
 * If the direction value is PORT_INPUT all pins in this port should be input pins.
 * If the direction value is PORT_OUTPUT all pins in this port should be output pins.
 * If the input port number is not correct, The function will not handle the request.
 */
void GPIO_setupPortDirection(uint8 port_num, uint8 direction)
{
    switch (port_num)
    {
    case PORTB_ID:

        DDRB = direction;

        break;
    case PORTC_ID:
        DDRC = direction;
        break;
    case PORTD_ID:
        DDRD = direction;
        break;
    }
}

/*
 * Description :
 * Write the value on the required port.
 * If any pin in the port is output pin the value will be written.
 * If any pin in the port is input pin this will activate/deactivate the internal pull-up resistor.
 * If the input port number is not correct, The function will not handle the request.
 */
void GPIO_writePort(uint8 port_num, uint8 value)
{
    switch (port_num)
    {
    case PORTB_ID:

        PORTB = value;

        break;
    case PORTC_ID:
        PORTC = value;
        break;
    case PORTD_ID:
        PORTD = value;
        break;
    }
}

/*
 * Description :
 * Read and return the value of the required port.
 * If the input port number is not correct, The function will return ZERO value.
 */
uint8 GPIO_readPort(uint8 port_num)
{
    uint8 portvalue = 0;
    switch (port_num)
    {
    case PORTB_ID:

        portvalue = PORTB;

        break;
    case PORTC_ID:
        portvalue = PORTC;
        break;
    case PORTD_ID:
        portvalue = PORTD;
        break;
    }
    return portvalue;
}