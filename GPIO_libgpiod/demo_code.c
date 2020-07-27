#include <gpiod.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>

#include "driver_gpio.h"

#define	CONSUMER "Consumer"

int main()
{
    char *chipname = "gpiochip0";   //* Selected rpi chip [rpi0]
    unsigned int pin_output = 23;   //* Select GPIO Pin [#23] as a output
    unsigned int pin_input = 24;    //* Select GPIO Pin [#24] as a input

    int val, i, control, button;
    struct gpiod_chip *chip;
    struct gpiod_line *output;
    struct gpiod_line *input;

    char command[100];

    chip = gpiod_chip_open_by_name(chipname);
    output = gpiod_chip_get_line(chip, pin_output);
    input = gpiod_chip_get_line(chip, pin_input); //! change for +1 offset to use the full line

    if (init_gpio(chip, output) < 0) //Initialize and check GPIO pin output
    {
        goto release_gpio;
    }

    if (init_gpio(chip, input) < 0) //Initialize and check GPIO pin input
    {
        goto release_gpio;
    }


/*
    int ret_out = gpiod_line_request_output(output, CONSUMER, 0); //Check GPIO pin can be output
    if (ret_out < 0) 
    {
		perror("Request line as output failed\n");
		goto release_gpio;
	}

    int ret_in = gpiod_line_request_input(input, CONSUMER); //Check GPIO pin can receive input
	if (ret_in< 0) 
    {
		perror("Request line as input failed\n");
		goto release_gpio;
	}
*/ 
//? Qual os problemas que podem gerar sem essa parte? 
//Need close the line before request input line //? Can make everthing in the same line?
//Não pode dar output e input ao mesmo tempo.
//TODO: Solving this problem

    //* Send on or off to control the LED, press button to end [or exit]

again:

    scanf("%s", command);

    if(strcmp(command, "on") == 0)
    {
        val = 1;
        control = gpio_set(output, chip, val); // Set the GPIO to 1 and get control flag
		if (control < 0)
		{
			goto release_gpio;
		}
		printf("Output %u on line #%u\n", val, output);
        sleep(1);
        goto check;
    }

    if(strcmp(command, "off") == 0)
    {
        val = 0;
        control = gpio_set(output, chip, val); // Set the GPIO to 1 and get control flag
		if (control < 0)
		{
			goto release_gpio;
		}
		printf("Output %u on line #%u\n", val, output);
        sleep(1);
        goto check;
    }
    if(strcmp(command, "exit") == 0)
    {
        goto release_gpio;
    }
    
check:

    button = gpio_get(input); //Get value from GPIO pin
    if (button < 0)
    {
        perror("Read line input failed\n");
        goto release_gpio;
    }

    if(button < 1)
    {
        goto again;
    }

release_gpio:

    close_gpio(chip, output); //Close comunication with GPIO
    close_gpio(chip, input);
    return 0;
}