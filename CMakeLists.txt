cmake_minimum_required(VERSION 3.0)

project(vc6qpudisas)

find_path(MESA_SOURCE_DIR src/broadcom/qpu/qpu_disasm.h)

if (MESA_SOURCE_DIR)
    message(STATUS "Source files of Mesa are found in ${MESA_SOURCE_DIR}")
else ()
    message(FATAL_ERROR "Source directory of Mesa is not found")
endif ()

find_path(MESA_BUILD_DIR src/broadcom/qpu/libbroadcom_qpu.a)

if (MESA_BUILD_DIR)
    message(STATUS "Build files of Mesa are found in ${MESA_BUILD_DIR}")
else ()
    message(FATAL_ERROR "Build directory of Mesa is not found")
endif ()

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -pipe -g -O2 -W -Wall -Wextra")

add_executable(vc6qpudisas vc6qpudisas.c)
target_include_directories(vc6qpudisas PRIVATE
        ${MESA_SOURCE_DIR}/src
        ${MESA_SOURCE_DIR}/include)
target_link_libraries(vc6qpudisas
        ${MESA_BUILD_DIR}/src/broadcom/qpu/libbroadcom_qpu.a
        ${MESA_BUILD_DIR}/src/util/libmesa_util.a)
