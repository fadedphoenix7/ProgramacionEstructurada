/*
Autor: Jimmy Nathan Ojeda Arana
Entradas: Se genera un vector de n numeros
Salidas: Se imprime el promedio, la desviacion estandar y la varianza de los elementos del vector
Proceso: Se define una funcion para rellenar el vector, otra para obtener el promedio, se captura el valor del promedio en una
variable llamada "promedio" y con ello se obtiene la desviacion estandar y la varianza.
*/

#include <iostream>
#include<stdlib.h>
#include<time.h>
#include<math.h>

using namespace std;

void rellenarVector(int*,int,int);
void imprimirVector(int*,int,int);
float funcionMedia(int*,int,int);
void funcionDesviacionEstandar(int*,int,float,int);
void funcionVarianza(int*,int,float,int);

int main()
{
    srand(time(NULL));
    int n;
    cout<<"Ingresa la cantidad de numeros del vector"<<endl;
    cin>>n;
    const int tamanio=n;
    int vectorN[tamanio];
    rellenarVector(vectorN,tamanio,n);
    cout<<"Los numeros generados en el vector son"<<endl;
    imprimirVector(vectorN,tamanio,n);
    funcionMedia(vectorN,tamanio,n);
    //Se guarda el valor del promedio para poder ser usado en otras funciones
    float promedio=funcionMedia(vectorN,tamanio,n);
    cout<<"El promedio es "<<promedio<<endl;
    funcionDesviacionEstandar(vectorN,tamanio,promedio,n);
    funcionVarianza(vectorN,tamanio,promedio,n);

    return 0;
}

void rellenarVector(int* vectorN,int tamanio,int n){
    for (int i=0;i<n;i++){
        //Se generan numeros al azar del 1 al 100
        vectorN[i]=rand()%101;
    }
}

void imprimirVector(int* vectorN,int tamanio,int n){
    for (int i=0;i<n;i++){
        //Se imprime el vector generado
        cout<<vectorN[i]<<endl;
    }
}

float funcionMedia(int* vectorN,int tamanio,int n){
    float sumaNumeros=0;
    for (int i=0;i<n;i++){
        sumaNumeros=sumaNumeros+vectorN[i];
    }
    //Se devuelve el promedio
    return sumaNumeros/n;
}

void funcionDesviacionEstandar(int* vectorN,int tamanio,float promedio,int n){
    int diferenciaAPromedio,diferenciaAPromedioCuadrada;
    int sumaDeDiferenciasCuadradas=0;
    float desviacionEstandar;
    //Se halla la diferencia del promedio con cada numero del vector
    for (int i=0;i<n;i++){
        diferenciaAPromedio=promedio-vectorN[i];
        //Se eleva al cuadrado dicha diferencia
        diferenciaAPromedioCuadrada=diferenciaAPromedio*diferenciaAPromedio;
        //Se suman todas las diferencias al cuadrado
        sumaDeDiferenciasCuadradas=sumaDeDiferenciasCuadradas+diferenciaAPromedioCuadrada;
    }
    //Se saca la raiz cuadrada de la division de las diferencias al cuadrado entre el numero n de elementos del vector
    desviacionEstandar=sqrt(sumaDeDiferenciasCuadradas/n);
    cout<<"La desviacion estandar es "<<desviacionEstandar<<endl;
}

void funcionVarianza(int* vectorN,int tamanio,float promedio,int n){
    int diferenciaAPromedio,diferenciaAPromedioCuadrada;
    int sumaDeDiferenciasCuadradas=0;
    float varianza;
    for (int i=0;i<n;i++){
        //Se halla la diferencia del promedio con cada numero del vector
        diferenciaAPromedio=promedio-vectorN[i];
        //Se eleva al cuadrado dicha diferencia
        diferenciaAPromedioCuadrada=diferenciaAPromedio*diferenciaAPromedio;
        //Se suman todas las diferencias al cuadrado
        sumaDeDiferenciasCuadradas=sumaDeDiferenciasCuadradas+diferenciaAPromedioCuadrada;
    }
    //Se divide entre n la cantidad obtenida de la suma
    cout<<"La varianza es "<<sumaDeDiferenciasCuadradas/n;
}