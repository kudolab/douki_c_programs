cmake_minimum_required(VERSION 3.14)
project(douki_c_programs C)

set(CMAKE_C_STANDARD 11)
#set(all_bin "FC_deviation FC_deviation_alter IMPmcode LE_1 WAVtoDSB_osx biascut cosine_windowing cutout_anyfile cutout_anyfile2 douki_new dv equ_schroeder1 equ_schroeder2 equ_schroeder3 equ_schroeder4 equ_schroeder5 fatchdb fff find_cutpoint henkan imp_add imp_add_by10 inverse linear_inpo_hrir_using_ATD mono2LR peaking_filter print_siglen random scaling_max_instant_amp sepach sinwave timeconvo zeropad_anyfile fftout2 fftout3 fftout4 make_whitenoise 2chplay 2chplay2 closed_loop_new monoplay monoplay2 monoplay_48k monoplay_8kHz monoplay_alter monorecord playrec_2ch_inPath playrec_2ch_new_kai playrec_mono playrec_mono_inPath")
#set(all_lib "umasig")
#INSTALL(TARGETS ${all_bin} RUNTIME DESTINATION $HOME/bin)
#INSTALL(TARGETS ${all_lib} RUNTIME DESTINATION $HOME/lib)
#message(${all_bin})
#message(${all_lib})


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

###################################### common ####################################
#add_executable(biascut
#        common/src/biascut.c
#        )
#add_executable(closed_loop_new
#        common/src/closed_loop_new.c
#        )
#add_executable(cosine_windowing
#        common/src/cosine_windowing.c
#        )
#add_executable(cutout_anyfile
#        common/src/cutout_anyfile.c
#        )
#add_executable(cutout_anyfile2
#        common/src/cutout_anyfile2.c
#        )
#add_executable(douki_new
#        common/src/douki_new.c
#        )
#add_executable(dv
#        common/src/dv.c
#        )
#add_executable(equ_schroeder1
#        common/src/equ_schroeder1.c
#        )
#add_executable(equ_schroeder2
#        common/src/equ_schroeder2.c
#        )
#add_executable(equ_schroeder3
#        common/src/equ_schroeder3.c
#        )
#add_executable(equ_schroeder4
#        common/src/equ_schroeder4.c
#        )
#add_executable(equ_schroeder5
#        common/src/equ_schroeder5.c
#        )
#add_executable(fatchdb
#        common/src/fatchdb.c
#        )
#add_executable(FC_deviation
#        common/src/FC_deviation.c
#        )
#add_executable(FC_deviation_alter
#        common/src/FC_deviation_alter.c
#        )
#add_executable(fff
#        common/src/fff.c
#        )
##add_executable(fft
##        fft.c
##        )
##add_executable(FileLib_osx
##        FileLib_osx.c
##        )
#add_executable(find_cutpoint
#        common/src/find_cutpoint.c
#        )
#add_executable(henkan
#        common/src/henkan.c
#        )
##add_executable(ifft
##        ifft.c
##        )
#add_executable(imp_add
#        common/src/imp_add.c
#        )
#add_executable(imp_add_by10
#        common/src/imp_add_by10.c
#        )
#add_executable(IMPmcode
#        common/src/IMPmcode.c
#        )
#add_executable(inverse
#        common/src/inverse.c
#        )
#add_executable(LE_1
#        common/src/LE_1.c
#        )
#add_executable(linear_inpo_hrir_using_ATD
#        common/src/linear_inpo_hrir_using_ATD.c
#        )
#add_executable(mono2LR
#        common/src/mono2LR.c
#        )
#add_executable(peaking_filter
#        common/src/peaking_filter.c
#        )
#add_executable(print_siglen
#        common/src/print_siglen.c
#        )
#add_executable(random
#        common/src/random.c
#        )
##add_executable(Rev_sup
##        Rev_sup.c
##        )
#add_executable(scaling_max_instant_amp
#        common/src/scaling_max_instant_amp.c
#        )
#add_executable(sepach
#        common/src/sepach.c
#        )
#add_executable(sinwave
#        common/src/sinwave.c
#        )
#add_executable(timeconvo
#        common/src/timeconvo.c
#        )
#add_executable(WAVtoDSB_osx
#        common/src/WAVtoDSB_osx.c
#        )
#add_executable(zeropad_anyfile
#        common/src/zeropad_anyfile.c
#        )
###################################### common ####################################

