#include <stdlib.h>
#include <mem.h>
#include <stdio.h>
#include "department.h"

departmentStructPointer newDepartment(const char name[128]){
    departmentStructPointer dep = calloc(1, sizeof(struct departmentStructPointer));
    strcpy(dep->name , name);
}

void increasePopulation(departmentStructPointer department, int ocupation){
    (department->population++);
    (department->ocupation[ocupation]++);
}