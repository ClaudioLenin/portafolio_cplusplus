/*
  Ejercicio # 7
  Calcular el numero de vocales que tiene cada palabra de una frase ingresada
*/
#include "iostream"
#include <conio.h>
using namespace std;
int main(){
   int n; //cantidad de palabras
   int i; //contador de ciclo
   char f; //frase
   void cantidad_de_frases(int *p); //prototipo de la funcion que determina la cantidad de frases
   void ing_frase(char *g);//prototipo de la funcion que permite el ingreso de la frases
   cantidad_de_frases(&n); //llamado a la funcion que determina la cantidad de frases


   cout<<"\t\tCONTAR NUMERO DE VOCALES\n";
   for(i = 1;i <= n;i ++){
        cout<<"\nFRASE "<<i;
        cout<<"\n_____________________\n";
        ing_frase(&f);//llamado a la funcion que permite el ingreso de la frases
   }
   getch();
   return 0;
}
//
void cantidad_de_frases(int *p) //prototipo de la funcion que determina la cantidad de frases
{
  do{
     cout<<"\nIngrese cantidad de frases: ";
     cin>>*p;
     }while(*p<1);
}
//
void ing_frase(char *g)//prototipo de la funcion que permite el ingreso de la frases
{
   int c=0; //contador de vocales
   int cont_vocales(int cont,char *a); //prototipo de la funcion que cuenta las vocales de la frase
   cout<<"(Ingrese la frase y finalice con punto)\n";
   do{
      *g=getche();
      c=cont_vocales(c,g); //prototipo de la funcion que cuenta las vocales de la frase
   }while(*g!='.');
   cout<<"\nLa frase tiene "<<c<<" Vocales\n";
}
//
int cont_vocales(int cont,char *a) //prototipo de la funcion que cuenta las vocales de la frase
{
   if((*a=='a')||(*a=='A')||(*a=='e')||(*a=='E')||(*a=='i')||(*a=='I')||(*a=='o')||(*a=='O')||(*a=='u')||(*a=='U'))
          cont++;
   return(cont);
}
