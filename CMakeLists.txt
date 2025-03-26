cmake_minimum_required(VERSION 3.15)
project(ChannelKit)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(${CMAKE_SOURCE_DIR}/cpp/include)

file(GLOB_RECURSE CHANNELKIT_SOURCES
    "${CMAKE_SOURCE_DIR}/cpp/src/*.cpp"
)

add_library(channel_kit ${CHANNELKIT_SOURCES})

add_executable(lab1 ${CMAKE_SOURCE_DIR}/labs/lab1.cpp)
target_link_libraries(lab1 channel_kit)

add_custom_command(
    OUTPUT ${CMAKE_BINARY_DIR}/../data/lab1.csv
           ${CMAKE_BINARY_DIR}/../figures/ber_plot.png
    COMMAND lab1 > ${CMAKE_BINARY_DIR}/../data/lab1.csv
    COMMAND python3 ${CMAKE_SOURCE_DIR}/labs/plot_lab1.py
            ${CMAKE_BINARY_DIR}/../data/lab1.csv
            ${CMAKE_BINARY_DIR}/../figures/ber_plot.png
    DEPENDS lab1
    WORKING_DIRECTORY ${CMAKE_BINARY_DIR}
    COMMENT "Running lab1 to generate CSV and plotting with Python..."
)

add_custom_target(plot_lab1
    DEPENDS ${CMAKE_BINARY_DIR}/../data/lab1.csv
            ${CMAKE_BINARY_DIR}/../figures/ber_plot.png
)

