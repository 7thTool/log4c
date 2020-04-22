# Sets the minimum version of CMake required to build the native library.

cmake_minimum_required(VERSION 3.4.1)

project(log4c C CXX)

ADD_DEFINITIONS(-std=c++11)

# add location of platform.hpp for Windows builds
if(WIN32)
  #需要兼容XP时,定义_WIN32_WINNT 0x0501
  ADD_DEFINITIONS(-D_WIN32_WINNT=0x0601)
  SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /bigobj")
  add_definitions(-DWIN32 -D_WINDOWS)
else()
  add_definitions(-g -W -Wall -fPIC)
endif()

# add include directories
INCLUDE_DIRECTORIES(./include)

# Creates and names a library, sets it as either STATIC
# or SHARED, and provides the relative paths to its source code.
# You can define multiple libraries, and CMake builds them for you.
# Gradle automatically packages shared libraries with your APK.

aux_source_directory(./src SRC_LIST)

# add_library( # Sets the name of the library.
#         log4c_static

#         # Sets the library as a static library.
#         STATIC

#         # Provides a relative path to your source file(s).
#         ${SRC_LIST}
#         )

add_library( # Sets the name of the library.
        log4c

        # Sets the library as a shared library.
        SHARED

        # Provides a relative path to your source file(s).
        ${SRC_LIST}
        )

# # 指定静态库的输出名称
# set_target_properties(log4c_static PROPERTIES OUTPUT_NAME "log4c")
# # 使动态库和静态库同时存在
# set_target_properties(log4c PROPERTIES CLEAN_DIRECT_OUTPUT 1)
# set_target_properties(log4c_static PROPERTIES CLEAN_DIRECT_OUTPUT 1)
 
# # 指定动态库版本
# # VERSION 动态库版本
# # SOVERSION API版本
# set_target_properties(log4c PROPERTIES VERSION 1.0 SOVERSION 1)
 
# # 将动态库与动态库同时安装到lib目录中
# install (TARGETS log4c log4c_static DESTINATION lib)

# 添加可执行文件
ADD_EXECUTABLE(main
  ${SRC_LIST}
	main.cpp
)
#TARGET_LINK_LIBRARIES(main log4c)