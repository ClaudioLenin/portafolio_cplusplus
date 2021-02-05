Ejercicio 2
/*Ejercicio # 2
Realizaddo por: Claudio Pilataxi
Código: 6042                        */
#include <iostream.h>
#include <conio.h>
#include <math.h>
#include <matriz.h>
#define F 20
#define C 20
void main ()
{
 int a,b;  //variables que reciben valores de filas y columnas del archivo de
cabecera matriz.h
 int m[F][C]; //matriz definida
 void invertir(int mat[][C],int f, int c); //Prototipo de la funcion que permite
invertir los valores de la matriz ingresada
 cout <<"\nPROGRAMA QUE PERMITE TRANSPONER LOS ELEMENTOS DE UNA MATRIZ SOBRE SI
MISMA\n\n";
 a=filas(F); //llamado a la funcion que permite ingresar la cantidad de filas
del archivo de cabecera matriz.h
 b=columnas(C); //llamado a la funcion que permite ingresar la cantidad de
columnas del archivo de cabecera matriz.h
 ing_valores (m,a,b);  //llamado a la funcion que permite ingresar los valores
en una matriz del archivo de cabecera matriz.h
 invertir(m,a,b); //Llamado a la funcion que permite invertir los valores de la
matriz ingresada
 imprimir_valores (m,a,b);   //Llamado a la funcion que permite imprimir los
elementos de una matriz  de cabecera matriz.h
 getch();
}
//******************************************************************************
*******************************
void invertir(int mat[][C],int f, int c) //Funcion que permite determinar el
factorial de cada numero de la matriz ingresada
{ //Inicio funcion......
 int i,j,x; //variables contadoras del ciclo for
 int aux;  //contador de numero de elementos
 int resp;  //variable de respaldo
 int dis1=f,dis2=c;  //posiciones de la matriz
     x=(f*c)/2;  //variable que define el cambio de valores solo hasta la mitad
de la matriz
 if((f*c)%2==0)
     aux=0;
 else
     aux=1;
 cout <<"\n\t\tMATRIZ INVERTIDA\n";
Página 1
Ejercicio 2
    for (i=1;i<=f;i++){    //ciclo de columnas
       for(j=1;j<=c;j++){  //ciclo de filas
             aux++;   //cuenta cantidad de elementos que se estan cambiando
             resp= mat[i][j];  //guardo el primer valor en la variable de
respaldo
             mat[i][j] = mat[dis1][dis2];  //ubico el valor de la ultima
posicion en una del comienzo
             mat[dis1][dis2]=resp;   //coloco el valor de respaldo en la ultima
posicion de la matriz
             if(x==aux){  //si los valores han llegado a la mitad entoces salto
el ciclo
                i=f;
                j=c;
             }
             dis2--;   //disminuye el numero de columnas desde la ultima
posicion
       }
       dis1--;  //disminuye el numero de filas desde la ultima posicion
    }
} //Fin funcion......
