/*
                                   TALLER # 1
 Realizado Por: Claudio Pilataxi    6042
                Mireya Guano        6056

  Elaborar un programa que permita generar los N primeros terminos de esta serie
  6/1, -5/3, 4/5, -3/7, -2/9, 1/11, -6/13, -5/15, -4/17, -3/19, -2/21, -1/23,........
*/
#include "iostream"
#include <conio.h>
using namespace std;
int main (){//Inicio Main
int n; //Cantidad de Elementos
int c1=1,c2=1;
int num=6; //Variable de numerador
int den=1; //Variable de denominador
   cout<<"\t\t\tSERIE ALTERNADA\n";
   do{   //Ciclo de repeticion mientras n sea menor que 1
      cout<<"\nIngrese cantidad de numeros: ";
      cin>>n;
   }while(n<1);


for(int i=1;i<=n;i++){ //Inicio For
    if(num==0)   //Si el numerado llega a cero entonces vuelve a tener el valor de 6
             num=6;

    if(i==1){  //Si i es igual a 1 simplemente se imprime el numero
          cout<<num<<"/"<<den<<"  ";
          den=den+2; //Incremento del denominador en 2 para que siempre sea impar
          num--;   //decremento en 1 el numerador
        }
    else{
         if(c1<=c2){  //si c1 es menor que c2 entoces imprime numeros negativos
              cout<<"  -"<<num<<"/"<<den<<"  "; //imprime un valor negativo
              den=den+2; //Incremento del denominador en 2 para que siempre sea impar
              num--; //decremento en 1 el numerador
              c1++;   //incremento de c1 hasta c2
                   }
         else {    //si c1 sobrepaso a c2 entonces imprime un numero positivo
              c2=c1; //c2 toma el valor de c1
              c1=1;  //c1 vuelve a tomar el valor de 1
              cout<<num<<"/"<<den<<"  ";   //imprime un valor positivo
              den=den+2;  //Incremento del denominador en 2 para que siempre sea impar
              num--; //decremento en 1 el numerador
                   }
         }
}  //Fin For

cout<<"\n\n\nREALIZADO POR: Claudio Pilataxi 6042\n";
cout<<"\t\tMireya Guano 6056";
getch();
return 0;
} //Fin Main



