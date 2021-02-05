/*
  Ejercicio 15
  Permitir el ingreso de dos vectores (pueden ser de distintas dimensiones), y
  determinar aquellos elementos del primer vector que estan incluidos en el
  segundo.
*/
#include <iostream.h>
#include <conio.h>
#include <deber7.h>
#define T 20  //dimension definida para el arreglo
void main ()
{//de main
   int v1[T],v2[T]; //declaracion del arreglo con dimension T
   int n1,n2; //variable que recibe la cantidad de elementos al vector

   void elementos_repetidos(int v1[],int v2[],int n1,int n2);//prototipo de la funcion que determina los elementos repetidos del primer vector en el segundo

   cout<<"\t\tCALCULAR ELEMENTOS REPETIDOS\n";
   cout<<"________________________________________________________";
   cout<<"\n\t\tARREGLO 1\n";
   cout<<"________________________________________________________";
   n1=lee_n(T);//llamado a la funcion que permite el ingreso de la cantidad de valores para el vector
   leer_vector(v1,n1); //llamado a la funcion que permite el ingreso de los N elementos al vector
   cout<<"\n\t\tARREGLO 2\n";
   cout<<"________________________________________________________";
   n2=lee_n(T);//llamado a la funcion que permite el ingreso de la cantidad de valores para el vector
   leer_vector(v2,n2); //llamado a la funcion que permite el ingreso de los N elementos al vector

   elementos_repetidos(v1,v2,n1,n2);//llamado a la funcion que determina los elementos repetidos del primer vector en el segundo

   getch();
}//de main
//
void elementos_repetidos(int v1[],int v2[],int n1,int n2)//funcion que determina los elementos repetidos del primer vector en el segundo
{
   int i,j;
   int vaux[T];
   int cont,c;
   c=i=j=0;
   for(i=0;i<n1;i++)
     for(j=0;j<n2;j++)
        if(v1[i]==v2[j])
           if(c==0){
              c++;
              vaux[c]=v1[i];
              }
           else{
              cont=0;
              for(int k=1;k<=c;k++)
                 if(vaux[k]==v1[i])
                    cont++;
              if(cont==0){
                c++;
                vaux[c]=v1[i];
              }
           }

   if(c!=0){
   cout<<"\n\t\tELEMENTO(S) REPETIDOS ENTRE VECTORES\n";
   for(i=1;i<=c;i++)
     cout<<vaux[i]<<endl;
   }
   else{
       cout<<"\nNo hay numeros repetidos entre vectores........";
   }

}

