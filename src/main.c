#include <stdio.h>
#include <stdlib.h>
#include "fileManager.h"

int main(int argc, char **argv) {

    countryStructPointer country = readFile("/Users/user/CLionProjects/TPE-Marcelo/censo1.csv");
    solution(country);
    int a = 10;
}