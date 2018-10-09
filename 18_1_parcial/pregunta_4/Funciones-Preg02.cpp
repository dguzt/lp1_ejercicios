//
// Created by Usuario on 8/10/2018.
//

#include "Funciones-Preg02.h"
#include "Funciones-Preg01.h"
#include <iostream>

#define TAM_DEFECT  5
#define TAM_CODIGO  9
#define TAM_NOMBRE  70

using namespace std;

void leerLibros(char*** &libros, int** &stock) {
    // variables auxiliares
    int cont = 0;
    cin >> ws;
    while(cin.peek()!='\n'){
        if(cont%TAM_DEFECT==0){
            aumentarArreglo(libros,cont,TAM_DEFECT);
            aumentarArreglo(stock ,cont,TAM_DEFECT);
        }
        libros[cont] = obtenerDatosLibro();
        stock [cont] = obtenerStockLibro();
        cont++;
    }   cin.ignore();
}

void imprimirLibros(char*** &libros, int** &stock) {
    cout << "LIBROS" << endl;
    imprimirLinea();
    int i = 0;
    while(libros[i]!= nullptr){
        cout << "Codigo: " << libros[i][0] << endl;
        cout << "Nombre: " << libros[i][1] << endl;
        cout << "Autor : " << libros[i][2] << endl;
        cout << "Cantidad en biblioteca: " << stock[i][0] << endl;
        cout << "Cantidad disponibles  : " << stock[i][1] << endl;
        i++;
        imprimirLinea('-');
    }
}

/**************************************************************/
/* FUNCIONES AUXILIARES */

template<typename T>
void aumentarArreglo(T* &arreglo, int cantidad, int aumento) {
    // caso base
    if(cantidad==0){
        arreglo = new T[cantidad + aumento + 1];
        for(int i=0;i<=(cantidad+aumento);i++)
            arreglo[i] = (T)0;
        return;
    }

    // otros casos
    auto * auxiliar = new T[cantidad + aumento + 1];
    for(int i=0; i<cantidad; i++) auxiliar[i] = arreglo[i];
    for(int i=cantidad;i<=(cantidad+aumento);i++) auxiliar[i] = (T)0;
    delete [] arreglo;
    arreglo = auxiliar;
}
template void aumentarArreglo(char***&,int,int);
template void aumentarArreglo(int**  &,int,int);


char** obtenerDatosLibro() {
    char codigo[TAM_CODIGO];
    char nombre[TAM_NOMBRE];
    char autor [TAM_NOMBRE];

    cin.getline(codigo,TAM_CODIGO,',');
    cin.getline(nombre,TAM_NOMBRE,',');
    cin.getline(autor ,TAM_NOMBRE,',');

    char** libro = new char*[3];
    libro[0] = stringExacto(codigo);
    libro[1] = stringExacto(nombre);
    libro[2] = stringExacto(autor );

    return libro;
}

int* obtenerStockLibro() {
    auto * stock = new int[2];

    int disponible;
    cin >> disponible;
    cin.ignore();   // ignorar salto de linea

    stock[0] = disponible;
    stock[1] = disponible;

    return stock;
}

