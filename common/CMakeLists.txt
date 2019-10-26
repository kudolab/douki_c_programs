cmake_minimum_required(VERSION 3.14)
project(douki_c_common C)

set(CMAKE_C_STANDARD 11)

##################################### common ####################################
add_executable(biascut
        src/biascut.c
        )
add_executable(cosine_windowing
        src/cosine_windowing.c
        )
add_executable(cutout_anyfile
        src/cutout_anyfile.c
        )
add_executable(cutout_anyfile2
        src/cutout_anyfile2.c
        )
add_executable(douki_new
        src/douki_new.c
        )
add_executable(dv
        src/dv.c
        )
add_executable(equ_schroeder1
        src/equ_schroeder1.c
        )
add_executable(equ_schroeder2
        src/equ_schroeder2.c
        )
add_executable(equ_schroeder3
        src/equ_schroeder3.c
        )
add_executable(equ_schroeder4
        src/equ_schroeder4.c
        )
add_executable(equ_schroeder5
        src/equ_schroeder5.c
        )
add_executable(fatchdb
        src/fatchdb.c
        )
add_executable(FC_deviation
        src/FC_deviation.c
        )
add_executable(FC_deviation_alter
        src/FC_deviation_alter.c
        )
add_executable(fff
        src/fff.c
        )
#add_executable(fft
#        fft.c
#        )
add_executable(find_cutpoint
        src/find_cutpoint.c
        )
add_executable(henkan
        src/henkan.c
        )
#add_executable(ifft
#        ifft.c
#        )
add_executable(imp_add
        src/imp_add.c
        )
add_executable(imp_add_by10
        src/imp_add_by10.c
        )
add_executable(IMPmcode
        src/IMPmcode.c
        )
add_executable(inverse
        src/inverse.c
        )
add_executable(LE_1
        src/LE_1.c
        )
add_executable(linear_inpo_hrir_using_ATD
        src/linear_inpo_hrir_using_ATD.c
        )
add_executable(mono2LR
        src/mono2LR.c
        )
add_executable(peaking_filter
        src/peaking_filter.c
        )
add_executable(print_siglen
        src/print_siglen.c
        )
add_executable(random
        src/random.c
        )
#add_executable(Rev_sup
#        Rev_sup.c
#        )
add_executable(scaling_max_instant_amp
        src/scaling_max_instant_amp.c
        )
add_executable(sepach
        src/sepach.c
        )
add_executable(sinwave
        src/sinwave.c
        )
add_executable(timeconvo
        src/timeconvo.c
        )
add_executable(WAVtoDSB_osx
        src/WAVtoDSB_osx.c
        )
add_executable(zeropad_anyfile
        src/zeropad_anyfile.c
        )
##################################### common ####################################
