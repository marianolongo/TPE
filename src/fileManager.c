#include <stdio.h>
#include <stdlib.h>
#include "fileManager.h"

provinceList readFile(provinceList list){
    int i = 0;
    const char *currentLine[4];

    FILE *file = fopen("..\\censo1.csv","r");
    char line[100];
    while (fgets(line,99,file)) {
        char* tmp = strdup(line);
        currentLine[i] = getField(tmp, i);
        printf(currentLine[i]);
        free(tmp);
        i++;
    }
}

void test(char file[]){

}

void solution(provinceList list){

}