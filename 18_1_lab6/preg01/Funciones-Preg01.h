//
// Created by jhair on 30/10/18.
//

#ifndef PREG01_FUNCIONES_PREG01_H
#define PREG01_FUNCIONES_PREG01_H


void leerUsuarios(void* &usuarios);
void leerDatosUsuario(int* &codigoU, char* &nombreU);
void almacenarDatosUsuario(void** usuariosStack, int* codigoU, char* nombreU, int cantU);


void imprimirUsuarios(void* usuarios);


template<typename T>
void arregloDinamico(T* &arrDinamic, T* arrStack, int cant);

void imprimirLinea(char='=');

#endif //PREG01_FUNCIONES_PREG01_H
