//
// Created by jhair on 10/10/18.
//

#include "entradaYsalida.h"
#include <iostream>
#include <iomanip>
#include <cstring>

#define TAM_DNI     9   // 8 digitos + 1 del '\0'
#define TAM_NOMBRE  50  // tanto apellido como nombre
#define TAM_CARGAF  3   // SI o NO de Carga Familiar
#define INCREMENTO  5

using namespace std;

void leerDatos(void* &contribuyentes) {
    int cont = 0;
    while(cin.peek()!='\n'){
        char dniC[TAM_DNI];
        char nombresC[TAM_NOMBRE];
        char apellidoPatC[TAM_NOMBRE];
        char apellidoMatC[TAM_NOMBRE];
        char cargaC[TAM_CARGAF];
        int riesgoC;
        double montoC = 0.0;
        leerDatosContribuyente(dniC,nombresC,apellidoPatC,apellidoMatC,cargaC,riesgoC);
        void** contribuyente = new void*[7];
        contribuyente[0] = stringPreciso(dniC);
        contribuyente[1] = stringPreciso(nombresC);
        contribuyente[2] = stringPreciso(apellidoPatC);
        contribuyente[3] = stringPreciso(apellidoMatC);
        contribuyente[4] = stringPreciso(cargaC);
        // para los numeros riesgoC y montoC
        contribuyente[5] = numeroPreciso(riesgoC);
        contribuyente[6] = numeroPreciso(montoC);
        agregarContribuyente(contribuyentes,cont,contribuyente);
    }
}

void reporte(void* &contribuyentes) {

}

/*********************************************************************/
/* FUNCIONES AUXILIARES DE ENTRADAYSALIDA.CPP */

void leerDatosContribuyente(char* dniC,char* nombresC,char* apellidoPatC,char* apellidoMatC,char* cargaC,int &riesgoC){
    cin.getline(dniC,TAM_DNI,',');
    cin.getline(nombresC,TAM_NOMBRE,',');
    cin.getline(apellidoPatC,TAM_NOMBRE,',');
    cin.getline(apellidoMatC,TAM_NOMBRE,',');
    cin.getline(cargaC,TAM_CARGAF,',');
    cin >> riesgoC; cin.ignore();               // se ignora el salto de linea
}

char *stringPreciso(char* cadena) {
    char* cadenaAux = new char[strlen(cadena)+1];
    strcpy(cadenaAux,cadena);
    return cadenaAux;
}

template<typename T>
T *numeroPreciso(T &numero) {
    T* numeroAux = new T;
    (*numeroAux) = numero;
    return numeroAux;
}
template double* numeroPreciso(double&);
template int*    numeroPreciso(int&);


void agregarContribuyente(void* &contribuyentes,int &cont,void** &contribuyente){
    if(cont%INCREMENTO==0) aumentarArreglo((void**&)contribuyentes,cont,INCREMENTO);
    ((void**)contribuyentes)[cont] = (void*)contribuyente;
    cont++;
}

template<typename T>
void aumentarArreglo(T* &arreglo,int cantidad,int aumento) {
    // caso base
    if(cantidad==0){
        arreglo = new T[cantidad+aumento+1];
        for(int i=0;i<=(cantidad+aumento);i++)
            arreglo[i] = (T)0;
        return;
    }
    // otros casos
    T* auxiliar = new T[cantidad + aumento + 1];
    for(int i=0;i<cantidad;i++) auxiliar[i] = arreglo[i];
    for(int i=cantidad;i<=(cantidad+aumento);i++) auxiliar[i] = (T)0;
    delete [] arreglo;
    arreglo = auxiliar;
}
template void aumentarArreglo(void**&,int,int);


