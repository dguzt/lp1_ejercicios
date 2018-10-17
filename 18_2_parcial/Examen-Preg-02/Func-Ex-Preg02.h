/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Func-Ex-Preg02.h
 * Author: Jhair Guzman
 * Codigo: 20163275
 *
 * Created on 16 de octubre de 2018, 09:12 AM
 */

#ifndef FUNC_EX_PREG02_H
#define FUNC_EX_PREG02_H

    int* asientos;
    char ***rutas, ****pasajeros, ***sinAsignar;
    void ubicarPasajeros(char***&,int*&,char****&,char***&);
    void reporteDeViajes(char***,int*,char****,char***);
    
    char** obtenerDatosPasajero();
    int posicionBusConRutaDePasajero(char***,char*);
    void colocarPasajeroSinAsignar(char***&,int&,char**);

    
    int imprimirRuta(char**);
    void imprimirPasajerosxCiudad(char**,int,char***);
    void imprimirPasajerosSinAsignar(char***);

    // funciones auxiliares
    template <typename T>
    int tamanioArreglo(T*);
    template <typename T>
    void aumentarArreglo(T*&,int,int);

#endif /* FUNC_EX_PREG02_H */

