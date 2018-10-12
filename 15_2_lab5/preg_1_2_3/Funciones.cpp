//
// Created by jhair on 12/10/18.
//

#include "Funciones.h"
#include <iostream>
#include <cstring>

#define TAM_CODIGO  8
#define TAM_NOMBRE  50
#define TAM_MAXIMO  200
#define LINEAS      100

using namespace std;


/***********************************************************************************************/
/* FUNCIONES PRINCIPALES */
// Leer primera parte del archivo e imprimir lo leido
void leerCursos(void* &cursos) {
    cin >> ws;
    void* cursosC[TAM_MAXIMO];
    int cont = 0;
    cout << "while leer cursos" << endl;
    while(cin.peek()!='0'){
        char codigoC[TAM_CODIGO];
        char nombreC[TAM_NOMBRE];
        cin.getline(codigoC,TAM_CODIGO,' ' ); cin >> ws;
        cin.getline(nombreC,TAM_NOMBRE,'\n'); cin >> ws;
        guardarCurso((void***)cursosC,codigoC,nombreC,cont);
        cout << cont << " " << codigoC << " " << nombreC << endl;
    }cin.ignore(); // se ignora el cero de separacion
    cin >> ws;
    cout << "cursos memoria dinamica" << endl;
    cursosMemoriaDinamica(cursos,cursosC,cont);
    cout << "imprimir cursos" << endl;
    imprimirCursos(cursos,cont);
}

// Leer segunda parte del archivo e imprimir lo leido
void leerMatricula(void* &cursos) {

}

// Generar reporte de las listas de clases segun formato
void imprimirListasDeClase(void* &cursos) {

}

/***********************************************************************************************/
/* FUNCIONES SECUNDARIAS */

void guardarCurso(void*** cursosC, char* codigoC, char* nombreC, int &cont){
    cout << "guardar cursos" << endl;
    char* codigoNew = new char[strlen(codigoC)+1];
    char* nombreNew = new char[strlen(nombreC)+1];
    strcpy(codigoNew,codigoC);
    strcpy(nombreNew,nombreC);
    cursosC[cont] = new void*[2];
    cursosC[cont][0] = codigoNew;
    cursosC[cont][1] = nombreNew;
    cont++;
}


void cursosMemoriaDinamica(void* &cursos,void* cursosC,int cont){
    cursos = new void*[cont+1];
    for(int i=0;i<cont;i++){
        ((void**)cursos)[i] = ((void**)cursosC)[i];
    }   ((void**)cursos)[cont] = NULL;
}

void imprimirCursos(void* &cursos,int cont){
    imprimirLinea();
    cout << "Cursos" << endl;
    for(int i=0;i<cont;i++){
        cout << "codigo: " << (char*)((void***)cursos)[i][0] << endl;
        cout << "cursos: " << (char*)((void***)cursos)[i][1] << endl;
        imprimirLinea('-');
    }
}
/***********************************************************************************************/
/* FUNCIONES TERCIARIAS */
void imprimirLinea(char c){
    for(int i=0;i<LINEAS;i++){
        cout.put(c);
    }   cout.put('\n');
}