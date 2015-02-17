/*
 * Copyright (c) 2015 Zubax, zubax.com
 * Distributed under the MIT License, available in the file LICENSE.
 * Author: Pavel Kirienko <pavel.kirienko@zubax.com>
 */

#include <cstdlib>
#include <rtems.h>

#pragma GCC diagnostic ignored "-Wmissing-declarations"

namespace __gnu_cxx
{

void __verbose_terminate_handler()
{
    ::printk("UNHANDLED EXCEPTION");
    std::abort();
}

}

extern "C"
{

int __aeabi_atexit(void*, void(*)(void*), void*)
{
    return 0;
}

void __cxa_atexit(void(*)(void *), void*, void*)
{
}

void __cxa_pure_virtual()
{
    ::printk("PURE VIRTUAL");
    std::abort();
}

}
