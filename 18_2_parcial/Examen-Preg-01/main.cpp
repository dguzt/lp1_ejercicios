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
 * Created on 16 de octubre de 2018, 08:11 AM
 */

#include <iostream>
#include <cstdlib>
#include "Func-Ex-Preg01.h"

using namespace std;

int main(int argc, char** argv) {
    int* asientos;
    char*** rutas;
    leerRutas(rutas,asientos);
    imprimirRutas(rutas,asientos);
    return 0;
}

