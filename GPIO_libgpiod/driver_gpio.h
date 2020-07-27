#ifndef DRIVER_GPIO_H_
#define DRIVER_GPIO_H_


int init_gpio(struct gpiod_chip *chip, struct gpiod_line *line);

int close_gpio(struct gpiod_chip *chip, struct gpiod_line *line);

int gpio_set(struct gpiod_line *line, struct gpiod_chip *chip, unsigned int val);

int gpio_get(struct gpiod_line *line);


#endif //* DRIVER_GPIO_H_