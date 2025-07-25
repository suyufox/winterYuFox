cmake_minimum_required(VERSION 3.21)

set(RootProjectVersion 0.0.1)
set(RootProjectLanguage CXX)
set(RootProjectDescription "A framework for winterYufox")

# if(NOT DEFINED ENV{LLVM_HOME})
#     message(FATAL_ERROR "LLVM_HOME environment variable not set!")
# endif()
if(NOT DEFINED ENV{VCPKG_HOME})
  message(FATAL_ERROR "VCPKG_HOME environment variable not set!")
endif()
# set(CMAKE_C_COMPILER    $ENV{LLVM_HOME}/bin/clang)
# set(CMAKE_CXX_COMPILER  $ENV{LLVM_HOME}/bin/clang++)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# 设置 可执行程序输出目录
set(target_bin_debug 			${CMAKE_CURRENT_SOURCE_DIR}/target/debug)
set(target_bin_release 		${CMAKE_CURRENT_SOURCE_DIR}/target/release)
# 设置库文件输出目录
set(target_lib_debug 			${CMAKE_CURRENT_SOURCE_DIR}/target/debug/lib)
set(target_lib_release 		${CMAKE_CURRENT_SOURCE_DIR}/target/release/lib)


set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_DEBUG 	   ${target_bin_debug})
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_RELEASE 	 ${target_bin_release})
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY_DEBUG 	   ${target_lib_debug})
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY_RELEASE 	 ${target_lib_release})

set(CMAKE_TOOLCHAIN_FILE "$ENV{VCPKG_HOME}/scripts/buildsystems/vcpkg.cmake"
    CACHE STRING "Vcpkg toolchain file")

project(winterYufoxFramework
  VERSION ${RootProjectVersion}
  DESCRIPTION ${RootProjectDescription}
  LANGUAGES ${RootProjectLanguage}
)

option(BUILD_WINITERFOXMANAGER_PROJECT "Build winterFoxManager" ON)

if(BUILD_WINITERFOXMANAGER_PROJECT)
  add_subdirectory(tools/wfox)
endif()
