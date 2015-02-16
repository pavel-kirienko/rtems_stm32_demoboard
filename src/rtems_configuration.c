/*
 * Copyright (C) 2015 Pavel Kirienko <pavel.kirienko@gmail.com>
 */


#include <bsp.h>

/*
 * RTEMS build configuration check
 */
#ifndef RTEMS_POSIX_API
# error This application requires POSIX API
#endif

#ifndef ARM_MULTILIB_HAS_WFI
# error WFI in the idle task should be enabled
#endif

/*
 * RTEMS application configuration
 */
// Drivers
#define CONFIGURE_APPLICATION_NEEDS_CONSOLE_DRIVER
#define CONFIGURE_APPLICATION_NEEDS_CLOCK_DRIVER

// Limits
#define CONFIGURE_UNIFIED_WORK_AREAS
#define CONFIGURE_UNLIMITED_OBJECTS
#define CONFIGURE_UNLIMITED_ALLOCATION_SIZE             1
#define CONFIGURE_MINIMUM_POSIX_THREAD_STACK_SIZE       4096

// Misc
#define CONFIGURE_STACK_CHECKER_ENABLED
#define CONFIGURE_SCHEDULER_SIMPLE
#define CONFIGURE_DISABLE_CLASSIC_API_NOTEPADS
#define CONFIGURE_ZERO_WORKSPACE_AUTOMATICALLY          TRUE
#define CONFIGURE_MICROSECONDS_PER_TICK                 1000

// Init threads
extern void* POSIX_Init(void* arg);
#define CONFIGURE_POSIX_INIT_THREAD_TABLE

#define CONFIGURE_INIT
#include <rtems/confdefs.h>
