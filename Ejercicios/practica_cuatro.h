void ingreso_frase()  //funcion de ingreso frase
{ //de ingreso frase
   char g;  //variable que recibe el caracter ingresado

   char a,A;  //variables de almacenamiento para vocal (a - A)
   char e,E;  //variables de almacenamiento para vocal (e - E)
   char i,I;  //variables de almacenamiento para vocal (i - I)
   char o,O;  //variables de almacenamiento para vocal (o - O)
   char u,U;  //variables de almacenamiento para vocal (u - U)

   void comp_caracter_min(char *x1,char *x2,char *x3,char *x4,char *x5,char f1);   //prototipo de la funcion que verifica vocales minusculas
   void comp_caracter_may(char *y1,char *y2,char *y3,char *y4,char *y5,char f2);   //prototipo de la funcion que verifica vocales mayusculas
   void combinar(char a_min,char e_min,char i_min,char o_min,char u_min,char a_may,char e_may,char i_may,char o_may,char u_may);  //prototipo de la funcion que realiza las combinaciones necesarias

   a=e=i=o=u=A=E=I=O=U='.';  //asigna caracter punto para hacer las combinaciones siempre que la variable no contenga este caracter

   cout<<"\nIngrese una frase y finalice con punto: ";

   do{//ciclo de lectura mientras el caracter ingresado no sea un punto
     g=getche();
     if((g=='a')||(g=='e')||(g=='i')||(g=='o')||(g=='u')){
        comp_caracter_min(&a,&e,&i,&o,&u,g);//llamado a la funcion que verifica vocales minusculas
        }
     if((g=='A')||(g=='E')||(g=='I')||(g=='O')||(g=='U')){
        comp_caracter_may(&A,&E,&I,&O,&U,g);//llamado a la funcion que verifica vocales mayusculas
     }
     }while(g!='.');

     combinar(a,e,i,o,u,A,E,I,O,U); //llamado a la funcion que realiza las combinaciones necesarias
} //de ingreso frase
//
void comp_caracter_min(char *x1,char *x2,char *x3,char *x4,char *x5,char f1)
{
   if(f1=='a')  //guarda el caracter a en el espacio de memoria apuntado por x1
      *x1=f1;
   if(f1=='e')  //guarda el caracter e en el espacio de memoria apuntado por x2
      *x2=f1;
   if(f1=='i')  //guarda el caracter i en el espacio de memoria apuntado por x3
      *x3=f1;
   if(f1=='o')  //guarda el caracter o en el espacio de memoria apuntado por x4
      *x4=f1;
   if(f1=='u')  //guarda el caracter o en el espacio de memoria apuntado por x5
      *x5=f1;

}
//
void comp_caracter_may(char *y1,char *y2,char *y3,char *y4,char *y5,char f2)
{
   if(f2=='A')  //guarda el caracter A en el espacio de memoria apuntado por y1
      *y1=f2;
   if(f2=='E')  //guarda el caracter E en el espacio de memoria apuntado por y2
      *y2=f2;
   if(f2=='I')  //guarda el caracter I en el espacio de memoria apuntado por y3
      *y3=f2;
   if(f2=='O')  //guarda el caracter O en el espacio de memoria apuntado por y4
      *y4=f2;
   if(f2=='U')  //guarda el caracter U en el espacio de memoria apuntado por y5
      *y5=f2;
}
//
void combinar(char a_min,char e_min,char i_min,char o_min,char u_min,char a_may,char e_may,char i_may,char o_may,char u_may)
{
    int cont=0;
    cout<<"\n\n\t\t\tLAS VOCALES ENCONTRADAS SON\n\n";
    cout<<a_min<<" "<<e_min<<" "<<i_min<<" "<<o_min<<" "<<u_min<<" "<<a_may<<" "<<e_may<<" "<<i_may<<" "<<o_may<<" "<<u_may<<endl;

    /*
       En este espacio se procede a verificar que no exista solo una vocal encontrada
       ......si el contador es 1 o 0 entonces no es posible realizar combinaciones
       de lo contrario que se realice las combinaciones necesarias
       Para eso se asigno el caracter punto(.) a todas las variables en la funcion ingreso_frase
       porque en esta parte se pregunta si los caracteres son distintos de punto
       entonces se los ejecuta..
    */

    if(a_min!='.')
        cont++;
    if(e_min!='.')
        cont++;
    if(i_min!='.')
        cont++;
    if(o_min!='.')
        cont++;
    if(u_min!='.')
        cont++;
    if(a_may!='.')
        cont++;
    if(e_may!='.')
        cont++;
    if(i_may!='.')
        cont++;
    if(o_may!='.')
        cont++;
    if(u_may!='.')
        cont++;

    cout<<"\n\t\t\tCOMBINACIONES\n";
    cout<<"_____________________________________________________________________\n\n";
    if(cont<=1){
       cout<<"NO ES POSIBLE HACER COMBINACIONES";
       }
    else{
       if(a_min!='.'){
          if(e_min!='.')
            cout<<a_min<<e_min<<endl;
          if(i_min!='.')
            cout<<a_min<<i_min<<endl;
          if(o_min!='.')
            cout<<a_min<<o_min<<endl;
          if(u_min!='.')
            cout<<a_min<<u_min<<endl;
          if(a_may!='.')
            cout<<a_min<<a_may<<endl;
          if(e_may!='.')
            cout<<a_min<<e_may<<endl;
          if(i_may!='.')
            cout<<a_min<<i_may<<endl;
          if(o_may!='.')
            cout<<a_min<<o_may<<endl;
          if(u_may!='.')
            cout<<a_min<<u_may<<endl;
          cout<<"\n__________________\n";
       }

       if(e_min!='.'){
          if(a_min!='.')
            cout<<e_min<<a_min<<endl;
          if(i_min!='.')
            cout<<e_min<<i_min<<endl;
          if(o_min!='.')
            cout<<e_min<<o_min<<endl;
          if(u_min!='.')
            cout<<e_min<<u_min<<endl;
          if(a_may!='.')
            cout<<e_min<<a_may<<endl;
          if(e_may!='.')
            cout<<e_min<<e_may<<endl;
          if(i_may!='.')
            cout<<e_min<<i_may<<endl;
          if(o_may!='.')
            cout<<e_min<<o_may<<endl;
          if(u_may!='.')
            cout<<e_min<<u_may<<endl;
          cout<<"\n__________________\n";
       }
       if(i_min!='.'){
          if(a_min!='.')
            cout<<i_min<<a_min<<endl;
          if(e_min!='.')
            cout<<i_min<<e_min<<endl;
          if(o_min!='.')
            cout<<i_min<<o_min<<endl;
          if(u_min!='.')
            cout<<i_min<<u_min<<endl;
          if(a_may!='.')
            cout<<i_min<<a_may<<endl;
          if(e_may!='.')
            cout<<i_min<<e_may<<endl;
          if(i_may!='.')
            cout<<i_min<<i_may<<endl;
          if(o_may!='.')
            cout<<i_min<<o_may<<endl;
          if(u_may!='.')
            cout<<i_min<<u_may<<endl;
          cout<<"\n__________________\n";
       }
       if(o_min!='.'){
          if(a_min!='.')
            cout<<o_min<<a_min<<endl;
          if(e_min!='.')
            cout<<o_min<<e_min<<endl;
          if(i_min!='.')
            cout<<o_min<<i_min<<endl;
          if(u_min!='.')
            cout<<o_min<<u_min<<endl;
          if(a_may!='.')
            cout<<o_min<<a_may<<endl;
          if(e_may!='.')
            cout<<o_min<<e_may<<endl;
          if(i_may!='.')
            cout<<o_min<<i_may<<endl;
          if(o_may!='.')
            cout<<o_min<<o_may<<endl;
          if(u_may!='.')
            cout<<o_min<<u_may<<endl;
          cout<<"\n__________________\n";
       }
       if(u_min!='.'){
          if(a_min!='.')
            cout<<u_min<<a_min<<endl;
          if(e_min!='.')
            cout<<u_min<<e_min<<endl;
          if(i_min!='.')
            cout<<u_min<<i_min<<endl;
          if(o_min!='.')
            cout<<u_min<<o_min<<endl;
          if(a_may!='.')
            cout<<u_min<<a_may<<endl;
          if(e_may!='.')
            cout<<u_min<<e_may<<endl;
          if(i_may!='.')
            cout<<u_min<<i_may<<endl;
          if(o_may!='.')
            cout<<u_min<<o_may<<endl;
          if(u_may!='.')
            cout<<u_min<<u_may<<endl;
          cout<<"\n__________________\n";
       }

       if(a_may!='.'){
          if(a_min!='.')
            cout<<a_may<<a_min<<endl;
          if(e_min!='.')
            cout<<a_may<<e_min<<endl;
          if(i_min!='.')
            cout<<a_may<<i_min<<endl;
          if(o_min!='.')
            cout<<a_may<<o_min<<endl;
          if(u_min!='.')
            cout<<a_may<<u_min<<endl;
          if(e_may!='.')
            cout<<a_may<<e_may<<endl;
          if(i_may!='.')
            cout<<a_may<<i_may<<endl;
          if(o_may!='.')
            cout<<a_may<<o_may<<endl;
          if(u_may!='.')
            cout<<a_may<<u_may<<endl;
          cout<<"\n__________________\n";
       }

       if(e_may!='.'){
          if(a_min!='.')
            cout<<e_may<<a_min<<endl;
          if(e_min!='.')
            cout<<e_may<<e_min<<endl;
          if(i_min!='.')
            cout<<e_may<<i_min<<endl;
          if(o_min!='.')
            cout<<e_may<<o_min<<endl;
          if(u_min!='.')
            cout<<e_may<<u_min<<endl;
          if(a_may!='.')
            cout<<e_may<<a_may<<endl;
          if(i_may!='.')
            cout<<e_may<<i_may<<endl;
          if(o_may!='.')
            cout<<e_may<<o_may<<endl;
          if(u_may!='.')
            cout<<e_may<<u_may<<endl;
          cout<<"\n__________________\n";
       }
       if(i_may!='.'){
          if(a_min!='.')
            cout<<i_may<<a_min<<endl;
          if(e_min!='.')
            cout<<i_may<<e_min<<endl;
          if(i_min!='.')
            cout<<i_may<<i_min<<endl;
          if(o_min!='.')
            cout<<i_may<<o_min<<endl;
          if(u_min!='.')
            cout<<i_may<<u_min<<endl;
          if(a_may!='.')
            cout<<i_may<<a_may<<endl;
          if(e_may!='.')
            cout<<i_may<<e_may<<endl;
          if(o_may!='.')
            cout<<i_may<<o_may<<endl;
          if(u_may!='.')
            cout<<i_may<<u_may<<endl;
          cout<<"\n__________________\n";
       }
       if(o_may!='.'){
          if(a_min!='.')
            cout<<o_may<<a_min<<endl;
          if(e_min!='.')
            cout<<o_may<<e_min<<endl;
          if(i_min!='.')
            cout<<o_may<<i_min<<endl;
          if(o_min!='.')
            cout<<o_may<<o_min<<endl;
          if(u_min!='.')
            cout<<o_may<<u_min<<endl;
          if(a_may!='.')
            cout<<o_may<<a_may<<endl;
          if(e_may!='.')
            cout<<o_may<<e_may<<endl;
          if(i_may!='.')
            cout<<o_may<<i_may<<endl;
          if(u_may!='.')
            cout<<o_may<<u_may<<endl;
          cout<<"\n__________________\n";
       }
       if(u_may!='.'){
          if(a_min!='.')
            cout<<u_may<<a_min<<endl;
          if(e_min!='.')
            cout<<u_may<<e_min<<endl;
          if(i_min!='.')
            cout<<u_may<<i_min<<endl;
          if(o_min!='.')
            cout<<u_may<<o_min<<endl;
          if(u_min!='.')
            cout<<u_may<<u_min<<endl;
          if(a_may!='.')
            cout<<u_may<<a_may<<endl;
          if(e_may!='.')
            cout<<u_may<<e_may<<endl;
          if(i_may!='.')
            cout<<u_may<<i_may<<endl;
          if(o_may!='.')
            cout<<u_may<<o_may<<endl;
          cout<<"\n__________________\n";
       }

    }

}
