# Sets the minimum version of CMake required to build the native
# library. You should either keep the default value or only pass a
# value of 3.4.0 or lower.

cmake_minimum_required(VERSION 3.4.1)

# Creates and names a library, sets it as either STATIC
# or SHARED, and provides the relative paths to its source code.
# You can define multiple libraries, and CMake builds it for you.
# Gradle automatically packages shared libraries with your APK.

add_library( # Sets the name of the library.
             native-lib

             # Sets the library as a shared library.
             SHARED

             # Provides a relative path to your source file(s).
             # Associated headers in the same location as their source
             # file are automatically included.
             src/main/cpp/abs.c
             src/main/cpp/bsearch.c
             src/main/cpp/chckxy.c
             src/main/cpp/diff.c
             src/main/cpp/emd.c
             src/main/cpp/error.c
             src/main/cpp/fft.c
             src/main/cpp/findpeaks.c
             src/main/cpp/indexShapeCheck.c
             src/main/cpp/power.c
             src/main/cpp/pwchcore.c
             src/main/cpp/rt_nonfinite.c
             src/main/cpp/rtGetInf.c
             src/main/cpp/rtGetNaN.c
             src/main/cpp/spline.c
             src/main/cpp/sum.c
             src/main/cpp/vsd_emxutil.c
             src/main/cpp/vsd_initialize.c
             src/main/cpp/vsd_rtwutil.c
             src/main/cpp/vsd_terminate.c
             src/main/cpp/vsd.c)

# Searches for a specified prebuilt library and stores the path as a
# variable. Because system libraries are included in the search path by
# default, you only need to specify the name of the public NDK library
# you want to add. CMake verifies that the library exists before
# completing its build.

find_library( # Sets the name of the path variable.
              log-lib

              # Specifies the name of the NDK library that
              # you want CMake to locate.
              log )

# Specifies libraries CMake should link to your target library. You
# can link multiple libraries, such as libraries you define in the
# build script, prebuilt third-party libraries, or system libraries.

target_link_libraries( # Specifies the target library.
                       native-lib

                       # Links the target library to the log library
                       # included in the NDK.
                       ${log-lib} )
