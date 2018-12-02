#ifndef TPE_PROVINCE_H
#define TPE_PROVINCE_H

#include "departmentList.h"
typedef struct provinceStruct* provinceStructPointer;

struct provinceStruct{
    char name[128];
    int population;
    departmentList departments;
    int homes;

};

provinceStructPointer newProvince(const char name[128]);

void increaseProvincePopulation(provinceStructPointer province);

void increaseProvinceHomesAmount(provinceStructPointer province);

void freeProvince(provinceStructPointer province);
#endif //TPE_PROVINCE_H
