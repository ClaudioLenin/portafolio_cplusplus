// programa que permita disimular el funcionamiento de un reloj con alarma mediante el capteo d bibliotecas

#include <iostream>
#include <conio.h>


main()
{  // inicio main
    int h, m, s;

    cout<<"\t\t\t\tprograma reloj " ;

    for(h=0;h<24;h++)
    {
       for(m=0;m<60;m++)
       {
           for(s=0;s<60;s++)
           {
               for(int ms=0; ms<6900;ms++){
               gotoxy ( 35, 7 );
               cout<< h <<" : " << m << " : " << s << endl;
           }  }
       }
    }

    getch();

}  // fin main