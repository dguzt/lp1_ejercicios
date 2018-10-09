#include <iostream>
#include "Funciones-Preg01.h"
#include "Funciones-Preg02.h"

int main() {

    int   *codigoUs,  **stock ;
    char **nombreUs, ***libros;

    leerUsuarios(codigoUs,nombreUs);
    imprimirUsuarios(codigoUs,nombreUs);
    std::cout << "LECTURA DE LIBROS " << std::endl;
    leerLibros(libros,stock);
    imprimirLinea('*');
    imprimirLinea('*');
    imprimirLibros(libros,stock);
    return 0;
}