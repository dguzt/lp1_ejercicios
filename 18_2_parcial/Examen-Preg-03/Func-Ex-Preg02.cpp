/* 
 * File:   Func-Ex-Preg02.h
 * Author: Jhair Guzman
 * Codigo: 20163275
 *
 * Created on 16 de octubre de 2018, 09:12 AM
 */

#include "Func-Ex-Preg02.h"
#include "Func-Ex-Preg01.h"
#include <iostream>
#include <iomanip>
#include <cstring>

#define TAM_DNI     10
#define TAM_NOMBRE  100
#define INCREMENTO  5

using namespace std;

void ubicarPasajeros(char*** &rutas ,int* &asientos, char**** &pasajeros, char*** &sinAsignar){
    int cantRutas = tamanioArreglo(rutas);
    pasajeros = new char***[cantRutas+1];
    int cantPasajxRuta[cantRutas];
    for(int i=0;i<cantRutas;i++) cantPasajxRuta[i] = 0;
    int cantSinAs = 0;
    while(!cin.eof()){
        char** pasajero = obtenerDatosPasajero();
        int posBus = posicionBusConRutaDePasajero(rutas,pasajero[2]);
        // si no existe bus con destino a la ciudad del pasajero
        if(posBus==-1){
            colocarPasajeroSinAsignar(sinAsignar,cantSinAs,pasajero);
        // si existe un bus con su destino
        }else{
            // si aun hay asiento en ese bus para esa ruta
            if(asientos[posBus]>0){
                if(cantPasajxRuta[posBus%INCREMENTO==0]) aumentarArreglo(pasajeros[posBus],cantPasajxRuta[posBus],INCREMENTO);
                pasajeros[posBus][cantPasajxRuta[posBus]] = pasajero;
                cantPasajxRuta[posBus]--;
            // si no alcanzó asiento, entonces se almacena en sinAsignar
            }else{
                colocarPasajeroSinAsignar(sinAsignar,cantSinAs,pasajero);
            }
        }
    }
}

char** obtenerDatosPasajero(){
    char dniP[TAM_DNI];
    char nombreP[TAM_NOMBRE];
    char ciudadP[TAM_NOMBRE];
    cin.getline(dniP,TAM_DNI,',');
    cin.getline(nombreP,TAM_NOMBRE,',');
    cin.getline(ciudadP,TAM_NOMBRE,',');
    char* dniNew = new char[strlen(dniP)+1];
    char* nombreNew = new char[strlen(nombreP)+1];
    char* ciudadNew = new char[strlen(ciudadP)+1];
    strcpy(dniNew,dniP);
    strcpy(nombreNew,nombreP);
    strcpy(ciudadNew,ciudadP);
    char** pasajero = new char*[3];
    pasajero[0] = dniNew;
    pasajero[1] = nombreNew;
    pasajero[2] = ciudadNew;
    return pasajero;
}

void colocarPasajeroSinAsignar(char*** &sinAsignar, int &cantSinAs,char** pasajero){
    if(cantSinAs%INCREMENTO==0) aumentarArreglo(sinAsignar,cantSinAs,INCREMENTO);
    sinAsignar[cantSinAs] = pasajero;
    cantSinAs++;
}
   
int posicionBusConRutaDePasajero(char*** rutas, char* ciudad){
    int contRutas=0;
    while(rutas[contRutas]!=NULL){
        char** ruta = rutas[contRutas];
        // se busca dentro de las ciudades de una ruta
        for(int i=2; ruta[i]!=NULL;i++){
            char* ciudadRuta = ruta[i];
            if(strcmp(ciudadRuta,ciudad)==0) return contRutas;
        }
        contRutas++;
    }
    return -1;
}


    
////////////////////////////////////////////////////////////////////////////////
void reporteDeViajes(char*** rutas ,int* asientos, char**** pasajeros, char*** sinAsignar){
    imprimirLinea();
    cout << setw(60) << right << "Lista de pasajeros" << endl;
    imprimirLinea();
    // impresion por cada bus con su respectiva ruta
    for(int iRutas=0;rutas[iRutas]!=NULL;iRutas++){
        char** ruta = rutas[iRutas];
        cout << "Vehiculo No. " << iRutas << endl;
        cout << "Placa: "  << ruta[0] << endl;
        cout << "Chofer: " << ruta[1] << endl;
        int cantCiudades = imprimirRuta(ruta);
        cout << "Pasajeros: " << endl;
        imprimirPasajerosxCiudad(ruta,cantCiudades,pasajeros[iRutas]);
        imprimirLinea('-');
    }
    imprimirPasajerosSinAsignar(sinAsignar);
}

