/*
  Ejercicio 13
  Transformar un numero a binario mediante el empleo de vectores
*/
#include <iostream.h>
#include <conio.h>
#include <math.h>
#include <deber7.h>
#define T 20  //dimension definida para el arreglo
void main ()
{//de main

   int num; //numero a ingresar
   void transformacion(int nume);//prototipo de la funcion que permite transformar un numero a binario

   cout<<"\t\tTRANSFORMAR UN NUMERO A BINARIO\n";
   cout<<"________________________________________________________";
   cout<<"\nIngrese un numero: ";
   cin>>num;


   transformacion(abs(num));//llamado a la funcion que permite transformar un numero a binario

   getch();
}//de main
//
void transformacion(int nume)//funcion que permite transformar un numero a binario
{
   int v[T]; //declaracion del arreglo con dimension T
   int aux;
   int x;
   int cont=0;
   int m;
   x=nume;
   do{
      aux=nume;
      nume/=2;
      aux%=2;
      cont++;
   }while(nume!=0);
   m=cont;
   do{
      aux=x;
      x/=2;
      aux%=2;
      v[cont]=aux;
      cont--;
   }while(x!=0);

   cout<<"\n\t\tVECTOR BINARIO\n";
   for(int i=1;i<=m;i++)
     cout<<v[i]<<" ";

}

