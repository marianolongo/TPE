#ifndef TPE_FILEMANAGER_H
#define TPE_FILEMANAGER_H

#include <stdio.h>
#include "provinceList.h"

char* getField(char* line, int num);

provinceList readFile(char *fileName);

void solution(provinceList proList);

#endif //TPE_FILEMANAGER_H
