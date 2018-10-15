//
// Created by jhair on 15/10/18.
//

#include "Bib_Func_ExtraccionesF.h"
#include "Biblioteca_Func_Incendios.h"
#include "Bib_Func_Provincias.h"
#include <iostream>
#include <iomanip>
#include <cstring>

#define TAM_NOMBRE  40
#define TAM_IGNORE  50
#define INCREMENTO  5

using namespace std;

void leerExtracciones(char** &especies, double*** &extracciones){
    int contEsp = 0; // contador de especies
    while(cin.peek()!='\n'){
        double codigoP, anio,cantR,cantC,cantL,cantP,cantO;
        char especie[TAM_NOMBRE];
        leerDatosExtraccion(codigoP,anio,cantR,cantC,cantL,cantP,cantO,especie);
        int posEsp = posicionEspecie(especies,especie,contEsp); // devuelve -1 si no se ha encontrado
        if(posEsp==-1){
            insertarEspecie(especies,especie,contEsp);
            aumentarArreglo(extracciones,contEsp,INCREMENTO);
            posEsp = contEsp;
            contEsp++;
        }
        insertarExtraccion(extracciones[posEsp],codigoP,anio,cantR,cantC,cantL,cantP,cantO);
    }   cin.clear();
}
void leerDatosExtraccion(double &codigoP, double &anio, double &cantR, double &cantC, double &cantL,
                         double &cantP, double &cantO, char* especie){
    cin >> codigoP; cin.ignore();   // se ignora la coma siguiente
    cin.ignore(TAM_IGNORE,',');     // se ignora el nombre de la provincia
    cin >>  anio  ; cin.ignore();
    cin.getline(especie,TAM_NOMBRE,',');
    cin.ignore(TAM_IGNORE,',');     // se ignora el caracter de unidad de medida de peso
    cin >> cantR; cin.ignore();
    cin >> cantC; cin.ignore();
    cin >> cantL; cin.ignore();
    cin >> cantP; cin.ignore();
    cin >> cantO; cin.ignore();     // se ignora el salto de linea
    cin.clear();                    // en caso intente ignorar en el final del archivo
}

int posicionEspecie(char** especies, char* especie, int contEsp){
    int pos = -1;
    for(int i=0;i<contEsp;i++){
        if(strcmp(especies[i],especie)==0){
            pos = i;
            break;
        }
    }
    return pos;
}

void insertarEspecie(char** &especies, char* especie, int contEsp){
    if(contEsp%INCREMENTO==0) aumentarArreglo(especies,contEsp,INCREMENTO);
    char* especieNew = new char[strlen(especie)+1];
    strcpy(especieNew,especie);
    especies[contEsp] = especieNew;
}

// insertar una extraccion dentro del arreglo de extracciones de una sola especie
void insertarExtraccion(double** &extraccionesEsp, double codigoP, double anio, double cantR,
                        double cantC, double cantL, double cantP, double cantO){
    int cantExtr = tamanioArreglo(extraccionesEsp);
    if(cantExtr%INCREMENTO==0) aumentarArreglo(extraccionesEsp,cantExtr,INCREMENTO);
    double* extraccion = new double[7];
    extraccion[0] = codigoP;
    extraccion[1] = anio;
    extraccion[2] = cantR;
    extraccion[3] = cantC;
    extraccion[4] = cantL;
    extraccion[5] = cantP;
    extraccion[6] = cantO;
    extraccionesEsp[cantExtr] = extraccion;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void imprimirExtracciones(char** especies, double*** extracciones, char*** provincias) {

}
