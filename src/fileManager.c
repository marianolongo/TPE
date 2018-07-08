#include <stdio.h>
#include <stdlib.h>
#include "fileManager.h"

provinceList readFile(char *fileName) {
    char *currentLineCenso[4];
    char *currentLineSup[2];
    provinceList proList = newProvinceList();
    FILE *censo = fopen(fileName, "r");
    FILE *superficies = fopen("..\\superficies.csv", "r");

    char line[100];
    char supLine[100];
    while (fgets(line, 100, censo)) {
        fgets(supLine, 100, superficies);
        for (int i = 0; i <= 3; ++i) {
            char *tmp = strdup(line);
            currentLineCenso[i] = getField(tmp, i + 1);
        }
        for (int j = 0; j <= 1; ++j) {
            char *aux = strdup(supLine);
            currentLineSup[j] = getField(aux, j + 1);
        }
        listElementProvince province = newProvince(currentLineCenso[3]);
        if (provinceBelongs(proList, province) == 1) { //Si la tiene
            province = searchProvince(proList, province);
            listElementDepartment department = newDepartment(currentLineCenso[2]);
            if (departmentBelongs(province->departments, department) == 1) { //Si la tiene
                department = searchDepartment(province->departments, department);
                increaseDepartmentPopulation(department, atoi(currentLineCenso[0]));
                increaseProvincePopulation(province);
                if(addHome(department,atoi(currentLineCenso[1])) == 1){ //Si agrego
                    increaseProvinceHomesAmount(province);
                }
            } else {
                insertDepartment(province->departments, department);
                increaseDepartmentPopulation(department, atoi(currentLineCenso[0]));
                increaseProvincePopulation(province);
                if(addHome(department,atoi(currentLineCenso[1])) == 1){ //Si agrego
                    increaseProvinceHomesAmount(province);
                }
            }
        } else {
            insertProvince(proList, province);
            listElementDepartment department = newDepartment(currentLineCenso[2]);
            if (departmentBelongs(province->departments, department) == 1) { //Si la tiene
                department = searchDepartment(province->departments, department);
                increaseDepartmentPopulation(department, atoi(currentLineCenso[0]));
                increaseProvincePopulation(province);
                if(addHome(department,atoi(currentLineCenso[1])) == 1){ //Si agrego
                    increaseProvinceHomesAmount(province);
                }
            } else {
                insertDepartment(province->departments, department);
                increaseDepartmentPopulation(department, atoi(currentLineCenso[0]));
                increaseProvincePopulation(province);
                if(addHome(department,atoi(currentLineCenso[1])) == 1){ //Si agrego
                    increaseProvinceHomesAmount(province);
                }
            }
//            printf("a");
        }
    }
    printf("a");

    for (int j = 0; j < listProvinceSize(proList); ++j) {
        provinceStructPointer province = getProvince(proList,j);
        printf("%i ", j);
        printf("%s ", province->name);
        printf("%i ", province->homes);
        printf("%i ", province->population);
        printf("%i\n", province->surface);
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