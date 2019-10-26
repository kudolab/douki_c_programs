cmake_minimum_required(VERSION 3.14)
project(douki_c_fftw C)

set(CMAKE_C_STANDARD 11)


#################################### fftw3 ####################################
add_executable(fftout2
        src/fftout2.c
        )
target_link_libraries(fftout2 /usr/local/lib/libfftw3.a)
add_executable(fftout3
        src/fftout3.c
        )
target_link_libraries(fftout3 /usr/local/lib/libfftw3.a)
add_executable(fftout4
        src/fftout4.c
        )
target_link_libraries(fftout4 /usr/local/lib/libfftw3.a)
add_executable(make_whitenoise
        src/make_whitenoise.c
        )
target_link_libraries(make_whitenoise /usr/local/lib/libfftw3.a)
#################################### fftw3 ####################################

set(fftw_bin fftout2 fftout3 fftout4 make_whitenoise)
INSTALL(TARGETS ${fftw_bin} RUNTIME DESTINATION bin)
