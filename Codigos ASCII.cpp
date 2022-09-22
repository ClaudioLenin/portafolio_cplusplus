//Tipos char==>8 bits==>numericos==>codigo ascii
//Programa que genere la tabla ascii
#include <iostream.h>
#include <conio.h>
void main ()
  { //de main
     int cod;  //Generara los codigos ascii

         for (cod=0;(cod <= 255);cod ++)   //ciclo q genera codigos ASCII q genera cd caracter
             cout<<cod<<": "<<char(cod)<<"\t";
  getch ();
}



