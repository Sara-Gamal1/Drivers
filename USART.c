#include <common_macros.h>
#include <USART.h>
#include <usart_reg.h>
/*
 * Description :
 * used to initialzie URAT protocol
 * must be called before using after or recive
 * used to send/recieve 8 bits data
 */
void usart_init()
{
    UCSR0A = 0x0;
    UCSR0B = 0x18;
    UCSR0C = 0x06;
    UBRR0H = 0x00;
    UBRR0L = 103;
}
/*
 * Description :
 *used to transmit data
 *it's a blocking function (will not return unless data is send)

 */
void usart_trasnmit(uint8 data)
{
    while (!READ_BIT(UCSR0A, 5))
        ;
    UDR0 = data;
}

/*
 * Description :
 *used to recieve data
 *it's a blocking function (will not return unless data is recieved)
 *in case an error occurs ! will be recieved
 */
uint8 usart_recieve()
{
    while (!READ_BIT(UCSR0A, 7))
        ;
    if (READ_BIT(UCSR0A, 4) == HIGH | READ_BIT(UCSR0A, 3) == HIGH | READ_BIT(UCSR0A, 2) == HIGH)
        return '!'; // in case of error
    return UDR0;
}