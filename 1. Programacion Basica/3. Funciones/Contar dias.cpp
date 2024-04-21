/*
  Elaborar un programa modular que permita ingresar varias fechas, y determinar
  la cantidad exacta de dìas existentes entre la fecha más antigua y la más reciente
*/
#include "iostream"
#include <conio.h>
using namespace std;
int main ()
{//de main
  int dia;   //dia de la fecha ingresada
  int mes;   //mes de la fecha ingresada
  int anio;  //año de la fecha ingresada
  int n;     //det. la cantidad de fechas a ingresar
  int i;     //contar las fechas ingresadas


  int dia_ant;
  int mes_ant;
  int anio_ant;


  int leer_n();  //prototipo de la funcion que ingresa la cantidad de fechas
  void ingreso_fecha(int *d,int *m,int *a);  //prototipo de la funcion que ingresa y devuelve dia mes y año de la fecha
  void imprimir_fecha(int d1,int m1,int a1);  //prototipo de la funcion que imprime dia mes y año de la fecha ingresada
  void comparar_fecha(int *dx,int *mx,int *ax,int dy,int my,int ay,int c);  //prototipo de la funcion que compara dos fechas y devuelve la fecha menor


       n = leer_n();   //llamado a la funcion que ingresa la cantidad de fechas

   for(i=1;i<=n;i++){
       cout<<"\t\tVALIDAR FECHA "<<i<<"\n";
       ingreso_fecha(&dia,&mes,&anio);  //llamado a la funcion que ingresa y devuelve dia mes y año de la fecha
       comparar_fecha(&dia_ant,&mes_ant,&anio_ant,dia,mes,anio,i);    //llamado a la funcion que compara dos fechas y devuelve la fecha menor
       imprimir_fecha(dia,mes,anio); //llamado a la funcion que imprime dia mes y año de la fecha ingresada

       }

   cout<<"\nLa fecha mas antigua es: ";
   imprimir_fecha(dia_ant,mes_ant,anio_ant); //llamado a la funcion que imprime dia mes y año de la fecha antigua

  getch();
  return 0;
}//de main
//
int leer_n()  //funcion que ingresa la cantidad de fechas
 {
    int c;
    do{
        cout<<"\nIngrese cantidad de fechas a procesar: ";
        cin>>c;
    }while(c<1);
    return(c);
 }
//
void ingreso_fecha(int *d,int *m,int *a)  //funcion que ingresa y devuelve dia mes y año de la fecha
{ //de ingreso fecha
  bool validar(int d2,int m2,int a2); //prototipo de la funcion que valida los valores correspondientes a una fecha ingresada
  do{
        cout<<"\nIngrese dia: ";
        cin>>*d;
        cout<<"\nIngrese mes: ";
        cin>>*m;
        cout<<"\nIngrese a"<<char(164)<<"o: ";
        cin>>*a;
     }while(!validar(*d,*m,*a));//llamado a la funcion que valida los valores correspondientes a una fecha ingresada
} //de ingreso fecha
//
void imprimir_fecha(int d1,int m1,int a1)  //funcion que imprime dia mes y año de la fecha ingresada
{
cout<<"\t\t\t    FECHA VALIDA\n";
cout<<"\n***********************************************************************";
cout<<"\n*************************| "<<d1<<" - "<<m1<<" - "<<a1<<" |*****************************";
cout<<"\n***********************************************************************";


}
//
bool validar(int d2,int m2,int a2) //funcion que valida los valores correspondientes a una fecha ingresada
{
    if (a2 < 1)
      return false;

    if ((m2 < 1) || (m2 > 12))
      return false;

    if (d2 < 1)
      return false;

    if (m2 == 2)  //febrero
       if (((a2 % 4 == 0) && (a2 % 100 != 0))  || (a2 % 400 == 0)){  //a?o bisiesto
          if (d2 > 29)
             return false;
          }
       else //a?o no bisiesto
          if (d2 > 28)
             return false;

    if ((m2 ==4) || (m2 == 6)|| (m2 == 9)|| (m2 == 11))   //MESES DE 30 DIAS
        if (d2 > 30)
          return false;

    if ((m2 ==1) || (m2 == 3)|| (m2 == 5)|| (m2 == 7)|| (m2 == 8)|| (m2 == 10)|| (m2 == 12))   //MESES DE 31 DIAS
        if (d2 > 31)
          return false;

    return true;
}
//
void comparar_fecha(int *dx,int *mx,int *ax,int dy,int my,int ay,int c)  //prototipo de la funcion que compara dos fechas y devuelve la fecha menor
{ //de comparar fechas

  if(ay<*ax){
        *dx=dy;
        *mx=my;
        *ax=ay;
  }
   else{
     if(ay==*ax)
       if(my<*mx){
          *dx=dy;
          *mx=my;
          *ax=ay;
       }
       else{
          if((ay==*ax)&&(my==*mx))
           if(dy<*dx){
               *dx=dy;
               *mx=my;
               *ax=ay;
           }
       }

   }
} //de comparar fechas
