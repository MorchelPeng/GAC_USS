
set(BIN_NAME "avm3d_gui_test")

  
set(avm3d_gui_test
  main.cpp
  )

include_directories(
    ${app_libs_SOURCE_DIR}/common_utils
    )


add_executable(avm3d_gui_test ${avm3d_gui_test})
target_link_libraries(avm3d_gui_test
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
        

