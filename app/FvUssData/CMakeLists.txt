
set(BIN_NAME "FvUssDataTest")

  
set(FvUssDataTest
  main.cpp
  )

include_directories(
    ${app_libs_SOURCE_DIR}/common_utils
    )


add_executable(FvUssDataTest ${FvUssDataTest})
target_link_libraries(FvUssDataTest
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
        

