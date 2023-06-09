#!/bin/sh

#SV Platform Development Environment Configuration

#Export Platform Root Path
export SVP_PLATFORM_ROOT=`pwd`
export PLATFORM_PATH=`pwd`

usage_full() {
    echo -e "\033[0;32mUsage:\033[0;0m env_setup.sh"\
        " --platform=ipu02"\
        " [--build-type=release|debug]"
}

usage_platform() {
    echo -e "\033[0;32mUsage:\033[0;0m env_setup.sh"\
        " --platform=ipu02"\
        " [--build-type=release|debug]"
}

usage_all() {
    usage_full
    usage_platform
}

is_platform_supported() {
    case "$1" in
        ipu02) return 0;;
        ipu02) return 0;;
        ipu02) return 0;;
        * ) return 1 ;;
    esac
}

is_build_type_supported() {
    case "$1" in
        debug) return 0 ;;
        release) return 0 ;;
        * ) return 1 ;;
    esac
}

set_platform() {
    . $SVP_PLATFORM_ROOT/conf/$1/env_setup.sh $2 \
        && export SVP_PLATFORM=$1 \
        && export SVP_BUILD_TYPE=$2
}

platform=
build_type=

format_args() {
    p=`echo $1 | cut -d= -f1`
    v=`echo $1 | cut -d= -f2`
    case $p in
        --platform) platform=$v ;;
        --build-type) build_type=$v ;;
        *) echo -e "\033[0;33mWARN:\033[0;0m Unknown argument: $v" ;;
    esac
}

#format_args --platform ipu02
format_args $1

# If no SVP_PLATFORM, --platform is needed.
if [ ! -n "$SVP_PLATFORM" ] && [ ! -n "$platform" ]; then
    echo -e "\033[0;31mERROR:\033[0;0m No SVP_PLATFORM specified!";
    usage_full
    usage_platform
    return 0
fi

# --platform must be supported.
if [ -n "$platform" ] && ! is_platform_supported $platform; then
    echo -e "\033[0;31mERROR:\033[0;0m Unsupported platform: $platform";
    usage_full
    usage_platform
    return 0
fi

# --build-type must along with --platform
if [ ! -n "$platform" ] && [ -n "$build_type" ]; then
    echo -e "\033[0;31mERROR:\033[0;0m '--build-type' can only be used along with '--platform' !";
    usage_full
    usage_platform
    return 0
fi

# --build-type must be supported
if [ -n "$build_type" ] && ! is_build_type_supported $build_type; then
    echo -e "\033[0;31mERROR:\033[0;0m Invalid build type: $build_type!";
    return 0
fi

# If no --build-type, use "release" by default
if [ ! -n "$build_type" ]; then
    build_type="release"
fi

if [ -n "$platform" ]; then
    # Reset platform when --platform is diff with SVP_PLATFORM,
    #    or --build-type is diff with SVP_BUILD_TYPE
    if [ "$platform" != "$SVP_PLATFORM" ] \
        || [ "$build_type" != "$SVP_BUILD_TYPE" ]; then

        set_platform $platform $build_type
    fi
fi


