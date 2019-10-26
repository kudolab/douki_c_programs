cmake_minimum_required(VERSION 3.14)
project(douki_c_portaudio C)

set(CMAKE_C_STANDARD 11)

#################################### portaudio ####################################
set(CMAKE_C_FLAGS "-lm /usr/local/Cellar/portaudio/19.6.0/lib/libportaudio.a -framework CoreAudio -framework AudioToolbox -framework AudioUnit -framework CoreServices")


add_executable(2chplay
        src/2chplay.c
        )
target_link_libraries(2chplay /usr/local/Cellar/portaudio/19.6.0/lib/libportaudio.a)
add_executable(2chplay2
        src/2chplay2.c
        )
target_link_libraries(2chplay2 /usr/local/Cellar/portaudio/19.6.0/lib/libportaudio.a)
add_executable(monoplay
        src/monoplay.c
        )
target_link_libraries(monoplay /usr/local/Cellar/portaudio/19.6.0/lib/libportaudio.a)
add_executable(closed_loop_new
        src/closed_loop_new.c
        )
target_link_libraries(closed_loop_new /usr/local/Cellar/portaudio/19.6.0/lib/libportaudio.a)
add_executable(monoplay2
        src/monoplay2.c
        )
target_link_libraries(monoplay2 /usr/local/Cellar/portaudio/19.6.0/lib/libportaudio.a)
add_executable(monoplay_48k
        src/monoplay_48k.c
        )
target_link_libraries(monoplay_48k /usr/local/Cellar/portaudio/19.6.0/lib/libportaudio.a)
add_executable(monoplay_8kHz
        src/monoplay_8kHz.c
        )
target_link_libraries(monoplay_8kHz /usr/local/Cellar/portaudio/19.6.0/lib/libportaudio.a)
add_executable(monoplay_alter
        src/monoplay_alter.c
        )
target_link_libraries(monoplay_alter /usr/local/Cellar/portaudio/19.6.0/lib/libportaudio.a)
add_executable(monorecord
        src/monorecord.c
        )
target_link_libraries(monorecord /usr/local/Cellar/portaudio/19.6.0/lib/libportaudio.a)
add_executable(playrec_2ch_inPath
        src/playrec_2ch_inPath.c
        )
target_link_libraries(playrec_2ch_inPath /usr/local/Cellar/portaudio/19.6.0/lib/libportaudio.a)
add_executable(playrec_2ch_new_kai
        src/playrec_2ch_new_kai.c
        )
target_link_libraries(playrec_2ch_new_kai /usr/local/Cellar/portaudio/19.6.0/lib/libportaudio.a)
add_executable(playrec_mono
        src/playrec_mono.c
        )
target_link_libraries(playrec_mono /usr/local/Cellar/portaudio/19.6.0/lib/libportaudio.a)
add_executable(playrec_mono_inPath
        src/playrec_mono_inPath.c
        )

#################################### portaudio ####################################

set(portaudio_bin 2chplay 2chplay2 closed_loop_new monoplay monoplay2 monoplay_48k monoplay_8kHz monoplay_alter monorecord playrec_2ch_inPath playrec_2ch_new_kai playrec_mono playrec_mono_inPath)
INSTALL(TARGETS ${portaudio_bin} RUNTIME DESTINATION $HOME/bin)
