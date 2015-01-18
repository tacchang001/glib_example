cmake_minimum_required(VERSION 2.8)

set (CMAKE_VERBOSE_MAKEFILE 1)

project (example C)

set (CMAKE_BUILD_TYPE Debug)

set (CMAKE_C_FLAGS "-Wall -Werror")

set (TARGET_EXE_NAME example)
set (SRCS
    src/main.c
)

# Apache Portable Runtime
execute_process (
    COMMAND pkg-config --cflags glib-2.0
    OUTPUT_VARIABLE GLIB_CFLAGS
    OUTPUT_STRIP_TRAILING_WHITESPACE
)
message ("GLIB_CFLAGS:" ${GLIB_CFLAGS})
execute_process (
    COMMAND pkg-config --libs glib-2.0
    OUTPUT_VARIABLE GLIB_LIBS
    OUTPUT_STRIP_TRAILING_WHITESPACE
)
message ("GLIB_LIBS:" ${GLIB_LIBS})

set (CMAKE_C_FLAGS "${CMAKE_C_FLAGS} ${GLIB_CFLAGS}")
include_directories (
)
link_directories (
)
set (LIBS
    ${GLIB_LIBS}
)

add_executable (${TARGET_EXE_NAME} ${SRCS})
target_link_libraries (${TARGET_EXE_NAME} ${LIBS})
