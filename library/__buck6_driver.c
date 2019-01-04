/*
    __buck6_driver.c

-----------------------------------------------------------------------------

  This file is part of mikroSDK.

  Copyright (c) 2017, MikroElektonika - http://www.mikroe.com

  All rights reserved.

----------------------------------------------------------------------------- */

#include "__buck6_driver.h"
#include "__buck6_hal.c"

/* ------------------------------------------------------------------- MACROS */
const uint8_t _BUCK6_MAX_RANGE_1000mV  = 0xFA;
const uint8_t _BUCK6_MAX_RANGE_1500mV  = 0xF4;
const uint8_t _BUCK6_MAX_RANGE_2000mV  = 0xF1;
const uint8_t _BUCK6_MAX_RANGE_2500mV  = 0xEE;
const uint8_t _BUCK6_MAX_RANGE_3000mV  = 0xEA;
const uint8_t _BUCK6_MAX_RANGE_3500mV  = 0xE7;
const uint8_t _BUCK6_MAX_RANGE_4000mV  = 0xE4;
const uint8_t _BUCK6_MAX_RANGE_4500mV  = 0xE1;
const uint8_t _BUCK6_MAX_RANGE_5000mV  = 0xDE;
const uint8_t _BUCK6_MAX_RANGE_5500mV  = 0xDB;

const uint8_t _BUCK6_MAX_RANGE_6000mV  = 0xD8;
const uint8_t _BUCK6_MAX_RANGE_6500mV  = 0xD4;
const uint8_t _BUCK6_MAX_RANGE_7000mV  = 0xD1;
const uint8_t _BUCK6_MAX_RANGE_7500mV  = 0xCF;
const uint8_t _BUCK6_MAX_RANGE_8000mV  = 0xCB;
const uint8_t _BUCK6_MAX_RANGE_8500mV  = 0xC8;
const uint8_t _BUCK6_MAX_RANGE_9000mV  = 0xC5;
const uint8_t _BUCK6_MAX_RANGE_9500mV  = 0xC2;
const uint8_t _BUCK6_MAX_RANGE_10000mV = 0xBF;
const uint8_t _BUCK6_MAX_RANGE_10500mV = 0xBC;
const uint8_t _BUCK6_MAX_RANGE_11000mV = 0xB9;
const uint8_t _BUCK6_MAX_RANGE_11500mV = 0xB6;
const uint8_t _BUCK6_MAX_RANGE_12000mV = 0xB2;
const uint8_t _BUCK6_MAX_RANGE_12500mV = 0xAF;

const uint8_t _BUCK6_MAX_RANGE_13000mV = 0xAB;
const uint8_t _BUCK6_MAX_RANGE_13500mV = 0xA9;
const uint8_t _BUCK6_MAX_RANGE_14000mV = 0xA6;
const uint8_t _BUCK6_MAX_RANGE_14500mV = 0xA3;
const uint8_t _BUCK6_MAX_RANGE_15000mV = 0xA0;
const uint8_t _BUCK6_MAX_RANGE_15500mV = 0x9C;
const uint8_t _BUCK6_MAX_RANGE_16000mV = 0x99;
const uint8_t _BUCK6_MAX_RANGE_16500mV = 0x96;
const uint8_t _BUCK6_MAX_RANGE_17000mV = 0x93;
const uint8_t _BUCK6_MAX_RANGE_17500mV = 0x90;
const uint8_t _BUCK6_MAX_RANGE_18000mV = 0x8D;
const uint8_t _BUCK6_MAX_RANGE_18500mV = 0x8A;
const uint8_t _BUCK6_MAX_RANGE_19000mV = 0x87;
const uint8_t _BUCK6_MAX_RANGE_19500mV = 0x84;
const uint8_t _BUCK6_MAX_RANGE_20000mV = 0x80;

const uint8_t _BUCK6_SLEEP_MODE = 0x00;
const uint8_t _BUCK6_ACTIVE_MODE = 0x01;



/* ---------------------------------------------------------------- VARIABLES */

#ifdef   __BUCK6_DRV_I2C__
static uint8_t _slaveAddress;
#endif

/* -------------------------------------------- PRIVATE FUNCTION DECLARATIONS */



/* --------------------------------------------- PRIVATE FUNCTION DEFINITIONS */



/* --------------------------------------------------------- PUBLIC FUNCTIONS */

#ifdef   __BUCK6_DRV_SPI__

void buck6_spiDriverInit(T_BUCK6_P gpioObj, T_BUCK6_P spiObj)
{
    hal_spiMap( (T_HAL_P)spiObj );
    hal_gpioMap( (T_HAL_P)gpioObj );

    // ... power ON
    // ... configure CHIP
}

#endif
#ifdef   __BUCK6_DRV_I2C__

void buck6_i2cDriverInit(T_BUCK6_P gpioObj, T_BUCK6_P i2cObj, uint8_t slave)
{
    _slaveAddress = slave;
    hal_i2cMap( (T_HAL_P)i2cObj );
    hal_gpioMap( (T_HAL_P)gpioObj );

    // ... power ON
    // ... configure CHIP
}

#endif
#ifdef   __BUCK6_DRV_UART__

void buck6_uartDriverInit(T_BUCK6_P gpioObj, T_BUCK6_P uartObj)
{
    hal_uartMap( (T_HAL_P)uartObj );
    hal_gpioMap( (T_HAL_P)gpioObj );

    // ... power ON
    // ... configure CHIP
}

#endif

// GPIO Only Drivers - remove in other cases
void buck6_gpioDriverInit(T_BUCK6_P gpioObj)
{
    hal_gpioMap( (T_HAL_P)gpioObj );

    // ... power ON
}

/* ----------------------------------------------------------- IMPLEMENTATION */

uint8_t buck6_getRST()
{
   return hal_gpio_rstGet();
}

void buck6_setMode(uint8_t mode)
{
   hal_gpio_anSet(mode);
}

void buck6_setMaxVoltage(uint8_t voltage)
{
   uint8_t wReg[2];
   wReg[0] = 0xF9;
   
   if( voltage < 0x80 )
   {
       wReg[1] = 0x80;
   }
   else
   {
       wReg[1] = voltage;
   }
   
   hal_i2cStart();
   hal_i2cWrite(_slaveAddress,wReg,2,END_MODE_STOP);
   Delay_100ms();
}





/* -------------------------------------------------------------------------- */
/*
  __buck6_driver.c

  Copyright (c) 2017, MikroElektonika - http://www.mikroe.com

  All rights reserved.

Redistribution and use in source and binary forms, with or without
modification, are permitted provided that the following conditions are met:

1. Redistributions of source code must retain the above copyright
   notice, this list of conditions and the following disclaimer.

2. Redistributions in binary form must reproduce the above copyright
   notice, this list of conditions and the following disclaimer in the
   documentation and/or other materials provided with the distribution.

3. All advertising materials mentioning features or use of this software
   must display the following acknowledgement:
   This product includes software developed by the MikroElektonika.

4. Neither the name of the MikroElektonika nor the
   names of its contributors may be used to endorse or promote products
   derived from this software without specific prior written permission.

THIS SOFTWARE IS PROVIDED BY MIKROELEKTRONIKA ''AS IS'' AND ANY
EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
DISCLAIMED. IN NO EVENT SHALL MIKROELEKTRONIKA BE LIABLE FOR ANY
DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
(INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
(INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

----------------------------------------------------------------------------- */