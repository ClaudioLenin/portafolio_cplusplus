/*
  Ejercicio 6
  De dos vectores iniciales, calcular un tercero(todos de iguales dimensiones) en
  el que cada elemento se obtiene de promediar los elementos correspondientes de
  los vectores iniciales en el caso de que sean de igual signo, si fueran de signo
  distinto, el valor resultante será el valor mayor
*/
#include "iostream"
#include <conio.h>
#define MY_HEADER_H
#include "deber7.h"
#define T 20  //dimension definida para el arreglo
using namespace std;
int main ()
{//de main
   float v1[T],v2[T]; //declaracion del arreglo con dimension T
   float v3[T];
   int n; //variable que recibe la cantidad de elementos al vector

   void tercer_vector(float v1[],float v2[],float v3[],int cant);//prototipo de la funcion que permite crear otro vector
   void imp_vect(float v[],int c); //prototipo de la funcion que imprime el tercer vector

   cout<<"\t\tCALCULAR UN TERCER VECTOR\n";
   cout<<"________________________________________________________";
   cout<<"\nDIMENSION DE LOS DOS VECTORES";
   n=lee_n(T);//llamado a la funcion que permite el ingreso de la cantidad de valores para el vector
   cout<<"\n\t\tARREGLO 1\n";
   cout<<"________________________________________________________";
   leer_vector_flotante(v1,n); //llamado a la funcion que permite el ingreso de los N elementos al vector
   cout<<"\n\t\tARREGLO 2\n";
   cout<<"________________________________________________________";
   leer_vector_flotante(v2,n); //llamado a la funcion que permite el ingreso de los N elementos al vector
   tercer_vector(v1,v2,v3,n);//llamado a la funcion que permite crear otro vector
    cout<<"\n\t\tARREGLO 3\n";
   cout<<"________________________________________________________\n";
   imp_vect(v3,n); //llamado a la funcion que imprime el tercer vector


   getch();
   return 0;
}//de main
//
void tercer_vector(float v1[],float v2[],float v3[],int cant)//funcion que permite crear otro vector
{
   for(int i=0;i<cant;i++)
      if(((v1[i]<=0)&&(v2[i]<=0))||((v1[i]>0)&&(v2[i]>0))){
        v3[i]=(v1[i]+v2[i])/2;
        }
      else{
        if(v1[i]>=v2[i])
           v3[i]=v1[i];
        else
           v3[i]=v2[i];
        }

}
//
void imp_vect(float v[],int c) //prototipo de la funcion que imprime el tercer vector
{
  for(int i=0;i<c;i++)
    cout<<"V["<<i<<"]:"<<v[i]<<endl;
}
