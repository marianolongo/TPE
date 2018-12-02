#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "department.h"

departmentStructPointer newDepartment(const char name[128]){
    departmentStructPointer dep = calloc(1, sizeof(struct departmentStruct));
    strcpy(dep->name , name);
    dep->homes = newHomeList();
    toBeginHomeList(dep->homes);
    return dep;
}

void increaseDepartmentPopulation(departmentStructPointer department, int ocupation){
    department->population++;
    department->ocupation[ocupation]++;
}

int addHome(departmentStructPointer department, listElementHome home){
    if(homeBelongs(department->homes,home) == 0){ //Si no la tiene
        insertHome(department->homes,home);
        return 1;
    }
    return 0;
}