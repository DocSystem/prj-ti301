cmake_minimum_required(VERSION 3.26)
project(prj_ti301 C)

set(CMAKE_C_STANDARD 11)

add_executable(prj_ti301
        main.c cell.h list.h cell.c list.c
        time_comparison.h
        time_comparison.c
        timer.c
        timer.h
        time_comparison.c
        contact.c
        contact.h
        event.c
        event.h
        agenda.c
        agenda.h)
