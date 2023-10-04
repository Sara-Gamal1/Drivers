#ifndef USART_H__
#define USEART_H__
#include <std_types.h>
/*******************************************************************************
 *                              Functions Prototypes                           *
 *******************************************************************************/

/*
 * Description :
 * used to initialzie URAT protocol
 * must be called before using transmit or recive
 * used to send/recieve 8 bits data
 */
void usart_init();

/*
 * Description :
 *used to transmit data
 *it's a blocking function (will not return unless data is send)

 */
void usart_trasnmit(uint8 data);

/*
 * Description :
 *used to recieve data
 *it's a blocking function (will not return unless data is recieved)
 *in case an error occurs ! will be recieved
 */
uint8 usart_recieve();
#endif /*USEART_H__*/
