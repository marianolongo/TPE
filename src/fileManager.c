#include <stdio.h>
#include <stdlib.h>
#include "fileManager.h"
#define MAX_LINE_LENGTH 80

countryStructPointer readFile(char *fileName) {
    char *currentLineCenso[4];
    provinceList proList = newProvinceList();
    countryStructPointer country = newCountry(proList);
    FILE *censo = fopen(fileName, "r");

    char line[MAX_LINE_LENGTH];
    while (fgets(line, MAX_LINE_LENGTH, censo)) {
        char *tmp = malloc(sizeof(char));
        char* toFree = tmp;
        for (int i = 0; i <= 3; ++i) {
            tmp = strdup(line);
            currentLineCenso[i] = getField(tmp, i + 1);
        }
        free(toFree);
        //todo provincias desde otro txt
        listElementProvince province = newProvince(currentLineCenso[3]);
        insertProvince(proList, province);
        //todo arreglar esto:usar provincia original
        province = searchProvince(proList, province);

            listElementDepartment department = newDepartment(currentLineCenso[2]);
            //todo reemplazar belongs y get por get
            if (departmentBelongs(province->departments, department) == 1) { //Si la tiene
                department = searchDepartment(province->departments, department);
            }
            else insertDepartment(province->departments, department);

            increaseDepartmentPopulation(department, atoi(currentLineCenso[0]));
            increaseProvincePopulation(province);
            toBeginDepartmentList(province->departments);
            if(addHome(department, atoi(currentLineCenso[1])) == 1){ //Si agrego
                increaseProvinceHomesAmount(province);
                increaseCountryHomes(country);
            }

        increaseCountryPopulation(country);
        toBeginProvinceList(proList);

        free(tmp);
    }
//    for (int j = 0; j < listProvinceSize(proList); ++j) {
//        provinceStructPointer province = getProvince(proList,j);
//        printf("%i ", j);
//        printf("%s ", province->name);
//        printf("%i ", province->homes);
//        printf("%i ", province->population);
//        printf("\n");
//    }
    return country;
}

void solution(countryStructPointer country) {
    FILE *countryFile = fopen("Pais.csv", "w");
    FILE *provinces = fopen("Provincia.csv", "w");
    FILE *departments = fopen("Departamento.csv", "w");

    if(departments == NULL ||provinces == NULL ||countryFile == NULL){
        printf("Could not create .csv");
    }

    fprintf(countryFile,"%d,%d,%d",country->population,listProvinceSize(country->provinces), country->homes);

    listElementProvince province = nextProvince(country->provinces);
    listElementDepartment department;
    while(hasNextProvince(country->provinces) == 1){//Mientras la tenga
        department = nextDepartment(province->departments);
        while(hasNextDepartment(province->departments) == 1){
            fprintf(departments, "%s,%s,%d\n",province->name,department->name,department->population);
            deleteDepartment(province->departments, department);

            freeDepartment(department);

            department = nextDepartment(province->departments);
        }
        fprintf(departments, "%s,%s,%d\n",province->name,department->name,department->population);
        fprintf(provinces,"%s,%d,%d\n",province->name,province->population,province->homes);
        deleteProvince(country->provinces,province);

        freeProvince(province);

        province = nextProvince(country->provinces);
    }
    department = nextDepartment(province->departments);
    while(hasNextDepartment(province->departments) == 1){
        fprintf(departments, "%s,%s,%d\n",province->name,department->name,department->population);
        deleteDepartment(province->departments, department);

        freeDepartment(department);

        department = nextDepartment(province->departments);
    }
    fprintf(departments, "%s,%s,%d\n",province->name,department->name,department->population);
    fprintf(provinces,"%s,%d,%d\n",province->name,province->population,province->homes);
    freeProvince(province);
    deleteProvince(country->provinces, province);

    freeCountry(country);

    fclose(countryFile);
    fclose(provinces);
    fclose(departments);
}

char *getField(char *line, int num) {
    char* tok;
    for (tok = strtok(line, ","); tok && *tok; tok = strtok(NULL, ",\n"))
    {
        if (!--num) {
            return tok;
        }
    }
    return NULL;
}