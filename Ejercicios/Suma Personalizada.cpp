/*
   Determinar la cantidad de valores numericos enteros que el usuario debera
   ingresar hasta conseguir que la sumatoria de los digitos que constan en todos
   ellos sea mayor o igual a X
*/
#include <iostream.h>
#include <conio.h>
void main (){
   int n; //cantidad de Numeros
   int x; //valor de X
   int c=0; //contador
   int r;

   void ing_numeros(int *v_x); //prototipo de la funcion que permite el ingreso de la cantidad de numeros
   void ing_num(int *num,int *cont); //prototipo de la funcion que permite el ingreso de los N numeros

   cout<<"\t\tMAYOR O IGUAL A (X)\n";
   ing_numeros(&x); //llamado a la funcion que permite el ingreso de la cantidad de numeros

   do{
      r=x-c;
      if(c<x){
         cout<<"\nFalta: "<<r<<endl;
         cout<<"_________________________\n";
         }
      ing_num(&n,&c); //llamado a la funcion que permite el ingreso de los N numeros
   }while(c<x);



   getch();
}
//
void ing_numeros(int *v_x) //funcion que permite el ingreso de la cantidad de numeros
{
   do{
      cout<<"\nIngrese el valor de X: ";
      cin>>*v_x;
   }while(*v_x<1);
}
//
void ing_num(int *num,int *cont) //funcion que permite el ingreso de los N numeros
{
   int *aux;
   do{
      cout<<"\nIngrese un numero: ";
      cin>>*num;
   }while(*num<1);
   do{
      *aux=*num;
      *aux%=10;
      *num/=10;
      *cont=*cont+*aux;
   }while(*num!=0);
}

