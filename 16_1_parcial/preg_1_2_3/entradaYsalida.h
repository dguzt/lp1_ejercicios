//
// Created by jhair on 10/10/18.
//

#ifndef PREG_1_2_3_ENTRADAYSALIDA_H
#define PREG_1_2_3_ENTRADAYSALIDA_H

void leerDatos(void*&);
void reporte(void*&);

void leerDatosContribuyente(char*,char*,char*,char*,char*,int&);
char* stringPreciso(char*);
template <typename T>
T* numeroPreciso(T&);
void agregarContribuyente(void*&,int&,void**&);
template <typename T>
void aumentarArreglo(T*&,int,int);
void imprimirLinea(char='=');
#endif //PREG_1_2_3_ENTRADAYSALIDA_H
