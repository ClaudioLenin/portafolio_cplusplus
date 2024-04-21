/*
  Ejercicio 1
  Invertir el orden de los elementos de un vector
*/
#include "iostream"
#include <conio.h>
#include "header1.h"
#define T 20  //dimension definida para el arreglo
using namespace std;
int main ()
{//de main
   int v[T]; //declaracion del arreglo con dimension T
   int n; //variable que recibe la cantidad de elementos al vector

   void invertir_vector(int v[],int cant);//prototipo de la funcion que permite invertir el vector

   cout<<"\t\tINVERTIR EL ORDEN DE UN VECTOR\n";
   cout<<"________________________________________________________";
   n=lee_n(T);//llamado a la funcion que permite el ingreso de la cantidad de valores para el vector
   leer_vector(v,n); //llamado a la funcion que permite el ingreso de los N elementos al vector
   invertir_vector(v,n);//llamado a la funcion que permite invertir el vector

   cout<<"\n\t\tVECTOR INVERTIDO";
   imprime_vector(v,n);//llamado a la funcion que imprime el vector

   getch();
   return 0;
}//de main
//
void invertir_vector(int v[],int cant)//funcion que permite invertir el vector
{

   int i,j;
   int aux[T]; //vector auxiliar que permite almacenar datos para luego ubicar en otro lugar
   int x;

   for(i=0;i<cant;i++)
       aux[i]=v[i];

   for(i=0,j=(cant-1);i<cant;i++){
     v[i]=aux[j];
     j--;
   }


}
