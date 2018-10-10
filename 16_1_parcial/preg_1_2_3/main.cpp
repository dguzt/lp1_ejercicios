#include <iostream>
#include "entradaYsalida.h"
#include "ordenacion.h"

int main(int argc, char** argv) {
    void *contribuyentes;
    leerDatos(contribuyentes);
    ordenarDatos(contribuyentes);
    reporte(contribuyentes);
    return 0;
}