int imprimirRuta(char** ruta){
    cout << "Ruta:";
    int iCiu;
    for(iCiu=0;ruta[iCiu+2]!=NULL;iCiu++){
        cout << ((iCiu==0)? " " : " - ") << ruta[iCiu+2];
    }   cout << endl;
    return iCiu;
}

void imprimirPasajerosxCiudad(char** ruta, int cantCiudades, char*** pasajerosRuta){
    for(int iCiu=0;iCiu<cantCiudades;iCiu++){
        char* ciudad = ruta[iCiu+2];
        cout << ciudad << ": "   << endl;
        cout << left << setw(10) << "No.";
        cout << left << setw(15) << "DNI";
        cout << left << setw(50) << "NOMBRE" << endl;
        int cantPasaj = 0;
        for(int iPasaj=0;pasajerosRuta[iPasaj]!=NULL;iPasaj++){
            char** pasajero = pasajerosRuta[iPasaj];
            // imprimiendo cada ciudad, imprimimos pasajeros que van a dicha ciudad
            if(strcmp(ciudad,pasajero[2])==0){
                cout << left << setw(10) << (cantPasaj+1);
                cout << left << setw(15) << pasajero[0];
                cout << left << setw(50) << pasajero[1] << endl;
                cantPasaj++;
            }
        }
    }
}
        

void imprimirPasajerosSinAsignar(char*** sinAsignar){
    imprimirLinea();
    cout << "PASAJEROS SIN ASIGNAR" << endl;
    cout << left << setw(10) << "No.";
    cout << left << setw(15) <<"DNI";
    cout << left << setw(50) <<"NOMBRE";
    cout << left << setw(25) <<"DESTINO" << endl;
    for(int iPasaj=0;sinAsignar[iPasaj]!=NULL;iPasaj++){
        char** pasajero = sinAsignar[iPasaj];
        cout << right << setw(2) << (iPasaj+1);
        cout << right << setw(15) << pasajero[0];
        cout << right << setw(50) << pasajero[1];
        cout << right << setw(25) << pasajero[2];
    }
}

////////////////////////////////////////////////////////////////////////////////
// FUNCIONES AUXILIARES
template <typename T>
int tamanioArreglo(T* arreglo){
    int cont = 0;
    while(arreglo[cont]!=NULL) cont++;
    return cont;
}
template int tamanioArreglo(char****);
template int tamanioArreglo(char*** );
template int tamanioArreglo(char**  );
template int tamanioArreglo(int**   );
template int tamanioArreglo(int***  );
template int tamanioArreglo(int**** );

template <typename T>
void aumentarArreglo(T* &arregloDin, int cantidad, int incremento){
    // caso base
    if(cantidad==0){
        arregloDin = new T[incremento+1];
        for(int i=0; i<=incremento;i++) arregloDin[i]=(T)0;
        return;
    }
    // para los otros casos
    T* arregloAux = new T[cantidad+incremento+1];
    for(int i=0;i<cantidad;i++) arregloAux[i]=arregloDin[i];
    for(int i=cantidad;i<=(cantidad+incremento);i++) arregloAux[i]=(T)0;
    arregloDin = arregloAux;
}
template void aumentarArreglo(char****&,int,int);
template void aumentarArreglo(char*** &,int,int);
template void aumentarArreglo(char**  &,int,int);
template void aumentarArreglo(int***  &,int,int);
template void aumentarArreglo(int**   &,int,int);
template void aumentarArreglo(int*    &,int,int);



