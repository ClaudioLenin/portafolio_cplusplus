/*
  Teniendo los números 50, 25, 20, 10, 5, 3, 2, 1 encuentrese la secuencia de tres
  numeros distintos tal que la sumatoria del doble de cada uno sea 96
*/
#include "iostream"
#include <conio.h>
#define T 20  //dimension definida para el arreglo
using namespace std;

int main ()
{//de main

   cout<<"\t\tSECUENCIA DE TRES NUMEROS DISTINTOS\n";
   cout<<"________________________________________________________";


   void secuencia(); //prototipo de la funcion que determina la secuencia

   secuencia(); //llamado a la funcion que determina la secuencia


   getch();
   return 0;
}//de main
//
void secuencia() //funcion que determina la secuencia
{
   int v[T]; //declaracion del arreglo con dimension T
   int n; //variable que recibe la cantidad de elementos al vector

   void burbuja(int vec[],int c); //funcion que permite ordenar un vector con el metodo de la burbuja
   void imprimir(int vec[],int c);  //imprime vector
   int suma(int v1[],int can); //calcula la suma de los dobles de los elementos ingresados
   int x;
   int i;
   int c;

   cout<<"\nIngrese tres numeros distintos: ";
   cout<<"(50, 25, 20, 10, 5, 3, 2, 1)\n";

   do{
    i=0;
    c=0;
    do{
       i++;
       do{
           cout<<"Numero "<<i<<": ";
           cin>>x;
         }while((x!=50)&&(x!=25)&&(x!=20)&&(x!=10)&&(x!=5)&&(x!=3)&&(x!=2)&&(x!=1));
       v[i]=x;
     }while(i!=3);
        if((v[1]!=v[2])&&(v[1]!=v[3]))
            c++;
        if((v[2]!=v[1])&&(v[2]!=v[3]))
            c++;
        if((v[3]!=v[1])&&(v[3]!=v[2]))
            c++;
    }while(c!=3);
    burbuja(v,3);
    v[4]=suma(v,3); //calcula la suma de los dobles de los elementos ingresados
    imprimir(v,4);  //imprime vector
}
//
void burbuja(int vec[],int c) //funcion que permite ordenar un vector con el metodo de la burbuja
{
   int s;
   for(int j=1;j<=c-1;j++)
    for(int i=(j+1);i<=c;i++)
       if(vec[i]<vec[j]){
          s=vec[i];
          vec[i]=vec[j];
          vec[j]=s;
       }
}
//
void imprimir(int vec[],int c)  //imprime vector
{
   cout<<"\n\t\tSECUENCIA DE LA SERIE\n";
   for(int i=1;i<=c;i++)
     cout<<"V["<<i<<"]: "<<vec[i]<<endl;
}
//
int suma(int v1[],int can) //calcula la suma de los dobles de los elementos ingresados
{
  int acum=0;
  for(int i=1;i<=can;i++)
     acum+=(v1[i]*2);

  if(acum<=96)
       return((96-acum)/2);
  else
       return(48);
}

