//SUMA RECURSIVA
#include <iostream.h>
#include <conio.h>
double suma(double n1, double n2)
{
    int r;
    if(n2==0)
        return(n1);
    else
        if(n1==0)
            return(n2);
        else
            return 1+suma(n1,n2-1);
}
void main()
{
     double suma(double n1, double n2);
     double x,y;
     cout << "\nPrimer numero\n";
     cin >> x;
     cout << "\nSegundo numero\n";
     cin >> y;
     cout << "suma: " << suma(x,y) <<"\n";
     getch();
}

