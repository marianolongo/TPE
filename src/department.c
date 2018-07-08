#include <stdlib.h>
#include <mem.h>
#include <stdio.h>
#include "department.h"

departmentStructPointer newDepartment(const char name[128]){
    departmentStructPointer dep = calloc(1, sizeof(struct departmentStruct));
    strcpy(dep->name , name);
    return dep;
}

void increaseDepartmentPopulation(departmentStructPointer department, int ocupation){
    department->population++;
    department->ocupation[ocupation]++;
}