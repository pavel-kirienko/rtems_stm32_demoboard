/*
 * Copyright (c) 2012 Sebastian Huber <rtems@embedded-brains.de>
 *               2015 Pavel Kirienko <pavel.kirienko@zubax.com>
 *
 * The license and distribution terms for this file may be
 * found in the file LICENSE in this distribution or at
 * http://www.rtems.org/license/LICENSE.
 */

#include <bsp/io.h>
#include <bsp.h>

const stm32f4_gpio_config stm32f4_start_config_gpio[] = {
    STM32F4_PIN_USART2_TX_MAP_1,
    STM32F4_PIN_USART2_RX_MAP_1,
//    STM32F4_PIN_USART3_TX_MAP_3,
//    STM32F4_PIN_USART3_RX_MAP_3,
    STM32F4_GPIO_CONFIG_TERMINAL
};
