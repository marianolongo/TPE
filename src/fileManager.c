#include <stdio.h>
#include <stdlib.h>
#include "fileManager.h"
#define MAX_LINE_LENGTH 80
#define COLUMN_AMOUNT 4

countryStructPointer readFile(char *fileName) {
    char *currentLineCenso[COLUMN_AMOUNT];
    provinceList proList = newProvinceList();
    countryStructPointer country = newCountry(proList);
    FILE *censo = fopen(fileName, "r");

    char line[MAX_LINE_LENGTH];
    while (fgets(line, MAX_LINE_LENGTH, censo)) {
        char *tmp = malloc(sizeof(char));
        for (int i = 0; i < COLUMN_AMOUNT; ++i) {
            tmp = strdup(line);
            currentLineCenso[i] = getField(tmp, i + 1);
        }

        listElementProvince province = newProvince(currentLineCenso[3]);
        insertProvince(proList, province);
        province = searchProvince(proList, province);
        toBeginProvinceList(proList);

        listElementDepartment department = newDepartment(currentLineCenso[2]);
        insertDepartment(province->departments, department);
        department = searchDepartment(province->departments, department);
        toBeginDepartmentList(province->departments);

        increaseDepartmentPopulation(department, atoi(currentLineCenso[0]));
        increaseProvincePopulation(province);

        int home = atoi(currentLineCenso[1]);
        if(insertHome(department->homes, home) == 1){
            increaseProvinceHomesAmount(province);
            increaseCountryHomes(country);
        }
        toBeginHomeList(department->homes);
        increaseCountryPopulation(country);

        free(tmp);
    }
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
    while(hasNextProvince(country->provinces) == 1){ //Mientras la tenga
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