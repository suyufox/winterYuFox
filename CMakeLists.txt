cmake_minimum_required(VERSION 3.21)

project(winter_yufox_framework)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
if (CMAKE_CL_64)
    # 设置 可执行程序输出目录
	set(publish_bin_debug 			${CMAKE_CURRENT_SOURCE_DIR}/publish/x64/bin/debug64)
	set(publish_bin_release 		${CMAKE_CURRENT_SOURCE_DIR}/publish/x64/bin/release64)

    # 设置库文件输出目录
	set(publish_lib_debug 			${CMAKE_CURRENT_SOURCE_DIR}/publish/x64/lib/debug64)
	set(publish_lib_release 		${CMAKE_CURRENT_SOURCE_DIR}/publish/x64/lib/release64)

	set(PROJECT_NAME 				${PROJECT_NAME}64)
# 32
else()
 # 设置 可执行程序输出目录
	set(publish_bin_debug 			${CMAKE_CURRENT_SOURCE_DIR}/publish/x86/bin/debug)
	set(publish_bin_release 		${CMAKE_CURRENT_SOURCE_DIR}/publish/x86/bin/release)

 # 设置库文件输出目录
	set(publish_lib_debug 			${CMAKE_CURRENT_SOURCE_DIR}/publish/x86/lib/debug)
	set(publish_lib_release 		${CMAKE_CURRENT_SOURCE_DIR}/publish/x86/lib/release)
endif()

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_DEBUG 	${publish_bin_debug})
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_RELEASE 	${publish_bin_release})
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY_DEBUG 	${publish_lib_debug})
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY_RLEASE 	${publish_lib_release})

option(BUILD_WINTERYUFOX_APP "Build Main program | 构建主程序" ON)

add_subdirectory(framework/winteryufox.core)

if(BUILD_WINTERYUFOX_APP)
	add_subdirectory(apps/winteryufox)
endif()
