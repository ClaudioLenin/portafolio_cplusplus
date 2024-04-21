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
    char f;    //caracteres de la frase
    int c1may = 0;
    int c1min = 0;  //contador iniciado en 0
    int cdig = 0;

    cout<<"\nIngrese la frase caracter por caracter, Finalizando con punto:";
    do{//inicio de ciclo de lectura
        cin>>f;
        //f = getch();
        //cout<<"X";
        //cin>>f;
        if((f >= 'a' ) && (f <= 'z')) //Es letra mayuscula o minuscula?
            c1min ++;    //se cuenta la letra
        else
            if((f >= 'A' ) && (f <= 'Z'))
                c1may++;
            else if ((f >= '0')&&(f <='9'))
                cdig++;
    }while(f != '.');  //inicio de ciclo de lectura

    cout<<"\nLa cantidad de letras mayusculas es:"<<c1may;
    cout<<"\nLa cantidad de letras minusculas es:"<<c1min;
    cout<<"\nLa cantidad de digitos es:"<<cdig;
	getch ();
	return 0;
}  //fin de main
