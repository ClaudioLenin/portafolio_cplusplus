//Convierte el algoritmo recursivo que calcula
//la potencia de un número natural entero
//positivo x^n a su forma iterativa.
#include <iostream.h>
#include <conio.h>
void main()
{
    int x,n;
    int r=1;
    do{
       cout<<"\nIngrese un numero: ";
       cin>>x;
       cout<<"\nIngrese exponente: ";
       cin>>n;
       }while(x<0);

    for(int i=0;i<n;i++)
       r*=x;
    cout<<"\nRespuesta: "<<r;
    getch();
}