#include <stdio.h>
#include <stdlib.h>
#include "fileManager.h"

provinceList readFile(char *fileName) {
    char *currentLine[4];
    provinceList proList = newProvinceList();
    FILE *file = fopen(fileName, "r");

    char line[100];
    while (fgets(line, 100, file)) {
        for (int i = 0; i <= 3; ++i) {
            char *tmp = strdup(line);
            currentLine[i] = getField(tmp, i + 1);
        }
        listElementProvince province = newProvince(currentLine[3]);
        if (provinceBelongs(proList, province) == 1) { //Si la tiene
            province = searchProvince(proList, province);
            listElementDepartment department = newDepartment(currentLine[2]);
            if (departmentBelongs(province->departments, department) == 1) { //Si la tiene
                department = searchDepartment(province->departments, department);
                increaseDepartmentPopulation(department, atoi(currentLine[0]));
                increaseProvincePopulation(province);
                if(addHome(department,atoi(currentLine[1])) == 1){ //Si agrego
                    increaseProvinceHomesAmount(province);
                }
            } else {
                insertDepartment(province->departments, department);
                increaseDepartmentPopulation(department, atoi(currentLine[0]));
                increaseProvincePopulation(province);
                if(addHome(department,atoi(currentLine[1])) == 1){ //Si agrego
                    increaseProvinceHomesAmount(province);
                }            }
        } else {
            insertProvince(proList, province);
            listElementDepartment department = newDepartment(currentLine[2]);
            if (departmentBelongs(province->departments, department) == 1) { //Si la tiene
                department = searchDepartment(province->departments, department);
                increaseDepartmentPopulation(department, atoi(currentLine[0]));
                increaseProvincePopulation(province);
                if(addHome(department,atoi(currentLine[1])) == 1){ //Si agrego
                    increaseProvinceHomesAmount(province);
                }            } else {
                insertDepartment(province->departments, department);
                increaseDepartmentPopulation(department, atoi(currentLine[0]));
                increaseProvincePopulation(province);
                if(addHome(department,atoi(currentLine[1])) == 1){ //Si agrego
                    increaseProvinceHomesAmount(province);
                }
            }
//            printf("a");
        }
    }

    for (int j = 0; j < listProvinceSize(proList); ++j) {
        provinceStructPointer province = getProvince(proList,j);
        printf("%i ", j);
        printf("%s ", province->name);
        printf("%i ", province->homes);
        printf("%i\n", province->population);
    }
    return proList;
}

void solution(provinceList list) {

}

char *getField(char *line, int num) {
    char* tok;
    for (tok = strtok(line, ",");
         tok && *tok;
         tok = strtok(NULL, ",\n"))
    {
        if (!--num)
            return tok;
    }
    return NULL;
}
