//Convierte el algoritmo recursivo que calcula
//el producto de dos números enteros positivos
//en su forma iterativa.
#include <iostream.h>
#include <conio.h>
void main()
{
   int n1,n2;
   int r=1;
   int s=0;

   do{
      cout<<"\nIngrese 1° numero: ";
      cin>>n1;
      cout<<"\nIngrese 2° numero: ";
      cin>>n2;
      }while(n1<0 || n2<0);
   do{
      s=n1+s;
      n2--;
   }while(n2!=0);

   cout<<"\nRespuesta: "<<s;

   getch();
}