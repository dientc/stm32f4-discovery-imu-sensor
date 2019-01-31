#include "dutils.h"

void Delay(uint32_t nCount)
{
	while(nCount--)
    __asm("nop"); // do nothing
}

static float Power(float x, float n)
{
  float p = 1;
  for(uint8_t i = 0; i < (uint8_t)n; ++i)
  {
    p = p * x;        
  }

  return p;
}

void Float2String(char *buf, float f, uint32_t dig_before, uint32_t dig_after)
{
  float a;
  uint32_t d;
  uint8_t leading_zero;

  if (f == 0.0f)
  {
    buf[0] = '0';
    buf[1] = '\0';
    return;
  }
  if (f < 0)
  {
    *buf++ = '-';
    f = -f;
  }
  a =  Power(10.0f, (float)dig_before);
  if (f >= a)
  {
    buf[0] = '#';
    buf[1] = '\0';
    return;
  }
  leading_zero = 1;
  while (dig_before)
  {
    a /= 10.0f;
    d = (uint32_t)(f / a);
    if (leading_zero && d == 0 && a >= 10.0f)
      *buf++ = ' ';
    else
    {
      leading_zero = 0;
      *buf++ = '0' + d;
      f -= d*a;
    }
    --dig_before;
  }
  if (!dig_after)
  {
    *buf++ = '\0';
    return;
  }
  *buf++ = '.';
  do
  {
    f *= 10.0f;
    d = (uint32_t)f;
    *buf++ = '0' + d;
    f -= (float)d;
    --dig_after;
  } while (dig_after);
  *buf++ = '\0';
}

void MemCopy(uint8_t* dst, uint8_t* src, uint32_t len)
{
  for (uint32_t i = 0; i < len; ++i)
  {
    dst[i] = src[i];
  }
}

int16_t MergeBytes(uint8_t high, uint8_t low)
{
  uint16_t v = ((uint16_t)high << 8) | low;
  return (int16_t)v;
}
