cmake_minimum_required(VERSION 2.8)
project(c03)

set(CMAKE_CXX_STANDARD 11)

if (EXISTS ${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
    include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
    conan_basic_setup()
endif()

# requires opencv
find_package(OpenCV 4.0.0 REQUIRED) # 4.3.0
message(STATUS "OpenCV version: " ${OpenCV_VERSION})

include_directories(${OpenCV_INCLUDE_DIRS})
link_directories(${OpenCV_LIB_DIR})

add_executable(c03 main.cpp)

add_executable(sample1 sample1.cpp)
target_link_libraries(sample1 ${OpenCV_LIBS})

add_executable(sample2 sample2.cpp)
target_link_libraries(sample2 ${OpenCV_LIBS})

add_executable(sample3 sample3.cpp)
target_link_libraries(sample3 ${OpenCV_LIBS})

add_executable(sample4 sample4.cpp)
target_link_libraries(sample4 ${OpenCV_LIBS})

add_executable(sample6 sample6.cpp)
target_link_libraries(sample6 ${OpenCV_LIBS})

add_executable(sample5 sample5.cpp)
target_link_libraries(sample5 ${OpenCV_LIBS} -lglut -lGL -lGLU)