/*
  Ejercicio 9
  Comprobar si un vector esta ordenado (ascendente o descendentemente)
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
   void comprobar(int v[],int c); //prototipo de la funcion que comprueba el orden del vector

   cout<<"\t\tASCENDENTE O DESCENDENTE?\n";
   cout<<"________________________________________________________";
   n=lee_n(T);//llamado a la funcion que permite el ingreso de la cantidad de valores para el vector
   leer_vector(v,n); //llamado a la funcion que permite el ingreso de los N elementos al vector
   comprobar(v,n); //prototipo de la funcion que comprueba el orden del vector
   getch();
   return 0;
}//de main
//
void comprobar(int v[],int c) //prototipo de la funcion que comprueba el orden del vector
{
   int may=1;
   int min=1;
   for(int i=1;i<c;i++){
     if(v[i-1]<v[i])
        min++;
     else
       if(v[i-1]>v[i])
        may++;
    if(v[i-1]==v[i]){
       may++;
       min++;
       }
     }

   if(may==c)
      cout<<"\nAscendente";
   else
      if(min==c)
        cout<<"\nDescendente";
      else
        cout<<"\nNo tiene orden";


}

