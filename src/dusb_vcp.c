#include "dusb_vcp.h"
#include "dutils.h"


void InitUSB_VCP(void)
{
  USBD_Init(&USB_OTG_dev,
            USB_OTG_FS_CORE_ID,
            &USR_desc, 
            &USBD_CDC_cb, 
            &USR_cb);
  
  if (SysTick_Config(SystemCoreClock / 1000))
  { 
    //Capture error
    while (1);
  }  
}

void PrintRawBuffer(uint8_t* buf, uint8_t len)
{
  VCP_DataTx(buf, len);
}

void PrintChar(uint32_t c)
{
  uint8_t buf[1];
  buf[0] = (uint8_t)c;

  //@@
  VCP_DataTx(buf, 1);
}

void PrintString(const char *s)
{
  while(*s != '\0')
  {
    PrintChar(*s);
    ++s;
  }
}

void PrintHexDigit(uint32_t digit)
{
  PrintChar((digit >= 10 ? 'A' - 10 + digit : '0' + digit));
}


void PrintHexByte(uint8_t byte)
{
  PrintHexDigit( byte >> 4);
  PrintHexDigit(byte & 0xf);
}

void PrintHexWord(uint16_t word)
{
  PrintHexDigit( word >> 12);
  PrintHexDigit( (word >> 8) & 0xf);
  PrintHexDigit( (word >> 4) & 0xf);
  PrintHexDigit(word & 0xf);
}

void PrintUInt32(uint32_t val)
{
  char buf[13];
  char *p = buf;
  uint32_t l, d;

  l = 1000000000UL;
  while (l > val && l > 1)
    l /= 10;

  do
  {
    d = val / l;
    *p++ = '0' + d;
    val -= d*l;
    l /= 10;
  } while (l > 0);

  *p++ = '\r';
  *p++ = '\n';
  *p = '\0';
  PrintString(buf);
}


void PrintInt32(int32_t val)
{
  if (val < 0)
  {
    PrintChar( '-');
    PrintUInt32( (uint32_t)0 - (uint32_t)val);
  }
  else
    PrintUInt32( val);
}

void PrintFloat(float f, uint32_t dig_before, uint32_t dig_after)
{
  char buf[21];
  char *p = buf;

  Float2String(p, f, dig_before, dig_after);
  while (*p)
    ++p;
  *p++ = '\r';
  *p++ = '\n';
  *p = '\0';
  PrintString( buf);
}
