/*
  Ejercicio # 10
  Determinar la posicion que ocupan las letras minusculas dentro de las palabras
  de una frase ingresada
*/
#include "iostream"
#include <conio.h>
#include <windows.h>
using namespace std;
void gotoxy(int x, int y) {
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
int main()
{
   	char f; //variable de ingreso caracter
   	void leer_nombre(char *x); //prototipo de la funcion que permite el ingreso de una frase

   	cout<<"\t\tPOSICIONES DE LETRAS MINUSCULAS\n";
	cout<<"\nFRASE ";
    cout<<"\n____________________\n";
    leer_nombre(&f); //llamado a la funcion que permite el ingreso de una frase
	getch();
	return 0;
} 
void leer_nombre(char *x)
{
  cout<<"\n(Ingrese la frase y finalice con punto)\n";
  char aux;
  int n_n;
  int c=0,c1=7,c2=10;
  int c_c=0;
  int acum=0;
  do{
     c++;
     c_c++;
     gotoxy(c,c1);
     *x=getche();
     if(c==80){
        c=0;
        c1++;
        }
     if((*x>='a')&&(*x<='z')){
         gotoxy(c,c1+1);
         cout<<c_c;
     }
     else{
         c_c=0;
     }
  }while(*x!='.');
}
