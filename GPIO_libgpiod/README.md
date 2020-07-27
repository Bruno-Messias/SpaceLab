# GPIO - libgpiod on *Raspberry Pi 0*

### Content
* driver_gpio.c
* blink.c
* input.c
* demo_code
---

> driver_gpio.c

Interface to use a more simple functions to control GPIO

> blink.c

Code to blink a LED on BCM pin #23

> input.c

Read a digital value on BCM pin #24 *use a button*

> demo_code.c

**Demo_Code under construction**

---
### Install lib and compile

#### Install Libgpiod

In terminal run:

```sh
$ sudo apt-get install gpiod
$ sudo apt-get install libgpiod-dev
```

#### Compiling

using gcc compilier use the argument `-lgpiod` to proper link the library and compile with `driver_gpio.c`

Example:
```sh
$ gcc -o blink blink.c driver_gpio.c -lgpiod
```

### Documentation about libgpiod

Can acess the documentation from [here](https://git.kernel.org/pub/scm/libs/libgpiod/libgpiod.git/about/) and [GiHub](https://github.com/brgl/libgpiod) 
**[may not be up-to-date!]**
