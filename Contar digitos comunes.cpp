/*
     Elaborar un programa modular que permita el ingreso de varios numeros enteros,
     y determinar los dígitos que son comunes a todos ellos. Ejemplo:
             1233
             -8513                    Dígitos Comunes a todos los valores: 1 y 3
             -9313
             1113
*/
#include <iostream.h>
#include <conio.h>
#include <math.h>
void main()
{//de main
  int n;  //variable que recibe los n numeros
  int num();  //prototipo de la funcion que permite el ingreso de la cantidad de numeros
  void ing_numeros(int h); //prototipo de la funcion que permite el ingreso de los n numeros


  cout<<"\t\tDETERMINAR DIGITOS COMUNES\n";
  n=num(); //llamado a la funcion que permite el ingreso de la cantidad de numeros
  ing_numeros(n); //llamado a la funcion que permite el ingreso de los n numeros

getch();
}//de main
//
void ing_numeros(int h) //funcion que permite el ingreso de los n numeros
{//de ingreso numeros
   int i; //contador de ciclo
   int num; //variable que recibe el numero

   int n0;  //variable que recibe un digito 0
   int n1;  //variable que recibe un digito 1
   int n2;  //variable que recibe un digito 2
   int n3;  //variable que recibe un digito 3
   int n4;  //variable que recibe un digito 4
   int n5;  //variable que recibe un digito 5
   int n6;  //variable que recibe un digito 6
   int n7;  //variable que recibe un digito 7
   int n8;  //variable que recibe un digito 8
   int n9;  //variable que recibe un digito 9


   int c0,c1,c2,c3,c4,c5,c6,c7,c8,c9;  //contadores de cada digito
   c0=c1=c2=c3=c4=c5=c6=c7=c8=c9=0;

   void separar_dig(int *x0,int *x1,int *x2,int *x3,int *x4,int *x5,int *x6,int *x7,int *x8,int *x9,int nu,int c,int *c0,int *c1,int *c2,int *c3,int *c4,int *c5,int *c6,int *c7,int *c8,int *c9,int cc0,int cc1,int cc2,int cc3,int cc4,int cc5,int cc6,int cc7,int cc8,int cc9); //prototipo de la funcion que permite separar digitos de cada numero

   for(i = 1;(i <= h);i ++){
      cout<<"\nNUM "<<i;
      cout<<"\n____________________\n";
      cin>>num;
      num=abs(num);
      separar_dig(&n0,&n1,&n2,&n3,&n4,&n5,&n6,&n7,&n8,&n9,num,i,&c0,&c1,&c2,&c3,&c4,&c5,&c6,&c7,&c8,&c9,c0,c1,c2,c3,c4,c5,c6,c7,c8,c9); //llamado a la funcion que permite separar digitos de cada numero
   }
   cout<<"\n********************************************************************\n";
   cout<<"\t\t\tLOS DIGITOS COMUNES SON \n";

   if(c0==h)
     cout<<n0<<endl;
   if(c1==h)
     cout<<n1<<endl;
   if(c2==h)
     cout<<n2<<endl;
   if(c3==h)
     cout<<n3<<endl;
   if(c4==h)
     cout<<n4<<endl;
   if(c5==h)
     cout<<n5<<endl;
   if(c6==h)
     cout<<n6<<endl;
   if(c7==h)
     cout<<n7<<endl;
   if(c8==h)
     cout<<n8<<endl;
   if(c9==h)
     cout<<n9<<endl;
   cout<<"\n********************************************************************\n";
   cout<<"\nRealizado Por: Claudio Pilataxi\n";
   cout<<"Codigo: 6042";
}//de ingreso numeros
//
int num()
{ //de ingreso cantidad de numeros
  int c; //ingreso numero
  do{
      cout<<"\nIngrese cantidad de numeros: ";
      cin>>c;
  }while(c<1); //ciclo de repeticion mientras el numero sea menor que uno
  return(c);
} //de ingreso cantidad de numeros
//
void separar_dig(int *x0,int *x1,int *x2,int *x3,int *x4,int *x5,int *x6,int *x7,int *x8,int *x9,int nu,int c,int *c0,int *c1,int *c2,int *c3,int *c4,int *c5,int *c6,int *c7,int *c8,int *c9,int cc0,int cc1,int cc2,int cc3,int cc4,int cc5,int cc6,int cc7,int cc8,int cc9) //funcion que permite separar digitos de cada numero
{//de separar digitos

  int aux;
  //todas estas variables son para evitar contar varias veces el mismo digito en un mismo numero ingresado
  int f0=0;
  int f1=0;
  int f2=0;
  int f3=0;
  int f4=0;
  int f5=0;
  int f6=0;
  int f7=0;
  int f8=0;
  int f9=0;

  do{
     aux=nu;
     aux%=10;
     nu/=10;
     if(c==1){
       if(aux==0){
          *x0=aux;
          if(f0==0){
            cc0++;
            *c0=cc0;
            f0++;
            }
          }
       if(aux==1){
          *x1=aux;
          if(f1==0){
            cc1++;
            *c1=cc1;
            f1++;
            }
          }
       if(aux==2){
          *x2=aux;
          if(f2==0){
            cc2++;
            *c2=cc2;
            f2++;
            }
          }
       if(aux==3){
          *x3=aux;
          if(f3==0){
            cc3++;
            *c3=cc3;
            f3++;
            }
          }
       if(aux==4){
          *x4=aux;
          if(f4==0){
            cc4++;
            *c4=cc4;
            f4++;
            }
          }
       if(aux==5){
          *x5=aux;
          if(f5==0){
            cc5++;
            *c5=cc5;
            f5++;
            }
          }
       if(aux==6){
          *x6=aux;
          if(f6==0){
            cc6++;
            *c6=cc6;
            f6++;
            }
          }
       if(aux==7){
          *x7=aux;
          if(f7==0){
            cc7++;
            *c7=cc7;
            f7++;
            }
          }
       if(aux==8){
          *x8=aux;
          if(f8==0){
            cc8++;
            *c8=cc8;
            f8++;
            }
          }
       if(aux==9){
          *x9=aux;
          if(f9==0){
            cc9++;
            *c9=cc9;
            f9++;
            }
          }
     }
     else{
       if(aux==0)
          if(f0==0){
            cc0++;
            *c0=cc0;
            f0++;
            }
       if(aux==1)
          if(f1==0){
            cc1++;
            *c1=cc1;
            f1++;
            }
       if(aux==2)
          if(f2==0){
            cc2++;
            *c2=cc2;
            f2++;
            }
       if(aux==3)
          if(f3==0){
            cc3++;
            *c3=cc3;
            f3++;
            }
       if(aux==4)
          if(f4==0){
            cc4++;
            *c4=cc4;
            f4++;
            }
       if(aux==5)
          if(f5==0){
            cc5++;
            *c5=cc5;
            f5++;
            }
       if(aux==6)
          if(f6==0){
            cc6++;
            *c6=cc6;
            f6++;
            }
       if(aux==7)
          if(f7==0){
            cc7++;
            *c7=cc7;
            f7++;
            }
       if(aux==8)
          if(f8==0){
            cc8++;
            *c8=cc8;
            f8++;
            }
       if(aux==9)
          if(f9==0){
            cc9++;
            *c9=cc9;
            f9++;
            }
     }
  }while(nu!=0);

} //de separar digitos

