cmake_minimum_required(VERSION 3.10)
project(TPE C)

set(CMAKE_C_STANDARD 99)

add_executable(TPE src/main.c src/department.h src/department.c src/departmentList.c src/departmentList.h src/provinceList.h src/provinceList.c src/department.h src/department.c src/province.h src/province.c)