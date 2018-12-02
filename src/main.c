#include <stdio.h>
#include <stdlib.h>
#include "fileManager.h"

int main(int argc, char **argv) {
    countryStructPointer country = readFile("..//censo1.csv");
    solution(country);
    int a = 10;
}