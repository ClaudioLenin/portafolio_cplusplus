/*
  Ejercicio 16
  Ordenamiento de  vectores
*/
#include <iostream.h>
#include <conio.h>
#include <deber7.h>
#include <ordenar_vector.h>
#define T 20  //dimension definida para el arreglo
void main ()
{//de main
   int v[T]; //declaracion del arreglo con dimension T
   int n; //variable que recibe la cantidad de elementos al vector

   void menu(int vec[],int cant);//prototipo de la funcion que lee la opcion seleccionada

   cout<<"\t\tORDENAMIENTO DE VECTORES\n";
   cout<<"________________________________________________________";
   n=lee_n(T);//llamado a la funcion que permite el ingreso de la cantidad de valores para el vector
   leer_vector(v,n); //llamado a la funcion que permite el ingreso de los N elementos al vector

   menu(v,n);//llamado a la funcion que lee la opcion seleccionada

   getch();
}//de main
//
void menu(int vec[],int cant)//funcion que lee la opcion seleccionada
{
  int resp;
  do{
     cout<<"\n\t\tMENU DE OPCIONES\n";
     cout<<"________________________________________________________";
     cout<<"\n1.- Metodo de la Burbuja\n";
     cout<<"2.- Metodo de Insercion\n";
     cout<<"3.- Metodo de Seleccion\n";
     cout<<"4.- Salir\n";
     cin>>resp;
  }while((resp<1)||(resp>4));

  cout<<"\t\tVECTOR ORDENADO\n";
  cout<<"________________________________________________________";

  switch(resp){
        case 1:
              burbuja(vec,cant); //funcion que permite ordenar un vector con el metodo de la burbuja
              imprime_vector(vec,cant);
              break;
        case 2:
              insercion(vec,cant); //funcion que permite ordenar un vector con el metodo de insercion
              imprime_vector(vec,cant);
              break;
        case 3:
              seleccion(vec,cant); //funcion que permite ordenar un vector con el metodo de seleccion
              imprime_vector(vec,cant);
              break;
        case 4:
              cout<<"\nGracias...........";
              break;
  }
}
