/*
  Ejercicio # 4
  De cada numero ingresado determinar la suma de sus factores primos
*/
#include "iostream"
#include <conio.h>
#include "math.h"
using namespace std;
int main()
{ //de main
   int n;  //variable que recibe la cantidad de numeros
   int nn; //variable que recibe el numero ingresado
   int i; //contador de ciclo
   int pri; //digitos primos
   int c_prim; //cantidad de elementos primos

   void c_num(int *c);  //prototipo de la funcion que recibe la cantidad de numeros
   void num_n(int *num);  //prototipo de la funcion que recibe los N numeros
   void sep_digitos(int *d_p,int *elp,int nm); //prototipo de la funcion que suma los digitos primos
   void imp_elem(int cant,int sm,int num);//prototipo de la funcion que imprime la suma de los digitos primos

   cout<<"\t\tSUMA DE FACTORES PRIMOS\n";
   c_num(&n);  //llamado a la funcion que recibe la cantidad de numeros


   for(i=1;i<=n;i++){
       cout<<"\nNUM "<<i;
       cout<<"\n____________________\n";
       num_n(&nn);  //llamado a la funcion que recibe los N numeros
       sep_digitos(&pri,&c_prim,nn); //llamado a la funcion que suma los digetos primos
       imp_elem(pri,c_prim,nn);//prototipo de la funcion que imprime la suma de los digitos primos
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
   *num=abs(*num);

}  //de ingreso de N numeros
//
void sep_digitos(int *d_p,int *elp,int nm) //prototipo de la funcion que suma los digetos primos
{  //de separar digitos
   int aux;
   int i;   //contador de ciclo
   int cont;   //contador de divisores
   int acum=0;
   int c_p=0; //contador de digitos primos
   do{
      cont = 0;
      aux = nm;
      aux%=10;
      if(aux==1){
          acum=acum+aux;
          c_p++;
          }
      else{
          for(i = 1;i <= aux;i ++)
               if(aux%i==0)
                  cont++;

          if(cont==2){
              acum=acum+aux;
              c_p++;
              }
          }
      nm/=10;
   }while(nm!=0);
   *d_p=acum;
   *elp=c_p;
}  //de separar digitos
//
void imp_elem(int cant,int sm,int num)//funcion que imprime la suma de los digitos primos
{
   cout<<"\nTiene "<<sm<<" digitos primos y la suma es: "<<cant;
}
