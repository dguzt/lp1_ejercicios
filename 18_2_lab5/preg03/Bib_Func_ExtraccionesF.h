//
// Created by jhair on 15/10/18.
//

#ifndef PREG03_BIB_FUNC_EXTRACCIONESF_H
#define PREG03_BIB_FUNC_EXTRACCIONESF_H


void leerExtracciones(char**&,double***&);
void imprimirExtracciones(char**,double***,char***);

void leerDatosExtraccion(double&,double&,double&,double&,double&,double&,double&,char*);
int posicionEspecie(char**,char*,int);

void insertarEspecie(char**&,char*,int);
void insertarExtraccion(double**&,double,double,double,double,double,double,double);

void ordenarEspeciesyExtracciones(char**&,double***&,int);

void quicksortEspecies(char**&,double***&,int,int);
int particionEspecies(char**&,double***&,int,int);

void quicksortExtracciones(double**&,int,int);
int particionExtracciones(double**&,int,int);
int compararExtracciones(double*,double*);

void imprimirCabeceraEspecie(char*,int,char***);
int posicionProvinciaCodigo(char***&,int);

#endif //PREG03_BIB_FUNC_EXTRACCIONESF_H
