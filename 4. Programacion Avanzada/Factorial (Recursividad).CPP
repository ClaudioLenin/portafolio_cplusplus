//FACTORIAL DE UN NUMERO
#include <iostream.h>
#include <conio.h>
int factorial(int n)
{
   int resultado=0;
   if(n==0)
       resultado=1;
   else
       resultado=(n*factorial(n-1));
   return(resultado);
}

void main ()
{
   int n;
   cout<<"\nIngrese un numero: ";
   cin>>n;
   cout<<"\nEl factorial es: "<<factorial(n);
   getch();
}

//https://mega.nz/#!1tRhmAaB!0vWkX4ePThUqfxsaPudNbUuldPfko5jPsD0HpzaD0Ik
