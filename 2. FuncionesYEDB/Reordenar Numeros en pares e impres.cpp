/*
Elaborar un programa modular en C++ que permita el ingreso de varios números enteros,
y con cada uno de ellos, forma un nuevo número conformado solamente con los dígitos pares del número original,
y otro valor que contenga solo los dígitos impares. Ejemplo:

Números                                          Respuestas

149                                                  4,     19

-328                                                28,    3

462                                                 462,   No existen dígitos impares

-179                                                No existen dígitos pares,  179
*/
#include "iostream"
#include <conio.h>
#include <math.h>
using namespace std;
int main (){
   int n; //cantidad de numeros
   int cant_numeros();//prototipo de la fucion que permite el ingreso de la cantidad de numeros
   void ing_numeros(int t);//prototipo de la fucion que permite el ingreso de los N numeros

   cout<<"\t\tSEPARAR DIGITOS (PARES E IMPARES)\n";
   n=cant_numeros();//llamado a la fucion que permite el ingreso de la cantidad de numeros
   ing_numeros(n);//llamado a la fucion que permite el ingreso de los N numeros

	getch();
	return 0;
}
//
void ing_numeros(int t)//fucion que permite el ingreso de los N numeros
{//de ingreso de numeros
   int i; //contador de ciclo
   int num;  //para lectura de numero
   void separar_digitos(int nume); //prototipo de la funcion que permite separar los digitos

   for(i = 1;i <= t;i ++){ //ciclo for
       cout<<"\n\nNUM "<<i;
       cout<<"\n________________________\n";
       cin>>num;      //lectura del numero
       num=abs(num);  //asigna valor absoluto del numero

       separar_digitos(num); //llamado a la funcion que permite separar los digitos

   }  //ciclo for
   cout<<"\n\n\t\tRealizado por: CLAUDIO PILATAXI \n";
   cout<<"\t\t\tCodigo: 6042 \n";
}//de ingreso de numeros
//
int cant_numeros()//fucion que permite el ingreso de la cantidad de numeros
{//de cantidad de numeros
   int n;
   do{ //ciclo do-while que repite si el numero es negativo
       cout<<"\nIngrese cantidad de numeros: ";
       cin>>n;  //lectura de cantidad de numeros
   }while(n<1);  //ciclo do-while que repite si el numero es negativo

   return(n);   //retorna valor
}//de cantidad de numeros
//
void separar_digitos(int nume) //funcion que permite separar los digitos
{   //de separar digitos
   int aux;  //variable auxiliar para intercambiar valores mientras se va modificando el numero ingresado y separando digitos
   int m1,m2;//variables multiplicadoras
   int par; //acumulador de digitos pares
   int impar;//acumulador de digitos impares

   par=impar=0;  //anula los valores anteriores para volver a acumular
   m1=m2=1;      //anula los valores anteriores para volver a multiplicar

   do{   //ciclo do-while para separar digitos
          aux=nume; //asigna un nuevo valor a aux
          aux%=10; //extrae digito
          nume/=10; //recorre un espacio del numero
             if(aux%2==0){
               par=par+aux*m1;  //acumula numeros pares
               m1=m1*10;   //actualiza el multiplicador de los pares
               }
             else{
               impar=impar+aux*m2;  //acumula numeros impares
               m2=m2*10;   //actualiza el multiplicador de los impares
             } //ciclo do-while para separar digitos

       }while(nume!=0);
       if((par==0)&&(impar==0))
           cout<<"\nNo existen digitos pares , No existen digitos impares "<<endl;

       if((par==0)&&(impar!=0))
           cout<<"\nNo existen digitos pares , "<<impar<<endl;

       if((par!=0)&&(impar==0))
           cout<<"\n"<<par<<", No existen digitos impares "<<endl;

       if((par!=0)&&(impar!=0))
           cout<<"\n"<<par<<" , "<<impar<<endl;

}   //de separar digitos
