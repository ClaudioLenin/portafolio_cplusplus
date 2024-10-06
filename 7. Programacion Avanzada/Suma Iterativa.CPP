// Convierte el algoritmo recursivo que calcula
//la suma de dos números enteros positivos en
//su forma iterativa.
#include <iostream.h>
#include <conio.h>
void main()
{
    int n1,n2;
    do{
        cout<<"\nIngrese el 1° numero: ";
        cin>>n1;
        cout<<"\nIngrese el 2° numero: ";
        cin>>n2;
    }while(n1<0||n2<0);

    do{
       n1+=1;
       n2--;
    }while(n2!=0);
    cout<<"\nRespuesta: "<<n1;
    getch();
}