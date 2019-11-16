cmake_minimum_required(VERSION 3.14)
project(douki_c_programs C)

set(CMAKE_C_STANDARD 11)

if(CMAKE_INSTALL_PREFIX_INITIALIZED_TO_DEFAULT)
    set(CMAKE_INSTALL_PREFIX $ENV{HOME}/local CACHE PATH "..." FORCE)
endif()

message(${CMAKE_INSTALL_PREFIX})

include_directories(include/umasig)

add_library(umasig
        include/umasig/c_vector.c
        include/umasig/complex.c
        include/umasig/conv.c
        include/umasig/fft.c
        include/umasig/plot.c
        include/umasig/random.c
        include/umasig/speech.c
        include/umasig/umasig.h
        include/umasig/utils.c
        include/umasig/vector.c
        include/umasig/window.c
        )

add_library(FileLib_osx
        include/FileLib_osx.c
        )

add_subdirectory(common)
add_subdirectory(fftw)
add_subdirectory(portaudio)


set(all_lib umasig)
INSTALL(TARGETS ${all_lib} RUNTIME DESTINATION lib)

