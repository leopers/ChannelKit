cmake_minimum_required(VERSION 3.15)
project(ChannelKit)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(${CMAKE_SOURCE_DIR}/cpp/include)

file(GLOB_RECURSE CHANNELKIT_SOURCES
    "${CMAKE_SOURCE_DIR}/cpp/src/*.cpp"
)

add_library(channel_kit ${CHANNELKIT_SOURCES})

add_executable(lab1 ${CMAKE_SOURCE_DIR}/labs/lab1/lab1.cpp)

target_link_libraries(lab1 channel_kit)