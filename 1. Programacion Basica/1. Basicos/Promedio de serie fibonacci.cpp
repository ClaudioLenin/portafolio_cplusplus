/*
  Elaborar el programa modular que permita calcular el promedio de los valores
  ingresados por el usuario que formen parte de la serie Fibonacci
*/
#include "iostream"
#include <conio.h>
#include <windows.h>
using namespace std;
int main ()
{//de main
   int n;  //variable que recibe la cantidad de numeros
   int cant_num(); //Prototipo de la funcion que recibe la cantidad de numeros
   int i;  //contador de ciclo
   int num; //variable que recibe el numero ingresado
   int acum=0; //variable acumuladora
   int c_cant=0; //contador de cantidad de numeros que si cumlen la condicion propuesta


   void fibonacci(int *a,int a1,int *c,int c1,int nn); //prototipo de la funcion que permite realizar la serie fibonacci




   cout<<"\t\tPROMEDIO DE LOS VALORES DENTRO DE LA SERIE FIBONACCI\n";
   cout<<"_______________________________________________________________________";
   n=cant_num(); //Llamado a la funcion que determina la cantidad de numeros a procesar
   for(i = 1;i <= n;i ++){   //ciclo de lectura de los N numeros
       cout<<"\nNUM "<<i;
       cout<<"\n_________________________________\n";
       cin>>num;  //ingreso de numero
       fibonacci(&acum,acum,&c_cant,c_cant,num); //llamado a la funcion que permite realizar la serie fibonacci

   }
   cout<<"\n********************************************************************************";
   cout<<"\nExisten "<<c_cant<<" Elementos de la serie Fibonacci\n";
   cout<<"\n********************************************************************************";
   cout<<"\nLa suma de estos elementos es: "<<acum;
   cout<<"\n********************************************************************************";
   cout <<"\nEl promedio de "<<acum<<"/"<<c_cant<<" = "<<acum/c_cant;
   cout<<"\n********************************************************************************\n";
   getch();
   return 0;
}//de main
//
int cant_num() //funcion que recibe la cantidad de numeros
{//de cantidad de numeros
   int n; //variable que recibe a cantidad de numeros
   do{ //ciclo de lectura de la cantidad de numeros mientras sea menor que uno
       cout<<"\nIngrese la cantidad de numeros a procesar: ";
       cin>>n; //lectura de cantidad de numeros
   }while(n<1);
   return(n); //retorno de la cantidad de numeros
}//de cantidad de numeros

//
void fibonacci(int *a,int a1,int *c,int c1,int nn) //funcion que permite realizar la serie fibonacci
{ //de la serie fibonacci
   int n1=0;   //variable 1 sumadora de la serie fibonacci
   int n2=1;   //variable 2 sumadora de la serie fibonacci
   int var_serie; //acumulador de la serie fibonacci
   void suma(int *ss,int ss1,int ss2);  //prototipo de la funcion que permite realizar la suma de la serie fibonacci
   int i=0;  //variable contadora
   int j=0;  //variable contadora


   do{   //ciclo de desarrollo de la serie fibonacci hasta que sea igual al numero ingresado
     i++;


     if(i==1)
         var_serie=0;  //var_serie toma un valor de cero
     else
         if(i==2){
           var_serie=1; //var_serie toma un valor de uno
           }
         else{
             suma(&var_serie,n1,n2);  //llamado a la funcion que permite realizar la suma de la serie fibonacci
             n1=n2;   //n1 toma el valor de n2
             n2=var_serie; //n2 toma el valor de la suma realizada anteriormente
           }


     if(nn==1){ //comaparacion del numero ingresado con los elementos de la serie
        j++;
        if(j==1){
          cout<<"Si esta dentro de la serie\n";
          c1++;     //incremento de la cantidad de elementos que cumplen la condicion
          *c=c1;    //devuelve el incremento al espacio apuntado por el acumulador
          a1=a1+nn; //acumula el valor si cumple con la condicion
          *a=a1;    //devuelve el valor acumulado al espacio apuntado por el acumulador
          }
        }
     else{
     if(var_serie==nn){
          cout<<"Si esta dentro de la serie Fibonacci\n";
          c1++;     //incremento de la cantidad de elementos que cumplen la condicion
          *c=c1;    //devuelve el incremento al espacio apuntado por el acumulador
          a1=a1+nn; //acumula el valor si cumple con la condicion
          *a=a1;    //devuelve el valor acumulado al espacio apuntado por el acumulador
     }
     }

   }while(var_serie<=nn);

} //de la serie fibonacci
//
void suma(int *ss,int ss1,int ss2)  //funcion que permite realizar la suma de la serie fibonacci
{  //de suma
  *ss=ss2+ss1;  //devuelve la suma de la serie fibonacci
}  //de suma
