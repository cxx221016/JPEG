cmake_minimum_required(VERSION 3.15)
project(parsejpeg)

set(CMAKE_CXX_STANDARD 17)

set(CMAKE_BUILD_TYPE "Release")

set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)
set(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/lib)

include_directories(${PROJECT_SOURCE_DIR}/include)

add_library(APP0 STATIC src/APP0.cpp)
add_library(parsejpeg STATIC src/parsejpeg.cpp)
add_library(DQT STATIC src/DQT.cpp)
add_library(SOF STATIC src/SOF.cpp)
add_library(DHT STATIC src/DHT.cpp)
add_library(SOS STATIC src/SOS.cpp)
add_library(Serial STATIC src/Serial.cpp)

add_executable(main main.cpp)

target_link_libraries(main parsejpeg APP0 DQT SOF DHT SOS Serial ws2_32)