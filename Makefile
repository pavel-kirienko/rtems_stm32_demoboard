#
# Copyright (C) 2015 Pavel Kirienko <pavel.kirienko@zubax.com>
# Distributed under the terms of the MIT license.
#

#
# Source files
#
CSRCS = $(wildcard src/*.c)        \
        $(wildcard src/*/*.c)      \
        $(wildcard src/*/*/*.c)

CXXSRCS = $(wildcard src/*.cpp)        \
          $(wildcard src/*/*.cpp)      \
          $(wildcard src/*/*/*.cpp)

#
# Flags
#
common_flags := -Wall -Wextra -Werror -pedantic -Wundef -Wfloat-equal -Wmissing-declarations \
                -Wno-error=format -Wno-error=pedantic \
                -ffunction-sections -fdata-sections -D_GLIBCXX_HAS_GTHREADS

AM_CFLAGS   := $(common_flags) -std=c99

AM_CXXFLAGS := $(common_flags) -std=c++11 -fno-exceptions -fno-rtti

AM_LDFLAGS  := -fwhole-program -fno-exceptions -fno-rtti -Os -Wl,--gc-sections

#
# Include the standard application makefile
#
include zubax_rtems/application.mk
