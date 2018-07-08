#ifndef TPE_DEPARTMENT_H
#define TPE_DEPARTMENT_H

#include <stdio.h>
#include "homeList.h"


typedef struct departmentStruct *departmentStructPointer;

struct departmentStruct{
    int ocupation[4];
    int population;
    char name[128];
    homeList homes;
};

departmentStructPointer newDepartment(const char name[128]);

void increaseDepartmentPopulation(departmentStructPointer department, int ocupation);

int addHome(departmentStructPointer department, listElementHome home);
#endif //TPE_DEPARTMENT_H
