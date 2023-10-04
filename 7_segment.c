#include <7_segment.h>

#ifdef COMMON_ANODE
const uint8 Patterns[16] = {
    0b11000000, // 0
    0b11111001, // 1
    0b10100100, // 2
    0b10110000, // 3
    0b10011001, // 4
    0b10010010, // 5
    0b10000010, // 6
    0b11111000, // 7
    0b10000000, // 8
    0b10010000, // 9
    0b10001000, // A
    0b10000011, // B
    0b11000110, // C
    0b10100001, // D
    0b10000110, // E
    0b10001110  // F
};
#else
const uint8 Patterns[16] = {
    0b00111111, // 0
    0b00000110, // 1
    0b01011011, // 2
    0b01001111, // 3
    0b01100110, // 4
    0b01101101, // 5
    0b01111101, // 6
    0b00000111, // 7
    0b01111111, // 8
    0b01101111, // 9
    0b01110111, // A
    0b01111100, // B
    0b00111001, // C
    0b01011110, // D
    0b01111001, // E
    0b01110001  // F

};
#endif

/*
 * Description :
 *intiliaze 7_segment.
 * make SEGMENT_PORT outputport
 * must be called before any Display
 */
void segment_init()
{
    GPIO_setupPortDirection(SEGMENT_PORT, 0xff);
    GPIO_writePort(SEGMENT_PORT, 0x00);
}

/*
 * Description :
 *Display number 0 on 7 segment
 */
void Display0()
{
    GPIO_writePort(SEGMENT_PORT, Patterns[0]);
}

void Display1()
{
    GPIO_writePort(SEGMENT_PORT, Patterns[1]);
}
/*
 * Description :
 *Display number 2 on 7 segment
 */
void Display2()
{
    GPIO_writePort(SEGMENT_PORT, Patterns[2]);
}
/*
 * Description :
 *Display number 3 on 7 segment
 */
void Display3()
{
    GPIO_writePort(SEGMENT_PORT, Patterns[3]);
}
/*
 * Description :
 *Display number 4 on 7 segment
 */
void Display4()
{
    GPIO_writePort(SEGMENT_PORT, Patterns[4]);
}
/*
 * Description :
 *Display number 5 on 7 segment
 */
void Display5()
{
    GPIO_writePort(SEGMENT_PORT, Patterns[5]);
}
/*
 * Description :
 *Display number 6 on 7 segment
 */
void Display6()
{
    GPIO_writePort(SEGMENT_PORT, Patterns[6]);
}
/*
 * Description :
 *Display number 7 on 7 segment
 */
void Display7()
{
    GPIO_writePort(SEGMENT_PORT, Patterns[7]);
}

/*
 * Description :
 *Display number 8 on 7 segment
 */
void Display8()
{
    GPIO_writePort(SEGMENT_PORT, Patterns[8]);
}

/*
 * Description :
 *Display number 9 on 7 segment
 */
void Display9() { GPIO_writePort(SEGMENT_PORT, Patterns[9]); }

/*
 * Description :
 *Display character A on 7 segment
 */
void DisplayA() { GPIO_writePort(SEGMENT_PORT, Patterns[10]); }
/*
 * Description :
 *Display character B on 7 segment
 */
void DisplayB() { GPIO_writePort(SEGMENT_PORT, Patterns[11]); }
/*
 * Description :
 *Display character C on 7 segment
 */
void DisplayC() { GPIO_writePort(SEGMENT_PORT, Patterns[12]); }
/*
 * Description :
 *Display character D on 7 segment
 */
void DisplayD() { GPIO_writePort(SEGMENT_PORT, Patterns[13]); }
/*
 * Description :
 *Display character E on 7 segment
 */
void DisplayE() { GPIO_writePort(SEGMENT_PORT, Patterns[14]); }

/*
 * Description :
 *Display character F on 7 segment
 */
void DisplayF() { GPIO_writePort(SEGMENT_PORT, Patterns[15]); }

/*
 * Description :
 *turn off all leds
 */
void segment_off()
{
#ifdef COMMON_ANODE
    GPIO_writePort(SEGMENT_PORT, 0xff);
#else
    GPIO_writePort(SEGMENT_PORT, 0x00);
#endif
}
