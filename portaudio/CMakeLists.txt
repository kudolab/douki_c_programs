cmake_minimum_required(VERSION 3.14)
project(douki_c_portaudio C)

set(CMAKE_C_STANDARD 11)

if(CMAKE_INSTALL_PREFIX_INITIALIZED_TO_DEFAULT)
    set(CMAKE_INSTALL_PREFIX $ENV{HOME}/local CACHE PATH "..." FORCE)
endif()

#################################### CHANGE HERE ####################################
set(portaudio_header "/usr/local/include")
set(libportaudio "/usr/local/Cellar/portaudio/19.6.0/lib/libportaudio.a")
#################################### CHANGE HERE ####################################

#################################### portaudio ####################################
set(CMAKE_C_FLAGS "-I ${portaudio_header} -lm ${libportaudio} -framework CoreAudio -framework AudioToolbox -framework AudioUnit -framework CoreServices")


add_executable(2chplay
        src/2chplay.c
        )
target_link_libraries(2chplay ${libportaudio})
add_executable(2chplay2
        src/2chplay2.c
        )
target_link_libraries(2chplay2 ${libportaudio})
add_executable(monoplay
        src/monoplay.c
        )
target_link_libraries(monoplay ${libportaudio})
add_executable(closed_loop_new
        src/closed_loop_new.c
        )
target_link_libraries(closed_loop_new ${libportaudio})
add_executable(monoplay2
        src/monoplay2.c
        )
target_link_libraries(monoplay2 ${libportaudio})
add_executable(monoplay_48k
        src/monoplay_48k.c
        )
target_link_libraries(monoplay_48k ${libportaudio})
add_executable(monoplay_8kHz
        src/monoplay_8kHz.c
        )
target_link_libraries(monoplay_8kHz ${libportaudio})
add_executable(monoplay_alter
        src/monoplay_alter.c
        )
target_link_libraries(monoplay_alter ${libportaudio})
add_executable(monorecord
        src/monorecord.c
        )
target_link_libraries(monorecord ${libportaudio})
add_executable(playrec_2ch_inPath
        src/playrec_2ch_inPath.c
        )
target_link_libraries(playrec_2ch_inPath ${libportaudio})
add_executable(playrec_2ch_new_kai
        src/playrec_2ch_new_kai.c
        )
target_link_libraries(playrec_2ch_new_kai ${libportaudio})
add_executable(playrec_mono
        src/playrec_mono.c
        )
target_link_libraries(playrec_mono ${libportaudio})
add_executable(playrec_mono_inPath
        src/playrec_mono_inPath.c
        )
target_link_libraries(playrec_mono_inPath ${libportaudio})
add_executable(playrec_multi
        src/playrec_multi.c
        )
target_link_libraries(playrec_multi ${libportaudio})

#################################### portaudio ####################################

set(portaudio_bin 2chplay 2chplay2 closed_loop_new monoplay monoplay2 monoplay_48k monoplay_8kHz monoplay_alter monorecord playrec_2ch_inPath playrec_2ch_new_kai playrec_mono playrec_mono_inPath)
INSTALL(TARGETS ${portaudio_bin} RUNTIME DESTINATION bin)
