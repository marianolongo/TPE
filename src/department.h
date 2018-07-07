#ifndef TPE_DEPARTMENT_H
#define TPE_DEPARTMENT_H

typedef struct departmentStruct* departmentStructPointer;

struct departmentStruct{
    int ocupation[4];
    int population;
    char name[128];
};

departmentStructPointer newDepartment(const char name[128]);

void increasePopulation(departmentStructPointer department, int ocupation);

#endif //TPE_DEPARTMENT_H
