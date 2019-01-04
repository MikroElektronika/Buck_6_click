/*
    __buck6_driver.h

-----------------------------------------------------------------------------

  This file is part of mikroSDK.
  
  Copyright (c) 2017, MikroElektonika - http://www.mikroe.com

  All rights reserved.

----------------------------------------------------------------------------- */

/**
@file   __buck6_driver.h
@brief    Buck6 Driver
@mainpage Buck6 Click
@{

@image html sch.jpg

@}

@defgroup   BUCK6
@brief      Buck6 Click Driver
@{

| Global Library Prefix | **BUCK6** |
|:---------------------:|:-----------------:|
| Version               | **1.0.0**    |
| Date                  | **Jan 2018.**      |
| Developer             | **MikroE Team**     |

*/
/* -------------------------------------------------------------------------- */

#include "stdint.h"

#ifndef _BUCK6_H_
#define _BUCK6_H_

/** 
 * @macro T_BUCK6_P
 * @brief Driver Abstract type 
 */
#define T_BUCK6_P    const uint8_t*

/** @defgroup BUCK6_COMPILE Compilation Config */              /** @{ */

//  #define   __BUCK6_DRV_SPI__                            /**<     @macro __BUCK6_DRV_SPI__  @brief SPI driver selector */
   #define   __BUCK6_DRV_I2C__                            /**<     @macro __BUCK6_DRV_I2C__  @brief I2C driver selector */                                          
// #define   __BUCK6_DRV_UART__                           /**<     @macro __BUCK6_DRV_UART__ @brief UART driver selector */ 

                                                                       /** @} */
/** @defgroup BUCK6_VAR Variables */                           /** @{ */

extern const uint8_t _BUCK6_MAX_RANGE_1000mV;
extern const uint8_t _BUCK6_MAX_RANGE_1500mV;
extern const uint8_t _BUCK6_MAX_RANGE_2000mV;
extern const uint8_t _BUCK6_MAX_RANGE_2500mV;
extern const uint8_t _BUCK6_MAX_RANGE_3000mV;
extern const uint8_t _BUCK6_MAX_RANGE_3500mV;
extern const uint8_t _BUCK6_MAX_RANGE_4000mV;
extern const uint8_t _BUCK6_MAX_RANGE_4500mV;
extern const uint8_t _BUCK6_MAX_RANGE_5000mV;
extern const uint8_t _BUCK6_MAX_RANGE_5500mV;

extern const uint8_t _BUCK6_MAX_RANGE_6000mV;
extern const uint8_t _BUCK6_MAX_RANGE_6500mV;
extern const uint8_t _BUCK6_MAX_RANGE_7000mV;
extern const uint8_t _BUCK6_MAX_RANGE_7500mV;
extern const uint8_t _BUCK6_MAX_RANGE_8000mV;
extern const uint8_t _BUCK6_MAX_RANGE_8500mV;
extern const uint8_t _BUCK6_MAX_RANGE_9000mV;
extern const uint8_t _BUCK6_MAX_RANGE_9500mV;
extern const uint8_t _BUCK6_MAX_RANGE_10000mV;
extern const uint8_t _BUCK6_MAX_RANGE_10500mV;

extern const uint8_t _BUCK6_MAX_RANGE_11000mV;
extern const uint8_t _BUCK6_MAX_RANGE_11500mV;
extern const uint8_t _BUCK6_MAX_RANGE_12000mV;
extern const uint8_t _BUCK6_MAX_RANGE_12500mV;
extern const uint8_t _BUCK6_MAX_RANGE_13000mV;
extern const uint8_t _BUCK6_MAX_RANGE_13500mV;
extern const uint8_t _BUCK6_MAX_RANGE_14000mV;
extern const uint8_t _BUCK6_MAX_RANGE_14500mV;
extern const uint8_t _BUCK6_MAX_RANGE_15000mV;
extern const uint8_t _BUCK6_MAX_RANGE_15500mV;

