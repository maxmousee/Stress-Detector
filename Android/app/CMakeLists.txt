# For more information about using CMake with Android Studio, read the
# documentation: https://d.android.com/studio/projects/add-native-code.html

# Sets the minimum version of CMake required to build the native library.

cmake_minimum_required(VERSION 3.4.1)

# Creates and names a library, sets it as either STATIC
# or SHARED, and provides the relative paths to its source code.
# You can define multiple libraries, and CMake builds them for you.
# Gradle automatically packages shared libraries with your APK.

add_library( # Sets the name of the library.
        vsd

        # Sets the library as a shared library.
        SHARED

        # Provides a relative path to your source file(s).
        src/main/cpp/abs.cpp
        src/main/cpp/bluesteinSetup.cpp
        src/main/cpp/diff.cpp
        src/main/cpp/emd.cpp
        src/main/cpp/fft.cpp
        src/main/cpp/fft1.cpp
        src/main/cpp/findpeaks.cpp
        src/main/cpp/power.cpp
        src/main/cpp/pwchcore.cpp
        src/main/cpp/rt_nonfinite.cpp
        src/main/cpp/rtGetInf.cpp
        src/main/cpp/rtGetNaN.cpp
        src/main/cpp/spline.cpp
        src/main/cpp/sum.cpp
        src/main/cpp/vsd_emxutil.cpp
        src/main/cpp/vsd_initialize.cpp
        src/main/cpp/vsd_terminate.cpp
        src/main/cpp/vsd.cpp
        src/main/cpp/VSDJNI.cpp)

# Searches for a specified prebuilt library and stores the path as a
# variable. Because CMake includes system libraries in the search path by
# default, you only need to specify the name of the public NDK library
# you want to add. CMake verifies that the library exists before
# completing its build.

find_library( # Sets the name of the path variable.
        log-lib

        # Specifies the name of the NDK library that
        # you want CMake to locate.
        log)

# Specifies libraries CMake should link to your target library. You
# can link multiple libraries, such as libraries you define in this
# build script, prebuilt third-party libraries, or system libraries.

target_link_libraries( # Specifies the target library.
        vsd

        # Links the target library to the log library
        # included in the NDK.
        ${log-lib})