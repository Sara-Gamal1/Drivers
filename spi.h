#ifndef SPI_H__
#define SPI_H__
#include <std_types.h>
/*******************************************************************************
 *                               Types Declaration                             *
 *******************************************************************************/

typedef enum
{
    SLAVE,
    MASTER
} ROLE;

typedef enum
{
    FCU_2,
    FCU_4,
    FCU_8,
    FCU_16,
    FCU_32,
    FCU_64,
    FCU_128
} PRESCALER;

/*******************************************************************************
 *                              Functions Prototypes                           *
 *******************************************************************************/
/*
 * Description :
 * used to initialzie SPI protocol
 * must be called before using transmit or recive

 */
void spi_init(ROLE role, PRESCALER pre);
/*
 * Description :
 *used to transmit data
 *it's a blocking function (will not return unless data is send)

 */
void spi_trasnmit(uint8 data);
/*
 * Description :
 *used to recieve data
 *it's a blocking function (will not return unless data is recieved)
 */
uint8 spi_recieve();
#endif /* SPI_H_ */