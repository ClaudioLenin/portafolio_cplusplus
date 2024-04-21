/*
  Ejercicio 11
  Modificar el orden de los elementos de un vector, de forma tal que los N ultimos elementos
  pasen a ser los primeros
*/
#include "iostream"
#include <conio.h>
#include "header1.h"
#define T 20  //dimension definida para el arreglo
int main ()
{//de main
   int v[T]; //declaracion del arreglo con dimension T
   int n; //variable que recibe la cantidad de elementos al vector
   int c_elemen(int l1);//prototipo de la funcion que permite obtener la cantidad de N
   int c;
   void trasponer_vector(int vec[],int c1,int v_n);//prototipo de la funcion que permite invertir el vector

   cout<<"\t\tCAMBIAR ORDEN DE UN VECTOR\n";
   cout<<"________________________________________________________";
   n=lee_n(T);//llamado a la funcion que permite el ingreso de la cantidad de valores para el vector
   leer_vector(v,n); //llamado a la funcion que permite el ingreso de los N elementos al vector
   c=c_elemen(n);//llamado a la funcion que permite obtener la cantidad de N
   cout<<"\n\t\tVECTOR ORDENADO\n";
   trasponer_vector(v,n,c);//llamado a la funcion que permite invertir el vector

   getch();
   return 0;
}//de main
//
int c_elemen(int l1)//prototipo de la funcion que permite obtener la cantidad de N
{
   int N;
   do{
      cout<<"\nCuantos elementos del final quiere que paseen al inicio del vector: ";
      cin>>N;
   }while((N<1)||(N>l1));
   return(N);
}
//
void trasponer_vector(int vec[],int c1,int v_n)//funcion que permite invertir el vector
{
   int i,j;
   int aux[T];
   i=(c1-1)-v_n;
   for(j=v_n;j>=0;j--){
     aux[j]=vec[i];
     i++;
     }
   i=0;
   for(j=v_n;j<c1;j++){
      aux[j]=vec[i];
      i++;
      }
   for(j=0;j<c1;j++)
     cout<<aux[j]<<endl;
}
