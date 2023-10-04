#ifndef USART_REG_H_
#define USART_REG_H_

#define UDR0 (*((volatile char *)0xc6))
#define UBRR0H (*((volatile char *)0xc5))
#define UBRR0L (*((volatile char *)0xc4))

#define UCSR0C (*((volatile char *)0xc2))
#define UCSR0B (*((volatile char *)0xc1))
#define UCSR0A (*((volatile char *)0xc0))

#endif /* USART_REG_H_ */