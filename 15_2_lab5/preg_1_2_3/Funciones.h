//
// Created by jhair on 12/10/18.
//

#ifndef PREG_1_2_3_FUNCIONES_H
#define PREG_1_2_3_FUNCIONES_H

void leerCursos(void*&);
void leerMatricula(void*&);
void imprimirListasDeClase(void*&);

void guardarCurso(void***,char*,char*,int&);
void cursosMemoriaDinamica(void*&,void*,int);
void imprimirCursos(void*&,int);
void actualizarCursos(void***&);
void ignorarEspacios();
int posicionCurso(void*&,char*);
void agregarAlumno(void**&,int,char*,int&);
void imprimirAlumnosxCursos(void*&);

template <typename T>
int tamArreglo(T*);
void imprimirLinea(char='=');
template <typename T>
void aumentarArreglo(T*&,int,int);

#endif //PREG_1_2_3_FUNCIONES_H
