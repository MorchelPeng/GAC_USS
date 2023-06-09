#!/bin/sh

#DS03H Development Environment Configuration

# Setup CMake
case "$1" in
	debug)
		export SVP_BUILD_DIR="build/debug"

		export CMAKE="cmake \
			-DCMAKE_INSTALL_PREFIX:PATH=$SVP_PLATFORM_ROOT/dist/debug/svp \
			-DCMAKE_INSTALL_BINDIR:PATH=$SVP_PLATFORM_ROOT/dist/debug/svp/bin \
			-DCMAKE_INSTALL_SYSCONFDIR:PATH=$SVP_PLATFORM_ROOT/dist/debug/svp/etc \
			-DCMAKE_INSTALL_SHAREDSTATEDIR:PATH=$SVP_PLATFORM_ROOT/dist/debug/svp/com \
			-DCMAKE_INSTALL_LOCALSTATEDIR:PATH=$SVP_PLATFORM_ROOT/dist/debug/svp/var \
			-DCMAKE_INSTALL_LIBDIR:PATH=$SVP_PLATFORM_ROOT/dist/debug/svp/lib \
			-DCMAKE_INSTALL_INCLUDEDIR:PATH=$SVP_PLATFORM_ROOT/dist/debug/svp/include \
			-DCMAKE_INSTALL_DATAROOTDIR:PATH=$SVP_PLATFORM_ROOT/dist/debug/svp/share \
            -DCMAKE_INSTALL_AVM_SDK_LIBDIR:PATH=$SVP_PLATFORM_ROOT/AVM_SDK/service_sdk/lib \
            -DCMAKE_INSTALL_AVM_SDK_INCLUDEDIR:PATH=$SVP_PLATFORM_ROOT/AVM_SDK/service_sdk/include \
			-DCMAKE_INSTALL_SO_NO_EXE=0 \
			-DCMAKE_BUILD_TYPE=Debug \
			-Wno-dev"
		;;
	*)
		export SVP_BUILD_DIR="build/release"

		export CMAKE="cmake \
			-DCMAKE_INSTALL_PREFIX:PATH=$SVP_PLATFORM_ROOT/dist/release/svp \
			-DCMAKE_INSTALL_BINDIR:PATH=$SVP_PLATFORM_ROOT/dist/release/svp/bin \
			-DCMAKE_INSTALL_SYSCONFDIR:PATH=$SVP_PLATFORM_ROOT/dist/release/svp/etc \
			-DCMAKE_INSTALL_SHAREDSTATEDIR:PATH=$SVP_PLATFORM_ROOT/dist/release/svp/com \
			-DCMAKE_INSTALL_LOCALSTATEDIR:PATH=$SVP_PLATFORM_ROOT/dist/release/svp/var \
			-DCMAKE_INSTALL_LIBDIR:PATH=$SVP_PLATFORM_ROOT/dist/release/svp/lib \
			-DCMAKE_INSTALL_INCLUDEDIR:PATH=$SVP_PLATFORM_ROOT/dist/release/svp/include \
			-DCMAKE_INSTALL_DATAROOTDIR:PATH=$SVP_PLATFORM_ROOT/dist/release/svp/share \
            -DCMAKE_INSTALL_AVM_SDK_LIBDIR:PATH=$SVP_PLATFORM_ROOT/AVM_SDK/service_sdk/lib \
            -DCMAKE_INSTALL_AVM_SDK_INCLUDEDIR:PATH=$SVP_PLATFORM_ROOT/AVM_SDK/service_sdk/include \
			-DCMAKE_INSTALL_SO_NO_EXE=0 \
			-DCMAKE_BUILD_TYPE=Release \
			-Wno-dev"
		;;
esac

# Export MAKE
export MAKE="make"
