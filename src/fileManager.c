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
        for (int i = 0; i <= 3; ++i) {
            tmp = strdup(line);
            currentLineCenso[i] = getField(tmp, i + 1);

        }

        listElementProvince province = newProvince(currentLineCenso[3]);

        insertProvince(proList, province);
        province = searchProvince(proList, province);
            listElementDepartment department = newDepartment(currentLineCenso[2]);
            if (departmentBelongs(province->departments, department) == 1) { //Si la tiene
                department = searchDepartment(province->departments, department);
                increaseDepartmentPopulation(department, atoi(currentLineCenso[0]));
                increaseProvincePopulation(province);
                toBeginDepartmentList(province->departments);
                if(addHome(department,atoi(currentLineCenso[1])) == 1){ //Si agrego
                    increaseProvinceHomesAmount(province);
                    increaseCountryHomes(country);
                }
            } else {
                insertDepartment(province->departments, department);
                increaseDepartmentPopulation(department, atoi(currentLineCenso[0]));
                increaseProvincePopulation(province);
                toBeginDepartmentList(province->departments);
                if(addHome(department,atoi(currentLineCenso[1])) == 1){ //Si agrego
                    increaseProvinceHomesAmount(province);
                    increaseCountryHomes(country);
                }
            }
        increseCountryPopulation(country);
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

    fprintf(countryFile,"%d,%d,%d",country->population,listProvinceSize(country->provinces), country->homes);
//    int amountOfCountries = 0;
    if(departments == NULL ||provinces == NULL ||countryFile == NULL){
        printf("Could not create .csv");
    }

    listElementProvince province = nextProvince(country->provinces);
    listElementDepartment department = nextDepartment(province->departments);
    while(hasNextProvince(country->provinces) == 1){ //Mientras la tenga
        while(hasNextDepartment(province->departments)){
            char *name = department->name;
            char *nameProvince = province->name;
            int populationDepartment = department->population;
            fprintf(departments, "%s,%s,%d\n",nameProvince,name,populationDepartment);
            department = nextDepartment(province->departments);
        }

        char *name = province->name;
        int population = province->population;
        int housing = province->homes;
//        amountOfCountries ++;
        fprintf(provinces,"%s,%d,%d\n",name,population,housing);
        deleteProvince(country->provinces,province);
        province = nextProvince(country->provinces);
    }
    char *departmentName = department->name;
    char *nameProvince = province->name;
    int populationDepartment = department->population;
    fprintf(departments, "%s,%s,%d\n",nameProvince,departmentName,populationDepartment);
    char *name = province->name;
    int population = province->population;
    int housing = province->homes;
//    amountOfCountries ++;
    fprintf(provinces,"%s,%d,%d\n",name,population,housing);

    fclose(countryFile);
    fclose(provinces);
    fclose(departments);
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