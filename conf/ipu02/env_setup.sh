#!/bin/sh


. $SVP_PLATFORM_ROOT/conf/share/make.sh $1



export TOOLCHAIN_ROOT=$QNX_HOST/usr/bin
export PATH=$PATH:$QNX_HOST/usr/bin
# Addon C/CXX FLAGS
export CFLAGS="$CFLAGS -D__LINUX__ -D__linux__ -D__AB02A_PLATFORM__"
export CXXFLAGS="$CXXFLAGS -D__LINUX__ -D__linux__ -D__AB02A_PLATFORM__"
export CPPFLAGS="$CPPFLAGS -D__LINUX__ -D__linux__ -D__AB02A_PLATFORM__"
