/*
  Ejercicio # 1
  Ingresar varios numeros enteros y en cada uno encontrar el digito menor y calcular
  la suma de las posiciones que ocupan los digitos pares
*/
#include "iostream"
#include <conio.h>
#include <math.h>
using namespace std;
int main()
{ //de main
   int n;  //variable que recibe la cantidad de numeros
   int nn; //variable que recibe el numero ingresado
   int i; //contador de ciclo
   void c_num(int *c);  //prototipo de la funcion que recibe la cantidad de numeros
   void num_n(int *num);  //prototipo de la funcion que recibe los N numeros
   void dig_nenor(int n_a); //prototipo de la funcion que calcula el digito menor

   cout<<"\tENCONTRAR EL DIGITO MENOR Y SUMAR POSICIONES DE DIGITOS PARES\n";
   c_num(&n);  //llamado a la funcion que recibe la cantidad de numeros
   for(i=1;i<=n;i++){
       cout<<"\nNUM "<<i;
       cout<<"\n____________________\n";
       num_n(&nn);  //llamado a la funcion que recibe los N numeros
       dig_nenor(nn); //llamado a la funcion que calcula el digito menor
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
void dig_nenor(int n_a) //prototipo de la funcion que calcula el digito menor
{
   void imprimir(int dm,int p); //prototipo de la funcion que imprime los digitos
   int aux;
   int min; //recibe el digito menor
   int c=0,c1; // var contadora
   int acum=0;
   int h;
   h=n_a=abs(n_a);
   do{
      h/=10;
      c++;
   }while(h!=0);
   c1=c;
   do{
      aux = n_a;
      aux %= 10;
      n_a /= 10;
      if(c1==c)
          min=aux;
      else
       if(aux<=min)
          min=aux;
      if(aux%2==0)
         acum=acum+c;
      c--;
   }while(n_a!=0);

   imprimir(min,acum); //llamado a la funcion que imprime los digitos

}
//

void imprimir(int dm,int p) //prototipo de la funcion que imprime los digitos
{
  cout<<"\nEl digito menor es "<<dm<<" y la suma de las posiciones de los elementos pares es "<<p;
}
