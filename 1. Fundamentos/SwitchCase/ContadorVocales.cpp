//Programa que nos permita contar las vocales que existen en una frase
#include "iostream"
#include <conio.h>

using namespace std;

int main ()
{
    char caracter;
    int contadorVocales = 0;

	cout<<"Ingrese una frase y finalice con punto (.):"<<endl;
	
    while ((caracter = getche()) !='.') 
    	switch(caracter){ 
        	case 'a':;
        	case 'A': contadorVocales++;
               	break;
        	case 'e':;
           	case 'E': contadorVocales++;
               	break;
           	case 'i':;
           	case 'I': contadorVocales++;
               	break;
           	case 'o':;
           	case 'O': contadorVocales++;
               	break;
           	case 'u':;
           	case 'U': contadorVocales++;
           		break;
        	default:
        		break;
        };
        
    cout<<endl<<"La cantidad de vocales existentes en la frase son: "<<contadorVocales;
    getch();
    return 0;
}

