//Programa q permita individualizar los digitos de cada numero ingresado
#include "iostream"
#include <conio.h>
#include <math.h>
using namespace std;
int main ()
{ //de main
    int n; //cantidad de numeros
    int ing_cant_numeros();  //Prototipo de la funcion q ingresa la cantidad de numeros
    void ing_numeros (int can_num);   //Prototipo de la funcion q ingresa los numeros

    n = ing_cant_numeros();    //llamado a la funcion q ingresa la cantidad de numeros
    ing_numeros(n);   //llamado a la funcion q ingresa los numeros, le pasamos n

    getch ();
    return 0;
} //de main






  int ing_cant_numeros ()  //funcion q ingresa la cantidad de numeros
  {  //de   int ing_cant_numeros
    int a; //variable para implementar la lectura de la cantidad de numeros

    do{  //ciclo de lectura de cantidad de numeros
       cout<<"Ingrese cantidad de numeros";
       cin>>a;
       } while (a<1); //rechazar cero y negativo
       return (a);
  } //  fin int ing_cant_numeros







   void ing_numeros (int can_num)   //funcion q ingresa los numeros
   {    // de ingreso numeros
        int i; //contar ciclo de lectura
        int num; //variable para almacenar numeros ingresados

        void extraer_digitos (int nume); //no tiene salida ; Prototipo de la funcion q extrae los digitos
        for(i = 1;i <= can_num;i++){ //inicio for
             cout <<"\nIngrese numero: ";
             cin>>num;  //lectura de numero
             extraer_digitos (num); //llamado a la funcion q extrae los digitos de cada numero
             } //Fin for
   }    // de ing_numeros







void extraer_digitos (int nume) //funcion q extrae los digitos
{    // extraer_digitos
    int dig;   //contener los digitos q salgan del numero
    int cont=0;
    do{ //ciclo de individualizacion
        dig = nume % 10; //Extraer un digito
        cout <<abs (dig)<<"   "; //imprimir digito extraido
        cont+=dig;
        nume /= 10; //eliminar el digito extraido del numero
        } while (nume !=0 ); //repetir mientras hay digitos en la funcion
        cout <<"\nLa suma de los digitos de este numero es: "<< cont;

}

