//Programa q nos permita contar las vocales q existen
#include "iostream"
#include <conio.h>
using namespace std;
int main ()
{
    char c;  //ingreso de caracteres de la frase
    int cv = 0; //cuenta vocales de la frase

    while ((c = getche()) !='.')  //ciclo de lectura, finaliza cuando se ingresa el c
        switch(c){ //poner el valor que quiere comparar
           case 'a' : ;  //cuando se ingresa una letra a se cuenta entre vocales :
           case 'A' : cv++;
               break; //salida incondicional del switch
           case 'e' : ;  //cuando se ingresa una letra e se cuenta entre vocales :
           case 'E' : cv++;
               break; //salida incondicional del switch
           case 'i' : ;  //cuando se ingresa una letra i se cuenta entre vocales :
           case 'I' : cv++;
               break; //salida incondicional del switch
           case 'o' : ;  //cuando se ingresa una letra o se cuenta entre vocales :
           case 'O' : cv++;
               break; //salida incondicional del switch
           case 'u' : ;  //cuando se ingresa una letra u se cuenta entre vocales :
           case 'U' : cv++;

        }; //fin de switch
    cout<<"La cantidad de vocales existentes en la frase son: "<<cv;
    getch ();
    return 0;
}

