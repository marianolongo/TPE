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

void addDepartmentToList(provinceStructPointer province, departmentStructPointer department);

void increaseProvincePopulation(provinceStructPointer province);

#endif //TPE_PROVINCE_H
