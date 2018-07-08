#ifndef TPE_PROVINCE_H
#define TPE_PROVINCE_H

#include "departmentList.h"
typedef struct provinceStruct* provinceStructPointer;

struct provinceStruct{
    char name[128];
    int population;
    departmentList departments;
    int homes;
    int surface;
};

provinceStructPointer newProvince(const char name[128]);

void increaseProvincePopulation(provinceStructPointer province);

void increaseProvinceHomesAmount(provinceStructPointer province);

void getSurface(provinceStructPointer province, char *name, int surface);
#endif //TPE_PROVINCE_H
