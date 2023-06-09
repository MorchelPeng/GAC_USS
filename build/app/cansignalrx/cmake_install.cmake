# Install script for directory: /home/uss/A8E.X3V.B1.20230117.S.E04.PS/App/pps_a8e_test_v36/pps_a8e_test/app/cansignalrx

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "/home/uss/A8E.X3V.B1.20230117.S.E04.PS/App/pps_a8e_test_v36/pps_a8e_test/output/test/release")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "Release")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

# Is this installation the result of a crosscompile?
if(NOT DEFINED CMAKE_CROSSCOMPILING)
  set(CMAKE_CROSSCOMPILING "TRUE")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}/home/uss/A8E.X3V.B1.20230117.S.E04.PS/App/pps_a8e_test_v36/pps_a8e_test/output/test/release/bin/test.cansignalrx.sub" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}/home/uss/A8E.X3V.B1.20230117.S.E04.PS/App/pps_a8e_test_v36/pps_a8e_test/output/test/release/bin/test.cansignalrx.sub")
    file(RPATH_CHECK
         FILE "$ENV{DESTDIR}/home/uss/A8E.X3V.B1.20230117.S.E04.PS/App/pps_a8e_test_v36/pps_a8e_test/output/test/release/bin/test.cansignalrx.sub"
         RPATH "")
  endif()
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "/home/uss/A8E.X3V.B1.20230117.S.E04.PS/App/pps_a8e_test_v36/pps_a8e_test/output/test/release/bin/test.cansignalrx.sub")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
file(INSTALL DESTINATION "/home/uss/A8E.X3V.B1.20230117.S.E04.PS/App/pps_a8e_test_v36/pps_a8e_test/output/test/release/bin" TYPE EXECUTABLE FILES "/home/uss/A8E.X3V.B1.20230117.S.E04.PS/App/pps_a8e_test_v36/pps_a8e_test/build/app/cansignalrx/test.cansignalrx.sub")
  if(EXISTS "$ENV{DESTDIR}/home/uss/A8E.X3V.B1.20230117.S.E04.PS/App/pps_a8e_test_v36/pps_a8e_test/output/test/release/bin/test.cansignalrx.sub" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}/home/uss/A8E.X3V.B1.20230117.S.E04.PS/App/pps_a8e_test_v36/pps_a8e_test/output/test/release/bin/test.cansignalrx.sub")
    file(RPATH_CHANGE
         FILE "$ENV{DESTDIR}/home/uss/A8E.X3V.B1.20230117.S.E04.PS/App/pps_a8e_test_v36/pps_a8e_test/output/test/release/bin/test.cansignalrx.sub"
         OLD_RPATH "/home/uss/A8E.X3V.B1.20230117.S.E04.PS/App/pps_a8e_test_v36/pps_a8e_test/app/app_libs/common_utils/service_sdk/lib:"
         NEW_RPATH "")
  endif()
endif()

