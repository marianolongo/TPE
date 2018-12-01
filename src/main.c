#include <stdio.h>
#include <stdlib.h>
#include "provinceList.h"
#include "fileManager.h"


int main(int argc, char **argv) {
    countryStructPointer country = readFile("..\\censo2.csv");
    solution(country);
    int a = 10;
}