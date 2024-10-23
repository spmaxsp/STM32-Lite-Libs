cmake_minimum_required(VERSION 3.22)

project(stm32litelibs)
add_library(stm32litelibs INTERFACE)

# Enable CMake support for C language
enable_language(C)


target_include_directories(stm32cubemx INTERFACE
    ./stm
    ./max6675
)

target_sources(stm32cubemx INTERFACE
)


