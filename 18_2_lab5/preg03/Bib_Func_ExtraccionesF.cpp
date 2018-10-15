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
    ordenarEspeciesyExtracciones(especies,extracciones,contEsp);
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

void ordenarEspeciesyExtracciones(char** &especies, double*** &extracciones, int cantEsp){
    // ordenamiento de las especies en orden alfabetico ascendente
    quicksortEspecies(especies,extracciones,0,cantEsp-1);

    // ordenamiento de las extracciones por cada especie de acuerdo al codigo de la ciudad y al anio en que se realizo
    for(int i=0;i<cantEsp;i++){
        quicksortExtracciones(extracciones[i],0,tamanioArreglo(extracciones[i])-1);
    }
}

void quicksortEspecies(char** &especies, double*** &extracciones, int ini, int fin){
    if(ini>=fin) return;
    int part = particionEspecies(especies,extracciones,ini,fin);
    quicksortEspecies(especies,extracciones,ini,part-1);
    quicksortEspecies(especies,extracciones,part+1,fin);
}

int particionEspecies(char** &especies, double*** &extracciones, int ini, int fin){
    char* pivote = especies[ini];
    int izq = ini + 1;
    int der = fin;
    while(izq<=der){
        while(izq<=der && strcmp(especies[izq],pivote) <= 0) izq++;
        while(izq<=der && strcmp(especies[der],pivote)  > 0) der--;
        if(izq<der){
            swap(especies[izq],especies[der]);
            swap(extracciones[izq],extracciones[der]);
        }
    }
    swap(especies[ini],especies[izq-1]);
    swap(extracciones[ini],extracciones[izq-1]);
    return izq-1;
}


void quicksortExtracciones(double** &extracciones, int ini, int fin){
    if(ini>=fin) return;
    int part = particionExtracciones(extracciones,ini,fin);
    quicksortExtracciones(extracciones,ini,part-1);
    quicksortExtracciones(extracciones,part+1,fin);
}

int particionExtracciones(double** &extracciones, int ini, int fin){
    double* pivote = extracciones[ini];
    int izq = ini + 1;
    int der = fin;
    while(izq<=der){
        while((izq<=der) && (compararExtracciones(extracciones[izq],pivote) <= 0)) izq++;
        while((izq<=der) && (compararExtracciones(extracciones[der],pivote)  > 0)) der--;
        if(izq<der) swap(extracciones[izq],extracciones[der]);
    }
    swap(extracciones[ini],extracciones[izq-1]);
    return izq-1;
}

int compararExtracciones(double* extrac1, double* extrac2){
    int codigoP1 = (int)extrac1[0]; int anio1 = (int)extrac1[1];
    int codigoP2 = (int)extrac2[0]; int anio2 = (int)extrac2[1];
    return (codigoP1<codigoP2) ? -1 :       // codigo de provincia 1 menor que provincia 2, retorna int < 0
           (codigoP1>codigoP2) ?  1 :       // codigo de provincia 1 mayor que provincia 2, retorna int > 0
           // en caso ambos codigos sean iguales (extracciones en la misma provincia)
           (anio1 < anio2)     ? -1 :       // la primera extraccion ocurrio antes que la segunda, retorna < 0
           (anio1 > anio2)     ?  1 :       // la segunda extraccion ocurrio antes que la primera, retorna > 0
                                  0 ;       // unico caso donde se habla de la misma extraccion en la misma provincia
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void imprimirExtracciones(char** especies, double*** extracciones, char*** provincias) {
    imprimirLinea();
    cout << setw(75) << right << "EXTRACCIONES FORESTALES POR ANIO Y TIPO(TONELADAS)" << endl;
    int contEsp = 0;
    while(especies[contEsp]!=NULL){
        double** extraccionesxEsp = extracciones[contEsp];
        int cantExtr = tamanioArreglo(extraccionesxEsp);
        // se imprimen todas las extracciones con respecto a una especie
        int codigoAntP = -1; // codigo de la provincia anterior en donde se realizo una extraccion de UNA especie
        for(int iExtr=0;iExtr<cantExtr;iExtr++){
            // OBS: extracciones de una especie se encuentran ordenadas por codigo y luego por anio
            int codigoP  = (int)extraccionesxEsp[iExtr][0];
            // se imprime una cabecera siempre y cuando se cambie de provincia (cambia el codigo)
            if(codigoP!=codigoAntP) imprimirCabeceraEspecie(especies[contEsp],codigoP,provincias);
            // impresion de los datos de una extraccion
            cout.precision(0);
            cout << setw(15) << right << fixed << extraccionesxEsp[iExtr][1];
            cout.precision(1);
            cout << setw(15) << right << fixed << extraccionesxEsp[iExtr][2];
            cout << setw(15) << right << fixed << extraccionesxEsp[iExtr][3];
            cout << setw(15) << right << fixed << extraccionesxEsp[iExtr][4];
            cout << setw(15) << right << fixed << extraccionesxEsp[iExtr][5];
            cout << setw(15) << right << fixed << extraccionesxEsp[iExtr][6];
            cout << endl;
            codigoAntP = codigoP;
        }   contEsp++;
    }
}

void imprimirCabeceraEspecie(char* especie, int codigoP, char*** provincias){
    imprimirLinea();
    cout << " ESPECIE: "  << setw(40) << left  << especie; cout.flush();
    cout << " PROVINCIA " << setw( 2) << right << codigoP << ": "; cout.flush();
    int posP = posicionProvinciaCodigo(provincias,codigoP);
    cout << provincias[posP][1] << endl; cout.flush();
    imprimirLinea('-');
    cout << setw(15) << right << "ANIO";
    cout << setw(15) << right << "TIPO-R";
    cout << setw(15) << right << "TIPO-C";
    cout << setw(15) << right << "TIPO-L";
    cout << setw(15) << right << "TIPO-P";
    cout << setw(15) << right << "TIPO-O";
    cout << endl;
}

int posicionProvinciaCodigo(char*** &provincias, int codigoP){
    int pos = 0;
    while(true){
        int codigoProv = StringParseoInt(provincias[pos][0]);
        if(codigoProv==codigoP) break;
        pos++;
    }
    return pos;
}