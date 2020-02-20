cmake_minimum_required(VERSION 3.15)
project(pft_master C)

set(CMAKE_C_STANDARD 11)

include_directories(src)

add_executable(pft_master
        configurations/42fc/unit_tests.42fc.c
        src/help.c
        src/help.h
        src/help_conf.c
        src/history.c
        src/main.c
        src/options.c
        src/print.c
        src/show_disabled_postprocess.c
        src/test.c
        src/test.h
        src/unit_tests_indexed.c
        src/utils.c
        unit_tests.c)
