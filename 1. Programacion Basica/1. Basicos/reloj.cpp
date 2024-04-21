// programa que permita disimular el funcionamiento de un reloj con alarma mediante el capteo d bibliotecas

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
    int h, m, s;

    cout<<"\t\t\t\tprograma reloj " ;

    for(h=0;h<24;h++)
    {
       for(m=0;m<60;m++)
       {
           for(s=0;s<60;s++)
           {
               for(int ms=0; ms<6900;ms++){
               		gotoxy ( 10, 7 );
               		cout<< h <<" : " << m << " : " << s << endl;
           		}  
		   }
       }
    }
    
    getch();
    return 0;
} 
