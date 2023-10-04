#include <keybad.h>
#include <common_macros.h>

/*
 * Description :
*return specific key pressed based in the column and the row of 4x3 bad.

 */
uint8 keybad4x3(uint8 num)
{
    num++;
    switch (num)
    {
    case 10:
        return '*';
    case 11:
        return '0';

    case 12:
        return '#';
    default:
        return num + '0';
    }
}

/*
 * Description :
*return specific key pressed based in the column and the row of 4x4 bad.

 */
uint8 keybad4x4(int num)
{
    {
        num++;
        switch (num)
        {
        case 1:
            return '1';
        case 2:
            return '2';

        case 3:
            return '3';
        case 4:
            return 'A';
        case 5:
            return '4';

        case 6:

            return '5';
        case 7:
            return '6';

        case 8:

            return 'B';
        case 9:
            return '7';

        case 10:
            return '8';

        case 11:
            return '9';

        case 12:

            return 'C';
        case 13:
            return '*';

        case 14:
            return '0';

        case 15:
            return '#';

        case 16:
            return 'D';
        }
    }
}
/*
 * Description :
 * return key pressed in keybad
 * if no key is pressed function will continue until a key is pressed .
* if no key is pressed function will continue until a key is pressed .
 * default is to take first 4/3  pins in port  as input(columns) and second  4    pins as output(rows) .

 */
uint8 Keypad_GetPressedKey()
{
#if (N_Col == 3)

    GPIO_setupPinDirection(Keypad_Port_In, 0, PIN_INPUT); // columns
    GPIO_setupPinDirection(Keypad_Port_In, 1, PIN_INPUT);
    GPIO_setupPinDirection(Keypad_Port_In, 2, PIN_INPUT);
    GPIO_writePin(Keypad_Port_In, 0, PIN_OUTPUT); // internal pull up
    GPIO_writePin(Keypad_Port_In, 1, PIN_OUTPUT); // internal pull up
    GPIO_writePin(Keypad_Port_In, 2, PIN_OUTPUT); // internal pull up
    uint8 PORT_OUTval = GPIO_readPort(Keypad_Port_Out);
    while (1)
    {

        for (uint8 row = 0; row < N_Row; row++)
        {

            GPIO_setupPinDirection(Keypad_Port_Out, 4, LOW);
            GPIO_setupPinDirection(Keypad_Port_Out, 5, LOW);
            GPIO_setupPinDirection(Keypad_Port_Out, 6, LOW);
            GPIO_setupPinDirection(Keypad_Port_Out, 7, LOW);
            GPIO_setupPinDirection(Keypad_Port_Out, row + 4, HIGH);

            GPIO_writePort(Keypad_Port_Out, ~(0b00010000 << row));

            for (uint8 col = 0; col < N_Row; col++)
            {
                if (GPIO_readPin(Keypad_Port_In, col) == LOW)
                {
                    GPIO_writePort(Keypad_Port_Out, PORT_OUTval);
                    return keybad4x3(row * N_Col + col);
                }
            }
        }
    }

#elif (N_Col == 4)
    GPIO_setupPinDirection(Keypad_Port_In, 0, PIN_INPUT); // columns
    GPIO_setupPinDirection(Keypad_Port_In, 1, PIN_INPUT);
    GPIO_setupPinDirection(Keypad_Port_In, 2, PIN_INPUT);
    GPIO_setupPinDirection(Keypad_Port_In, 3, PIN_INPUT);
    GPIO_writePin(Keypad_Port_In, 0, PIN_OUTPUT); // internal pull up
    GPIO_writePin(Keypad_Port_In, 1, PIN_OUTPUT); // internal pull up
    GPIO_writePin(Keypad_Port_In, 2, PIN_OUTPUT); // internal pull up
    GPIO_writePin(Keypad_Port_In, 3, PIN_OUTPUT); // internal pull up
    uint8 PORT_OUTval = GPIO_readPort(Keypad_Port_Out);
    while (1)
    {

        for (uint8 row = 0; row < N_Row; row++)
        {
            GPIO_setupPinDirection(Keypad_Port_Out, 4, LOW);
            GPIO_setupPinDirection(Keypad_Port_Out, 5, LOW);
            GPIO_setupPinDirection(Keypad_Port_Out, 6, LOW);
            GPIO_setupPinDirection(Keypad_Port_Out, 7, LOW);
            GPIO_setupPinDirection(Keypad_Port_Out, row + 4, HIGH);

            GPIO_writePort(Keypad_Port_Out, ~(0b00010000 << row));

            for (uint8 col = 0; col < N_Row; col++)
            {
                if (GPIO_readPin(Keypad_Port_In, col) == LOW)
                {
                    GPIO_writePort(Keypad_Port_Out, PORT_OUTval);
                    return keybad4x4(row * N_Col + col);
                }
            }
        }
    }

#endif
}
