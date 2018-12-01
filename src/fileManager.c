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
//                    toBeginHomeList(department->homes);
                }
            } else {
                insertDepartment(province->departments, department);
                increaseDepartmentPopulation(department, atoi(currentLineCenso[0]));
                increaseProvincePopulation(province);
                toBeginDepartmentList(province->departments);
                if(addHome(department,atoi(currentLineCenso[1])) == 1){ //Si agrego
                    increaseProvinceHomesAmount(province);
                    increaseCountryHomes(country);
//                    toBeginHomeList(department->homes);
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

//    fprintf(countryFile,"%d\n",1);
    int amountOfCountries = 0;
    if(departments == NULL ||provinces == NULL ||countryFile == NULL){
        printf("NO");
    }

//    listElementProvince province = getProvince(proList,0);
    listElementProvince province = nextProvince(country->provinces);
//    listElementDepartment department = getDepartment(province->departments,0);
    listElementDepartment department = nextDepartment(province->departments);
    while(hasNextProvince(country->provinces) == 1){ //Mientras la tenga
        while(hasNextDepartment(province->departments)){
            char *name = department->name;
            char *nameProvince = province->name;
            int *populationDepartment = department->population;
            fprintf(departments, "%s,%s,%d\n",nameProvince,name,populationDepartment);
            department = nextDepartment(province->departments);
        }

        char *name = province->name;
        int population = province->population;
        int housing = province->homes;
        amountOfCountries ++;
        fprintf(provinces,"%s,%d,%d\n",name,population,housing);
        deleteProvince(country->provinces,province);
        province = nextProvince(country->provinces);
    }
    char *departmentName = department->name;
    char *nameProvince = province->name;
    int *populationDepartment = department->population;
    fprintf(departments, "%s,%s,%d\n",nameProvince,departmentName,populationDepartment);
    char *name = province->name;
    int population = province->population;
    int housing = province->homes;
    amountOfCountries ++;
    fprintf(provinces,"%s,%d,%d\n",name,population,housing);
    fprintf(countryFile,"%d,%d,%d",country->population,country->homes,amountOfCountries);

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

//void create_marks_csv(char *filename,int a[][3],int n,int m){
//
////printf("\n Creating %s.csv file",filename);
//
//    FILE *fp;
//
//    int i,j;
//
//    filename=strcat(filename,".csv");
//
//    fp=fopen(filename,"a");
//
//    fprintf(fp,"Nombre De Provincia, Superficie total, Densidad de poblacion");
//
//    for(i=0;i<m;i++){
//
//        fprintf(fp,"\n%c",i+1);
//
//        for(j=0;j<n;j++)
//
//            fprintf(fp,",%c ",a[i][j]);// para que sea un string, las c hay que cambiarlas por s, pero no me funcaba igual
//            fputs(atoi(a[i][j]), fp);
//
//    }
//
//    fclose(fp);
//
//    printf("\n %sfile created",filename);
//
//}

//int main(){ //--> lo de aca obvio iria en la ufncion
//
//    int a[4][3]={{'c','a','s','l'},{'a','l','a','V'},{'h','l','k','k'}}; //--> aca es donde tengo qe hacer que recorra el coso
//
//    char str[100];
//
//
//    gets(str);
//
//    create_marks_csv(str,a,3,provincelist.size);
//
//    return 0;
//
//}