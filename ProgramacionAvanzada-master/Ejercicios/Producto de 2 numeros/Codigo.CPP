//PRODUCTO DE 2 NUMEROS
#include <conio.h>
#include <iostream>
#include <windows.h>
void main()
{
    double producto(int x, int y);
    int x, y;
    cout << "Introduzca primer numero: ";
    cin >> x;
    do
    {
        cout << "Introduzca segundo numero: ";
        cin >> y;
    }while((y<0));
    cout <<"Potencia de X^N es:" <<producto(x,y)<<"\n";
    system("pause");
}
double producto(int x, int y)
{
 if (y==0)
     return 0;
 else
     return x+producto(x,y-1);
}
