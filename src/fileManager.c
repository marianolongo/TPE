#include <stdio.h>
#include <stdlib.h>
#include "fileManager.h"


const char* getField(char* line, int num) {
    const char* tok;
    for (tok = strtok(line, ",");
         tok && *tok;
         tok = strtok(NULL, ",\n"))
    {
        if (!--num)
            return tok;
    }
    return NULL;
}

provinceList readFile(provinceList list, char file[]){

}

void solution(provinceList list){

    FILE *censo = fopen("..\\censo2.csv","r");
    if(censo == NULL){
        printf("File not found");
        exit(1);
    }

    char line[100];
    while (fgets(line, 100, censo)) {
        char* tmp = strdup(line);
        listElementProvince province = newProvince(getField(tmp, 4));
        insertProvince(list,province)
        free(tmp);
    }
}