##################################### fftw3 ####################################
##set(CMAKE_C_FLAGS "-lm /usr/local/lib/libfftw3.a")
#add_executable(fftout2
#        fftw/src/fftout2.c
#        )
#target_link_libraries(fftout2 /usr/local/lib/libfftw3.a)
#add_executable(fftout3
#        fftw/src/fftout3.c
#        )
#target_link_libraries(fftout3 /usr/local/lib/libfftw3.a)
#add_executable(fftout4
#        fftw/src/fftout4.c
#        )
#target_link_libraries(fftout4 /usr/local/lib/libfftw3.a)
#add_executable(make_whitenoise
#        fftw/src/make_whitenoise.c
#        )
#target_link_libraries(make_whitenoise /usr/local/lib/libfftw3.a)
##unset(CMAKE_C_FLAGS)
##################################### fftw3 ####################################

##################################### portaudio ####################################
#set(CMAKE_C_FLAGS "-lm /usr/local/Cellar/portaudio/19.6.0/lib/libportaudio.a -framework CoreAudio -framework AudioToolbox -framework AudioUnit -framework CoreServices")
##unset(CMAKE_C_FLAGS )
#add_executable(2chplay
#        portaudio/src/2chplay.c
#        )
#target_link_libraries(2chplay /usr/local/Cellar/portaudio/19.6.0/lib/libportaudio.a)
#add_executable(2chplay2
#        portaudio/src/2chplay2.c
#        )
#target_link_libraries(2chplay2 /usr/local/Cellar/portaudio/19.6.0/lib/libportaudio.a)
#add_executable(monoplay
#        portaudio/src/monoplay.c
#        )
#target_link_libraries(monoplay /usr/local/Cellar/portaudio/19.6.0/lib/libportaudio.a)
#add_executable(monoplay2
#        portaudio/src/monoplay2.c
#        )
#target_link_libraries(monoplay2 /usr/local/Cellar/portaudio/19.6.0/lib/libportaudio.a)
#add_executable(monoplay_48k
#        portaudio/src/monoplay_48k.c
#        )
#target_link_libraries(monoplay_48k /usr/local/Cellar/portaudio/19.6.0/lib/libportaudio.a)
#add_executable(monoplay_8kHz
#        portaudio/src/monoplay_8kHz.c
#        )
#target_link_libraries(monoplay_8kHz /usr/local/Cellar/portaudio/19.6.0/lib/libportaudio.a)
#add_executable(monoplay_alter
#        portaudio/src/monoplay_alter.c
#        )
#target_link_libraries(monoplay_alter /usr/local/Cellar/portaudio/19.6.0/lib/libportaudio.a)
#add_executable(monorecord
#        portaudio/src/monorecord.c
#        )
#target_link_libraries(monorecord /usr/local/Cellar/portaudio/19.6.0/lib/libportaudio.a)
#add_executable(playrec_2ch_inPath
#        portaudio/src/playrec_2ch_inPath.c
#        )
#target_link_libraries(playrec_2ch_inPath /usr/local/Cellar/portaudio/19.6.0/lib/libportaudio.a)
#add_executable(playrec_2ch_new_kai
#        portaudio/src/playrec_2ch_new_kai.c
#        )
#target_link_libraries(playrec_2ch_new_kai /usr/local/Cellar/portaudio/19.6.0/lib/libportaudio.a)
#add_executable(playrec_mono
#        portaudio/src/playrec_mono.c
#        )
#target_link_libraries(playrec_mono /usr/local/Cellar/portaudio/19.6.0/lib/libportaudio.a)
#add_executable(playrec_mono_inPath
#        portaudio/src/playrec_mono_inPath.c
#        )
##target_link_libraries(playrec_mono_inPath /usr/local/Cellar/portaudio/19.6.0/lib/libportaudio.a)
##unset(CMAKE_C_FLAGS)
##################################### portaudio ####################################
