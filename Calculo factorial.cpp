/*
  Ejercicio 12
  Calcular el factorial del producto de los elementos de un vector comprendidos
  entre las posiciones M y N
*/
#include <iostream.h>
#include <conio.h>
#include <deber7.h>
#define T 20  //dimension definida para el arreglo
void main ()
{//de main
   int v[T]; //declaracion del arreglo con dimension T
   int c;
   int m;
   int n;

   void producto(int vec[],int cant,int v_m,int v_n);//prototipo de la funcion que calcula el producto de las n posiciones

   cout<<"\t\tFACTORIAL\n";
   cout<<"________________________________________________________";
   c=lee_n(T);//llamado a la funcion que permite el ingreso de la cantidad de valores para el vector
   leer_vector(v,c); //llamado a la funcion que permite el ingreso de los N elementos al vector
   do{
      cout<<"\nIngrese la posicion M: ";
      cin>>m;
      }while((m<0)||(m>(c-1)));
   do{
      cout<<"\nIngrese la posicion N: ";
      cin>>n;
      }while((n<m)||(n>(c-1)));

   producto(v,c,m,n);//llamado a la funcion que calcula el producto de las n posiciones
   getch();
}//de main
//
void producto(int vec[],int cant,int v_m,int v_n)//funcion que calcula el producto de las n posiciones
{
   int i=0;
   int producto;
   int r;
   int factorial(int pro); //prototipo de la funcion que calcula el factorial de las n posiciones
   for(producto=1;i<cant;i++)
      if((i>=v_m)&&(i<=v_n))
         producto*=vec[i];
   r=factorial(producto); //llamado a la funcion que calcula el factorial de las n posiciones
   cout<<"\nEl factorial de las posiciones ["<<v_m<<"...."<<v_n<<"] es:"<<r;
}
//
int factorial(int pro) //funcion que calcula el factorial de las n posiciones
{
  int p=1;
  for(int i=1;i<=pro;i++)
      p*=i;
  return(p);
}
