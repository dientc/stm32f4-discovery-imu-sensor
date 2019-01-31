#include "main.h"

#include "dutils.h"
#include "dusb_vcp.h"
#include "dmpu6050.h"

int main(void)
{
  uint8_t temp_val0;
  int16_t temp_val;
  uint8_t temp_buf[14];

  InitUSB_VCP();

  uint32_t count = 0;
  while (count < 50)
  {
    Delay(3000*3360);
    PrintString("world hello\r\n");
    PrintInt32(count);
    count++;
  }

  InitMPU6050();

  PrintString( "Hello world, ready to blink!\r\n");

  temp_val0 = read_mpu6050_reg(MPU6050_REG_WHOAMI);
  PrintString( "\r\nMPU6050: whoami=0x");
  PrintHexByte( temp_val0);
  temp_val0 = read_mpu6050_reg(MPU6050_REG_PWR_MGMT_1);
  PrintString( "\r\nMPU6050: pwr_mgmt_1=0x");
  PrintHexByte( temp_val0);
  
  // Start to read data
  PrintString( "\r\nRead sensors ...\r\n");

  while (1)
  {
    async_read_mpu6050_reg_multi(MPU6050_REG_ACCEL_XOUT_H, temp_buf, 14);
    PrintRawBuffer(temp_buf, 14);    
    Delay(40000);    // system clock ~ 16Mhz, delay 10000 cycles
  }

  return 0;
} 

///////////////////////////////////////////////////////

#ifdef USE_FULL_ASSERT
/**
* @brief  assert_failed
*         Reports the name of the source file and the source line number
*         where the assert_param error has occurred.
* @param  File: pointer to the source file name
* @param  Line: assert_param error line source number
* @retval None
*/
void assert_failed(uint8_t* file, uint32_t line)
{
  /* User can add his own implementation to report the file name and line number,
  ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  
  /* Infinite loop */
  while (1)
  {}
}
#endif

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
