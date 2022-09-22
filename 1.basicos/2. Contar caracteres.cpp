//PROGRAMA QUE PERMITA CONTAR LAS LETRAS DE UNA FRASE INGRESADA
//datos ==>frase
//cantidad de letras
//Frase sucesiôn de char
//caracter de fin de frase ==>"."
#include "iostream"
#include <conio.h>
using namespace std;

int main ()
  { 
     char frase;   
     int cantidadMayusculas = 0;
     int cantidadMinusculas = 0; 
     int cantidadDigitos = 0;

        cout<<"\nIngrese la frase caracter por caracter, Finalizando con punto:";
        do{
            cin>>frase;
            //frase = getch();
            //cout<<"X";
            //cin>>frase;
            if((frase >= 'a' ) && (frase <= 'z'))
                cantidadMinusculas++;
            else
                if((frase >= 'A' ) && (frase <= 'Z'))
                	cantidadMayusculas++;
                else
                    if ((frase >= '0')&&(frase <='9'))
                        cantidadDigitos++;
        }while(frase != '.');

    cout<<"\nLa cantidad de letras mayusculas es:"<<cantidadMayusculas;
    cout<<"\nLa cantidad de letras minusculas es:"<<cantidadMinusculas;
    cout<<"\nLa cantidad de digitos es:"<<cantidadDigitos;
	getch ();
	return 0;
}
