/*
 * Autor: Jhair Guzman
 * Codigo: 20163275
 * */
#include <iostream>
#include "Bib_Func_Provincias.h"

int main(int argc, char** argv) {
    char*** provincias;
    long int*** incendios;
    leerProvincias(provincias);
    imprimirProvincias(provincias);
    return 0;
}