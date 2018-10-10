//
// Created by jhair on 09/10/18.
//

#ifndef PREGUNTA_3_FUNCIONES_PREG03_H
#define PREGUNTA_3_FUNCIONES_PREG03_H

int* registrarPrestamos(int*&,char****&,char***&,int**&);
void imprimirPrestamos(int*&,char**&,char****&);

void leerDatosPrestamo(int&,char*,char*);
void reducirStock(char*,char***&,int**&);
template <typename T>
int tamanioArreglo(T*&);
int posicionUsuario(int,int*&);
void registrarPrestamoUsuario(int,char****&,char*,char*,int*&);

int posicionLibro(char*,char***&);
bool stringsIguales(char*,char*);

#endif //PREGUNTA_3_FUNCIONES_PREG03_H
