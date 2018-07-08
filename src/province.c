#include <stdio.h>
#include <stdlib.h>
#include "province.h"

provinceStructPointer newProvince(const char name[128]){
    provinceStructPointer pro = calloc(1, sizeof(struct provinceStructPointer));
    strcpy(pro->name,name);
    return pro;
}
