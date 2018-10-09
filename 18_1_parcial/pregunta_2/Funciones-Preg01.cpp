//
// Created by Jhair Guzman on 8/10/2018.
//

#include "Funciones-Preg01.h"
#include <iostream>

#define TAM_NOMBRE  30
#define TAM_MAX     300
#define LINEAS      100

using namespace std;

/* LECTURA E IMPRESION DE LA PRIMERA PARTE DEL ARCHIVO BIBLIOTECA */
void leerUsuarios(int* &codigosU, char** &nombresU) {
    // variables auxiliares para recoleccion de datos
    int codigosArr[TAM_MAX];
    char* nombresArr[TAM_MAX];

    int cont = 0;
    int codigo;
    char nombre[TAM_NOMBRE];

    // la primera parte termina con un salto de linea
    while(cin.peek()!='\n'){
        cin >> codigo; cin.ignore();        // se ignora la coma siguiente
        cin.getline(nombre,TAM_NOMBRE,'\n');    // se descarta el salto de final de linea

        // almacenamiento en los arreglos correctos
        codigosArr[cont] = codigo;
        nombresArr[cont] = stringExacto(nombre);

        cont++; cout << "contador: " << cont << endl;
    }   cin.ignore(); // se ignora salto de linea que separa la 1er y 2da parte del archivo

    // colocar datos en memoria dinamica exacta
    memoriaExacta(codigosU,codigosArr,cont);
    memoriaExacta(nombresU,nombresArr,cont);
}


void imprimirUsuarios(int* &codigosU, char** &nombresU) {
    int i = 0;
    cout << "USUARIOS" << endl;
    imprimirLinea();
    while(codigosU[i]!=NULL){
        cout << "Codigo: " << codigosU[i] << endl;
        cout << "Nombre: " << nombresU[i] << endl;
        imprimirLinea('-');
        i++;
    }
}


char* stringExacto(char* palabra){
    // cantidad de caracteres de la palabra
    int i = 0;
    while(palabra[i]!='\0') i++;
    // copiar caracteres a puntero
    char* palabraNew = new char[i+1]; // +1 por el caracter '\0'
    for(int e=0;e<=i;e++) palabraNew[e] = palabra[e];

    return palabraNew;
}


template <typename T>
void memoriaExacta(T* &puntero, T* arreglo, int cont){
    puntero = new T[cont+1];
    for(int i=0;i<cont;i++) {
        puntero[i] = arreglo[i];
    }   puntero[cont] = NULL;
}
template void memoriaExacta(char**&,char**,int);
template void memoriaExacta(int  *&,int  *,int);


void imprimirLinea(char c){
    for(int i=0;i<LINEAS;i++){
        cout.put(c);
    }   cout.put('\n');
}


