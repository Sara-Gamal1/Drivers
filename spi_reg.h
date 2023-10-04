#ifndef SPI_REG_H_
#define SPI_REG_H_

#define SPCR (*((volatile char *)0x4c))
#define SPSR (*((volatile char *)0x4d))
#define SPDR (*((volatile char *)0x4e))


#endif /* SPI_REG_H_ */