/* basic math for CHRISTMAS STAR project */
#include <stm32f10x.h>
#include <stdint.h>

// X(n+1) = (2053 * X(n)) + 13849)
#define FASTLED_RAND16_2053  ((uint16_t)(2053))
#define FASTLED_RAND16_13849 ((uint16_t)(13849))
#define RAND16_SEED 1337

uint8_t random8 (void);	//Generate an 8-bit random number.
uint8_t random8L (uint8_t lim);	//Generate an 8-bit random number between 0 and lim.
uint8_t random8ML (uint8_t min, uint8_t lim);	//Generate an 8-bit random number in the given range.
uint16_t random16(void);
uint8_t qadd8(uint8_t i, uint8_t j);	//add one byte to another, saturating at 0xFF
uint8_t qsub8(uint8_t i, uint8_t j);	//subtract one byte from another, saturating at 0x00

