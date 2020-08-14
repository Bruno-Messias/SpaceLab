#include "I2C_SMbus.h"

const int addr = 0x8; //! change for the addr show in  'sudo i2cdetect -y 1' in terminal
const int busnum = 1; //* For I2C port 1 ons rp1

__u8 reg = 0x10; //* Device register to access 
int value;

void main()
{

    rpiI2cSetup(addr,busnum); //Set up the I2C Device

    int numb = 1; //control for i2c bus
    int value; 

    printf("Enter 1 for ON or 0 for OFF\n");
    while (numb==1)
    {
        scanf("%i", &value);

        if (value == 1)
        {
            rpiI2cWrite(reg, 1);
        }
		else if (value == 0)
        {
            rpiI2cWrite(reg, 1);
        }
		else 
            numb = 0;
    }
};