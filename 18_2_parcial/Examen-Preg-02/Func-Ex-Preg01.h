/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Func-Ex-Preg01.h
 * Autor : Jhair Guzman
 * Codigo: 20163275
 *
 * Created on 16 de octubre de 2018, 08:14 AM
 */

#ifndef FUNC_EX_PREG01_H
#define FUNC_EX_PREG01_H

    void leerRutas(char***&,int*&);
    void imprimirRutas(char***&,int*&);
    
    void leeryAlmacenarDatosChofer(char***,int);
    void leeryAlmacenarCiudadesDestino(char***,int);
    void leeryAlmacenarMaxPasajeros(int*,int);

    void actualizarRutaConDatosCiudad(char**&,char**&,int);
    
    // funciones auxiliares
    bool esNumero(char);
    void imprimirLinea(char='=');
    template <typename T>
    void arregloMemoriaDinamica(T*&,T*,int);
    
#endif /* FUNC_EX_PREG01_H */

