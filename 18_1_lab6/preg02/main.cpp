#include "Funciones-Preg01.h"
#include "Funciones-Preg02.h"

int main(int argc, char** argv) {
    void* usuarios;
    leerUsuarios(usuarios);
    imprimirUsuarios(usuarios);
    leerPrestamos(usuarios);
    imprimirPrestamos(usuarios);
    return 0;
}