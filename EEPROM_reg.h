#ifndef EEPROM_REG_H_
#define EEPROM_REG_H_

#define EEARL (*((volatile char *)0x41))
#define EEDR (*((volatile char *)0x40))
#define EECR (*((volatile uint16 *)0x3f))

#endif /* EEPROM_REG_H_ */