//
// Created by jhair on 09/10/18.
//

#ifndef PREGUNTA_4_FUNCIONES_PREG04_H
#define PREGUNTA_4_FUNCIONES_PREG04_H

void reporteYregistroDeSolicitudes(int*&,char**&,char****&,int*&,char***&,int**&);

void leerDatosSolicitud(char*,int&,char*,char&);
void imprimirCabeceraSolicitudes();
void procesarSolicitud(int&,char***&,int*&,char*,char*,char,char*,bool&);
void imprimirSolicitud(char*,char*&,char*,char,char*);

int posicionLibroPrestado(char*,char***&,int&);
int compararFechasStr(char*,char*);

void desapilarLibroPrestamo(int&,char***&,int);
void apilarLibroPrestamo(int&,char***&,char*,char*);

#endif //PREGUNTA_4_FUNCIONES_PREG04_H
