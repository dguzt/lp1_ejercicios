/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 * 
 * Autor : Jhair Guzman
 * Codigo: 20163275
 */

#include "Func-Ex-Preg01.h"
#include <iostream>
#include <iomanip>
#include <cstring>

#define TAM_PLACA   10
#define TAM_NOMBRE  100
#define TAM_MAXIMO  500
#define TAM_CIUDAD  100
#define LINEAS      100

using namespace std;

void leerRutas(char*** &rutas, int* &asientos){
    int contRutas = 0;
    char** rutasEst[TAM_MAXIMO]; // arreglo estatico
    int asientosEst[TAM_MAXIMO]; // arreglo estatico
    while(cin.peek()!='\n'){
        leeryAlmacenarDatosChofer(rutasEst,contRutas);
        leeryAlmacenarCiudadesDestino(rutasEst,contRutas);
        leeryAlmacenarMaxPasajeros(asientosEst,contRutas);
        contRutas++;
    }
    arregloMemoriaDinamica(rutas,rutasEst,contRutas);
    arregloMemoriaDinamica(asientos,asientosEst,contRutas);
}

void leeryAlmacenarDatosChofer(char*** rutasEst,int contRutas){
    char placa[TAM_PLACA];
    char nombreCH[TAM_NOMBRE];
    cin.getline(placa,TAM_PLACA,',');
    cin.getline(nombreCH,TAM_NOMBRE,',');
    char* placaNew = new char[strlen(placa)+1];
    strcpy(placaNew,placa);
    char* nombreCHNew = new char[strlen(nombreCH)+1];
    strcpy(nombreCHNew,nombreCH);
    char** ruta = new char*[2];
    ruta[0] = placaNew;
    ruta[1] = nombreCHNew;
    rutasEst[contRutas] = ruta;
}

void leeryAlmacenarCiudadesDestino(char*** rutas, int contRutas){
    char** ruta = rutas[contRutas];
    char* ciudadesEst[TAM_MAXIMO];
    int cantCiudades = 0;
    while(!esNumero(cin.peek())){
        char ciudad[TAM_CIUDAD];
        cin.getline(ciudad,TAM_CIUDAD,',');
        char* ciudadNew = new char[strlen(ciudad)+1];
        strcpy(ciudadNew,ciudad);
        ciudadesEst[cantCiudades] = ciudadNew;
        cantCiudades++;
    }
    char** ciudadesNew;
    arregloMemoriaDinamica(ciudadesNew,ciudadesEst,cantCiudades);
    // pasamos todos los datos a ruta
    actualizarRutaConDatosCiudad(ruta,ciudadesNew,cantCiudades);
}
        
void actualizarRutaConDatosCiudad(char** &ruta,char** &ciudadesNew, int cantCiudades){
    char* placaNew    = ruta[0];
    char* nombreCHNew = ruta[1];
    delete [] ruta; // se eliminan los dos espacios de punteros de placa y nombre
    ruta = new char* [2+cantCiudades+1]; // placa y nombre(+2), ciudades, NULL(+1)
    ruta[0] = placaNew;
    ruta[1] = nombreCHNew;
    for(int i=2;i<(cantCiudades+2);i++) ruta[i] = ciudadesNew[i];
    ruta[cantCiudades+2] = NULL;
}

void leeryAlmacenarMaxPasajeros(int* asientosEst, int contRutas){
    int maxPasajeros=0;
    cin >> maxPasajeros;
    cin.ignore(); // se ignora el salto de linea que viene despues de leer el numero
    asientosEst[contRutas] = maxPasajeros;
}
        
////////////////////////////////////////////////////////////////////////////////
void imprimirRutas(char*** rutas, int* asientos){
    imprimirLinea();
    cout << "RUTAS DE BUSES DE DIFERENTES COMPAÑIAS" << endl;
    imprimirLinea();
    int contRutas = 0;
    while(rutas[contRutas]!=NULL){
        char** ruta = rutas[contRutas];
        cout << "ruta " << contRutas << ": " << endl;
        cout << "placa : " << left << setw(20) << ruta[0];
        cout << "chofer: " << left << setw(60) << ruta[1] << endl;
        cout << "Ciudades de destino: " << endl;
        int contCiudades = 0;
        while(ruta[contCiudades]!=NULL){
            char* ciudad = ruta[contCiudades];
            cout << "  " << ciudad << endl;
            contCiudades++;
        }
        imprimirLinea('-');
        contRutas++;        
    }
}
    




////////////////////////////////////////////////////////////////////////////////
// FUNCIONES AUXILIARES
template <typename T>
void arregloMemoriaDinamica(T* &arregloDin, T* arregloEst, int cant){
    if(cant==0) arregloDin = NULL;
    arregloDin = new T[cant+1];
    for(int i=0; i<cant;i++) arregloDin[i] = arregloEst[i];
    arregloDin[cant] = (T)0;
}
template void arregloMemoriaDinamica(char***&,char***,int);
template void arregloMemoriaDinamica(char** &,char** ,int);
template void arregloMemoriaDinamica(int*   &,int*   ,int);

    
bool esNumero(char c){
    return (c=='0') or (c=='1') or
           (c=='2') or (c=='3') or
           (c=='4') or (c=='5') or
           (c=='6') or (c=='7') or
           (c=='8') or (c=='9');
}

void imprimirLinea(char c){
    for(int i=0;i<LINEAS;i++){
        cout.put(c);
    }   cout.put('\n');
}
    