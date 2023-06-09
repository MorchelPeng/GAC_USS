project(test_app)
set(BIN_NAME "test_app")

# 1. ENV setup
# 1.1 Include/link path


include_directories(
    ${CMAKE_CURRENT_SOURCE_DIR}
    $ENV{PLATFORM_PATH}/../app/app_libs/include/pps_com
    $ENV{PLATFORM_PATH}/../app/app_libs/include/gac_inc
    $ENV{PLATFORM_PATH}/../app/app_libs/include/desay_inc)

# 1.2 C/CXX/LD Flags
# N/A

# 1.3 set QT5 ENV
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_INCLUDE_CURRENT_DIR ON)



# 2. Build
aux_source_directory(${CMAKE_CURRENT_SOURCE_DIR} DIR_SRCS)



add_executable(${BIN_NAME}
    ${DIR_SRCS}

)



target_link_libraries(
    ${BIN_NAME}

)


add_subdirectory(app_libs)
add_subdirectory(imu/test)
add_subdirectory(cansignaltx/test)
add_subdirectory(FvUssData)
add_subdirectory(powerM_pub)
add_subdirectory(cansignalrx)
add_subdirectory(did_dtc_resp)
add_subdirectory(did_dtc_req)
add_subdirectory(avm3d_gui_test)
add_subdirectory(Uss_Function)

# 3. Install
# 3.1 Install include files
# N/A
# 3.2 Install avm3d_app
install(TARGETS ${BIN_NAME}
        RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
        LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
        ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR})


