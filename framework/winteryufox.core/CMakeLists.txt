cmake_minimum_required(VERSION 3.21)

project(winteryufox.core VERSION 1.0.0 LANGUAGES CXX)

# SHARED | STATIC
add_library(winteryufox.core SHARED
    src/library.cpp
    include/winteryufox.core/library.h
)

target_include_directories(winteryufox.core PUBLIC 
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    $<INSTALL_INTERFACE:include>
)

target_compile_definitions(winteryufox.core PRIVATE
    WINTERYUFOX_COER_RARY_EXPORTS
)