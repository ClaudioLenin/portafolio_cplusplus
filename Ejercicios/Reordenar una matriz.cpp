/*
Elaborar un programa que permita ordenar los elementos de una matriz ingresada,
sin el empleo de otros arreglos auxiliares. El usuario decidirá si desea orden ascendente o descendente.
Ejemplo:
MATRIZ ORIGINAL:

2 3 1
9 0 3

MATRIZ ORDENADA ASCENDENTEMENTE:

0 1 2
3 3 9

MATRIZ ORDENADA DESCENDENTEMENTE:

9 3 3
2 1 0
*/
#include <iostream.h>
#include <conio.h>
#include <windows.h>
#define T 10  //definicion de la cantidad de filas y columnas maximas de una matriz
void main (){
   int f; //cantidad de filas del arreglo
   int c; //cantidad de columnas del arreglo
   int m[T][T]; //definicion de la matriz con de dimension T

   int cantidad_de_elementos();  //prototipo de la funcion que permite el ingreso de la cantidad de elementos para ingresar al arreglo
   void ingreso_a_matriz(int m1[][T],int f1,int c1);   //prototipo de la funcion que permite el ingreso de elementos a una matriz

   cout<<"__________________________________________________________________";
   cout<<"\t\t\t\t\tORDENAR UNA MATRIZ";
   cout<<"\n__________________________________________________________________\n";
   cout<<"NUMERO DE FILAS";
   f=cantidad_de_elementos();  //llamado a la funcion que permite el ingreso de la cantidad de filas del arreglo
   cout<<"NUMERO DE COLUMNAS";
   c=cantidad_de_elementos();  //llamado a la funcion que permite el ingreso de la cantidad de columnas del arreglo
   ingreso_a_matriz(m,f,c);   //llamado a la funcion que permite el ingreso de elementos a una matriz

   getch();
}
//
int cantidad_de_elementos() //prototipo de la funcion que permite el ingreso de la cantidad de elementos para ingresar al arreglo
{ //de cantidad_de_elementos
  int n; //cantidad de elementos
  do{
     cout<<"\nIngrese cantidad de elementos: ";
     cin>>n;
  }while((n<1)||(n>T));   //ciclo de lectura de cantidad de elementos que se repite mientras el numero ingresado sea nemor que uno o mayor a la cantidad establecida T
  return(n); //retorna cantidad de elementos
}  //de cantidad_de_elementos
//
void ingreso_a_matriz(int m1[][T],int f1,int c1)   //funcion que permite el ingreso de elementos a una matriz
{
  int i; //recorre ciclo de filas de una matriz
  int j; //recorre ciclo de columnas de una matriz
  int r;
  void ordenar_matriz_ascendente(int m2[][T],int f2,int c2);  //prototipo de la funcion que permite ordenar una matriz de forma ascendente
  void ordenar_matriz_descendente(int m3[][T],int f3,int c3);  //prototipo de la funcion que permite ordenar una matriz de forma descendente
  void imprime_matriz(int d[][T],int f4,int c4); //prototipo de la funcion que permite imprimir la matriz

  for(i=0;i<f1;i++)  //ciclo de lectura por filas
     for(j=0;j<c1;j++){  //ciclo de lectura por columnas
        cout<<"\nPosicion [ "<<i<<" , "<<j<<" ]: ";
        cin>>m1[i][j];
     }


  do{
     cout<<"\n__________________________________________________________________";
     cout<<"\t\t\t\t\tORDENAR DE FORMA";
     cout<<"\n__________________________________________________________________";
     cout<<"\n1.- Ascendente";
     cout<<"\n2.- Descendente";
     cout<<"\n3.- Salir\n";
     cin>>r;
  }while((r<1)||(r>3));  //ciclo de seleccion de opciones de ordenamiento
  clrscr();    //borrar pantalla
  switch(r){
            case 1:
                  cout<<"\n__________________________________________________________________";
                  cout<<"\t\t\t\t\tMATRIZ ORIGINAL";
                  cout<<"\n__________________________________________________________________\n";
                  imprime_matriz(m1,f1,c1); //llamado a la funcion que permite la impresion de una matriz
                  SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),GREEN);
                  cout<<"\n\n__________________________________________________________________";
                  cout<<"\t\t\t\t\tASCENDENTE";
                  cout<<"\n__________________________________________________________________\n";
                  ordenar_matriz_ascendente(m1,f1,c1);  //llamado a la funcion que permite ordenar una matriz de forma ascendente
                  imprime_matriz(m1,f1,c1); //llamado a la funcion que permite la impresion de una matriz
                  break;
            case 2:
                  cout<<"\n__________________________________________________________________";
                  cout<<"\t\t\t\t\tMATRIZ ORIGINAL";
                  cout<<"\n__________________________________________________________________\n";
                  imprime_matriz(m1,f1,c1); //llamado a la funcion que permite la impresion de una matriz
                  SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),GREEN);
                  cout<<"\n\n__________________________________________________________________";
                  cout<<"\t\t\t\t\tDESCENDENTE";
                  cout<<"\n__________________________________________________________________\n";
                  ordenar_matriz_descendente(m1,f1,c1);  //llamado a la funcion que permite ordenar una matriz de forma descendente
                  imprime_matriz(m1,f1,c1); //llamado a la funcion que permite la impresion de una matriz
                  break;
            case 3:
                  cout<<"\nGracias........";
                  break;
  }

  SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),BROWN);
  cout<<"\n__________________________________________________________________";
  cout<<"\nRealizado por: Claudio Pilataxi                        Codigo: 6042";
  cout<<"\n__________________________________________________________________\n";

}
//
void ordenar_matriz_ascendente(int m2[][T],int f2,int c2)  //prototipo de la funcion que permite ordenar una matriz de forma ascendente
{

int i,j,h,k;  //variables para recorrer la matriz: i para filas, j para columnas
int aux;  //variable para intercambio de valores

   for(i=0;i<f2;i++) //ciclo para recorrer las filas de la matriz
      for(j=0;j<c2;j++)   //ciclo para recorrer las columnas de la matriz
         for(h=0;h<f2;h++)
           for(k=0;k<c2;k++)
              if(m2[i][j]<=m2[h][k]){
                aux=m2[i][j];
                m2[i][j]=m2[h][k];  //transposicion de valores
                m2[h][k]=aux;
                }


}
//
void ordenar_matriz_descendente(int m3[][T],int f3,int c3)  //prototipo de la funcion que permite ordenar una matriz de forma descendente
{
int i,j,h,k;  //variables para recorrer la matriz: i para filas, j para columnas
int aux;  //variable para intercambio de valores

   for(i=0;i<f3;i++) //ciclo para recorrer las filas de la matriz
      for(j=0;j<c3;j++)   //ciclo para recorrer las columnas de la matriz
         for(h=0;h<f3;h++)
           for(k=0;k<c3;k++)
              if(m3[i][j]>=m3[h][k]){
                aux=m3[i][j];
                m3[i][j]=m3[h][k];  //transposicion de valores
                m3[h][k]=aux;
                }
}
 //
void imprime_matriz(int d[][T],int f4,int c4)//funcion q permite imprimir los elementos de una matriz previmente ingresada
{
  int i,j; //variables para recorrer la matriz: i para filas, j para columnas
  for(i=0;(i<f4);i++){
     cout<<"\n";
     for(j=0;(j<c4);j++)
       cout<<"  "<<d[i][j];
       }
}
