/*
  Ejercicio # 4
  De cada numero ingresado determinar la suma de sus factores primos
*/
#include "iostream"
#include <conio.h>
#include "math.h"
using namespace std;
int main()
{ 

   int cantidad;  //variable que recibe la cantidad de numeros
   int numero; //variable que recibe el numero ingresado
   int sumaPrimos; //digitos primos
   int cantidadPrimos; //cantidad de elementos primos

   void leerCantidadNumeros(int *c);  //prototipo de la funcion que recibe la cantidad de numeros
   void leerNumero(int *numero);  //prototipo de la funcion que recibe los N numeros
   void separarDigitos(int *d_p,int *elp,int nm); //prototipo de la funcion que suma los digitos primos

   cout<<"\t\tSUMA DE FACTORES PRIMOS\n";
   leerCantidadNumeros(&cantidad);  //llamado a la funcion que recibe la cantidad de numeros


   for(int i=1;i<=cantidad;i++){
       cout<<"\nNUM "<<i;
       cout<<"\n____________________\n";
       leerNumero(&numero);  //llamado a la funcion que recibe los N numeros
       separarDigitos(&sumaPrimos,&cantidadPrimos,numero); //llamado a la funcion que suma los digetos primos
       cout<<"\nEl número "<<numero<<" tiene "<<cantidadPrimos<<" digitos primos y la suma es: "<<sumaPrimos;
   }

   getch();
   return 0;
} 
void leerCantidadNumeros(int *cantidad) 
{ 
   do{
       cout<<"\nIngrese cantidad de numeros: ";
       cin>>*cantidad;
   }while(*cantidad<1);
} 
void leerNumero(int *numero) 
{
   cin>>*numero;
   *numero=abs(*numero);
} 
void separarDigitos(int *sumaPrimos,int *cantidadPrimos,int numero)
{  
   int contador; 
   int numeroTemp;
   int sumatoria=0;
   int contadorPrimos=0;
   do{
      contador = 0;
      numeroTemp = numero;
      numeroTemp%=10;
      if(numeroTemp==1){
          sumatoria=sumatoria+numeroTemp;
          contadorPrimos++;
          }
      else{
          for(int i = 1;i <= numeroTemp;i ++)
               if(numeroTemp%i==0)
                  contador++;

          if(contador==2){
              sumatoria=sumatoria+numeroTemp;
              contadorPrimos++;
              }
          }
      numero/=10;
   }while(numero!=0);
   *sumaPrimos=sumatoria;
   *cantidadPrimos=contadorPrimos;
} 
