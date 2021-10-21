cmake_minimum_required(VERSION 3.10.2)
# Creates and names a library, sets it as either STATIC
# or SHARED, and provides the relative paths to its source code.
# You can define multiple libraries, and CMake builds them for you.
# Gradle automatically packages shared libraries with your APK.

add_library(native-lib
        SHARED
        src/main/jni/native_lib.cpp)

target_compile_options(native-lib PUBLIC -fsanitize=address -fno-omit-frame-pointer)
set_target_properties(native-lib PROPERTIES LINK_FLAGS -fsanitize=address)


find_library( # Sets the name of the path variable.
        log-lib
        # Specifies the name of the NDK library that
        # you want CMake to locate.
        log)


target_link_libraries( # Specifies the target library.
        native-lib #.so库名 可自定义
        # Links the target library to the log library
        # included in the NDK.
        ${log-lib})