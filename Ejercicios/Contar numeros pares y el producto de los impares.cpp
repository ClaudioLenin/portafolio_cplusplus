/*
  Ejercicio 4
  Calcular la sumatoria de los elementos que ocupan las posiciones pares, y la productoria
  de los elementos que ocupan las posiciones impares de un vector previamente ingresado
*/
#include <iostream.h>
#include <conio.h>
#include <deber7.h>
#define T 20  //dimension definida para el arreglo
void main ()
{//de main
   int v[T]; //declaracion del arreglo con dimension T
   int n; //variable que recibe la cantidad de elementos al vector
   int s; //variable que contiene la suma de los pares
   int p; //variable que contiene la productoria de los impares


   void sum_prod(int v[],int cant,int *x1,int *x2);//protoripo de la funcion que permite calcular la sumatoria y la productoria

   cout<<"SUMATORIA DE POSCIONES PARES Y PRODUCTORIA DE LAS IMPARES\n";
   cout<<"________________________________________________________";
   n=lee_n(T);//llamado a la funcion que permite el ingreso de la cantidad de valores para el vector
   leer_vector(v,n); //llamado a la funcion que permite el ingreso de los N elementos al vector
   sum_prod(v,n,&s,&p);//llamado a la funcion que permite calcular la sumatoria y la productoria

   cout<<"\nLa sumatoria de los pares es: "<<s;
   cout<<"\nLa productoria de los impares es: "<<p;
   getch();
}//de main
//
void sum_prod(int v[],int cant,int *x1,int *x2)//protoripo de la funcion que permite calcular la sumatoria y la productoria
{
   int i=0;
   for(*x1=0,*x2=1 ;(i<cant); i++)
      (i%2==0)?*x1+=v[i]:*x2*=v[i];
}

