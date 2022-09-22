/*
  Programa que permita el ingreso de varios numeros enteros y determine la posicion
  en que se encuentra el digito mayor de cada uno de ellos

*/
#include <iostream.h>
#include <conio.h>
#include <math.h>
void main (){  //Inicio main
int n;  //cantidad de numeros
int num; //contiene el numero ingresado
int i; //contador ciclo for
int may; //contiene el valor mayor
int pos; //contador de posicion del valor mayor
int aux,x; //variable auxiliar
int g_pos; //contiene posicion
int p_p;  //guarda cantidad de elementos
int n_i; //contador de mumeros iguales

   cout<<"\nPROGRAMA QUE DETERMINA EL DIGITO MAYOR DE CADA NUMERO INGRESADO\n";
   cout<<"____________________________________________________________________\n";
   do{//ciclo de cantidad de numeros
      cout<<"\nIngrese la cantidad de numeros: ";
      cin>>n;
   }while(n<1); //repite mientras el valor sea negativo



   for(i=1;i<=n;i++){  //inicio for
      cout<<"\n\n"<<i<<char(248)<<" NUMERO: ";
      cin>>num;
      num=abs(num);
      pos=0;
      x=num;
      n_i=1;

         do{   //ciclo que cuenta los elementos totales del numero
                pos++; //cuenta elementos
                num/=10;
         }while(num!=0);

         p_p=pos;   //guarda la cantidad de elementos para volver a disminuir



         do{ //ciclo que cuenta la posicion de los numeros de izquierda a derecha
                aux=x;   //asiga el nuevo valor entero
                aux%=10;  //separa el digito

                if(pos==p_p){
                    may=aux;   //define el primer valor mayor
                    g_pos=pos;  //guarda la primera posicion
                }
               else{
                   if(aux>may){
                       may=aux;  //cambia el valor mayor
                       g_pos=pos; //guarda la posicion
                   }
                   else{
                      if(aux==may)
                         n_i++;   //cuenta si existe numeros iguales
                   }


                }
                 x/=10; //recorre la coma del numero
                 pos--;   //disminuye la cantidad de elementos

         }while(x!=0);//repite mientras que el numero aun contenga digitos

    if(n_i==p_p)
      cout<<"\nNo existe numero mayor.....";
    else
      cout<<"\nEl digito mayor es "<<may<<" ocupa la posicion "<<g_pos;

   }//fin for
   cout<<"\n\n\t\tREALIZADO POR: Claudio Pilataxi ";
   cout<<"\n\t\t\tCODIGO: 6042";

/*
     Para la resolucion de este ejercicio lo primero que se desarrolla es contar
     la cantidad de elementos, desarmando el numero ingresado dividiendo para diez
     antes de esto se conserva el numero en otra variable para el siguiente proceso.

     Una vez contado la cantidad de digitos del numero, volvemos a desarmar el numero
     guardado anteriormente para contar los digitos de izquierda a derecha, es decir
     disminuimos la cantidad de elementos contada anteriormente, comparando con una
     variable adicional que es may y guardando la pocision.

     Es asi como se ha resuelto este ejercicio..........
*/

getch();
}  //fin main