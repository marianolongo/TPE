#include <stdio.h>
#include <stdlib.h>
#include "country.h"

countryStructPointer newCountry(provinceList pro){
    countryStructPointer country = calloc(1, sizeof(struct countryStruct));
    country->homes = 0;
    country->population = 0;
    country->provinces = pro;
}

void increaseCountryPopulation(countryStructPointer country){
    country->population++;
}

void increaseCountryHomes(countryStructPointer country){
    country->homes++;
}

void freeCountry(countryStructPointer country){
    freeProvinceList(country->provinces);
    free(country);
}