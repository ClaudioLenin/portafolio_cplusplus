/*
  Ejercicio 1
  Calcular la media aritmetica de un vector
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
   int c_p; //contador de elementos del vector
   float a_c; //acumulador de elementos del vector

   void media_vector(int vx[],int cant,int *cc1,float *cc2);//protoripo de la funcion que permite calcular la media aritmetica

   cout<<"\t\tCALCULAR LA MEDIA ARITMETICA\n";
   cout<<"________________________________________________________";
   n=lee_n(T);//llamado a la funcion que permite el ingreso de la cantidad de valores para el vector
   leer_vector(v,n); //llamado a la funcion que permite el ingreso de los N elementos al vector
   media_vector(v,n,&c_p,&a_c);//llamado a la funcion que permite calcular la media aritmetica
   cout<<"\nLa media es: "<<a_c/c_p;

   getch();
   return 0;
}//de main
//
void media_vector(int vx[],int cant,int *cc1,float *cc2)//funcion que permite calcular la media aritmetica
{//de media_vector
   float acum=0; //variable acumuladora
   int c_el=0; //contador de elementos
   for(int i=0;i<cant;i++){
     acum+=vx[i];
     c_el++;
     }
   *cc1=c_el;
   *cc2=acum;
}//de media_vector
