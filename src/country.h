#ifndef TPE_COUNTRY_H
#define TPE_COUNTRY_H

#include "provinceList.h"
typedef struct countryStruct* countryStructPointer;
struct countryStruct{
    provinceList provinces;
    int population;
    int homes;
};

countryStructPointer newCountry(provinceList pro);

void increseCountryPopulation(countryStructPointer country);

void increaseCountryHomes(countryStructPointer country);

int getCountryHomeAmount(countryStructPointer country);
#endif //TPE_COUNTRY_H
