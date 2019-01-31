#ifndef __DUTILS_H
#define __DUTILS_H

#include "stm32f4xx.h"


/*Function prototypes*/

void Delay(uint32_t nCount); // delay in cycles
static float Power(float x, float n);
void Float2String(char *buf, float f, uint32_t dig_before, uint32_t dig_after);
void MemCopy(uint8_t* dst, uint8_t* src, uint32_t len);
int16_t MergeBytes(uint8_t high, uint8_t low);

#endif