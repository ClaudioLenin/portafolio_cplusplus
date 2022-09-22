/*
  Ejercicio # 3
  Calcular la sumatoria de los N últimos dígitos de cada número ingresado
*/
#include <iostream.h>
#include <conio.h>
#include <math.h>
void main()
{ //de main
   int n;  //variable que recibe la cantidad de numeros
   int nn; //variable que recibe el numero ingresado
   int i; //contador de ciclo
   int cont; //contador de digitos
   void c_num(int *c);  //prototipo de la funcion que recibe la cantidad de numeros
   void num_n(int *num);  //prototipo de la funcion que recibe los N numeros
   void cont_elem(int *h,int cc); //prototipo de la funcion que cuenta los digitos de un numero
   void sum_n_dig(int n_a,int c_el); //prototipo de la funcion que calcula la suma de los N-esimos digitos

   cout<<"\tENCONTRAR EL DIGITO MENOR Y SUMAR POSICIONES DE DIGITOS PARES\n";
   c_num(&n);  //llamado a la funcion que recibe la cantidad de numeros
   for(i=1;i<=n;i++){
       cout<<"\nNUM "<<i;
       cout<<"\n____________________\n";
       num_n(&nn);  //llamado a la funcion que recibe los N numeros
       cont_elem(&cont,nn); //llamado a la funcion que cuenta los digitos de un numero
       sum_n_dig(nn,cont); //llamado a la funcion que calcula la suma de los N-esimos digitos
   }



   getch();
} //de main
//
void c_num(int *c)  //funcion que recibe la cantidad de numeros
{  //de cantidad de numeros
   do{
       cout<<"\nIngrese cantidad de numeros: ";
       cin>>*c;
   }while(*c<1);
   *c=abs(*c);
}  //de cantidad de numeros

//
void num_n(int *num)  //funcion que recibe los N numeros
{  //de ingreso de N numeros

   cin>>*num;

}  //de ingreso de N numeros
//
void sum_n_dig(int n_a,int c_el) //funcion que calcula la suma de los N-esimos digitos
{
  cout<<"El numero contiene "<<c_el<<" digitos";
  int pos;
  int sum=0;
  int f=0;
  int aux;
  do{
     cout<<"\nIngrese una posicion del numero: ";
     cin>>pos;
  }while((pos<1)||(pos>c_el));
  do{
    aux=n_a;
    aux%=10;
    if(c_el>=pos){
        sum=sum+aux;
        f++;
        }
    n_a/=10;
    c_el--;
  }while(n_a!=0);
  cout<<"\nLa suma de los "<<f<<" ultimos digitos es: "<<sum;
}
//
void cont_elem(int *h,int cc) //funcion que cuenta los digitos de un numero
{
   int c=0;
   do{
     c++;
     cc/=10;
   }while(cc!=0);
   *h=c;
}
