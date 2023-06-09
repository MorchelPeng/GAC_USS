
set(BIN_NAME "test.did_dtc_resp.pub")

set(test_did_dtc_resp_Src
  did_dtc_resp.cpp
  )

include_directories("${app_libs_SOURCE_DIR}/common_utils")


add_executable(test.did_dtc_resp.pub ${test_did_dtc_resp_Src})
target_link_libraries(test.did_dtc_resp.pub
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


