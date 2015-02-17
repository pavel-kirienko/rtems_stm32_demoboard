#
# Copyright (C) 2015 Pavel Kirienko <pavel.kirienko@zubax.com>
# Distributed under the terms of the MIT license.
#

SRC_DIR := src

AM_CFLAGS := -Werror -Wno-error=format -Wno-error=pedantic -flto
AM_CXXFLAGS := $(AM_CFLAGS) -fno-exceptions -fno-rtti

AM_LDFLAGS := -fno-exceptions -fno-rtti -Os -flto

include zubax_rtems/application.mk
