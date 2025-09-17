/* ta biblioteka jest w kopia biblioteki fastled v3.1*/
#ifndef __BASIC_MATH_H
#define __BASIC_MATH_H

#include "basic_math.h"


uint16_t rand16seed = RAND16_SEED;

uint8_t random8(void)	//Generate an 8-bit random number.
{
	rand16seed = (rand16seed * FASTLED_RAND16_2053) + FASTLED_RAND16_13849;
	// return the sum of the high and low bytes, for better
	//  mixing and non-sequential correlation
	return (uint8_t)(((uint8_t)(rand16seed & 0xFF)) + ((uint8_t)(rand16seed >> 8)));
}

uint8_t random8L (uint8_t lim)	//Generate an 8-bit random number between 0 and lim.
{
	uint8_t r = random8();
	r = (r*lim) >> 8;
	return r;
}

uint8_t random8ML (uint8_t min, uint8_t lim)	//Generate an 8-bit random number in the given range.
{
	uint8_t delta = lim - min;
	uint8_t r = random8L(delta) + min;
	return r;
}

uint16_t random16(void)
{
     rand16seed = (rand16seed * FASTLED_RAND16_2053) + FASTLED_RAND16_13849;
     return rand16seed;
}

void random16_add_entropy( uint16_t entropy)
{
     rand16seed += entropy;
}

uint8_t qadd8(uint8_t i, uint8_t j)	//add one byte to another, saturating at 0xFF
{
  unsigned int t = i + j;
  if( t > 255) t = 255;
  return t;
}

uint8_t qsub8(uint8_t i, uint8_t j)	//subtract one byte from another, saturating at 0x00
{
    int t = i - j;

    if( t < 0) t = 0;

    return t;

}

#endif
