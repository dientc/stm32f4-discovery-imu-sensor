#ifndef __DMPU6050_H
#define __DMPU6050_H


#include "dusb_vcp.h"
#include "dutils.h"

/*
  The 7-bit address of the I2C slave.
  For the MPU6050, this is 0x68 if the AD0 pin is held low, and 0x69 if the
  AD0 pin is held high.
*/
#define MPU6050_I2C_ADDR 0x68

#define NUM_OF_DATA_REGISTERS 14

/*Define MPU registers, take a look at datasheet for more details.*/

#define MPU6050_REG_SMPRT_DIV 25
#define MPU6050_REG_CONFIG 26
#define MPU6050_REG_GYRO_CONFIG 27
#define MPU6050_REG_ACCEL_CONFIG 28
#define MPU6050_REG_FIFO_EN 35
#define MPU6050_REG_INT_PIN_CFG 55
#define MPU6050_REG_INT_ENABLE 56
#define MPU6050_REG_INT_STATUS 58

#define MPU6050_REG_ACCEL_XOUT_H 59
#define MPU6050_REG_ACCEL_XOUT_L 60
#define MPU6050_REG_ACCEL_YOUT_H 61
#define MPU6050_REG_ACCEL_YOUT_L 62
#define MPU6050_REG_ACCEL_ZOUT_H 63
#define MPU6050_REG_ACCEL_ZOUT_L 64
#define MPU6050_REG_TEMP_OUT_H 65
#define MPU6050_REG_TEMP_OUT_L 66
#define MPU6050_REG_GYRO_XOUT_H 67
#define MPU6050_REG_GYRO_XOUT_L 68
#define MPU6050_REG_GYRO_YOUT_H 69
#define MPU6050_REG_GYRO_YOUT_L 70
#define MPU6050_REG_GYRO_ZOUT_H 71
#define MPU6050_REG_GYRO_ZOUT_L 72

#define MPU6050_REG_USER_CTRL 106
#define MPU6050_REG_PWR_MGMT_1 107
#define MPU6050_REG_PWR_MGMT_2 108
#define MPU6050_REG_FIFO_COUNT_H 114
#define MPU6050_REG_FIFO_COUNT_L 115
#define MPU6050_REG_FIFO_R_W 116
#define MPU6050_REG_WHOAMI 117


/*Function prototypes*/
void InitMPU6050(void);
void async_read_mpu6050_reg_multi(uint8_t reg, uint8_t *buf, uint32_t len);
uint8_t read_mpu6050_reg(uint8_t reg);

// static functions
static void write_mpu6050_reg(uint8_t reg, uint8_t val);
static void setup_i2c_for_mpu6050();
static void setup_mpu6050(void);
static void read_mpu6050_reg_multi(uint8_t reg, uint8_t *buf, uint32_t len);
static void async_read_event_handler(void);
static void dma_done_handler(void);
static void trigger_async_read_mpu6050_reg_multi(uint8_t reg, uint8_t *buf, uint32_t len);

#endif