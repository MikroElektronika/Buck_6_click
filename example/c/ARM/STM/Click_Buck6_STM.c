/*
Example for Buck6 Click

    Date          : Jan 2018.
    Author        : MikroE Team

Test configuration STM32 :
    
    MCU              : STM32F107VCT6
    Dev. Board       : EasyMx PRO v7 for STM32
    ARM Compiler ver : v6.0.0.0

---

Description :

The application is composed of three sections :

- System Initialization -  Initialization I2C module and AN pin as OUTPUT and RST pin as INPUT
- Application Initialization - Initialization Driver init and settings chip on ACTIVE mode and setting the maximum range to 5V.
- Application Task - (code snippet) - Sets the different ranges of the maximum voltage.

 If a higher voltage than the maximum range is applied to the VIN input, the maximum output will be obtained at the VOUT output.
 If a smaller voltase is output than the maximum range to the VIN input, at the VOUT output we will have a (+ -) 1V lower value than a VIN input.
 This click was tested with 15V at the VIN input so that it could display different ranges of the maximum bandwidth.

*/

#include "Click_Buck6_types.h"
#include "Click_Buck6_config.h"

void systemInit()
{
    mikrobus_gpioInit( _MIKROBUS1, _MIKROBUS_AN_PIN, _GPIO_OUTPUT );
    mikrobus_gpioInit( _MIKROBUS1, _MIKROBUS_RST_PIN, _GPIO_INPUT );
    mikrobus_i2cInit( _MIKROBUS1, &_BUCK6_I2C_CFG[0] );
    mikrobus_logInit( _LOG_USBUART_A, 9600 );
    Delay_ms( 100 );
}

void applicationInit()
{
    buck6_i2cDriverInit( (T_BUCK6_P)&_MIKROBUS1_GPIO, (T_BUCK6_P)&_MIKROBUS1_I2C, 0x48 );
    Delay_100ms();
    buck6_setMode(_BUCK6_ACTIVE_MODE);
    buck6_setMaxVoltage(_BUCK6_MAX_RANGE_5000mV);
    Delay_100ms();
}

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

void main()
{
    systemInit();
    applicationInit();

    while (1)
    {
            applicationTask();
    }
}
