//
// Created by jhair on 30/10/18.
//

#include "Funciones-Preg02.h"
#include "Funciones-Preg01.h"
#include <iostream>
#include <cstring>

#define TAM_CODIGO  10
#define TAM_FECHA   15
#define INCREMENTO  5

using namespace std;

/*********************************************************************************************************************/
void leerPrestamos(void* &usuarios) {
    inicializarCantLibrosxUsuario(usuarios);
    cin.ignore(); // ignorar el salto de linea anterior
    while(cin.peek()!='\n'){
        int codigoU; char* codigoL; char* fechaD;
        leerDatosPrestamo(codigoU, codigoL, fechaD);
        int posU = posicionUsuario(usuarios, codigoU);
        almacenarDatos(((void**&)usuarios)[posU],codigoL, fechaD);
    }
}

void inicializarCantLibrosxUsuario(void* &usuarios){
    for(int i=0;((void**)usuarios)[i]!=NULL;i++){
        void* usuario = ((void**)usuarios)[i];
        ((int*)usuario)[2] = 0;
    }
}

void leerDatosPrestamo(int &codigoU, char* &codigoL, char* &fechaD){
    // codigo de usuario
    cin >> codigoU; cin.ignore();

    // codigo del libro
    char codigo[TAM_CODIGO];
    cin.getline(codigo,TAM_CODIGO,',');
    codigoL = new char[strlen(codigo)+1];

    // fecha de prestamo
    char fecha[TAM_FECHA];
    cin.getline(fecha,TAM_FECHA,'\n');
    fechaD = new char[strlen(fecha)+1];
}

int posicionUsuario(void* usuarios, int codigoU){
    for(int i=0;((void**)usuarios)[i]!=NULL;i++){
        void** usuario = ((void***)usuarios)[i];
        int codigoUser = *((int*)usuario[0]);
        if(codigoUser == codigoU) return i;
    }
    return -1; // no puede suceder porque se asume que los prestamos los realiza una persona con codigo valido
}

void almacenarDatos(void* &usuario, char* &codigoLibro, char* &fechaDev){
    int cantLibros = ((int*)usuario)[3];
    void* prestamos = ((void**)usuario)[2];
    if(cantLibros%INCREMENTO==0) aumentarArreglo((void**&)prestamos,cantLibros, INCREMENTO);
    void** datosPrestamo = new void*[2]; // dos espacios para punteros a codigo del libro prestado y a fecha de dev.
    datosPrestamo[0] = codigoLibro;
    datosPrestamo[1] = fechaDev;
    ((void**)prestamos)[cantLibros] = datosPrestamo;
}

/*********************************************************************************************************************/
void imprimirPrestamos(void* usuarios) {
    imprimirLinea();
    cout << "PRESTAMOS DE LIBROS" << endl;
    imprimirLinea();
    for(int i=0;((void**)usuarios)[i]!=NULL;i++){
        void* usuario = ((void**)usuarios)[i];
        int   codigoU = ((int*)usuario)[0];
        char* nombreU = ((char**)usuario)[1];
        void* prestamosU = ((void**)usuario)[2];
        int cantLU = ((int*)usuario)[3];
        cout << "Codigo de usuario: " << codigoU << endl;
        cout << "Nombre de usuario: " << nombreU << endl;
        imprimirLinea('-');
        for(int e=0;e<cantLU;e++){
            char** libro = ((char***)prestamosU)[e];
            cout << "   Codigo Libro       :" << libro[0] << endl;
            cout << "   Fecha de devolucion:" << libro[1] << endl;
        }
    }
}


/*********************************************************************************************************************/
template <typename T>
int tamanioArreglo(T* arreglo){
    // caso base
    if(arreglo==NULL) return 0;

    // otros casos
    int i=0;
    while(arreglo[i]!=NULL) i++;
    return i;
}
template int tamanioArreglo(void** );
template int tamanioArreglo(void***);
template int tamanioArreglo(int**  );


template<typename T>
void aumentarArreglo(T* arreglo, int cantidad, int aumento){
    // caso base
    if(cantidad==0){
        arreglo = new T[aumento];
        for(int i=0; i<=aumento;i++) arreglo[i]=(T)0;
        return;
    }
    // otros casos
    T* auxiliar = new T[cantidad + aumento + 1];
    int i;
    for(i=0;i<cantidad;i++) auxiliar[i]=arreglo[i];
    for(;i<=(cantidad+aumento);i++) auxiliar[i]=(T)0;
    delete [] arreglo;
    arreglo = auxiliar;
}
template void aumentarArreglo(void**  ,int,int);
template void aumentarArreglo(void*** ,int,int);
template void aumentarArreglo(void****,int,int);

