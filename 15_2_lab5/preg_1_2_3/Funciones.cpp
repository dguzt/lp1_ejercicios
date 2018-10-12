//
// Created by jhair on 12/10/18.
//

#include "Funciones.h"
#include <iostream>
#include <cstring>

#define TAM_CODIGO  8
#define TAM_NOMBRE  80
#define TAM_MAXIMO  200
#define LINEAS      100
#define INCREMENTO  5

using namespace std;


/***********************************************************************************************/
/* FUNCIONES PRINCIPALES */
// Leer primera parte del archivo e imprimir lo leido
void leerCursos(void* &cursos) {
    cin >> ws;
    void* cursosC[TAM_MAXIMO];
    int cont = 0;
    while(cin.peek()!='0'){
        char codigoC[TAM_CODIGO];
        char nombreC[TAM_NOMBRE];
        cin.getline(codigoC,TAM_CODIGO,' ' ); cin >> ws;
        cin.getline(nombreC,TAM_NOMBRE,'\n'); cin >> ws;
        guardarCurso((void***)cursosC,codigoC,nombreC,cont);
    }cin.ignore(); // se ignora el cero de separacion
    cin >> ws;
    cursosMemoriaDinamica(cursos,cursosC,cont);
    imprimirCursos(cursos,cont);
}

// Leer segunda parte del archivo e imprimir lo leido
void leerMatricula(void* &cursos) {
    actualizarCursos((void***&)cursos);
    // inicializamos contadores del numero de alumnos para cada curso
    int cantC = tamArreglo((void**)cursos);
    int cantAxC[cantC];
    for(int i=0;i<cantC;i++) cantAxC[i]=0;
    // inicia la lectura de los alumnos matriculados
    int i  = 0;
    while(cin.peek()!='0'){
        i++;
        int codigoA;
        char nombreA[TAM_NOMBRE];
        cin >> codigoA; cin >> ws;
        cin.getline(nombreA,TAM_NOMBRE,' '); cin >> ws;
        // inicia la lectura de los cursos en los que un alumno se ha matriculado
        while(cin.peek()!='\n'){
            char codigoC[TAM_CODIGO];
            cin >> codigoC;
            ignorarEspacios();
            cout << "pos" << endl;
            int posCurso = posicionCurso(cursos,codigoC);
            cout << "pos es ... " << posCurso << endl;
            agregarAlumno(((void***&)cursos)[posCurso],codigoA,nombreA,cantAxC[posCurso]);
            cout << "alumno agregado" << endl;
        } cin.ignore();
    }
    imprimirAlumnosxCursos(cursos);
}

// Generar reporte de las listas de clases segun formato
void imprimirListasDeClase(void* &cursos) {

}

/***********************************************************************************************/
/* FUNCIONES SECUNDARIAS */

void guardarCurso(void*** cursosC, char* codigoC, char* nombreC, int &cont){
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

void actualizarCursos(void*** &cursos){
    int i=0;
    while(cursos[i]!=NULL){
        void** cursoAmpliado = new void*[4];
        cursoAmpliado[0] = cursos[i][0];
        cursoAmpliado[1] = cursos[i][1];
        delete [] cursos[i];
        cursos[i] = cursoAmpliado;
        i++;
    }
}

int posicionCurso(void* &cursos,char* codigoC){
    int pos = 0;
    while(true){
        cout << " comparar: " << (char*)((void***)cursos)[pos][0] << " = " << codigoC << endl;
        if(strcmp((char*)((void***)cursos)[pos][0],codigoC)==0)
            break;
        pos++;
    }
    return pos;
}

void ignorarEspacios(){
    char c;
    while(true){
        c=(char)cin.peek();
        if(c==' ' or c=='\t'){
            cin.ignore();
            continue;
        }
        return;
    }
}

void agregarAlumno(void** &curso,int codigoA,char* nombreA,int &cont){
    cout << "agregar alumno: " << cont << "codigo: " << nombreA << endl;
    // obtenemos un string exacto del nombre del alumno
    char* nombreNew = new char[strlen(nombreA)+1];
    strcpy(nombreNew,nombreA);
    if(cont%TAM_MAXIMO==0){
        aumentarArreglo((int*&)curso[2],cont,INCREMENTO);
        aumentarArreglo((void**&)curso[3],cont,INCREMENTO);
    }
    ((int*)curso[2])[cont] = codigoA;
    ((void**)curso[3])[cont] = nombreNew;
    cont++;
}


void imprimirAlumnosxCursos(void* &cursos){
    imprimirLinea();
    cout << "Cursos y Matriculados" << endl;
    imprimirLinea();
    int iCursos = 0;
    while(((void**)cursos)[iCursos]!=NULL){
        imprimirLinea('*');
        int iAlum = 0;
        while(((void****)cursos)[iCursos][3][iAlum]!=NULL){
            cout << "   codigo: " << ((int*)((void***)cursos)[iCursos][2])[iAlum] << endl;
            cout << "   alumno: " << ((char*)((void***)cursos)[iCursos][3])[iAlum] << endl;
            imprimirLinea('-');
            iAlum++;
        }
        iCursos++;
    }
}

/***********************************************************************************************/
/* FUNCIONES TERCIARIAS */
void imprimirLinea(char c){
    for(int i=0;i<LINEAS;i++){
        cout.put(c);
    }   cout.put('\n');
}

template<typename T>
int tamArreglo(T* arreglo) {
    int pos = 0;
    while(arreglo[pos]!=NULL) pos++;
    return pos;
}
template int tamArreglo(void**);
template int tamArreglo(void***);

template <typename T>
void aumentarArreglo(T* &arreglo, int contador, int aumento){
    // caso base
    if(contador==0){
        arreglo = new T[aumento+1]; // +1 por el ultimo elemento NULL
        for(int i=0;i<=aumento;i++) arreglo[i] = NULL;
        return;
    }
    // otros casos
    T* auxiliar = new T[contador+aumento+1];
    for(int i=0;i<contador;i++) auxiliar[i] = arreglo[i];
    for(int i=contador;i<=(contador+aumento);i++) auxiliar[i] = NULL;
    delete [] arreglo;
    arreglo = auxiliar;
}
template void aumentarArreglo(int*&,int,int);
template void aumentarArreglo(void**&,int,int);
template void aumentarArreglo(void***&,int,int);
