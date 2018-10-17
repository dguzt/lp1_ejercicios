/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Autor : Jhair Guzman
 * Codigo: 20163275
 *
 */

#include <iostream>
#include <cstdlib>
#include "Func-Ex-Preg01.h"
#include "Func-Ex-Preg02.h"

using namespace std;

int main(int argc, char** argv) {
    int* asientos;
    char ***rutas, ****pasajeros, ***sinAsignar;
    leerRutas(rutas,asientos);
    imprimirRutas(rutas,asientos);
    ubicarPasajeros(rutas,asientos,pasajeros,sinAsignar);
    reporteDeViajes(rutas,asientos,pasajeros,sinAsignar);
    return 0;
}

