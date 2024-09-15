cmake_minimum_required(VERSION 3.29)
project(prac_1 C)

set(CMAKE_C_STANDARD 11)

add_executable(prac_1
    matrix_multiplication.c)

add_executable(threading
        threading.c)

#threading.c
add_executable(row_wise row_wise_multithreading.c)
