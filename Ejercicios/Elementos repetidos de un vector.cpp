/*
  Ejercicio 8
  Determinar las posiciones que ocupan los elementos que se encuentran repetidos en un vector
*/
#include <iostream.h>
#include <conio.h>
#include <deber7.h>
#define T 20  //dimension definida para el arreglo
void main ()
{//de main
   int v[T]; //declaracion del arreglo con dimension T
   int n; //variable que recibe la cantidad de elementos al vector

   void v_repetidos(int vec[],int cant);//prototipo de la funcion que encuentra los valores repetidos en un vector

   cout<<"\t\tDETERMINAR LAS POSICIONES DE LOS ELEMENTOS REPETIDOS\n";
   cout<<"________________________________________________________";
   n=lee_n(T);//llamado a la funcion que permite el ingreso de la cantidad de valores para el vector
   leer_vector(v,n); //llamado a la funcion que permite el ingreso de los N elementos al vector
   v_repetidos(v,n);//prototipo de la funcion que encuentra los valores repetidos en un vector


   getch();
}//de main
//
void v_repetidos(int vec[],int cant)//funcion que encuentra los valores repetidos en un vector
{
  int i,j,k=1,c=0;
  int cont;
  int pos[T];   //VECTOR QUE CONTIENE LAS POSICIONES DE ELEMENTOS REPETIDOS


  for(i=0;i<cant;i++)
      for(j=0;j<cant;j++)
         if(i!=j)
            if(vec[i]==vec[j])
              if(i==0){
                pos[k]=i;
                c++;
                }
              else{
                cont=0;
                for(k=1;k<=c;k++)
                   if(pos[k]==i)
                     cont++;
                if(cont==0)
                   c++;
                   pos[c]=i;
                }

  cout<<"\n\t\tPOSICIONES DE ELEMENTOS REPETIDOS\n";
  for(i=1;i<=c;i++)
    cout<<pos[i]<<endl;
}


