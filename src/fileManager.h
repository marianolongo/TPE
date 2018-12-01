#ifndef TPE_FILEMANAGER_H
#define TPE_FILEMANAGER_H

#include <stdio.h>
#include "country.h"

char* getField(char* line, int num);

countryStructPointer readFile(char *fileName);

void solution(countryStructPointer country);

#endif //TPE_FILEMANAGER_H
