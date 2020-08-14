


#ifndef I2C_SMBUS_H
#define I2C_SMBUS_H

#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <linux/types.h>
#include <sys/ioctl.h>
#include <linux/i2c-dev.h>
#include <i2c/smbus.h>

int fd;

void rpiI2cSetup(__u8, __u8);
void rpiI2cWrite(__u8, __u8);
__u8 rpiI2cRead8(__u8);
__u16 rpiI2cRead16(__u8);
void rpiI2cClose(void);

#endif
