#!/bin/bash
#
# Copyright (C) 2015 Pavel Kirienko <pavel.kirienko@zubax.com>
# Distributed under the terms of the MIT license.
#
# Also see this:
#     https://devel.rtems.org/wiki/TBR/BSP/STM32_F4
#     https://devel.rtems.org/wiki/TBR/BSP/STM32F105
#

#
# BSP configuration
#
# System clock
export STM32F4_HSE_OSCILLATOR=8000000
export STM32F4_SYSCLK=8000000
export STM32F4_HCLK=$STM32F4_SYSCLK
export STM32F4_PCLK1=8000000            # STM32F10x 36 MHz max
export STM32F4_PCLK2=$STM32F4_SYSCLK
# USART
export STM32F4_USART_BAUD=115200
export STM32F4_ENABLE_USART_1=""
export STM32F4_ENABLE_USART_2="1"
export STM32F4_ENABLE_USART_3="1"
export STM32F4_ENABLE_UART_4=""
export STM32F4_ENABLE_UART_5=""
export STM32F4_ENABLE_USART_6=""
# I2C
export STM32F4_ENABLE_I2C1=""
export STM32F4_ENABLE_I2C2=""
# General BSP options
export BSP_PRINT_EXCEPTION_CONTEXT="1"

#
# Building RTEMS if necessary
#
cd $(dirname $(readlink -f $0))

# See TinyRTEMS: https://devel.rtems.org/wiki/Projects/TinyRTEMS
export RTEMS_CONFIGURE_EXTRA_OPTIONS="\
--disable-itron --disable-networking --disable-multiprocessing \
USE_TICKS_FOR_CPU_USAGE_STATISTICS=1 USE_TICKS_FOR_RATE_MONOTONIC_STATISTICS=1 \
"

if ! [ -f env.sh ]; then
    zubax_rtems/build_rtems.sh --cpu=arm                                             \
                               --bsp=stm32f105rc                                     \
                               --amend-bsp-dir=$(dirname $(readlink -f $0))/stm32f4  \
                               --remove-unused-bsp                                   \
        || exit 1
    cp -f zubax_rtems/env.sh .
fi

#
# Building the application
#
source env.sh || exit 1

make $@
