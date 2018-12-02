#include <stdio.h>
#include <stdlib.h>
#include "fileManager.h"
#if defined(unix) || defined(__unix__) || defined(__unix)
#define PATH
#else

#endif

int main(int argc, char **argv) {
    countryStructPointer country = readFile("..//censo2.csv");
    solution(country);
    int a = 10;
}