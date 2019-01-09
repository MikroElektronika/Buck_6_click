![MikroE](http://www.mikroe.com/img/designs/beta/logo_small.png)

---

# Buck6 Click

- **CIC Prefix**  : BUCK6
- **Author**      : Katarina Perendic

---

### Software Support

We provide a library for the Buck6 Click on our [LibStock](https://libstock.mikroe.com/projects/view/2304/buck-6-click) 
page, as well as a demo application (example), developed using MikroElektronika 
[compilers](http://shop.mikroe.com/compilers). The demo can run on all the main 
MikroElektronika [development boards](http://shop.mikroe.com/development-boards).

**Library Description**

Library carries all necessary functions to have complete control over BUCK 6 click board.
Control over PWM is not included in library.

Key functions :

- ``` void buck6_setMode(uint8_t mode) ``` - Set working mode
- ``` void buck6_setMaxVoltage(uint8_t voltage) ``` - Set maximum voltage on outputs

**Examples Description**

The application is composed of three sections :

- System Initialization -  Initialization I2C module and AN pin as OUTPUT and RST pin as INPUT
- Application Initialization - Initialization Driver init and settings chip on ACTIVE mode and setting the maximum range to 5V.
- Application Task - (code snippet) - Sets the different ranges of the maximum voltage.

```.c
void applicationTask()
{
    buck6_setMaxVoltage(_BUCK6_MAX_RANGE_2500mV);
    Delay_ms( 3000 );
    buck6_setMaxVoltage(_BUCK6_MAX_RANGE_5000mV);
    Delay_ms( 3000 );
    buck6_setMaxVoltage(_BUCK6_MAX_RANGE_7500mV);
    Delay_ms( 3000 );
    buck6_setMaxVoltage(_BUCK6_MAX_RANGE_10000mV);
    Delay_ms( 3000 );
    buck6_setMaxVoltage(_BUCK6_MAX_RANGE_7500mV);
    Delay_ms( 3000 );
    buck6_setMaxVoltage(_BUCK6_MAX_RANGE_5000mV);
    Delay_ms( 3000 );
}
```

If a higher voltage than the maximum range is applied to the VIN input, the maximum output will be obtained at the VOUT output.
If a smaller voltase is output than the maximum range to the VIN input, at the VOUT output we will have a (+ -) 1V lower value than a VIN input.
This click was tested with 15V at the VIN input so that it could display different ranges of the maximum bandwidth.


The full application code, and ready to use projects can be found on our 
[LibStock](https://libstock.mikroe.com/projects/view/2304/buck-6-click) page.

mikroE Libraries used in the example:

- I2C

---
---
