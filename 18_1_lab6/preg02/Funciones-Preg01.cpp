//
// Created by jhair on 30/10/18.
//

#include "Funciones-Preg01.h"
#include <iostream>
#include <cstring>

#define TAM_NOMBRE  50
#define TAM_MAXIMO  300
#define LINEAS      100

using namespace std;

void leerUsuarios(void* &usuariosU) {
    void* usuariosStack[TAM_MAXIMO];
    int cantU = 0;
    while(cin.peek()!='\n'){
        int* codigoU; char* nombreU;
        leerDatosUsuario(codigoU, nombreU);
        almacenarDatosUsuario(usuariosStack, codigoU, nombreU, cantU);
        cantU++;
    }
    arregloDinamico((void**&)usuariosU,(void**)usuariosStack,cantU);
}

void leerDatosUsuario(int* &codigoU, char* &nombreU){
    codigoU = new int;
    cin >> (*codigoU); cin.ignore();
    char nombre[TAM_NOMBRE];
    cin.getline(nombre,TAM_NOMBRE,'\n');
    nombreU = new char[strlen(nombre)+1];
    strcpy(nombreU,nombre);
}

void almacenarDatosUsuario(void** usuariosStack, int* codigoU, char* nombreU, int cantU){
    usuariosStack[cantU] = new void*[4];
    ((void**)usuariosStack[cantU])[0] = codigoU;
    ((void**)usuariosStack[cantU])[1] = nombreU;
    ((void**)usuariosStack[cantU])[2] = NULL;
    ((void**)usuariosStack[cantU])[3] = NULL;
}

/***************************************************************************/
void imprimirUsuarios(void* usuarios) {
    for(int cont=0; ((void**)usuarios)[cont]!=NULL; cont++){
        void** usuario = ((void***)usuarios)[cont];
        cout << "codigo: " << *((int *)usuario[0]) << endl;
        cout << "nombre: " <<  ((char*)usuario[1]) << endl;
        imprimirLinea();
    }
}

/***************************************************************************/
template<typename T>
void arregloDinamico(T* &arrDinamic, T* arrStack, int cant){
    arrDinamic = new T[cant+1];
    for(int i=0; i<cant; i++) arrDinamic[i] = arrStack[i];
    arrDinamic[cant] = NULL;
}
template void arregloDinamico(void**  &, void**  , int);
template void arregloDinamico(void*** &, void*** , int);
template void arregloDinamico(void****&, void****, int);


void imprimirLinea(char c){
    for(int i=0; i<LINEAS; i++){
        cout.put(c);
    }   cout.put('\n');
}