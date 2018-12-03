#include <stdio.h>
#include <stdlib.h>
#include "fileManager.h"

int main(int argc, char **argv) {
    countryStructPointer country = readFile("..//censo400k.csv");
    solution(country);
    int a = 10;
}