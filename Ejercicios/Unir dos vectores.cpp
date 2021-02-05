/*
  Ejercicio 14
  Calcular la union de dos vectores inicialmente ingresados
*/
#include <iostream.h>
#include <conio.h>
#include <deber7.h>
#define T 20  //dimension definida para el arreglo
void main ()
{//de main
   int v1[T],v2[T]; //declaracion del arreglo con dimension T
   int n; //variable que recibe la cantidad de elementos al vector

   void unir_vectores(int vx1[],int vx2[],int c);//prototipo de la funcion que permite unir dos vectores ingresados

   cout<<"\t\tCALCULAR UN TERCER VECTOR\n";
   cout<<"________________________________________________________";
   cout<<"\nDIMENSION DE LOS DOS VECTORES";
   n=lee_n(T);//llamado a la funcion que permite el ingreso de la cantidad de valores para el vector
   cout<<"\n\t\tARREGLO 1\n";
   cout<<"________________________________________________________";
   leer_vector(v1,n); //llamado a la funcion que permite el ingreso de los N elementos al vector
   cout<<"\n\t\tARREGLO 2\n";
   cout<<"________________________________________________________";
   leer_vector(v2,n); //llamado a la funcion que permite el ingreso de los N elementos al vector

   unir_vectores(v1,v2,n);//llamado a la funcion que permite unir dos vectores ingresados

   getch();
}//de main
//
void unir_vectores(int vx1[],int vx2[],int c)//funcion que permite unir dos vectores ingresados
{

  int nuevo_valor(int x1,int x2); //prototipo de la funcion que permite unir cada valor de los dos vectores
  int v3[T]; //nuevo vector con valores unidos
  int i=0;

  for(;i<c;i++)
    v3[i]=nuevo_valor(vx1[i],vx2[i]);   //llamado a la funcion que permite unir cada valor de los dos vectores

  cout<<"\n\t\tNUEVO VECTOR\n";
  for(i=0;i<c;i++)
    cout<<"V["<<i<<"]: "<<v3[i]<<endl;

}
//
int nuevo_valor(int x1,int x2) //funcion que permite unir cada valor de los dos vectores
{
int num,dig,n_num=0,n=0;

      do{
           dig=x1%10;
           x1/=10;
           n_num=(n_num*10)+dig;
           }while(x1!=0);
      do{
           dig=x2%10;
           x2/=10;
           n_num=(n_num*10)+dig;
      }while(x2!=0);

      do{
           dig=n_num%10;
           n_num/=10;
           n=(n*10)+dig;
      }while(n_num!=0);

    return(n);


}
