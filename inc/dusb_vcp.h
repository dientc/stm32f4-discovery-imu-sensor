#ifndef __DUSB_VCP_H
#define __DUSB_VCP_H


#include "stm32f4xx.h"

// Headers for USB VCP
#include "usbd_cdc_core.h"
#include "usbd_usr.h"
#include "usb_conf.h"
#include "usbd_desc.h"
#include "usbd_cdc_vcp.h"


__ALIGN_BEGIN USB_OTG_CORE_HANDLE    USB_OTG_dev __ALIGN_END ;


// Function prototypes;
void InitUSB_VCP(void);
void PrintRawBuffer(uint8_t* buf, uint8_t len);
void PrintChar(uint32_t c);
void PrintString(const char *s);
void PrintHexDigit(uint32_t digit);
void PrintHexByte(uint8_t byte);
void PrintHexWord(uint16_t word);
void PrintUInt32(uint32_t val);
void PrintInt32(int32_t val);
void PrintFloat(float f, uint32_t dig_before, uint32_t dig_after);

#endif