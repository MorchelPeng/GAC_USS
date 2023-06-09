
set(BIN_NAME "test.imu.sub")


  
set(test_imu_sub_Src
  imu_sub_main.cpp
  )

include_directories("${app_libs_SOURCE_DIR}/common_utils")

add_executable(test.imu.sub ${test_imu_sub_Src})
target_link_libraries(test.imu.sub
  app_utils_console_io
  pps_com
  )


# 3. Install
# 3.1 Install include files
# N/A
# 3.2 Install avm3d_app
install(TARGETS ${BIN_NAME}
        RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
        LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
        ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR})
        

