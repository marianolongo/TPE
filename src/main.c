#include <stdio.h>
#include <stdlib.h>
#include "provinceList.h"
#include "fileManager.h"


int main(int argc, char **argv) {
    provinceList proList = readFile("..\\censo1.csv");
    solution(proList);
}