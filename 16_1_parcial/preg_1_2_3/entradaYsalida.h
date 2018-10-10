//
// Created by jhair on 10/10/18.
//

#ifndef PREG_1_2_3_ENTRADAYSALIDA_H
#define PREG_1_2_3_ENTRADAYSALIDA_H

void leerDatos(void*&);
void reporte(void*&);

/* Funciones para lectura de datos */
void leerDatosParte1(void*&,int&);
void leerDatosParte2(void*&,int&);
void leerDatosContribuyente(char*,char*,char*,char*,char*,int&);
char* stringPreciso(char*);
template <typename T>
T* numeroPreciso(T&);
void agregarContribuyente(void*&,int&,void**&);
int posicionContribuyente(char*,void*&,int);
template <typename T>
void aumentarArreglo(T*&,int,int);
bool stringsIguales(char*,char*);
/* Funciones para reporte */
void imprimirLinea(char='=');
void imprimirCabeceraReporte();
double lineaCreditoBanco(int,char*,double,char);
int    f(char*,char);
double h(int  ,char);

#endif //PREG_1_2_3_ENTRADAYSALIDA_H
