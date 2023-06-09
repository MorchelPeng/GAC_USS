# 0. CMake Defs
cmake_minimum_required(VERSION 2.8 FATAL_ERROR)
cmake_policy(VERSION 2.6)

# 1. Project Name
project(test)
set(APP_PROJECT_NAME ${PROJECT_NAME})

# 2. definitions && checkers
add_definitions(
        -D_QNX_SOURCE
	-Wno-unknown-pragmas
)


set(PROJECT_OUTPUT_PATH "$ENV{PLATFORM_PATH}/output/${PROJECT_NAME}/release")
set(CMAKE_BUILD_TYPE "Release")

# 3.QNX Platform Env (Include/Lib Path, C/CXX/LD FLAGS)
SET(CMAKE_C_FLAGS "-Vgcc/8.3.0,gcc_ntoaarch64le ")
#SET(CMAKE_CXX_FLAGS "-std=c++11 -Vgcc/5.4.0,gcc_ntoaarch64le -Y_cxx -fpermissive ")
SET(CMAKE_CXX_FLAGS "-std=c++11 -Vgcc/8.3.0,gcc_ntoaarch64le -Y_cxx -fpermissive ")
add_definitions("-Wall -Wno-strict-aliasing -Wno-unused-function -Wno-deprecated -Wno-deprecated-declarations")

set(CMAKE_STRIP "$ENV{STRIP}")
set(CMAKE_INSTALL_PREFIX "${PROJECT_OUTPUT_PATH}")
set(CMAKE_INSTALL_BINDIR "${PROJECT_OUTPUT_PATH}/bin")
set(CMAKE_INSTALL_SYSCONFDIR "${PROJECT_OUTPUT_PATH}/etc")
set(CMAKE_INSTALL_SHAREDSTATEDIR "${PROJECT_OUTPUT_PATH}/com")
set(CMAKE_INSTALL_LOCALSTATEDIR "${PROJECT_OUTPUT_PATH}/var")
set(CMAKE_INSTALL_LIBDIR "${PROJECT_OUTPUT_PATH}/lib")
set(CMAKE_INSTALL_INCLUDEDIR "${PROJECT_OUTPUT_PATH}/include")
set(CMAKE_INSTALL_DATAROOTDIR "${PROJECT_OUTPUT_PATH}/res")
set(SERVICE_SDK_PATH "$ENV{PLATFORM_PATH}/app/app_libs/common_utils/service_sdk")


message("${QNX_BASE}")


link_directories(
    ${SERVICE_SDK_PATH}/lib
)

include_directories(app/pps_public)
include_directories(app/gac_inc)

# 5. Sub Projects
add_subdirectory(app)



