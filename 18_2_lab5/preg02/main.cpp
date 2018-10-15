#include <iostream>
#include "Bib_Func_Provincias.h"
#include "Biblioteca_Func_Incendios.h"

int main() {
    char*** provincias;
    long int*** incendios;
    leerProvincias(provincias);
    imprimirProvincias(provincias);
    leerIncendios(incendios,provincias);
    imprimirIncendios(incendios,provincias);
    return 0;
}