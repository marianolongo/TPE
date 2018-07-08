#include <stdio.h>
#include <stdlib.h>
#include "provinceList.h"
#include "fileManager.h"

int main(int argc, char **argv) {
    char *currentLine[4];
    provinceList proList = newProvinceList();
    FILE *file = fopen("..\\censo2.csv", "r");

    char line[100];
    while (fgets(line, 100, file)) {
        for (int i = 0; i <= 3; ++i) {
            char *tmp = strdup(line);
            currentLine[i] = getField(tmp, i + 1);
        }
        listElementProvince province = newProvince(currentLine[3]);
        if (provinceBelongs(proList, province) == 1) { //Si la tiene
            province = searchProvince(proList,province);
            listElementDepartment department = newDepartment(currentLine[2]);
            if (departmentBelongs(province->departments, department) == 1) { //Si la tiene
                department = searchDepartment(province->departments,department);
                increaseDepartmentPopulation(department, atoi(currentLine[0]));
                increaseProvincePopulation(province);
            } else {
                insertDepartment(province->departments, department);
                increaseDepartmentPopulation(department, atoi(currentLine[0]));
                increaseProvincePopulation(province);
            }
        } else {
            insertProvince(proList, province);
            listElementDepartment department = newDepartment(currentLine[2]);
            if (departmentBelongs(province->departments, department) == 1) { //Si la tiene
                department = searchDepartment(province->departments,department);
                increaseDepartmentPopulation(department, atoi(currentLine[0]));
                increaseProvincePopulation(province);
            } else {
                insertDepartment(province->departments, department);
                increaseDepartmentPopulation(department, atoi(currentLine[0]));
                increaseProvincePopulation(province);
            }
        }
//        printf("hello");
    }
            printf("hello");
//    for (int j = 0; j < listProvinceSize(proList); ++j) {
//        provinceStructPointer province = getProvince(proList,j);
//        printf("%i ", j);
//        printf("%s ", province->name);
//        printf("%i\n", province->population);
//    }
}