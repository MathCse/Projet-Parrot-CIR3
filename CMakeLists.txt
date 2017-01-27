cmake_minimum_required(VERSION 2.8 FATAL_ERROR)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}")

# check for c++11 with gcc
include(CheckCXXCompilerFlag)
CHECK_CXX_COMPILER_FLAG("-std=c++11" COMPILER_SUPPORTS_CXX11)
CHECK_CXX_COMPILER_FLAG("-std=c++0x" COMPILER_SUPPORTS_CXX0X)

if(COMPILER_SUPPORTS_CXX11)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
elseif(COMPILER_SUPPORTS_CXX0X)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++0x")
else()
    message(STATUS "The compiler ${CMAKE_CXX_COMPILER} has no C++11 support. Please use a different C++ compiler.")
endif()

# enable warnings
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra")

# main library
find_package(Threads REQUIRED)
include_directories(lib)
add_library(sumo
		lib/decode.cpp
		lib/control.cpp
		lib/common.cpp
		lib/realtime.cpp
		lib/image.cpp
)
target_link_libraries(sumo ${CMAKE_THREAD_LIBS_INIT})

if(UNIX AND NOT APPLE)
	find_library(RT rt)
    target_link_libraries(sumo ${RT})
endif()

find_package(OpenCV REQUIRED)
include_directories(${OpenCV_INCLUDE_DIRS})
add_executable(projetCIR projetCIR/main.cpp projetCIR/recognition/detection.cpp)
target_link_libraries(projetCIR sumo ${OpenCV_LIBS})
