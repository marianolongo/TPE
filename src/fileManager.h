#ifndef TPE_FILEMANAGER_H
#define TPE_FILEMANAGER_H

#include <stdio.h>
#include "provinceList.h"

char* getField(char* line, int num) {
    char* tok;
    for (tok = strtok(line, ",");
         tok && *tok;
         tok = strtok(NULL, ",\n"))
    {
        if (!--num)
            return tok;
    }
    return NULL;
}

provinceList readFile(provinceList list);

void solution(provinceList list);

#endif //TPE_FILEMANAGER_H
