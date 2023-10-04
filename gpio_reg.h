#ifndef GPIO_REG_H_
#define GPIO_REG_H_

#define PORTD (*((volatile char *)0x2B))
#define PIND (*((volatile const char *)0x29))
#define DDRD (*((volatile char *)0x2A))

#define PORTC (*((volatile char *)0x28))
#define PINC (*((volatile const char *)0x26))
#define DDRC (*((volatile char *)0x27))

#define PORTB (*((volatile char *)0x25))
#define PINB (*((volatile const char *)0x23))
#define DDRB (*((volatile char *)0x24))

#endif /* GPIO_REG_H_ */