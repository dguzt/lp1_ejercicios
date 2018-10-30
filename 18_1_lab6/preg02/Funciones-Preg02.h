//
// Created by jhair on 30/10/18.
//

#ifndef PREG02_FUNCIONES_PREG02_H
#define PREG02_FUNCIONES_PREG02_H


void leerPrestamos(void* &usuarios);
void inicializarCantLibrosxUsuario(void* &usuarios);
void leerDatosPrestamo(int &codigoU, char* &codigoL, char* &fechaD);
int posicionUsuario(void* usuarios, int codigoU);
void almacenarDatos(void* &usuario, char* &codigoLibro, char* &fechaDev);

void imprimirPrestamos(void* usuarios);

template <typename T>
int tamanioArreglo(T* arreglo);

template<typename T>
void aumentarArreglo(T* arreglo, int cantidad, int aumento);

#endif //PREG02_FUNCIONES_PREG02_H
