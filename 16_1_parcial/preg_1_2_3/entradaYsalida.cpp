//
// Created by jhair on 10/10/18.
//

#include "entradaYsalida.h"
#include <iostream>
#include <iomanip>
#include <cstring>

#define TAM_DNI     10  // 8 digitos + 1 del '\0'
#define TAM_NOMBRE  50  // tanto apellido como nombre
#define TAM_CARGAF  3   // SI o NO de Carga Familiar
#define INCREMENTO  5
#define LINEAS      100

using namespace std;

void leerDatos(void* &contribuyentes) {
    int cont = 0;
    leerDatosParte1(contribuyentes,cont);
    leerDatosParte2(contribuyentes,cont);
}

void reporte(void* &contribuyentes) {
    imprimirCabeceraReporte();
    cout.fixed; cout.precision(2);
    int i=0;
    while(((void**)contribuyentes)[i]!=NULL){
        int    riesgo = *(int   *)((void***)contribuyentes)[i][4];
        char*  carga  =  (char  *)((void***)contribuyentes)[i][5];
        double monto  = *(double*)((void***)contribuyentes)[i][6];
        char* nombres =  (char  *)((void***)contribuyentes)[i][1];
        char* apellidoPat = (char*)((void***)contribuyentes)[i][2];
        char* apellidoMat = (char*)((void***)contribuyentes)[i][3];
        cout << left << setw(10) << (char*)((void***)contribuyentes)[i][0];
        cout << left << nombres << " " << apellidoPat << " " << apellidoMat;
        cout << left << setw(60-(int)strlen(nombres)-(int)strlen(apellidoPat)-(int)strlen(apellidoMat)-2) << " ";
        cout << left << setw(10) << fixed << lineaCreditoBanco(riesgo,carga,monto,'A');
        cout << left << setw(10) << fixed << lineaCreditoBanco(riesgo,carga,monto,'B');
        cout << left << setw(10) << fixed << lineaCreditoBanco(riesgo,carga,monto,'C');
        cout << "carga: " << carga << " monto: " << monto << " riesgo: " << riesgo;
        cout << endl;
        i++;
    }
}

/**********************************************************************/
/************* FUNCIONES AUXILIARES DE ENTRADAYSALIDA.CPP *************/

/* FUNCIONES PARA LECTURA DE DATOS */

void leerDatosParte1(void* &contribuyentes,int &cont){
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
        contribuyente[5] = stringPreciso(cargaC);
        // para los numeros riesgoC y montoC
        contribuyente[4] = numeroPreciso(riesgoC);
        contribuyente[6] = numeroPreciso(montoC);
        agregarContribuyente(contribuyentes,cont,contribuyente);
    }
}

void leerDatosParte2(void* &contribuyentes,int& cont){
    cin >> ws; cin.clear();
    while(!cin.eof()){
        char dni[TAM_DNI];
        double monto;
        cin.getline(dni,TAM_DNI,',');
        cin >> monto;
        cin.ignore(); cin.clear();  // se ignora el salto de linea
        int posC = posicionContribuyente(dni,contribuyentes,cont);
        *(double*)((void***)contribuyentes)[posC][6] = monto;
        cin >> ws; cin.clear();
    }
}

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

int posicionContribuyente(char* dni,void* &contribuyentes,int cont){
    int pos;
    for(pos=0;pos<cont;pos++){
        if(stringsIguales(dni,((char*)((void***)contribuyentes)[pos][0]))) break;
    }
    cout << "return pos: " << pos << endl;
    return pos;
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


/* FUNCIONES PARA REPORTE */

void imprimirLinea(char c){
    for(int i=0;i<LINEAS;i++){
        cout.put(c);
    }   cout.put('\n');
}

void imprimirCabeceraReporte(){
    imprimirLinea();
    cout << right << setw(58) << "LINEAS DE CREDITO" << endl;
    imprimirLinea();
    cout << left << setw(10) << "DNI";
    cout << left << setw(60) << "NOMBRE";
    cout << left << setw(10) << "BANCO A";
    cout << left << setw(10) << "BANCO B";
    cout << left << setw(10) << "BANCO C" << endl;
}

double lineaCreditoBanco(int riesgo,char* carga,double monto,char banco) {
    return (4*monto)/14 * f(carga,banco)/3 * h(riesgo,banco);
}

int f(char* carga,char banco) {
    bool no = (strcmp(carga,"No")==0);
    switch(banco){
        case 'A': return (no) ? 3 : 1;
        case 'B': return (no) ? 4 : 1;
        case 'C': return (no) ? 3 : 2;
        default:  return 0;
    }
}

double h(int riesgo,char banco) {
    switch(banco){
        case 'A': return (1<=riesgo && riesgo<=2) ? 3.0 :
                         (3<=riesgo && riesgo<=5) ? 0.6 :
                         (6<=riesgo && riesgo<=7) ? 0.6 :
                                                    0.0 ;
        case 'B': return (1<=riesgo && riesgo<=2) ? 1.0 :
                                                    0.0 ;
        case 'C': return (riesgo==1)              ? 1.0 :
                         (2<=riesgo && riesgo<=4) ? 0.4 :
                                                    0.0 ;
        default:  return 0.0;
    }
}

bool stringsIguales(char* string1, char* string2){
    int i=-1;
    while(true){
        i++;
        if(string1[i]=='\0' && string2[i]=='\0') return true;
        if(string1[i]==string2[i])                  continue;
        return false;
    }
}