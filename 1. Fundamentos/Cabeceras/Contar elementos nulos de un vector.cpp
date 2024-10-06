/*
  Ejercicio 3
  Contar el numero de elementos nulos de un vector
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
   int cont_car_nulos(int v1[],int cc);//prototipo de la funcion que permite contar los caracteres nuloes en un vector

   cout<<"\t\tCONTAR ELEMENTOS NULOS\n";
   cout<<"________________________________________________________";
   n=lee_n(T);//llamado a la funcion que permite el ingreso de la cantidad de valores para el vector
   leer_vector(v,n); //llamado a la funcion que permite el ingreso de los N elementos al vector

   cout<<"\nExisten "<<cont_car_nulos(v,n)<<" caracteres nulos.....";
   getch();
   return 0;
}//de main
//
int cont_car_nulos(int v1[],int cc)//funcion que permite contar los caracteres nuloes en un vector
{
  int i=0,c; //variable contadora
  for(c=0;i<cc;i++)
    if(v1[i]==0)
      c++;
  cout<<c<<endl;
  return(c);
}
