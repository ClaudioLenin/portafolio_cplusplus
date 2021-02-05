//Programa que permite individualizar los digito de cada numero ingresado
#include <iostream.h>
#include <conio.h>
#include <math.h>
#include <windows.h>

void main()
 {//de_main
   int n; //cantidad de numeros
    system ("color F");
   int ing_cant_numeros(); //prototipo de la funcion que ingresa la cantidad de numeros
   void ing_numeros(int can_num);  //prototipo de la funcion que ingresa los numeros
   void elaborado();

   n = ing_cant_numeros(); //llamado a la funcion que ingresa la cant. de numeros
   ing_numeros(n);  //llamado a la funcion que ingresa los numeros, le pasamos el valor de n
   elaborado();
   getch();
 }//de_main

 int ing_cant_numeros()//funcion que ingresa la cantidad de numeros
 {  //de ing_cant_numeros
 int a;
   do{
   cout<<"\nIngrese la cantidad de numeros.  ";
   cin>>a; //lectura del valor
     }while(a<1); //rechazar el cero y los negativos
     return(a); //retornar el valor leido y restringido
 } //de ing_cant_numeros


 void ing_numeros(int can_num)
 {//de ing_numeros
  int i=1; //contar el ciclo de lectura
  int num,j; //variable para almacenar los numeros a ingresar
  int sumt=0;
  int extraer_digitos(int nume); //prototipo de la funcion que extrae los digitos de cada numero
   for(;(i<=can_num);) //ciclo de lectura y càlculo
    {//de for
    cout<<"\nIngrese numero. ";
    cin>>num; //lectura del numero

    j=extraer_digitos(num); //llamado a la funcion que extrae los digitos de cada numero.
    sumt=sumt+j;
    i++;
    }//de for
     cout<<"\n\nSuma total. "<<sumt;
 }//de ing_numeros


int extraer_digitos(int nume)
 { //de extraer_digitos
 int dig,k=0,sumt=0;
    do{ //ciclo de individualizacion
   	dig= (abs(nume) % 10); //toma el valor absoluto del numero.
     	cout<<"\n"<<dig; //imprime el digito extraido
      nume/=10;
      k=k+dig;
     }while(nume != 0); //
      return(k);
 } //de extraer_digitos

  void elaborado()
  {
    cout<<"\n\n\nby.    ";
    cout<<"C";Sleep(75);
    cout<<"H";Sleep(75);
    cout<<"O";Sleep(75);
    cout<<"T";Sleep(75);
    cout<<"O";Sleep(75);
    cout<<" - ";Sleep(75);
    cout<<"6";Sleep(75);
    cout<<"0";Sleep(75);
    cout<<"2";Sleep(75);
    cout<<"3";Sleep(75);
    }