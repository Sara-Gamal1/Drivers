#include <common_macros.h>
#include <EEPROM.h>
#include <EEPROM_reg.h>
/*
 * Description :
 * write 8 bit data in the given address
 */
uint8 EEPROM_WriteByte(uint8 Addr, uint8 data)
{
    while (EECR & (1 << 1))
        ;
    /* Set up address and Data Registers */
    EEARL = Addr;
    EEDR = data;
    /* Write logical one to EEMPE */
    EECR |= (1 << 2);
    /* Start eeprom write by setting EEPE */
    EECR |= (1 << 1);
}
/*
 * Description :
 * return 8 bit data from given address
 */
uint8 EEPROM_ReadByte(uint8 Addr)
{
    /* Wait for completion of previous write */
    while (EECR & (1 << 1))
        ;
    /* Set up address register */
    EEARL = Addr;
    /* Start eeprom read by writing EERE */
    EECR |= (1);
    /* Return data from Data Register */
    return EEDR;
}