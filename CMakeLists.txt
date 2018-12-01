cmake_minimum_required(VERSION 3.10)
project(TPE C)

set(CMAKE_C_STANDARD 99)

add_executable(TPE src/main.c src/department.h src/department.c src/departmentList.h src/departmentList.c src/province.h src/province.c src/provinceList.h src/provinceList.c src/fileManager.h src/fileManager.c src/homeList.c src/homeList.h src/country.h src/country.c)