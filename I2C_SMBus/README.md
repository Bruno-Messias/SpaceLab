# Lib I2C SmBus/linux kernel

- Content
    - I2C_SMbus.c
    - I2C_test.c
    - Arduino_I2C
        -arduino_i2c.ino
        -rpi_i2c.py

---

> I2C_SMbus.c

Interface to use a more simple functions to control I2C

> I2C_test.c

Demo code to use a a I2C to control a arduino to use a LED

> Arduino_I2C

Arduino code to use a I2C with Raspberry Pi

---

### Install lib and compile

### Install I2C-tool

Run:

```
sudo apt-get install install i2c-tools libi2c-dev
```

To get the I2C addr run in terminal:

```
i2cdetect - y 1
```

### Compiling

Example using gcc compiler:

```
$ gcc -o test I2C_test.c I2C_SMbus.c -li2c
$ ./test
```

### Documentation about SMbus/kernel linux

Can acess the documentation from [here](https://www.kernel.org/doc/html/latest/i2c/dev-interface.html).
----
### Limitacion

Only can read or write by bytes  
