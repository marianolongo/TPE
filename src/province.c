#include <stdio.h>
#include <stdlib.h>
#include "province.h"

provinceStructPointer newProvince(const char name[128]){
    provinceStructPointer pro = calloc(1, sizeof(struct provinceStruct));
    strcpy(pro->name,name);
    pro->departments = calloc(1, sizeof(struct departmentStruct));
    return pro;
}

void addDepartmentToList(provinceStructPointer province, departmentStructPointer department){
    if(departmentBelongs(province->departments,department) == 0) { //Si la tiene
        insertDepartment(province->departments, department);
    }
}

void increaseProvincePopulation(provinceStructPointer province){
    province->population++;
}
