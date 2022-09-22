//Programa q permita el ingreso de varios numeros ingresados y deterninar la cantidad
//total de digitos que en ellos existe
#include <iostream.h>
#include <conio.h>
#define DIV 10 //el divisor que es 10

void main ()
{
    int n;    //cantidad de numeros a ingresar
    int i;    //ciclo
    int num;  //numeros ingresados por el usuario
    int cdig = 0; //contador de digitos, almacena respuesta
    int may=0;
    int g;
    int h;
    int l;
        do {   //ciclo de lectura y restriccion de n
            cout <<"\nIngrese la cantidad de numeros:";
            cin>>n;
           } while (n < 1); //rechazar cero y negativos
            for(i = 1;(i <= n);i ++){
                cout<<"\n Ingrese un numero ";
                cin>>num;
                h=num;
                  cdig=0;
                do{
                   num /= DIV;     //recorrer la coma un espacio a la izquierda
                   cdig++; //contar el digito ya individualizado
                   g=cdig;
                }while(num != 0); //mientras haya digitos en el numero, repetir el proceso

                  if (cdig >= may){
                      may=cdig;
                      l=h;
                      }

            }
            cout<<"El numero con mas digitos es: "<<l;
getch();
}