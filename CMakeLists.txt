cmake_minimum_required(VERSION 3.14)
project(douki_c_programs C)

set(CMAKE_C_STANDARD 11)
#set(CMAKE_INSTALL_PREFIX $HOME/dev/local)

if(CMAKE_INSTALL_PREFIX_INITIALIZED_TO_DEFAULT)
    set(CMAKE_INSTALL_PREFIX $ENV{HOME}/dev/local CACHE PATH "..." FORCE)
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

add_subdirectory(common)
add_subdirectory(fftw)
add_subdirectory(portaudio)


set(all_lib umasig)
INSTALL(TARGETS ${all_lib} RUNTIME DESTINATION lib)

#set(all_bin "FC_deviation FC_deviation_alter IMPmcode LE_1 WAVtoDSB_osx biascut cosine_windowing cutout_anyfile cutout_anyfile2 douki_new dv equ_schroeder1 equ_schroeder2 equ_schroeder3 equ_schroeder4 equ_schroeder5 fatchdb fff find_cutpoint henkan imp_add imp_add_by10 inverse linear_inpo_hrir_using_ATD mono2LR peaking_filter print_siglen random scaling_max_instant_amp sepach sinwave timeconvo zeropad_anyfile fftout2 fftout3 fftout4 make_whitenoise 2chplay 2chplay2 closed_loop_new monoplay monoplay2 monoplay_48k monoplay_8kHz monoplay_alter monorecord playrec_2ch_inPath playrec_2ch_new_kai playrec_mono playrec_mono_inPath")
#INSTALL(TARGETS ${all_bin} RUNTIME DESTINATION $HOME/bin)
#message(${all_bin})
#message(${all_lib})
