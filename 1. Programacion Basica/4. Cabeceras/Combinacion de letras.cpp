/*
   Elabore un programa modular que permita el ingreso de una frase, y forme
   todas las combinaciones posibles con las vocales alli existentes (por parejas)
   ejemplo 1:
        ESTE DIA PRACTICAMOS
   VOCALES ENCONTRADAS
        E
        I
        A
        O
   COMBINACIONES
     EI    IA
     IE    AI
     EA    IO
     AE    OI
     EO    AO
     OE    OA
   ejemplo 2:
       AA
   VOCALES ENCONTRADAS
        A
   COMBINACIONES
   NO ES POSIBLE

*/
#include "iostream"
#include <conio.h>
#include "header2.h"
using namespace std;
int main (){

    cout<<"\t\t\tCOMBINACIONES DE VOCALES\n";
    ingreso_frase();
    cout<<"\n\t\t\tPOR: Claudio Pilataxi";
    cout<<"\n\t\t\tCODIGO: 6042";
    getch();
    return 0;
}
//

