/*
  Ejercicio # 2
  Ingresar varios numeros y transformar cada numero entero a cualquier base de numeracion
*/
#include "iostream"
#include <conio.h>
#include "math.h"
#include <windows.h>
using namespace std;
// Prototipo de la función clrscr()
void clrscr();
void gotoxy(int x, int y) {
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
int main()
{ //de main
   int n;  //variable que recibe la cantidad de numeros
   int nn; //variable que recibe el numero ingresado
   int i; //contador de ciclo
   void c_num(int *c);  //prototipo de la funcion que recibe la cantidad de numeros
   void num_n(int *num);  //prototipo de la funcion que recibe los N numeros
   void p(int *n); //prototipo de la funcion que recibe los N numeros y los convierte a cualquier base

   cout<<"\t\tTRANSFORMACION DE NUMEROS\n";
   c_num(&n);  //llamado a la funcion que recibe la cantidad de numeros


   for(i=1;i<=n;i++){
       cout<<"\nNUM "<<i;
       cout<<"\n____________________\n";
       num_n(&nn);  //llamado a la funcion que recibe los N numeros
       p(&nn);
   }

   getch();
   return 0;
} //de main
//
void c_num(int *c)  //funcion que recibe la cantidad de numeros
{  //de cantidad de numeros
   do{
       cout<<"\nIngrese cantidad de numeros: ";
       cin>>*c;
   }while(*c<1);
}  //de cantidad de numeros

//
void num_n(int *num)  //funcion que recibe los N numeros
{  //de ingreso de N numeros

   cin>>*num;


}  //de ingreso de N numeros
//
void p(int *n)
{
  int aux,aux1;


  int el;
  int resp;

do{
  aux=aux1=abs(*n);
  el=0;
  do{
     cout<<"\n\t\tMENU DE OPCIONES\n";
     cout<<"1.- Binario";
     cout<<"\n2.- Octal";
     cout<<"\n3.- Decimal";
     cout<<"\n4.- Hexadecimal";
     cout<<"\n5.- Salir\n";
     cin>>resp;
  }while((resp<1)||(resp>5));
  clrscr();
  switch(resp){
         case 1:
                do{
                   el++;
                   aux/=2;
                }while(aux!=0);
                do{
                   aux=aux1;
                   aux%=2;
                   aux1/=2;
                   gotoxy(el,2);
                   cout<<aux;
                   el--;
                }while(aux1!=0);
                break;
         case 2:
                do{
                   el++;
                   aux/=8;
                }while(aux!=0);
                do{
                   aux=aux1;
                   aux%=8;
                   aux1/=8;
                   gotoxy(el,2);
                   cout<<aux;
                   el--;
                }while(aux1!=0);
                break;
         case 3:
                do{
                   el++;
                   aux/=10;
                }while(aux!=0);
                do{
                   aux=aux1;
                   aux%=10;
                   aux1/=10;
                   gotoxy(el,2);
                   cout<<aux;
                   el--;
                }while(aux1!=0);
                break;
         case 4:
                do{
                   el++;
                   aux/=16;
                }while(aux!=0);
                do{
                   aux=aux1;
                   aux%=16;
                   aux1/=16;
                   gotoxy(el,2);
                   cout<<aux;
                   el--;
                }while(aux1!=0);
                break;
         case 5:
                break;
  }
}while(resp!=5);
}
// Definición de la función clrscr()
void clrscr() {
    system("cls"); // Llama al comando de limpieza de pantalla específico del sistema operativo
}
