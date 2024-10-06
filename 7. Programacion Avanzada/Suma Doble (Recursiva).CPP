//SUMA DOBLE RECURSIVA
#include <iostream.h>
#include <conio.h>
double num(double x, double y)
{
    if(y==0)
       return(0);
    else
       return(x+num(x,y-1));
}
void main(){

    double n;
    cout<<"\nIngrese un numero: ";
    cin>>n;
    cout<<num(n,n);
    getch();
}


