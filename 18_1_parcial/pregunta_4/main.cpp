#include <iostream>
#include "Funciones-Preg01.h"
#include "Funciones-Preg02.h"
#include "Funciones-Preg03.h"
#include "Funciones-Preg04.h"

int main(int argc, char** argv) {
    int *codigosU, **stocksL, *tamanioP;
    char **nombresU, ***librosL, ****prestamosP;

    leerUsuarios(codigosU,nombresU);
    imprimirUsuarios(codigosU,nombresU);

    leerLibros(librosL,stocksL);
    imprimirLibros(librosL,stocksL);

    tamanioP = registrarPrestamos(codigosU,prestamosP,librosL,stocksL);
    imprimirPrestamos(codigosU,nombresU,prestamosP);
    imprimirLibros(librosL,stocksL);

    reporteYregistroDeSolicitudes(codigosU,nombresU,prestamosP,tamanioP,librosL,stocksL);
    imprimirPrestamos(codigosU,nombresU,prestamosP);
    imprimirLibros(librosL,stocksL);
    return 0;
}