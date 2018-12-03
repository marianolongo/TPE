#include <stdio.h>
#include <stdlib.h>
#include "fileManager.h"

int main(int argc, char *argv[]) {
    countryStructPointer country;
    if(argc > 1){
    country = readFile(argv[1]);
    }
    else{
        country = readFile("..//censo1.csv");
    }
    if(country == NULL){
        return 1;
    }
    solution(country);
    return 0;
}