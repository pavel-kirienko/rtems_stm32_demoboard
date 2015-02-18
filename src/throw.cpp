/*
 * Copyright (C) 2015 Pavel Kirienko <pavel.kirienko@gmail.com>
 */


#include <bsp.h>

#include <rtems.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <rtems/shell.h>
#include <sys/time.h>
#include <chrono>
#include <string>


static std::string systime2str(const std::chrono::system_clock::time_point& tp)
{
    const auto tt = std::chrono::system_clock::to_time_t(tp);
    return std::ctime(&tt);
}

static std::string nanoseconds2str(long long nanos)
{
    (void)nanoseconds2str;
    using namespace std; // For snprintf()
    char buf[80];
    (void)snprintf(buf, sizeof(buf), "%lli.%09lli",
                   static_cast<long long>(nanos / 1000000000ULL),
                   static_cast<long long>(nanos % 1000000000ULL));
    return buf;
}

extern "C" void* POSIX_Init(void*);

void* POSIX_Init(void*)
{
    printf("\nHello world!\n");

    auto ret = rtems_shell_init("SHLL", 4096, 254, "/dev/console", true, false, NULL);

    printf("RTEMS SHELL init ret: %d\n", int(ret));

    printf("Work area size: %d\n", rtems_configuration_get_work_space_size());
    printf("Tick interval : %d\n", rtems_configuration_get_microseconds_per_tick());

    for (;;)
    {
        ::sleep(1);

        printf("system clock:    %s\n", systime2str(std::chrono::system_clock::now()).c_str());
        printf("monotonic clock: %s   %s\n",
               nanoseconds2str(std::chrono::duration_cast<std::chrono::nanoseconds>(
                   std::chrono::steady_clock::now().time_since_epoch()).count()).c_str(),
               nanoseconds2str(std::chrono::duration_cast<std::chrono::nanoseconds>(
                   std::chrono::steady_clock::now().time_since_epoch()).count()).c_str());

        auto ts = ::timespec();
        (void)::clock_gettime(CLOCK_MONOTONIC, &ts);
        printf("%u.%09li   ", unsigned(ts.tv_sec), ts.tv_nsec);
        (void)::clock_gettime(CLOCK_MONOTONIC, &ts);
        printf("%u.%09li\n", unsigned(ts.tv_sec), ts.tv_nsec);

        puts("");
    }

    return NULL;
}
