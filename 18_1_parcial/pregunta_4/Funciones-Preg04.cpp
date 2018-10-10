//
// Created by jhair on 09/10/18.
//

#include "Funciones-Preg04.h"
#include "Funciones-Preg01.h"
#include "Funciones-Preg02.h"
#include "Funciones-Preg03.h"
#include <iostream>
#include <iomanip>

#define TAM_FECHA           11
#define TAM_CODIGO_LIBRO    9
#define TAM_OBSERVACION     30

using namespace std;

void reporteYregistroDeSolicitudes(int* &codigosU, char** &nombresU, char**** &prestamosP, int* &tamanioP, char*** &librosL, int** &stocksL) {
    // arreglo de los estados de morosidad de los usuarios, por defecto todos no lo son
    int numUsuarios = tamanioArreglo(codigosU);
    bool morososU[numUsuarios];
    for(int i=0;i<numUsuarios;i++) morososU[i] = false;
    imprimirCabeceraSolicitudes();
    while(!cin.eof()){
        char fechaS[TAM_FECHA];
        int  codigoU;
        char codigoL[TAM_CODIGO_LIBRO];
        char operacionS;
        char observacionS[TAM_OBSERVACION];
        leerDatosSolicitud(fechaS,codigoU,codigoL,operacionS);
        int posU = posicionUsuario(codigoU,codigosU);
        int posL = posicionLibro(codigoL,librosL);
        procesarSolicitud(tamanioP[posU],prestamosP[posU],stocksL[posL],fechaS,codigoL,operacionS,observacionS,morososU[posU]);
        imprimirSolicitud(fechaS,nombresU[posU],codigoL,operacionS,observacionS);
    }
}

/*********************************************************************/
/* FUNCIONES AUXILIARES DE LA PREGUNTA 4 */

void leerDatosSolicitud(char* fechaP,int &codigoU,char* codigoL,char &operacion){
    cin.getline(fechaP,TAM_FECHA,',');
    cin >> codigoU; cin.ignore();                   // ignorar coma
    cin.getline(codigoL,TAM_CODIGO_LIBRO,',');
    cin.get(operacion); cin.ignore(); cin.clear();  // ignorar salto de linea
}

void imprimirCabeceraSolicitudes(){
    imprimirLinea();
    cout << right << setw(60) << "REPORTE DE SOLICITUDES" << endl;
    imprimirLinea();
    cout << right << setw( 8) << "Fecha" << "    ";
    cout << left  << setw(25) << "Nombre";
    cout << left  << setw(12) << "Libro";
    cout << left  << setw(15) << "Solicitud";
    cout << left  << setw(30) << "Observacion" << endl;
    imprimirLinea('-');
}

void procesarSolicitud(int &tamP,char*** &prestamoP,int* &stockL,char* fechaS,char* codigoL,char operacionS,char* observacionS,bool &morosoU) {
    if(operacionS=='D'){
        // aumentar stock del libro por devolucion
        stockL[1]++;
        // obtenemos la posicion del libro a desapilar
        int posLibroP = posicionLibroPrestado(codigoL,prestamoP,tamP);
        // comparamos fechas y vemos si se convierte en moroso o no
        int fechaBool = compararFechasStr(fechaS,prestamoP[posLibroP][1]); // -1 si la fecha1 es menor a la fecha2, 0 si son iguales, 1 si es mayor
        // si la fecha cuando lo devuelve se pasa de la establecida en prestamo, se considerara al usuario como moroso
        if(fechaBool==1) morosoU = true;
        observacionS[0] = '\0';
        // desapilar libro en prestamo del usuario

    }else{

    }
}

void imprimirSolicitud(char* fechaS,char* &nombreU,char* codigoL,char operacionS,char* observacionS){
    cout << left << setw(12) << fechaS;
    cout << left << setw(25) << nombreU;
    cout << left << setw(12) << codigoL;
    cout << left << setw(15) << ((operacionS=='D')? "Devolucion" : "Prestamo");
    cout << left << setw(30) << observacionS << endl;
}

int posicionLibroPrestado(char* codigoL,char*** &prestamoP,int &tamP){
    int pos;
    for(pos=0;pos<tamP;pos++){
        if(stringsIguales(codigoL,prestamoP[pos][0])) break;
    }   return pos;
}

// -1 si la fecha1 es menor a la fecha2, 1 si es mayor, 0 si son iguales
int compararFechasStr(char* fechaStr1, char* fechaStr2){
    int i;
    // xx/xx/xxxx
    // 01/34/6789
    // comparando anios
    for(i=6;i<=9;i++){
        if(fechaStr1[i]<fechaStr2[i]) return -1;
        if(fechaStr2[i]<fechaStr1[i]) return  1;
    }
    // comparando meses
    for(i=3;i<=4;i++){
        if(fechaStr1[i]<fechaStr2[i]) return -1;
        if(fechaStr2[i]<fechaStr1[i]) return  1;
    }
    // comparando dias
    for(i=0;i<=1;i++){
        if(fechaStr1[i]<fechaStr2[i]) return -1;
        if(fechaStr2[i]<fechaStr1[i]) return  1;
    }
    return 0;
}