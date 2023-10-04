#ifndef ADC_REG_H_
#define ADC_REG_H_

#define ADMUX (*((volatile char *)0x7c))
#define ADCSRA (*((volatile char *)0x7a))
#define ADC (*((volatile uint16 *)0x78))

#endif /* ADC_REG_H_ */