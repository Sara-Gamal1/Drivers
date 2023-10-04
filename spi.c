#include <common_macros.h>
#include <spi.h>
#include <spi_reg.h>
#include <gpio_reg.h>
/*
 * Description :
 * used to initialzie SPI protocol
 * must be called before using transmit or recive

 */
void spi_init(ROLE role, PRESCALER pre)
{
    uint8 temp;
    temp = 0x60;
    if (role == MASTER)
    {

        SET_BIT(temp, 4);
        SET_BIT(DDRB, 2); // SS
        CLEAR_BIT(PORTB, 2);
        CLEAR_BIT(DDRB, 4); // MISO
        SET_BIT(DDRB, 3);   // MOSI
        SET_BIT(DDRB, 5);   // clk
    }
    else
    {
        CLEAR_BIT(DDRB, 2);
        SET_BIT(DDRB, 4);   // MISO
        CLEAR_BIT(DDRB, 3); // MOSI
        CLEAR_BIT(DDRB, 5); // clk
    }
    switch (pre)
    {
    case FCU_4:
        CLEAR_BIT(temp, 0);
        CLEAR_BIT(temp, 1);
        CLEAR_BIT(temp, 0);
        break;
    case FCU_16:
        SET_BIT(temp, 0);
        CLEAR_BIT(temp, 1);
        CLEAR_BIT(temp, 0);
        break;
    case FCU_64:
        CLEAR_BIT(temp, 0);
        SET_BIT(temp, 1);
        CLEAR_BIT(temp, 0);
        break;
    case FCU_128:
        SET_BIT(temp, 0);
        SET_BIT(temp, 1);
        CLEAR_BIT(temp, 0);
        break;
    case FCU_2:
        CLEAR_BIT(temp, 0);
        CLEAR_BIT(temp, 1);
        SET_BIT(temp, 0);
        break;
    case FCU_8:
        SET_BIT(temp, 0);
        CLEAR_BIT(temp, 1);
        SET_BIT(temp, 0);
        break;
    case FCU_32:
        CLEAR_BIT(temp, 0);
        SET_BIT(temp, 1);
        SET_BIT(temp, 0);
        break;
    }
    SPSR = temp;
}
/*
 * Description :
 *used to transmit data
 *it's a blocking function (will not return unless data is send)

 */
void spi_trasnmit(uint8 data)
{

    SPDR = data;
    while (!READ_BIT(SPSR, 7))
        ;
}

/*
 * Description :
 *used to recieve data
 *it's a blocking function (will not return unless data is recieved)
 */
uint8 spi_recieve()
{

    while (!READ_BIT(SPSR, 7))
        ;
    return SPDR;
}