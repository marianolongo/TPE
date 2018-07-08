#include <stdio.h>
#include <stdlib.h>
#include "provinceList.h"
#include "fileManager.h"

int main(int argc, char **argv) {
    char *currentLine[4];
    provinceList proList = newProvinceList();
    FILE *file = fopen("..\\censo1.csv","r");

    char line[100];
    while (fgets(line, 100, file)) {
        for (int i = 0; i <= 3; ++i) {
            char* tmp = strdup(line);
            currentLine[i] = getField(tmp,i + 1);
        }
        listElementProvince province = newProvince(currentLine[3]);
        if(provinceBelongs(proList,province) == 1){ //Si la tiene
            listElementDepartment department = newDepartment(currentLine[2]);
            if(departmentBelongs(province->departments,department) == 1){ //Si la tiene
                increasePopulation(department,atoi(currentLine[0]));
            }
            else{
                insertDepartment(province->departments,department);
                increasePopulation(department,atoi(currentLine[0]));
            }
        }
        else{
            insertProvince(proList,province);
        }
//        departmentStructPointer department = newDepartment(currentLine[2]);
//        increasePopulation(department,(int)currentLine[0]);
    }
    printf("hello");
}