//
// Created by jhair on 14/10/18.
//

#include "Biblioteca_Func_Incendios.h"
#include "Bib_Func_Provincias.h"
#include <iostream>
#include <iomanip>
#include <cstring>

#define TAM_NOMBRE 50
#define INCREMENTO 5

using namespace std;

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void leerIncendios(long int*** &incendios, char*** &provincias) {
    int* cantIncen;
    inicializarIncendios(incendios,provincias,cantIncen);
    while(cin.peek()!='\n'){
        long int anio, hectaBN, hectaBC, hectaA, hectaP, hectaI;
        char nombreCiudad[TAM_NOMBRE];
        leerDatosIncendio(anio,nombreCiudad,hectaBN,hectaBC,hectaA,hectaP,hectaI);
        int posCiudad = posicionCiudadArreglo(provincias,nombreCiudad);
        almacenarIncendioCiudad(incendios[posCiudad],cantIncen[posCiudad],anio,hectaBN,hectaBC,hectaA,hectaP,hectaI);
        cantIncen[posCiudad]++;
    }   cin >> ws;
    ordenarIncendiosxCiudad(incendios,cantIncen);
}

void inicializarIncendios(long int*** &incendios, char*** provincias, int* &cantIncen){
    int cantProv = tamanioArreglo(provincias);
    incendios = new long int**[cantProv+1];
    incendios[cantProv] = NULL;
    cantIncen = new int[cantProv];
    for(int i=0;i<cantProv;i++) cantIncen[i]=0;
}

void leerDatosIncendio(long int &anio, char* nombreCiudad, long int &hectaBN, long int &hectaBC,
                       long int &hectaA, long int &hectaP, long int &hectaI){
    cin >> anio; cin.ignore(); // se ignora la coma
    cin.getline(nombreCiudad,TAM_NOMBRE,',');
    cin >> hectaBN; cin.ignore();
    cin >> hectaBC; cin.ignore();
    cin >> hectaA ; cin.ignore();
    cin >> hectaP ; cin.ignore();
    cin >> hectaI ; cin.ignore(); // ignorar el salto de linea
}

int posicionCiudadArreglo(char*** provincias, char* nombreCiudad){
    int pos = 0;
    while(true){
        if(strcmp(provincias[pos][1],nombreCiudad)==0) break;
        pos++;
    }
    return pos;
}

void almacenarIncendioCiudad(long int** &ciudad, int cantIncen, long int anio, long int hectaBN,
                             long int hectaBC, long int hectaA, long int hectaP, long int hectaI){
    if(cantIncen%INCREMENTO==0) aumentarArreglo(ciudad,cantIncen,INCREMENTO);
    long int* incendio = new long int[7];
    incendio[0] = anio;
    incendio[1] = hectaBN + hectaBC + hectaA + hectaP + hectaI;
    incendio[2] = hectaBN;
    incendio[3] = hectaBC;
    incendio[4] = hectaA;
    incendio[5] = hectaP;
    incendio[6] = hectaI;
    ciudad[cantIncen] = incendio;
}


void ordenarIncendiosxCiudad(long int*** &incendios,int* cantIncen){
    // ordenamiento de los incendios para cada ciudad
    int posCiudad = 0;
    while(incendios[posCiudad]!=NULL){
        quicksortIncendios(incendios[posCiudad],0,cantIncen[posCiudad]-1);
        posCiudad++;
    }
}

void quicksortIncendios(long int** &ciudad,int ini,int fin){
    if(ini>=fin) return;
    int part = particionIncendios(ciudad,ini,fin);
    quicksortIncendios(ciudad,ini,part-1);
    quicksortIncendios(ciudad,part+1,fin);
}

int particionIncendios(long int** &ciudad, int ini, int fin){
    long int* pivote = ciudad[ini];
    int izq = ini + 1;
    int der = fin;
    while(izq<=der){
        while(izq<=der && ciudad[izq][0] <= pivote[0]) izq++;
        while(izq<=der && ciudad[der][0]  > pivote[0]) der--;
        if(izq<der){
            long int* auxiliar = ciudad[izq];
            ciudad[izq] = ciudad[der];
            ciudad[der] = auxiliar;
        }
    }
    ciudad[ ini ] = ciudad[izq-1];
    ciudad[izq-1] = pivote;
    return izq-1;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void imprimirIncendios(long int*** &incendios, char*** &provincias) {
    imprimirLinea();
    cout << setw(79) << "INCENDIOS FORESTALES POR TIPO DE SUPERFICIE (EN HECTAREAS)" << endl;
    imprimirLinea();
    int posCiu = 0;
    while(provincias[posCiu]!=NULL) {
        char** ciudad = provincias[posCiu];
        imprimirLinea('-');
        cout << "PROVINCIA " << ciudad[0] << ": " << ciudad[1] << " (" << ciudad[2] << ") " << endl;
        imprimirLinea('-');
        cout << right << setw(10) << "ANIO" ;
        cout << right << setw(10) << "TOTAL";
        cout << right << setw(10) << "BN"   ;
        cout << right << setw(10) << "BC"   ;
        cout << right << setw(10) << "A"    ;
        cout << right << setw(10) << "P"    ;
        cout << right << setw(10) << "I" << endl;
        imprimirLinea('-');
        imprimirIncendiosCiudad(incendios[posCiu]);
        posCiu++;
    }
}


void imprimirIncendiosCiudad(long int** incendios){
    int cantInc = 0;
    while(incendios[cantInc]!=NULL){
        long int* incendio = incendios[cantInc];
        cout << right << setw(10) << incendio[0];
        cout << right << setw(10) << incendio[1];
        cout << right << setw(10) << incendio[2];
        cout << right << setw(10) << incendio[3];
        cout << right << setw(10) << incendio[4];
        cout << right << setw(10) << incendio[5];
        cout << right << setw(10) << incendio[6];
        cout << endl;
        cantInc++;
    }
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// FUNCIONES AUXILIARES

template <typename T>
void aumentarArreglo(T* &arreglo, int cantidad, int incremento){
    // caso base
    if(cantidad==0){
        arreglo = new T[incremento+1];
        for(int i=0; i<=incremento; i++) arreglo[i] = NULL;
        return;
    }
    // otros casos
    T* arregloAux = new T[cantidad+incremento+1];
    for(int i=0; i<cantidad; i++) arregloAux[i] = arreglo[i];
    for(int i=cantidad; i<=(cantidad+incremento); i++) arregloAux[i] = NULL;
    delete [] arreglo;
    arreglo = arregloAux;
}
template void aumentarArreglo(long int** &,int,int);

template <typename T>
int tamanioArreglo(T* arreglo){
    int cant = 0;
    while(arreglo[cant]!=(T)0) cant++;
    return cant;
}
template int tamanioArreglo(char***);
template int tamanioArreglo(long int***);
