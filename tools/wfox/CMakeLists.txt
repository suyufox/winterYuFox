cmake_minimum_required(VERSION 3.21)

project(winterFoxManager
  VERSION 0.0.1
  DESCRIPTION "winterFox Manager"
  LANGUAGES CXX
)

find_package(fmt CONFIG REQUIRED)
find_package(CLI11 CONFIG REQUIRED)
find_package(spdlog CONFIG REQUIRED)
find_package(indicators CONFIG REQUIRED)
find_package(date CONFIG REQUIRED)
find_package(tomlplusplus CONFIG REQUIRED)

add_executable(wfox
  src/main.cpp
  
  include/wfox/main.h
  
)

target_link_libraries(wfox
  PRIVATE
    fmt::fmt
    CLI11::CLI11
    spdlog::spdlog
    indicators::indicators
    date::date
    date::date-tz
    tomlplusplus::tomlplusplus
)

target_include_directories(wfox PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    $<INSTALL_INTERFACE:include>
)