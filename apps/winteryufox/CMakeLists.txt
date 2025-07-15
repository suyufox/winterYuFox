project(winteryufox LANGUAGES CXX)

add_executable(winteryufox 
    src/main.cpp
    include/winteryufox/main.h
)

# 设置包含路径
target_include_directories(winteryufox  PUBLIC 
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    $<INSTALL_INTERFACE:include>
)

target_link_libraries(winteryufox  PRIVATE
    winteryufox.core
)