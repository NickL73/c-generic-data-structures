#Define the minimum required version
cmake_minimum_required(VERSION 3.16.3)

#Initialize the project and name
project(collections)

set(LIBRARY_SRCS
    src/dll.c)

if ( CMAKE_COMPILER_IS_GNUCC )
    set(CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} -Wall -Werror -Wextra")
endif()

add_library(${PROJECT_NAME} SHARED ${LIBRARY_SRCS})
target_include_directories(${PROJECT_NAME} PRIVATE ${PROJECT_SOURCE_DIR}/src)
target_include_directories(${PROJECT_NAME} PUBLIC ${PROJECT_SOURCE_DIR}/include)

