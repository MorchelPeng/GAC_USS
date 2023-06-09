

set(BIN_NAME "cansignaltx")

  
set(app_src
  main.cpp

  )
    

include_directories("${app_libs_SOURCE_DIR}/common_utils")



add_executable(${BIN_NAME} ${app_src})
target_link_libraries(${BIN_NAME}
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
  
  






