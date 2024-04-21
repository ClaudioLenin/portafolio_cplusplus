/*
  Calcular la suma cruzada de dos vectores de distintas dimensiones
*/
#include "iostream"
#include <conio.h>
#include "header1.h"
#define T 20  //dimension definida para el arreglo
using namespace std;
int main ()
{//de main
   int v1[T],v2[T]; //declaracion del arreglo con dimension T
   int n1,n2; //variable que recibe la cantidad de elementos al vector

   void suma_cruzada(int v1[],int v2[],int cant1,int cant2);//prototipo de la funcion que permite calcular la suma cruzada de vectores

   cout<<"\t\tSUMA CRUZADA\n";
   cout<<"________________________________________________________";
   cout<<"\n\t\tARREGLO 1\n";
   n1=lee_n(T);//llamado a la funcion que permite el ingreso de la cantidad de valores para el vector
   leer_vector(v1,n1); //llamado a la funcion que permite el ingreso de los N elementos al vector
   cout<<"\n________________________________________________________";
   cout<<"\n\t\tARREGLO 2\n";
   n2=lee_n(T);//llamado a la funcion que permite el ingreso de la cantidad de valores para el vector
   leer_vector(v2,n2); //llamado a la funcion que permite el ingreso de los N elementos al vector

   suma_cruzada(v1,v2,n1,n2);//llamado a la funcion que permite calcular la suma cruzada de vectores

   getch();
   return 0;
}//de main
//
void suma_cruzada(int v1[],int v2[],int cant1,int cant2)//funcion que permite calcular la suma cruzada de vectores
{
   int aux[T];
   int may[T];
   int x;
   int i,j;
   int suma[T];
   int con;
   if(cant1<=cant2){
     for(i=0,j=(cant1-1);i<cant1;i++){
        aux[j]=v1[i];
        j--;
        }
     for(i=0;i<cant2;i++)
        may[i]=v2[i];
        x=cant2;
        con=cant1;
        }
   else {
     for(i=0,j=(cant2-1);i<cant2;i++){
        aux[j]=v2[i];
        may[i]=v1[i];
        j--;
        }
     for(i=0;i<cant1;i++)
        may[i]=v1[i];
        con=cant2;
        x=cant1;
        }
   for(i=0;i<x;i++)
     if(i<con)
        suma[i]=aux[i]+may[i];
     else
        suma[i]=may[i];
   cout<<"\n\t\tVECTOR CON SUMA CRUZADA\n";
   for(i=0;i<x;i++)
     cout<<"V["<<i<<"]"<<" : ["<<suma[i]<<"]"<<endl;

}
//


