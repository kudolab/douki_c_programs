cmake_minimum_required(VERSION 3.14)
project(douki_C_programs C)

set(CMAKE_C_STANDARD 11)

include_directories(umasig)

add_library(umasig
        umasig/c_vector.c
        umasig/complex.c
        umasig/conv.c
        umasig/fft.c
        umasig/plot.c
        umasig/random.c
        umasig/speech.c
        umasig/umasig.h
        umasig/utils.c
        umasig/vector.c
        umasig/window.c
        )
add_executable(biascut
        biascut.c
        )
add_executable(closed_loop_new
        closed_loop_new.c
        )
add_executable(cosine_windowing
        cosine_windowing.c
        )
add_executable(cutout_anyfile
        cutout_anyfile.c
        )
add_executable(cutout_anyfile2
        cutout_anyfile2.c
        )
add_executable(douki_new
        douki_new.c
        )
add_executable(dv
        dv.c
        )
add_executable(equ_schroeder1
        equ_schroeder1.c
        )
add_executable(equ_schroeder2
        equ_schroeder2.c
        )
add_executable(equ_schroeder3
        equ_schroeder3.c
        )
add_executable(equ_schroeder4
        equ_schroeder4.c
        )
add_executable(equ_schroeder5
        equ_schroeder5.c
        )
add_executable(fatchdb
        fatchdb.c
        )
add_executable(FC_deviation
        FC_deviation.c
        )
add_executable(FC_deviation_alter
        FC_deviation_alter.c
        )
add_executable(fff
        fff.c
        )
#add_executable(fft
#        fft.c
#        )
#add_executable(FileLib_osx
#        FileLib_osx.c
#        )
add_executable(find_cutpoint
        find_cutpoint.c
        )
add_executable(henkan
        henkan.c
        )
#add_executable(ifft
#        ifft.c
#        )
add_executable(imp_add
        imp_add.c
        )
add_executable(imp_add_by10
        imp_add_by10.c
        )
add_executable(IMPmcode
        IMPmcode.c
        )
add_executable(inverse
        inverse.c
        )
add_executable(LE_1
        LE_1.c
        )
add_executable(linear_inpo_hrir_using_ATD
        linear_inpo_hrir_using_ATD.c
        )
add_executable(mono2LR
        mono2LR.c
        )
add_executable(peaking_filter
        peaking_filter.c
        )
add_executable(print_siglen
        print_siglen.c
        )
add_executable(random
        random.c
        )
#add_executable(Rev_sup
#        Rev_sup.c
#        )
add_executable(scaling_max_instant_amp
        scaling_max_instant_amp.c
        )
add_executable(sepach
        sepach.c
        )
add_executable(sinwave
        sinwave.c
        )
add_executable(timeconvo
        timeconvo.c
        )
add_executable(WAVtoDSB_osx
        WAVtoDSB_osx.c
        )
add_executable(zeropad_anyfile
        zeropad_anyfile.c
        )

#################################### fftw3 ####################################
#set(CMAKE_C_FLAGS "-lm /usr/local/lib/libfftw3.a")
add_executable(fftout2
        fftout2.c
        )
target_link_libraries(fftout2 /usr/local/lib/libfftw3.a)
add_executable(fftout3
        fftout3.c
        )
target_link_libraries(fftout3 /usr/local/lib/libfftw3.a)
add_executable(fftout4
        fftout4.c
        )
target_link_libraries(fftout4 /usr/local/lib/libfftw3.a)
add_executable(make_whitenoise
        make_whitenoise.c
        )
target_link_libraries(make_whitenoise /usr/local/lib/libfftw3.a)
#unset(CMAKE_C_FLAGS)
#################################### fftw3 ####################################

#################################### portaudio ####################################
set(CMAKE_C_FLAGS "-lm /usr/local/Cellar/portaudio/19.6.0/lib/libportaudio.a -framework CoreAudio -framework AudioToolbox -framework AudioUnit -framework CoreServices")
#unset(CMAKE_C_FLAGS )
add_executable(2chplay
        2chplay.c
        )
target_link_libraries(2chplay /usr/local/Cellar/portaudio/19.6.0/lib/libportaudio.a)
add_executable(2chplay2
        2chplay2.c
        )
target_link_libraries(2chplay2 /usr/local/Cellar/portaudio/19.6.0/lib/libportaudio.a)
add_executable(monoplay
        monoplay.c
        )
target_link_libraries(monoplay /usr/local/Cellar/portaudio/19.6.0/lib/libportaudio.a)
add_executable(monoplay2
        monoplay2.c
        )
target_link_libraries(monoplay2 /usr/local/Cellar/portaudio/19.6.0/lib/libportaudio.a)
add_executable(monoplay_48k
        monoplay_48k.c
        )
target_link_libraries(monoplay_48k /usr/local/Cellar/portaudio/19.6.0/lib/libportaudio.a)
add_executable(monoplay_8kHz
        monoplay_8kHz.c
        )
target_link_libraries(monoplay_8kHz /usr/local/Cellar/portaudio/19.6.0/lib/libportaudio.a)
add_executable(monoplay_alter
        monoplay_alter.c
        )
target_link_libraries(monoplay_alter /usr/local/Cellar/portaudio/19.6.0/lib/libportaudio.a)
add_executable(monorecord
        monorecord.c
        )
target_link_libraries(monorecord /usr/local/Cellar/portaudio/19.6.0/lib/libportaudio.a)
add_executable(playrec_2ch_inPath
        playrec_2ch_inPath.c
        )
target_link_libraries(playrec_2ch_inPath /usr/local/Cellar/portaudio/19.6.0/lib/libportaudio.a)
add_executable(playrec_2ch_new_kai
        playrec_2ch_new_kai.c
        )
target_link_libraries(playrec_2ch_new_kai /usr/local/Cellar/portaudio/19.6.0/lib/libportaudio.a)
add_executable(playrec_mono
        playrec_mono.c
        )
target_link_libraries(playrec_mono /usr/local/Cellar/portaudio/19.6.0/lib/libportaudio.a)
add_executable(playrec_mono_inPath
        playrec_mono_inPath.c
        )
#target_link_libraries(playrec_mono_inPath /usr/local/Cellar/portaudio/19.6.0/lib/libportaudio.a)
#unset(CMAKE_C_FLAGS)
#################################### portaudio ####################################
