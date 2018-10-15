#include <iostream>
#include "Bib_Func_Provincias.h"
#include "Biblioteca_Func_Incendios.h"
#include "Bib_Func_ExtraccionesF.h"

int main(int argc, char** argv) {
    char ***provincias, **especies;
    long int ***incendios;
    double ***extracciones;
    leerProvincias(provincias);
    imprimirProvincias(provincias);

    leerIncendios(incendios,provincias);
    imprimirIncendios(incendios,provincias);

    leerExtracciones(especies,extracciones);
    // imprimirExtracciones(especies, extracciones, provincias);
    return 0;
}