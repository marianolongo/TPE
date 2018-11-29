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
    while(fgets(supLine, 100, superficies)){
        char *aux = malloc(sizeof(char));
        for (int i = 0; i <= 1; ++i) {
            aux = strdup(supLine);
            currentLineSup[i] = getField(aux, i + 1);
        }
        provinceStructPointer province = newProvince(currentLineSup[0]);
        province->surface = atoi(currentLineSup[1]);
        toBeginProvinceList(proList);
        insertProvince(proList,province);
        free(aux);
    }
    while (fgets(line, 100, censo)) {
        char *tmp = malloc(sizeof(char));
        for (int i = 0; i <= 3; ++i) {
            tmp = strdup(line);
            currentLineCenso[i] = getField(tmp, i + 1);
        }
        listElementProvince province = newProvince(currentLineCenso[3]);
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
//            printf("a");
        free(tmp);
    }
//    printf("a");
//
//    for (int j = 0; j < listProvinceSize(proList); ++j) {
//        provinceStructPointer province = getProvince(proList,j);
//        printf("%i ", j);
//        printf("%s ", province->name);
//        printf("%i ", province->homes);
//        printf("%i ", province->population);
//        printf("%i\n", province->surface);
//    }
    return proList;
}

void solution(provinceList proList) {
    FILE *country = fopen("Pais.csv", "a");
    FILE *provinces = fopen("Provincia.csv", "a");
    FILE *departments = fopen("Departamento.csv", "w");

    if(departments == NULL ||provinces == NULL ||country == NULL){
        printf("NO");
    }

    listElementProvince province = getProvince(proList,0);
    listElementDepartment department = getDepartment(province->departments,0);
    while(hasNextProvince(proList) == 1){ //Mientras la tenga
        while(hasNextDepartment(province->departments)){
            char *name = department->name;
            fprintf(departments,name);
            department = nextDepartment(province->departments);
        }
        deleteProvince(proList,province);
        province = nextProvince(proList);
    }
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