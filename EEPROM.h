#ifndef EEPROM_H_
#define EEPROM_H_

#include <std_types.h>
/*******************************************************************************
 *                              Functions Prototypes                           *
 *******************************************************************************/
/*
 * Description :
 * write 8 bit data in the given address
 */
uint8 EEPROM_WriteByte(uint8 Addr, uint8 data);
/*
 * Description :
 * return 8 bit data from given address
 */
uint8 EEPROM_ReadByte(uint8 Addr);

#endif /* EEPROM_H_ */