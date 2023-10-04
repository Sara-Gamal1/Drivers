#ifndef TIMER_REG_H_
#define TIMER_REG_H_

#define TCCR0A (*((volatile char *)0x44))
#define TCCR0B (*((volatile char *)0x45))
#define TCNT0 (*((volatile char *)0x46))

#define OCR0A (*((volatile char *)0x47))
#define OCR0B (*((volatile char *)0x48))
#define TIMSK0 (*((volatile char *)0x6E))

#define TIFR0 (*((volatile char *)0x35))

#define TCNT2 (*((volatile char *)0xb2))

#define TCCR2B (*((volatile char *)0xb1))

#define TCCR2A (*((volatile char *)0xb0))

#define SREG (*((volatile char *)0x5F))

#endif /* TIMER_REG_H_ */
