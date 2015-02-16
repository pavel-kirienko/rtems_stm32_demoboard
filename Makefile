#
# Copyright (C) 2015 Pavel Kirienko <pavel.kirienko@zubax.com>
# Distributed under the terms of the MIT license.
#

SRC_DIR := src

AM_CFLAGS := -Wno-error=format -Wno-error=pedantic
AM_CXXFLAGS := $(AM_CFLAGS)

include zubax_rtems/application.mk
