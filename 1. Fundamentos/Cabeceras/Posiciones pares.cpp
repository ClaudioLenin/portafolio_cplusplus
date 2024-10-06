/*
  Ejercicio 2
  Imprimir las posiciones de los elementos mayores que el valor X
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
   int x; //variable que recibe el elemento X

   void elementos_mayores(int v1[],int c,int v_x);//prototipo de la funcion que permite la impresion de los elementos mayores a X

   cout<<"\t\tIMPRIMIR POSICIONES DE ELEMENTOS MAYORES A X\n";
   cout<<"________________________________________________________";
   n=lee_n(T);//llamado a la funcion que permite el ingreso de la cantidad de valores para el vector
   leer_vector(v,n); //llamado a la funcion que permite el ingreso de los N elementos al vector
   cout<<"________________________________________________________";
   cout<<"\nIngrese el valor de X:";
   cin>>x;
   elementos_mayores(v,n,x);//llamado a la funcion que permite la impresion de los elementos mayores a X
   getch();
   return 0;
}//de main
//
void elementos_mayores(int v1[],int c,int v_x)//prototipo de la funcion que permite la impresion de los elementos mayores a X
{
   cout<<"\n\t\t\tPOSICIONES\n";
   for(int i=0;i<c;i++)
      if(v1[i]>=v_x)
          cout<<"V["<<i<<"]\n";
}
