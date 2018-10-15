//
// Autor : Jhair Guzman
// Codigo: 20163275

#ifndef PREG02_BIBLIOTECA_FUNC_INCENDIOS_H
#define PREG02_BIBLIOTECA_FUNC_INCENDIOS_H

void leerIncendios(long int***&,char***&);
void imprimirIncendios(long int***&,char***&);

void inicializarIncendios(long int***&,char***,int*&);
void leerDatosIncendio(long int&,char*,long int&,long int&,long int&,long int&, long int&);
int posicionCiudadArreglo(char***,char*);
void almacenarIncendioCiudad(long int**&,int,long int,long int,long int,long int,long int,long int);
void ordenarIncendiosxCiudad(long int***&,int*);
void quicksortIncendios(long int**&,int,int);
int particionIncendios(long int**&,int,int);

void imprimirIncendiosCiudad(long int**);

/* FUNCIONES AUXILIARES */
template <typename T>
int tamanioArreglo(T*);
template <typename T>
void aumentarArreglo(T*&,int,int);

#endif //PREG02_BIBLIOTECA_FUNC_INCENDIOS_H
