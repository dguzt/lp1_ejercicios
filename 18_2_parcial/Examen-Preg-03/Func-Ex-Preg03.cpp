/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 * 
 * Autor: Jhair Guzman
 * Codigo: 20163275
 * 
 */

#include "Func-Ex-Preg03.h"
#include <iostream>

using namespace std;


void redefinirRutas(char*** &rutas, int* &asientos,char**** &pasajeros){
    char** ciudadesDest;
    obtenerCiudadesDestinoPasajeros(pasajeros,ciudadesDest);
    for(int iRutas=0;rutas[iRutas]!=NULL;iRutas++){
        borrarCiudadesDeRuta(rutas[iRutas],ciudadesDest);    
    }
    // disminuir asientos, si pasajero no encuentra asiento, se elimina de pasajeros
    for(int iPasaj=0;pasajeros[iPasaj]!=NULL;iPasaj++){
        char*** pasajero = pasajeros[iPasaj];
        int posbus = posicionBusConRutaDePasajero(rutas,pasajero[2]);
        // no encontró bus, se elimina de la lista
        if(posbus==-1){
            eliminarPasajero(pasajeros,iPasaj);
        }
    }
}

void obtenerCiudadesDestinoPasajeros(char**** pasajeros, char** &ciudadesDest){
    
}
    
void borrarCiudadesDeRuta(char** &ruta,char** ciudadesDest){
    
}

void eliminarPasajero(char**** &pasajeros, int iPasaj){
    
}
