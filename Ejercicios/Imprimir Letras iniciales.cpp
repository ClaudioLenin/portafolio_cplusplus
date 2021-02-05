/*
  Ejercicio # 5
  Ingresar una lista de nombre e imprimir las letras iniciales empleadas siempre
  y cuando sean mayusculas
*/
#include <iostream.h>
#include <conio.h>

void main()
{ //de main
   int n;  //variable que recibe la cantidad de nombres
   int i;  //contador de ciclo
   char f; //variable de ingreso caracter

   void cant_nombres(int *cn); //prototipo de la funcion que recibe la cantidad de nombres
   void leer_nombre(char *x); //prototipo de la funcion que permite el ingreso de una frase

   cout<<"\t\tIMPRIMIR EL PRIMER CARACTER MAYUSCULA DE CADA NOMBRE\n";
   cant_nombres(&n); //llamado a la funcion que recibe la cantidad de nombres

   for(i = 1;(i <= n);i++){
       cout<<"\nNOMBRE "<<i;
       cout<<"\n____________________\n";
       leer_nombre(&f); //llamado a la funcion que permite el ingreso de una frase
   }
   getch();
} //de main
//
void cant_nombres(int *cn) //prototipo de la funcion que recibe la cantidad de nombres
{ //de cantidad de nombres
   do{
     cout<<"\Ingrese cantidad de nombres: ";
     cin>>*cn;
     }while(*cn<1);
} //de cantidad de nombres
//
void leer_nombre(char *x) //prototipo de la funcion que permite el ingreso de una frase
{ //de leer nombre
  cout<<"\n(Ingrese el nombre y finalice con punto)\n";
  char aux;
  int c=0;
  bool r=false;
  do{
     c++;
     *x=getche();
     if(c==1)
        if((*x>='A')&&(*x<='Z')){
            aux=*x;
            r=true;
            }
  }while(*x!='.');


  if(r)
     cout<<"\nPrimer caracter del nombre **** "<<aux<<" ***";
  else
     cout<<"\nPrimer caracter de nombre no es mayuscula";
} //de leer nombre
