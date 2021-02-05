/*
   Elaborar un programa modular que permita ingresar una frase y determinar la
   posición que ocupa la palabra que cuenta con la mayor cantidad de vocales distintas.

   Ejemplo:
   abcda, eeeeeeeeeeeeeeee iiiii ae uuuu. => 4 (está en la posición 4)

*/
#include <iostream.h>
#include <conio.h>
#include <windows.h>
#include <ctype.h>
void main()
{   //de main
     char g;  //variable que recibe el caracter ingresado

     int c1=0; //contadores de vocales
     int c3;   //espacio de almacenamiento del contador mayor de las vocales
     int p;    //espacio de almacenamiento de la posicion del contador mayor de las vocales

   int c_pal=0; //contador de palabras
   char a,A;  //variables de almacenamiento para vocal (a - A)
   char e,E;  //variables de almacenamiento para vocal (e - E)
   char i,I;  //variables de almacenamiento para vocal (i - I)
   char o,O;  //variables de almacenamiento para vocal (o - O)
   char u,U;  //variables de almacenamiento para vocal (u - U)

   void comp_caracter_min(char *x1,char *x2,char *x3,char *x4,char *x5,char f1);   //prototipo de la funcion que verifica vocales minusculas
   void comp_caracter_may(char *y1,char *y2,char *y3,char *y4,char *y5,char f2);   //prototipo de la funcion que verifica vocales mayusculas


   void comp_contadores(char a_min,char e_min,char i_min,char o_min,char u_min,char a_may,char e_may,char i_may,char o_may,char u_may,int *c,int c2,int pos,int *g_pos);  //prototipo de la funcion que compara contadores de vocales

   a=e=i=o=u=A=E=I=O=U='.';  //asigna caracter punto para hacer las combinaciones siempre que la variable no contenga este caracter

   cout<<"\t\tCONTADOR DE VOCALES DISTINTAS EN CADA PALABRA DE UNA FRASE\n";
   cout<<"______________________________________________________________________";
   cout<<"\nIngrese una frase y finalice con punto\n";
   cout<<"______________________________________________________________________\n";

   do{//ciclo de lectura mientras el caracter ingresado no sea un punto
         g=getche();
         if((g=='a')||(g=='e')||(g=='i')||(g=='o')||(g=='u')){
               comp_caracter_min(&a,&e,&i,&o,&u,g);//llamado a la funcion que verifica vocales minusculas
             }
         if((g=='A')||(g=='E')||(g=='I')||(g=='O')||(g=='U')){
               comp_caracter_may(&A,&E,&I,&O,&U,g);//llamado a la funcion que verifica vocales mayusculas
             }
         if(!isalpha(g)){  //si el caracter ingresado no es una vocal entonces verifica cual es el que tiene mas vocales hasta ese momento
             c_pal++;
             comp_contadores(a,e,i,o,u,A,E,I,O,U,&c3,c1,c_pal,&p); //llamado a la funcion que compara contadores de vocales
             c1=0; //contador de vocales vuelve a cero
             a=e=i=o=u=A=E=I=O=U='.'; //asigna caracter punto a todas las variables para q no contengan nada de valor al comparar en la siguiente palabra
         }
     }while(g!='.'); //ciclo de lectura mientras el caracter ingresado no sea un punto


     if(c3!=0) {

     SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),YELLOW);
     cout<<"\n\n******************************************************************";
     cout<<"\n********** El numero mayor de variacion de vocales es: "<<c3<<" *********\n";
     cout<<"********************* Esta en la posicion: "<<p<<" *********************";
     cout<<"\n******************************************************************";
     }
     else{
     cout<<"\n\nNo hay vocales en la frase";
     }
     SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),GREEN);
     cout<<"\n\nRealizado Por: Claudio Pilataxi\n";
     cout<<"Codigo: 6042";
     getch();

} //de ingreso frase
//
void comp_caracter_min(char *x1,char *x2,char *x3,char *x4,char *x5,char f1) //funcion que verifica vocales minusculas
{ //de comp_caracter minuscula
   if(f1=='a')  //guarda el caracter a en el espacio de memoria apuntado por x1
      *x1=f1;
   if(f1=='e')  //guarda el caracter e en el espacio de memoria apuntado por x2
      *x2=f1;
   if(f1=='i')  //guarda el caracter i en el espacio de memoria apuntado por x3
      *x3=f1;
   if(f1=='o')  //guarda el caracter o en el espacio de memoria apuntado por x4
      *x4=f1;
   if(f1=='u')  //guarda el caracter o en el espacio de memoria apuntado por x5
      *x5=f1;
} //de comp_caracter minuscula
//
void comp_caracter_may(char *y1,char *y2,char *y3,char *y4,char *y5,char f2) //funcion que verifica vocales mayusculas
{  //de comp_caracter mayuscula
   if(f2=='A')  //guarda el caracter A en el espacio de memoria apuntado por y1
      *y1=f2;
   if(f2=='E')  //guarda el caracter E en el espacio de memoria apuntado por y2
      *y2=f2;
   if(f2=='I')  //guarda el caracter I en el espacio de memoria apuntado por y3
      *y3=f2;
   if(f2=='O')  //guarda el caracter O en el espacio de memoria apuntado por y4
      *y4=f2;
   if(f2=='U')  //guarda el caracter U en el espacio de memoria apuntado por y5
      *y5=f2;
}  //de comp_caracter mayuscula
//
void comp_contadores(char a_min,char e_min,char i_min,char o_min,char u_min,char a_may,char e_may,char i_may,char o_may,char u_may,int *c,int c2,int pos,int *g_pos)//funcion que compara contadores de vocales
{  //de comp_contadores


    //incremento del contador de vocales mientras el caracter ingresado sea una vocal
    if(a_min!='.')
        c2++;
    if(e_min!='.')
        c2++;
    if(i_min!='.')
        c2++;
    if(o_min!='.')
        c2++;
    if(u_min!='.')
        c2++;
    if(a_may!='.')
        c2++;
    if(e_may!='.')
        c2++;
    if(i_may!='.')
        c2++;
    if(o_may!='.')
        c2++;
    if(u_may!='.')
        c2++;

    if(pos==1){
       *c=c2;  //asigna el primer contador al espacio de memoria asignado en main
       *g_pos=pos;  //asigna la primera posicion al espacio de memoria asignado en main
       }
    else{
       if(c2>=*c){
          *c=c2;  //asigna el contador mayor al espacio de memoria asignado en main
          *g_pos=pos;   //asigna la nueva posicion al espacio de memoria asignado en main
       }
    }

}  //de comp_contadores

//
