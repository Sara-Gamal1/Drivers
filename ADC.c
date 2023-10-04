#include <ADC.h>
#include <common_macros.h>
#include <ADC_reg.h>
/*
 * Description :
 * read analog value from given pin
 */
uint16 ADC_read(uint8 pin_num)
{
    ADMUX |= 0b1 << 6;
    ADCSRA |= 0b11100111;
    switch (pin_num)
    {
    case 0:
        break;
    case 1:
        SET_BIT(ADMUX, 0);
        break;
    case 2:
        SET_BIT(ADMUX, 1);
        break;
    case 3:
        SET_BIT(ADMUX, 0);
        SET_BIT(ADMUX, 1);
        break;
    case 4:
        SET_BIT(ADMUX, 2);
        break;
    case 5:
        SET_BIT(ADMUX, 0);
        SET_BIT(ADMUX, 2);
        break;
    }
    while (!(ADCSRA & 1 << 4))
        ;

    ADCSRA |= 1 << 4;
    return ADC;
}