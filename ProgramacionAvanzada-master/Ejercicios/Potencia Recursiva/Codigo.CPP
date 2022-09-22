//POTENCIA
#include <conio.h>
#include <iostream>
#include <windows.h>
int main()
{
    double potencia(int x, int n);
    int x, n;
    cout << "Introduzca base X: ";
    cin >> x;
    do
    {
        cout << "Introduzca exponente N: ";
        cin >> n;
    }while(n<0);
    cout <<"Potencia de X^N es:" <<potencia(x,n)<<"\n";
    system("pause");
}
double potencia(int x, int n)
{
 if (n==0)
     return 1;
 else
     return x*potencia(x,n-1);
}