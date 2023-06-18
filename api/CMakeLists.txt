## Copyright 2018 Intel Corporation
## SPDX-License-Identifier: Apache-2.0

set(API_SOURCES
  api.cpp
)

add_library(OpenImageDenoise2 ${OIDN_LIB_TYPE} ${API_SOURCES} ${OIDN_RESOURCE_FILE})
set_property(TARGET OpenImageDenoise2 PROPERTY VERSION ${PROJECT_VERSION})
set_property(TARGET OpenImageDenoise2 PROPERTY SOVERSION ${PROJECT_VERSION_MAJOR})

target_include_directories(OpenImageDenoise2
  PUBLIC
    $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/include>
    $<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>
)

target_link_libraries(OpenImageDenoise2 PRIVATE OpenImageDenoise_core)

if(NOT OIDN_STATIC_LIB)
  oidn_strip_symbols(OpenImageDenoise2)
endif()

install(TARGETS OpenImageDenoise2
  EXPORT
    OpenImageDenoise_Exports
  ARCHIVE
    DESTINATION ${CMAKE_INSTALL_LIBDIR} COMPONENT devel
  LIBRARY
    DESTINATION ${CMAKE_INSTALL_LIBDIR} COMPONENT devel
  RUNTIME
    DESTINATION ${CMAKE_INSTALL_BINDIR} COMPONENT lib
)