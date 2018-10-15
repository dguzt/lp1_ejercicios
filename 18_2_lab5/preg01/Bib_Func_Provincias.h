//
// Created by jhair on 14/10/18.
//

#ifndef PREG01_BIB_FUNC_PROVINCIAS_H
#define PREG01_BIB_FUNC_PROVINCIAS_H

void leerProvincias(char***&);
void imprimirProvincias(char***&);

void leerDatosProvincia(char*&,char*&,char*&,char*&);
char** generarProvincia(char*&,char*&,char*&,char*&);
void quicksortProvincias(char***&,int,int);
int dividirProvincias(char***&,int,int);
int compararCodigos(char**,char**);
int StringParseoInt(char*);
void imprimirArreglo(char***,int,int);

/* funciones auxiliares */
void imprimirLinea(char='=');
template <typename T>
void arregloDinamico(T*&,T*,int);

#endif //PREG01_BIB_FUNC_PROVINCIAS_H
