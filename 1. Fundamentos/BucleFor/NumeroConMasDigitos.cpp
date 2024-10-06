//Programa que permita el ingreso de varios numeros ingresados y deterninar la cantidad total de digitos que en ellos existe
#include <iostream>
#include <conio.h>
#define DIV 10

using namespace std;

int main (){
    int cantidad = 0;
    int contadorDigitos = 0;
    int contadorMayor = 0;
    int numero;
    int cache;
    int respuesta;
    
    do {
        cout <<"\nIngrese la cantidad de numeros:";
        cin>>cantidad;
    } while (cantidad < 1);
    
    for(int i = 1; i <= cantidad; i ++){
        cout<<"\n Ingrese un numero ";
		cin>>numero;
        cache = numero;
        contadorDigitos = 0;
        do{
            numero /= DIV;
            contadorDigitos++;
        }while(numero != 0);
        if (contadorDigitos >= contadorMayor){
            contadorMayor = contadorDigitos;
        	respuesta = cache;
        }
    }
            
	cout<<"El numero con mas digitos es: "<<respuesta;
	return 0;
}
