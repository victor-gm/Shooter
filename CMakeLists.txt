cmake_minimum_required(VERSION 3.16)
project(shooter_victor_garrido C)

set(CMAKE_C_STANDARD 11)

include_directories(.)
include_directories(ext2)
include_directories(fat16)
include_directories(io)
include_directories(utils)
include_directories(volume_manager)

add_executable(shooter_victor_garrido
        ext2/ext2.c
        ext2/ext2.h
        fat16/fat16.c
        fat16/fat16.h
        io/io.c
        io/io.h
        utils/utils.c
        utils/utils.h
        volume_manager/volume_manager.c
        volume_manager/volume_manager.h
        lib.h
        main.c)
