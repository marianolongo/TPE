#ifndef TPE_DEPARTMENT_H
#define TPE_DEPARTMENT_H

#include <stdio.h>

typedef struct departmentStruct* departmentStructPointer;

struct departmentStruct{
    int ocupation[4];
    int population;
    char name[128];
    int homes[];
};

departmentStructPointer newDepartment(const char name[128]);

void increaseDepartmentPopulation(departmentStructPointer department, int ocupation);

void increaseDepartmentHomesAmount(departmentStructPointer department);
#endif //TPE_DEPARTMENT_H
