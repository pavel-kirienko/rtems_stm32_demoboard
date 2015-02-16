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
#define CONFIGURE_MINIMUM_TASK_STACK_SIZE               2048

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

#if CONFIGURE_MINIMUM_POSIX_THREAD_STACK_SIZE != (2 * CONFIGURE_MINIMUM_TASK_STACK_SIZE)
# error Unexpected configuration
#endif

#if CONFIGURE_POSIX_INIT_THREAD_STACK_SIZE != CONFIGURE_MINIMUM_POSIX_THREAD_STACK_SIZE
# error Unexpected configuration
#endif

/*
 * RTEMS Shell
 */
#define CONFIGURE_SHELL_COMMANDS_INIT
#define CONFIGURE_SHELL_COMMAND_STACKUSE
#define CONFIGURE_SHELL_COMMAND_CPUUSE
#define CONFIGURE_SHELL_COMMAND_WKSPACE_INFO
#define CONFIGURE_SHELL_COMMAND_CD
#define CONFIGURE_SHELL_COMMAND_LS

#include <rtems/shellconfig.h>

