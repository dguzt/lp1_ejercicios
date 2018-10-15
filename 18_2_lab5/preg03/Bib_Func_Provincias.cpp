//
// Created by jhair on 14/10/18.
//

#include "Bib_Func_Provincias.h"
#include <iostream>
#include <cstring>
#include <iomanip>

#define TAM_NOMBRE          70
#define TAM_ABREVIATURA     70
#define TAM_CODIGO          10
#define TAM_MAXIMO          300
#define TAM_IGNORE          100
#define LINEAS              100

using namespace std;

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void leerProvincias(char*** &provinciasP) {
    // datos importantes que se almacenaran como datos de cada provincia
    char *nombreP, *abrevP, *codigoP, *codigoIsoP;
    char** provincias[TAM_MAXIMO];  int cantP = 0;
    while(cin.peek()!='\n'){
        leerDatosProvincia(nombreP,abrevP,codigoP,codigoIsoP);
        provincias[cantP] = generarProvincia(nombreP,abrevP,codigoP,codigoIsoP);
        cantP++;
    }   cin >> ws;
    arregloDinamico(provinciasP,provincias,cantP);
    quicksortProvincias(provinciasP,0,cantP-1);
}

void leerDatosProvincia(char* &nombreP, char* &abrevP, char* &codigoP, char* &codigoIsoP){
    char nombre[TAM_NOMBRE];
    char abrev[TAM_ABREVIATURA];
    char codigo[TAM_CODIGO];
    char codigoIso[TAM_CODIGO];

    cin.ignore(TAM_IGNORE,',');         // se ignora el nombre largo de la provincia
    cin.ignore(TAM_IGNORE,',');         // se ignora el tipo de jurisdiccion
    cin.getline(nombre,TAM_NOMBRE,',');
    cin.ignore(TAM_IGNORE,',');         // se ignora la autoridad fuente
    cin.getline(codigo,TAM_CODIGO,',');
    cin.getline(abrev,TAM_ABREVIATURA,',');
    cin.getline(codigoIso,TAM_CODIGO,'\n');

    nombreP = new char[strlen(nombre)+1];
    strcpy(nombreP,nombre);
    abrevP = new char[strlen(abrev)+1];
    strcpy(abrevP,abrev);
    codigoP = new char[strlen(codigo)+1];
    strcpy(codigoP,codigo);
    codigoIsoP = new char[strlen(codigoIso)+1];
    strcpy(codigoIsoP,codigoIso);
}

char** generarProvincia(char* &nombreP, char* &abrevP, char* &codigoP, char* &codigoIsoP){
    char** provinciaP = new char*[4];
    provinciaP[0] = codigoP;
    provinciaP[1] = nombreP;
    provinciaP[2] = abrevP;
    provinciaP[3] = codigoIsoP;
    return provinciaP;
}

void quicksortProvincias(char*** &provinciasP, int ini, int fin){
    if(ini >= fin) return;
    int ind_pivot = dividirProvincias(provinciasP,ini,fin);
    quicksortProvincias(provinciasP,ini,ind_pivot-1);
    quicksortProvincias(provinciasP,ind_pivot+1,fin);
}

int dividirProvincias(char*** &provinciasP, int ini, int fin){
    int izq = ini+1, der = fin;
    char** pivotP = provinciasP[ini];
    while(izq<=der){
        while((izq<=der) && (compararCodigos(provinciasP[izq],pivotP) <= 0)) izq++; // si prov[izq] <= pivote -> izq++
        while((izq<=der) && (compararCodigos(provinciasP[der],pivotP)  > 0)) der--; // si prov[der]  > pivote -> der--
        if(izq<der){
           char** provinciaAux = provinciasP[izq];
           provinciasP[izq] = provinciasP[der];
           provinciasP[der] = provinciaAux;
        }
    }
    char** provinciaAux = provinciasP[izq-1];
    provinciasP[izq-1] = pivotP;
    provinciasP[ ini ] = provinciaAux;
    return izq - 1;
}

int compararCodigos(char** provincia1,char** provincia2){
    int codigo1 = StringParseoInt(provincia1[0]);
    int codigo2 = StringParseoInt(provincia2[0]);
    return codigo1 < codigo2 ? -1 : // si la primera provincia es menor que la segunda, devuelve -1 (comp < 0)
           codigo1 > codigo2 ?  1 : // si la segunda es mayor que la primera, devuelve 1            (comp > 0)
                                0 ; // si ambos son iguales, devuelve 0                             (comp = 0)
}

int StringParseoInt(char* numeroStr){
    int numeroInt = 0;
    for(int i=0;i<strlen(numeroStr);i++){
        numeroInt = numeroInt*10 + (numeroStr[i]-'0');
    }
    return numeroInt;
}

void imprimirArreglo(char*** provinciasP, int ini, int fin){
    int i = ini;
    cout << "codigo: " << endl;
    while(i<=fin){
        cout << provinciasP[i][0] << " ";
        i++;
    }   cout << endl;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void imprimirProvincias(char*** &provinciasP) {
    int i = 0;
    imprimirLinea();
    cout << setw(55) << "PROVINCIAS" << endl;
    imprimirLinea();
    while(provinciasP[i]!=NULL){
        cout << "Codigo     : "    << provinciasP[i][0] << endl;
        cout << "   Nombre     : " << provinciasP[i][1] << endl;
        cout << "   Abreviatura: " << provinciasP[i][2] << endl;
        cout << "   Codigo ISO : " << provinciasP[i][3] << endl;
        imprimirLinea('-');
        i++;
    }
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// FUNCIONES AUXILIARES

template <typename T>
void arregloDinamico(T* &arregloDinamico,T* arregloEstatico,int cantidad){
    arregloDinamico = new T[cantidad+1];
    for(int i=0;i<cantidad;i++) arregloDinamico[i] = arregloEstatico[i];
    arregloDinamico[cantidad] = NULL;
}
template void arregloDinamico(char***&,char***,int);

void imprimirLinea(char c){
    for(int i=0;i<LINEAS;i++){
        cout.put(c);
    }   cout.put('\n');
}