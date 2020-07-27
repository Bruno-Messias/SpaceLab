#include <gpiod.h>
#include <stdio.h>
#include <unistd.h>

#include "driver_gpio.h"

#define	CONSUMER "Consumer"

int main()
{
	char *chipname = "gpiochip0"; 	//! Selected rpi chip [rpi0]
	unsigned int line_num = 23;		//! Select GPIO Pin [#23]
	unsigned int val;
	int i;
	struct gpiod_chip *chip;
	struct gpiod_line *line;

	chip = gpiod_chip_open_by_name(chipname);
    line = gpiod_chip_get_line(chip, line_num);

	if (init_gpio(chip, line) < 0) //Initialize and check GPIO pin
	{
		goto release_gpio;
	}
	 
	int ret = gpiod_line_request_output(line, CONSUMER, 0); //Check GPIO pin can be output
	if (ret < 0) 
    {
		perror("Request line as output failed\n");
		goto release_gpio;
	}
    return 0;

	//* Blink 20 times 

	val = 0;
	for (i = 20; i > 0; i--) 
	{
		
		int control = gpio_set(line, chip, val); // Set the GPIO and get control flag
		if (control < 0)
		{
			goto release_gpio;
		}
		printf("Output %u on line #%u\n", val, line_num);
		sleep(1);
		
		val = !val;
	}

release_gpio:

	close_gpio(chip, line); //Close comunication with GPIO
	return 0;
}