#include <iostream>
#include "../pregunta_2/Funciones-Preg01.h"


int main(int argc, char** argv) {
    int* codigoUs; char** nombreUs;
    leerUsuarios(codigoUs,nombreUs);
    imprimirUsuarios(codigoUs,nombreUs);
    return 0;
}
