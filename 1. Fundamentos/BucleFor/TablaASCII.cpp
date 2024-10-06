#include "iostream"
#include <conio.h>

using namespace std;

int main ()
{ 
    for (int cod=0;(cod <= 255);cod ++)
        cout<<cod<<": "<<char(cod)<<"\t";
	
	getch ();
	return 0;
}
