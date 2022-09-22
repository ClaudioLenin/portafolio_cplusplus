/*
Elaborar un programa modular que permita calcular el ranking de varios valores.
El ranking corresponde al promedio de las posiciones en que se encuentra un valor
dentro de un vector previamente leido. Ejemplo

   0   1     2   3     4    5     6
------------------------------------------
| 10 | 20 | 30 | 20 | 40 | 10 | 10 |
------------------------------------------

Ranking 10 = 3.66  =>   ( 0 + 5 + 6 ) / 3
Ranking 20 = 2   =>  ( 1 + 3 ) / 2
Ranking 30 = 2  => (2) / 1
Ranking 40 = 4  => (4) / 1
Ranking 18 = NO EXISTE!!!!!
*/
#include <iostream.h>
#include <conio.h>
#include <windows.h>
#include <practica_vectores.h>
#define C 20
void main(){
   int n; //numero de elementos para el arreglo
   int c; //variable que define la cantidad de elementos del ranking
   int c1; //variable que recibe el numero del ranking
   int i=0;

   int v1[C]; //definicion de un arreglo
   cout<<"\t\tRANKING DE ELEMENTOS DE UN VECTOR\n";
   n=lee_n(C); //llamado a la funcion que define la cantidad de elementos
   leer_vector(v1,n);  //llamado a la funcion q permite el ingreso de los valores al arreglo

   cout<<"\n____________________________________________________________________";
   cout<<"\n\t\tEL VECTOR INGRESADO ES:\n";
   imprime_vector(v1,n);
   cout<<"\n____________________________________________________________________";

   do{//ciclo de lectura de la cantidad de elementos del ranking
         cout<<"\nIngrese la cantidad de elementos para el ranking: ";
         cin>>c;
      }while(c<1); //retipe mientras sea negativo o cero

   do{ //ciclo de ingreso de cada elemento del ranking
         i++;
         SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),LIGHTGRAY);   //funcion que establece el color blanco para la impresion del mensaje de ingreso numero del ranking
         cout<<"\nNumero "<<i<<" de ranking: ";
         cin>>c1;
         determinar_ranking(v1,n,c1); //llamado a la funcion que permite calcular el ranking de un numero
      }while(i<c); //retipe mientras no se ingrese toda la cantidad de elementos para el ranking

    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),BROWN);
    cout<<"\n____________________________________________________________________";
    cout<<"\nRealizado Por: Claudio Pilataxi                          Codigo:6042";
getch();
}
