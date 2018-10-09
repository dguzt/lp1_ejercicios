//
// Created by jhair on 09/10/18.
//

#ifndef PREGUNTA_3_FUNCIONES_PREG03_H
#define PREGUNTA_3_FUNCIONES_PREG03_H

int* registrarPrestamos(int*&,char****&,char***&,int**&);
void imprimirPrestamos(int*&,char**&,char****&);

void leerDatosPrestamo(int&,char*,char*);
template <typename T>
int tamanioArreglo(T*&);
int posicionUsuario(int,int*&);
void registrarPrestamoUsuario(int,char****&,char*,char*,int*&);

#endif //PREGUNTA_3_FUNCIONES_PREG03_H
