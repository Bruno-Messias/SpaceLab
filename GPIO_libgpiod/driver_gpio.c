#include <gpiod.h>
#include <stdio.h>
#include <unistd.h>

#include "driver_gpio.h"


int init_gpio(struct gpiod_chip *chip, struct gpiod_line *line)
{

	if (!chip) 
    {
		perror("Open chip failed\n");
		return -1;
	}

	if (!line) 
    {
		perror("Get line failed\n");
		return -1;
	}

}

int close_gpio(struct gpiod_chip *chip, struct gpiod_line *line)
{
    gpiod_line_release(line);
    gpiod_chip_close(chip);
}

int gpio_set(struct gpiod_line *line, struct gpiod_chip *chip, unsigned int val)
{
   
   int ret = gpiod_line_set_value(line, val);

	if (ret < 0) 
	{
		perror("Set line output failed\n");
        return -1;
	}
    return 0;
}

int gpio_get(struct gpiod_line *line)
{
	int val = gpiod_line_get_value(line);
	return val;
}
