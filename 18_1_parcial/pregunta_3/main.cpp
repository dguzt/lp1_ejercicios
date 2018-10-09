#include <iostream>
#include "Funciones-Preg01.h"
#include "Funciones-Preg02.h"
#include "Funciones-Preg03.h"

int main(int argc, char** argv) {
    int *codigosU, **stocksL, *tamP;
    char **nombresU, ***librosL, ****prestamosP;

    leerUsuarios(codigosU,nombresU);
    imprimirUsuarios(codigosU,nombresU);

    leerLibros(librosL,stocksL);
    imprimirLibros(librosL,stocksL);

    tamP = registrarPrestamos(codigosU,prestamosP,librosL,stocksL);
    imprimirPrestamos(codigosU,nombresU,prestamosP);
    imprimirLibros(librosL,stocksL);

    return 0;
}