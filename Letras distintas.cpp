/*
   Elaborar un programa que permita el ingreso de una frase, y proceda a modificar
   el orden de las palabras que contiene en función de la cantidad de letras
   distintas que posee. Se debe emplear el orden decreciente. Ejemplo:

FRASE:                     AHORA VAMOS A PRACTICAR CADENAS.

LETRAS DISTINTAS:      4           5      1         6                 6

RESPUESTA:            PRACTICAR CADENAS VAMOS AHORA A.
*/
#include <iostream.h>
#include <conio.h>
#include <string.h>
#include <stdio.h>
#include <ctype.h>
void main(){
   char cad[50]; //definicion de la cadena de caracteres
   char m[50][50];  //definicion de una mtriz que contendra todas las palabras,,,una en cada renglon
   int i;  //contador de ciclo for
   int f=0;  //contador de las filas de la matriz
   int c=0;  //contador de las columnas de la matriz
   int cd; //cantidad de caracteres distintos
   int vp[50];  //vector de posiciones de cada palabra
   int c_dis[26]; //vector de la cantidad de caracteres distintos de cada palabra
   int determinar_cantidad_de_palabras_distintas(char v1[]); //prototipo de la funcion que permite determinar la cantidad de letras distintas
   void ordenar_vector(int cc[],int cp[],int el);   //prototipo de la funcion que permite ordenar los elementos de mayor a menor de los caracteres distintos
   char final[50]; //cadena de caracteres que contendra las palabras ya ordenadas
   int cont=0; //contador de cantidad de filas de la matriz de caracteres y asi ir uniendo las palabras en una sola cadena
   int n;  //variable que recibe la posicion almacenada despues de la ordenacion del vector de cantidad de elementos distintos



   cout<<"\t\tINGRESE UNA FRASE\n";
   gets(cad);  //lectura de la cadena de caracteres
   for(i=0;i<strlen(cad);i++){
       if(isalpha(cad[i])){   //si es un caracter alfabetico entonces guardo en la matriz fila por fila
           m[f][c++]=cad[i];  //guarda cada caracter alfanumerico en la matriz
           }
       else {
           m[f][c]='\0';   //final de la matriz de caracteres
           c=0;     //ubica en la posicion cero de cada fila de la matriz
           f++;     //incremento de las filas
           }
   }

   m[f][c]='\0'; //final de la ultima fila de la matriz
   for(i=0;i<=f;i++){
       cd=determinar_cantidad_de_palabras_distintas(m[i]); //llamado a la funcion que permite determinar la cantidad de letras distintas
       c_dis[i]=cd;  //asigna al vector la canidad de caracteres distinos de la cadena
       vp[i]=i; //asigna la posicion de la cadena procesada
       }
   ordenar_vector(c_dis,vp,f);    //llamado a la funcion que permite ordenar los elementos de mayor a menor de los caracteres distintos
   final[0]='\0';  //como es una cadena vacia entonces tiene como primer caracter el final ('\0')

   do{
      n=vp[cont]; //adquiere la posicion guardada en el vector
      cont++;  //incremento de contador
      strcat(final,m[n]);  //une la cadena vacia con la cadena de la matriz en la posicion n
      strcat(final," ");   //añade un espacio entre palabras de la cadena anterior
   }while(cont!=f+1);

   cout<<"\n\nLA CADENA ORDENADA ES\n";
   cout<<"________________________________________\n";
   puts(final);  //mpresion de la cadena modificada
   getch();
}
//
int determinar_cantidad_de_palabras_distintas(char v1[])//funcion que permite determinar la cantidad de letras distintas
{
   int i;  //contador de ciclo for
   char car[26];//caracteres distintos
   int k=0; //contador de vector de caracteres distintos
   int cont; //contador

   for(i=0;i<strlen(v1);i++){
       if(i==0){
          car[k]=v1[i]; //el primer caracter
          k++;
          }
       else{
          cont=0;
          for(int h=0;h<k;h++)
             if(car[h]==v1[i])
                 cont++;
          if(cont==0){  //si el caracter es distinto se guarda en una cadena auxiliar
              car[k]=v1[i];  //guarda en un vector auxiliar el caracter distinto
              k++;  //incremento de la cantidad de elementos
              }
          }
       }
   car[k]='\0';
   return(strlen(car));
}

//
void ordenar_vector(int cc[],int cp[],int el)//funcion que permite ordenar los elementos de mayor a menor de los caracteres distintos
{
 int i;
 int j;
 int aux1;  //contiene la cantidad de caracteres distintos
 int aux2;  //guarda la posicion de la cadena

 for(i=0;i<=el-1;i++)
    for(j=i+1;j<=el;j++)
       if(cc[i]<cc[j]){  //ordenamiento de la cantidad de caracteres distintos y tambien ubica en que orden se deben imprimir cada palabra
           aux1=cc[i];
           cc[i]=cc[j];
           cc[j]=aux1;

           aux2=cp[i];   //ubica en que orden se deben imprimir las palabras
           cp[i]=cp[j];
           cp[j]=aux2;
       }
}

