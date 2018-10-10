//
// Created by jhair on 09/10/18.
//

#include "Funciones-Preg03.h"
#include "Funciones-Preg02.h"
#include "Funciones-Preg01.h"
#include <iostream>

#define TAM_DEFECTO_ARR  5
#define TAM_CODIGO_LIBRO 9
#define TAM_FECHA        11

using namespace std;

int *registrarPrestamos(int* &codigosU, char**** &prestamosP, char*** &librosL, int** &stocksL) {
    int cantCodU = tamanioArreglo(codigosU);
    prestamosP    = new char***[cantCodU];  // arreglo de prestamos se rige por la cantidad de usuarios
    int* tamanioP = new int[cantCodU];      // arreglo de cantidades de libros por usuario
    for(int i=0;i<cantCodU;i++){
        prestamosP[i] = new char**[1];      // todos los usuarios inician sin libros prestados (NULL)
        prestamosP[i][0] = NULL;
        tamanioP[i] = 0;                    // todos los usuarios tienen cero prestamos de libros
    }
    cin.clear(); cin >> ws;
    int contP = 0;
    while(cin.peek()!='\n'){
        int  codigoU;
        char codigoL[TAM_CODIGO_LIBRO];
        char fechaP [TAM_FECHA];
        leerDatosPrestamo(codigoU,codigoL,fechaP);
        int posU = posicionUsuario(codigoU,codigosU);
        reducirStock(codigoL,librosL,stocksL);
        registrarPrestamoUsuario(posU,prestamosP,codigoL,fechaP,tamanioP);
        contP++;
    }   cin.ignore(); // ignorar el salto de linea que separa parte 3 con parte 4
    return tamanioP;
}

void imprimirPrestamos(int* &codigosU, char** &nombresU, char**** &prestamosP) {
    cout << "PRESTAMOS DE USUARIOS" << endl;
    imprimirLinea();
    int i=0;
    while(codigosU[i]!=NULL){
        cout << "Codigo: " << codigosU[i] << endl;
        cout << "Alumno: " << nombresU[i] << endl;
        cout << "Libros prestados: " << endl;
        int e=0;
        while(prestamosP[i][e]!=NULL){
            cout << "   Codigo Libro  : " << prestamosP[i][e][0] << endl;
            cout << "   Fecha Prestamo: " << prestamosP[i][e][1] << endl;
            e++;
        }
        i++;
        imprimirLinea('-');
    }
}

/********************************************************************/
/* FUNCIONES AUXLIARES DE LA PREGUNTA 03 */

void leerDatosPrestamo(int &codigoU,char* codigoL,char* fechaP){
    cin >> codigoU; cin.ignore();               // se ignora la coma siguiente
    cin.getline(codigoL,TAM_CODIGO_LIBRO,',' );
    cin.getline(fechaP ,TAM_FECHA       ,'\n');
}

void reducirStock(char* codigoL,char*** &librosL,int** &stocksL) {
    int posL = posicionLibro(codigoL,librosL);
    stocksL[posL][1]--;
}

template <typename T>
int tamanioArreglo(T* &arreglo){
    int i = 0;
    while(arreglo[i]!=(T)0) i++;
    return i;
}
template int tamanioArreglo(char****&);
template int tamanioArreglo(char*** &);
template int tamanioArreglo(char**  &);
template int tamanioArreglo(char*   &);
template int tamanioArreglo(int*    &);
template int tamanioArreglo(int**   &);


// en esta funcion no se considera el que no lo haya encontrado, para ello es necesario colocar un assert
// o enviar un mensaje a pantalla, ademas de evitar lo que genere este ciclo del bucle fallido
int posicionUsuario(int codigoU,int* &codigosU){
    int pos =0;
    while(codigosU[pos]!=codigoU) pos++;
    return pos;
}

void registrarPrestamoUsuario(int posU,char**** &prestamosP,char* codigoL,char* fechaP,int* &tamanioP){
    // si no alcanza espacio en el arreglo de libros de un alumno, se aumenta el tamanio
    if(tamanioP[posU]%TAM_DEFECTO_ARR==0){
        aumentarArreglo(prestamosP[posU],tamanioP[posU],TAM_DEFECTO_ARR);
    }
    // strings exactos de codigo de libro y fecha de prestamo guardados en el prestamo de un libro de un alumno
    prestamosP[posU][tamanioP[posU]] = new char*[2];
    prestamosP[posU][tamanioP[posU]][0] = stringExacto(codigoL);
    prestamosP[posU][tamanioP[posU]][1] = stringExacto(fechaP);
    tamanioP[posU]++;
}

// esta funcion no considera el no encontrar el codigo del libro,
// considerar implementar un assert o alerta por consola dentro del while
int posicionLibro(char* codigoL, char*** &librosL) {
    int pos = 0;
    while(!stringsIguales(codigoL,librosL[pos][0])) pos++;
    return pos;
}

bool stringsIguales(char* string1,char* string2){
    int i=-1;
    while(true){
        i++;
        if(string1[i]=='\0' && string2[i]=='\0') return true;
        if(string1[i]==string2[i]) continue;
        return false;
    }
}