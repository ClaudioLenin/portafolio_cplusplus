/*
  Ejercicio # 6
  Admitir los valores totales de compras de varios clientes de un local comercial,
  y el pago efectuado por cada uno. El programa debe calcular el cambio a entregar
  a cada persona, en monedas de 50, 25, 10, 5, 1 centavos, y billetes de 1, 5, 10,20
  dolares
*/
#include <iostream.h>
#include <conio.h>
#include <math.h>
#include <iomanip.h>
void main()
{ //de main
   int n;  //variable que recibe la cantidad de numeros
   int nn; //variable que recibe el numero ingresado
   int i; //contador de ciclo
   float p_t;  //pago total
   float p_c;  //pago de cliente
   float cam;  //cambio a cliente
   void c_num(int *c);  //prototipo de la funcion que recibe la cantidad de clientes
   void pagos(float *p1,float *p2);  //prototipo de la funcion que recibe el pago total y de clientes
   void cambios(float pr1,float pr2); //prototipo de la funcion que envia cambios

   cout<<"\t\tCAMBIO DE COMPRAS REALIZADAS\n";
   c_num(&n);  //llamado a la funcion que recibe la cantidad de clientes
   for(i=1;i<=n;i++){
       cout<<"\nCLIENTE "<<i;
       cout<<"\n____________________\n";
       pagos(&p_t,&p_c);  //llamado a la funcion que recibe el pago total y de clientes
       cambios(p_t,p_c); //llamado a la funcion que envia cambios
   }



   getch();
} //de main
//
void c_num(int *c)  //funcion que recibe la cantidad de numeros
{  //de cantidad de numeros
   do{
       cout<<"\nIngrese cantidad de clientes: ";
       cin>>*c;
   }while(*c<1);
}  //de cantidad de numeros

//
void pagos(float *p1,float *p2)  //prototipo de la funcion que recibe el pago total y de clientes
{
   do{
      cout<<"\nIngrese total a pagar en la tienda: ";
      cin>>*p1;
   }while(*p1<0);
   do{
      cout<<"\nIngrese su paga: ";
      cin>>*p2;
   }while((*p2<0)||(*p2<*p1));

}
//
void cambios(float pr1,float pr2) //funcion que envia cambios
{
   float b;
   b = pr2-pr1;
   cout<<"\nSu cambio es: "<<b<<endl<<endl;
   int vd,dd,cd,ud,cc,vcc,dc,c_c,uc;
   void imprimir_cambio(int c1,int c2,int c3,int c4,int c5,int c6,int c7,int c8,int c9); //prototipo de la funcion que imprime la respuesta

   vd=dd=cd=ud=cc=vcc=dc=c_c=uc=0;
   do{
      if(b>=20){
         b-=20;
         vd++;
         }
      if((b>=10)&&(b<20)){
         b-=10;
         dd++;
         }
      if((b>=5)&&(b<10)){
         b-=5;
         cd++;
         }
      if((b>=1)&&(b<5)){
         b-=1;
         ud++;
         }
      if((b>=0.50)&&(b<1)){
         b-=0.50;
         cc++;
         }
      if((b>=0.25)&&(b<0.50)){
         b-=0.25;
         vcc++;
         }
      if((b>=0.10)&&(b<0.25)){
         b-=0.10;
         dc++;
         }
      if((b>=0.05)&&(b<0.10)){
         b-=0.05;
         c_c++;
         }
      if((b>=0.01)&&(b<0.05)){
         b-=0.01;
         uc++;
         }
   }while(int(b)!=0);
   imprimir_cambio(vd,dd,cd,ud,cc,vcc,dc,c_c,uc); //llamado a la funcion que imprime la respuesta
}
//
void imprimir_cambio(int c1,int c2,int c3,int c4,int c5,int c6,int c7,int c8,int c9) //funcion que imprime la respuesta
{
  if(c1!=0)
     cout<<c1<<" BILLETE(S) DE 20 $ "<<endl;
  if(c2!=0)
     cout<<c2<<" BILLETE(S) DE 10 $ "<<endl;
  if(c3!=0)
     cout<<c3<<" BILLETE(S) DE 5 $ "<<endl;
  if(c4!=0)
     cout<<c4<<" BILLETE(S) DE 1 $ "<<endl;
  if(c5!=0)
     cout<<c5<<" MONEDA(S) DE 0.50 C "<<endl;
  if(c6!=0)
     cout<<c6<<" MONEDA(S) DE 0.25 C "<<endl;
  if(c7!=0)
     cout<<c7<<" MONEDA(S) DE 0.10 C "<<endl;
  if(c8!=0)
     cout<<c8<<" MONEDA(S) DE 0.05 C "<<endl;
  if(c9!=0)
     cout<<c9<<" MONEDA(S) DE 0.01 C "<<endl;

}
