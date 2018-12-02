#include <stdio.h>
#include <stdlib.h>
#include "province.h"

provinceStructPointer newProvince(const char name[128]){
    provinceStructPointer pro = calloc(1, sizeof(struct provinceStruct));
    strcpy(pro->name,name);
    pro->departments = newDepartmentList();
    return pro;
}

void increaseProvincePopulation(provinceStructPointer province){
    province->population++;
}

void increaseProvinceHomesAmount(provinceStructPointer province){
    province->homes++;
}
