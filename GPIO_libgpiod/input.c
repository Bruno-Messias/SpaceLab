#include <gpiod.h>
#include <stdio.h>
#include <unistd.h>

#include "driver_gpio.h"

#define	CONSUMER "Consumer"

int main()
{
    char *chipname = "gpiochip0";   //! Selected rpi chip [rpi0]
    unsigned int line_num = 24;     //! Select GPIO Pin [#24]
    int val, i;
    struct gpiod_chip *chip;
    struct gpiod_line *line;


    chip = gpiod_chip_open_by_name(chipname);
    line = gpiod_chip_get_line(chip, line_num);

    if (init_gpio(chip, line) < 0) //Initialize and check GPIO pin
    {
        goto release_gpio;
    }

    int ret = gpiod_line_request_input(line, CONSUMER); //Check GPIO pin can receive input
	if (ret < 0) 
    {
		perror("Request line as input failed\n");
		goto release_gpio;
	}

    //* Read input 20 times 
    for (i = 20; i > 0; i--)
    {
        val = gpio_get(line); //Get value from GPIO pin
        if (val < 0)
        {
            perror("Read line input failed\n");
            goto release_gpio;
        }
        printf("Intput %d on line #%u\n", val, line_num);
        sleep(1);
    }





release_gpio:

    close_gpio(chip, line); //Close comunication with GPIO
    return 0;
}