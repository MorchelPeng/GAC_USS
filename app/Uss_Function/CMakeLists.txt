
set(BIN_NAME "GAC_USS_APP")

  
set(GAC_USS_APP
${CMAKE_CURRENT_SOURCE_DIR}/src/main.cpp
${CMAKE_CURRENT_SOURCE_DIR}/src/uss_obs.cpp
${CMAKE_CURRENT_SOURCE_DIR}/src/data_sub.cpp
${CMAKE_CURRENT_SOURCE_DIR}/src/client.cpp
  )

include_directories(
    ${app_libs_SOURCE_DIR}/common_utils
    )


add_executable(GAC_USS_APP ${GAC_USS_APP})
target_link_libraries(GAC_USS_APP
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
        

