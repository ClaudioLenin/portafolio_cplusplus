/*
  Ingresar varios numeros reales, y proceda a invertir el orden de los digitos
  de cada uno de ellos
*/
#include "iostream"
#include <conio.h>
#include <math.h>
using namespace std;
int main()
{ //de main
   int n;  //variable que recibe la cantidad de numeros
   float nn; //variable que recibe el numero ingresado
   int i; //contador de ciclo
   void c_num(int *c);  //prototipo de la funcion que recibe la cantidad de numeros
   void num_n(float *num);  //prototipo de la funcion que recibe los N numeros
   void separar_digitos(float n);

   cout<<"\t\tINVERTIR UN NUMERO REAL\n";
   c_num(&n);  //llamado a la funcion que recibe la cantidad de numeros
   for(i=1;i<=n;i++){
       cout<<"\n\nNUM "<<i;
       cout<<"\n____________________\n";
       num_n(&nn);  //llamado a la funcion que recibe los N numeros
       separar_digitos(nn);

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
void num_n(float *num)  //funcion que recibe los N numeros
{  //de ingreso de N numeros

   cin>>*num;

}  //de ingreso de N numeros
//
void separar_digitos(float n)
{
   int aux,aux1;
   void p_entera_p_fraccionaria(int *n1,int *n2); //prototipo de la funcion que invierte el orden de los digitos del numero ingresado
   int n_num=0,m=1;
   aux=int(n);

   n=n-aux;
   n*=10;
   while(int(n)!=0){
      aux1=int(n);
      n=n-aux1;

      n_num=n_num+(aux1*m);
      m*=10;
   }
   cout<<"\n";
   p_entera_p_fraccionaria(&aux,&n_num); //llamado a la funcion que invierte el orden de los digitos del numero ingresado


}
//
void p_entera_p_fraccionaria(int *n1,int *n2) //prototipo de la funcion que invierte el orden de los digitos del numero ingresado
{
   int aux;

   do{
      aux=*n2;
      aux%=10;
      *n2/=10;
      cout<<aux;
   }while(*n2!=0);
      cout<<"...,";
   do{
      aux=*n1;
      aux%=10;
      *n1/=10;
      cout<<aux;
   }while(*n1!=0);

}