extern const uint8_t _BUCK6_MAX_RANGE_16000mV;
extern const uint8_t _BUCK6_MAX_RANGE_16500mV;
extern const uint8_t _BUCK6_MAX_RANGE_17000mV;
extern const uint8_t _BUCK6_MAX_RANGE_17500mV;
extern const uint8_t _BUCK6_MAX_RANGE_18000mV;
extern const uint8_t _BUCK6_MAX_RANGE_18500mV;
extern const uint8_t _BUCK6_MAX_RANGE_19000mV;
extern const uint8_t _BUCK6_MAX_RANGE_19500mV;
extern const uint8_t _BUCK6_MAX_RANGE_20000mV;

extern const uint8_t _BUCK6_SLEEP_MODE;
extern const uint8_t _BUCK6_ACTIVE_MODE;

                                                                       /** @} */
/** @defgroup BUCK6_TYPES Types */                             /** @{ */



                                                                       /** @} */
#ifdef __cplusplus
extern "C"{
#endif

/** @defgroup BUCK6_INIT Driver Initialization */              /** @{ */

#ifdef   __BUCK6_DRV_SPI__
void buck6_spiDriverInit(T_BUCK6_P gpioObj, T_BUCK6_P spiObj);
#endif
#ifdef   __BUCK6_DRV_I2C__
void buck6_i2cDriverInit(T_BUCK6_P gpioObj, T_BUCK6_P i2cObj, uint8_t slave);
#endif
#ifdef   __BUCK6_DRV_UART__
void buck6_uartDriverInit(T_BUCK6_P gpioObj, T_BUCK6_P uartObj);
#endif

// GPIO Only Drivers - remove in other cases
void buck6_gpioDriverInit(T_BUCK6_P gpioObj);
                                                                       /** @} */
/** @defgroup BUCK6_FUNC Driver Functions */                   /** @{ */

/**
 * @brief Function reads state of pin
 *
 * @return  state of pin
        1 - if the input voltage is greater than the set maximum range.
        0 - if the input voltage is lower than the set maximum range.
 */
 
uint8_t buck6_getRST();
/**
 * @brief Function for settings chip mode
 *
 * @param[in] mode     mode of work chip
 *
 *  Mode options:
       ACTIVE mode,
       SLEEP mode.
 *
 */
void buck6_setMode(uint8_t mode);

/**
 * @brief Function for settings maximum range.
 *
 * @param[in] voltage     maximum voltages
 */
void buck6_setMaxVoltage(uint8_t voltage);




                                                                       /** @} */
#ifdef __cplusplus
} // extern "C"
#endif
#endif

/**
    @example Click_Buck6_STM.c
    @example Click_Buck6_TIVA.c
    @example Click_Buck6_CEC.c
    @example Click_Buck6_KINETIS.c
    @example Click_Buck6_MSP.c
    @example Click_Buck6_PIC.c
    @example Click_Buck6_PIC32.c
    @example Click_Buck6_DSPIC.c
    @example Click_Buck6_AVR.c
    @example Click_Buck6_FT90x.c
    @example Click_Buck6_STM.mbas
    @example Click_Buck6_TIVA.mbas
    @example Click_Buck6_CEC.mbas
    @example Click_Buck6_KINETIS.mbas
    @example Click_Buck6_MSP.mbas
    @example Click_Buck6_PIC.mbas
    @example Click_Buck6_PIC32.mbas
    @example Click_Buck6_DSPIC.mbas
    @example Click_Buck6_AVR.mbas
    @example Click_Buck6_FT90x.mbas
    @example Click_Buck6_STM.mpas
    @example Click_Buck6_TIVA.mpas
    @example Click_Buck6_CEC.mpas
    @example Click_Buck6_KINETIS.mpas
    @example Click_Buck6_MSP.mpas
    @example Click_Buck6_PIC.mpas
    @example Click_Buck6_PIC32.mpas
    @example Click_Buck6_DSPIC.mpas
    @example Click_Buck6_AVR.mpas
    @example Click_Buck6_FT90x.mpas
*/                                                                     /** @} */
/* -------------------------------------------------------------------------- */
/*
  __buck6_driver.h

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