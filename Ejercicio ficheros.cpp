// programa que permite el ingreso  de varios numeros y genere un fichero que contenga

#include <iostream.h>
#include <conio.h>
#include <stdio.h>

struct numero{   // contiene la definicion del struc
  int nume;       // contener el numero ingresado
  int cdig;       // cantidad de digitos
}; // fin declaracion struc
//
void main()
  {  // de main

      int op;
      int n;  // cantidad de numeros a ingresar
      int leer_n();    // prototipo de la funcion que permite el ingreso de numeros
      void ingreso_numeros(int n1); //prototipo de la funcion que permite ingresar numeros al fichero
      void recupera_datos_fichero(); // prototipo de la funcion que recupera los datos desde el fichero creado
      void eliminar_datos(); //prototipo de la funcion que permite eliminar elementos de un fichero ingresado
      void modificar_fichero(); //prototipo de la funcion que permite modificar elementos de un fichero ingresado
      void ordenar_fichero(); //prototipo de la funcion que permite ordenar los elementos de un fichero ingresado



      do{
          do{
             cout<<"\n____________________________________________________________\n";
             cout<<"\n\n\t\t\tMENU DE OPCIONES\n";
             cout<<"____________________________________________________________\n";
             cout<<"1. Aniadir valores al fichero\n";
             cout<<"2. Eliminar valores del fichero\n";
             cout<<"3. Modificar valores del fichero\n";
             cout<<"4. Listar ordenadamente los valores del fichero\n";
             cout<<"5. Salir\n";
             cin>>op;
             clrscr();
          }while((op<1)||(op>5));
          switch(op){
              case 1:
                     n = leer_n();  // llamado a la lectura de la cantidad de valores a ingresar
                     ingreso_numeros(n);   // llamado a la funcion que lee los numeros
                     clrscr();
                     cout<<"\nLos valores ingresados al fichero son: \n";
                     cout<<"____________________________________________________________\n";
                     recupera_datos_fichero(); // llamado a la funcion que recupera los datos desde el fichero creado
                     break;
              case 2:
                     eliminar_datos(); //llamado a la funcion que permite eliminar elementos de un fichero ingresado
                     break;
              case 3:
                     modificar_fichero(); //llamado a la funcion que permite modificar elementos de un fichero ingresado
                     break;
              case 4:
                     ordenar_fichero(); //llamado a la funcion que permite ordenar los elementos de un fichero ingresado
                     break;
              case 5:
                     cout<<"Gracias por su uso....................";
                     break;
          }

      }while(op!=5);

      getch();

  }  // de main
//
int leer_n()
{  // de leer_n
      int aux;
    do {
       cout<<"\n\t\tIngrese la cantidad de valores a ingresar: ";
       cin >> aux;
       } while(aux < 1);

       return (aux);

}  // de leer_n
//
void ingreso_numeros(int n1)
{  //  ingreso_numeros
    int i;  // contador

    numero reg; //declaro la variable que contenga los capos del struct

    int contar_digitos(int nume);
    void grabar_fichero(numero x);  //prototipo de la funcion que graba el registro x en el fichero a crear

    for(i=1; (i <= n1); i++){   // ciclo de lectura
        cout <<"\n\tIngrese un numero: " ;
        cin >> reg.nume;  //lectura del numero en el campo de la struct

        reg.cdig = 0;       // inicializa el contador
        reg.cdig = contar_digitos(reg.nume); // digitos que contiene el numeros ingresado

        cout<<"\n\tEl numero "<<reg.nume <<" posee " << reg.cdig <<  " digitos " ;
     grabar_fichero(reg);  //llamado a la funcion que graba el struct en el fichero
    }    // de for
} // ingreso numeros +

//
void grabar_fichero(numero x)  //funcion que graba el struct x en el fichero a crear
	{ //de grabar_fichero
   	FILE *f; // declara el fichero que contendra los structs

      f = fopen("numeros.txt","ab");  //abrir el fichero binario para escritura

      fwrite(&x, sizeof(x), 1, f); //grabar el struct en el fichero f

      fclose(f);  //cerrar el ficher de numeros

   }  //de grabacion_fichero

//
void eliminar_datos(){ //funcion que permite eliminar elementos de un fichero ingresado
   FILE *f2;
   numero v[100]; //declaracion de un vector de tipo numero para separar los numeros que no se van a elimina
   numero x; //variable de tipo numero
   int nu; //numero a eliminar
   int i=1;
   void recupera_datos_fichero(); // llamado a la funcion que recupera los datos desde el fichero creado

   cout<<"\nIngrese el numero a eliminar: ";
   cin>>nu;
   f2 = fopen("numeros.txt", "rb");
   fread(&x, sizeof(x), 1, f2);  //lectura de un struct desde el fichero
   if(f2!=NULL){
         while(!feof(f2)){
            if(x.nume!=nu){
              v[i]=x;
              i++;
            }
            fread(&x, sizeof(x), 1, f2);  //lectura de un struct desde el fichero
         }
   fclose(f2);  //cerrar el ficher de numeros
   f2 = fopen("numeros.txt", "wb");
   for(int j=1;j<i;j++)
       fwrite(&v[j], sizeof(v[j]), 1, f2);  //lectura de un struct desde el fichero
   fclose(f2);
   recupera_datos_fichero(); // llamado a la funcion que recupera los datos desde el fichero creado

   }
   else{
       cout<<"\nEl fichero no contiene datos.......=(\n";
   }



}
//
void modificar_fichero(){ //funcion que permite modificar elementos de un fichero ingresado
   FILE *f3;
   numero v[100]; //declaracion de un vector de tipo numero para separar los numeros que no se van a elimina
   numero x; //variable de tipo numero
   int nu; //numero a eliminar
   numero aux;
   int i=1;
   int pos;
   int c;
   void recupera_datos_fichero(); // llamado a la funcion que recupera los datos desde el fichero creado
   int contar_digitos(int num);

   cout<<"\nIngrese un nuevo numero para modificar: ";
   cin>>nu;
   cout<<"\nIngrese la posicion en la que va ha suplantar: ";
   cin>>pos;
   aux.nume=nu;
   f3 = fopen("numeros.txt", "rb");
   fread(&x, sizeof(x), 1, f3);  //lectura de un struct desde el fichero
   if(f3!=NULL){
         while(!feof(f3)){
            v[i]=x;
            i++;
            fread(&x, sizeof(x), 1, f3);  //lectura de un struct desde el fichero
         }
   fclose(f3);  //cerrar el ficher de numeros
   f3 = fopen("numeros.txt", "wb");

   for(int j=1;j<i;j++)
       if(j==pos){
         aux.cdig=contar_digitos(nu);
         fwrite(&aux, sizeof(aux), 1, f3);  //lectura de un struct desde el fichero
         }
       else{
         fwrite(&v[j], sizeof(v[j]), 1, f3);  //lectura de un struct desde el fichero
         }
   fclose(f3);
   recupera_datos_fichero(); // llamado a la funcion que recupera los datos desde el fichero creado

   }
   else{
       cout<<"\nEl fichero no contiene datos.......=(\n";
   }

}
//
void ordenar_fichero(){ //funcion que permite ordenar los elementos de un fichero ingresado
   FILE *f4;
   numero v[100]; //declaracion de un vector de tipo numero para separar los numeros que no se van a elimina
   numero x; //variable de tipo numero
   int i=1;
   void recupera_datos_fichero(); // llamado a la funcion que recupera los datos desde el fichero creado
   void ordenar(numero v1[],int cant);  //prot de la funcion que ordena un vector de structs

   f4 = fopen("numeros.txt", "rb");
   fread(&x, sizeof(x), 1, f4);  //lectura de un struct desde el fichero
   if(f4!=NULL){
         while(!feof(f4)){
              v[i]=x;
              i++;
              fread(&x, sizeof(x), 1, f4);  //lectura de un struct desde el fichero
         }

   ordenar(v,i);  //llamado a la funcion que ordena un vector de structs

   fclose(f4);  //cerrar el ficher de numeros
   f4 = fopen("numeros.txt", "wb");
   for(int j=1;j<i;j++)
       fwrite(&v[j], sizeof(v[j]), 1, f4);  //lectura de un struct desde el fichero
   fclose(f4);
   recupera_datos_fichero(); // llamado a la funcion que recupera los datos desde el fichero creado

   }
   else{
       cout<<"\nEl fichero no contiene datos.......=(\n";
   }

}
//
void recupera_datos_fichero() // llamado a la funcion que recupera los datos desde el fichero creado
	{
    FILE *f1;
    numero y;
    f1= fopen("numeros.txt", "rb");

    fread(&y, sizeof(y), 1, f1);  //lectura de un struct desde el fichero

    while(!feof(f1)){
      cout<<"\n\tEl numero "<< y.nume <<" posee " << y.cdig <<  " digitos " ;
      fread(&y, sizeof(y), 1, f1);  //lectura de un struct desde el fichero
    }
    fclose(f1);  //cerrar el ficher de numeros
   }

//
int contar_digitos(int num)
{ //  de contador digitos
  int cont = 0;

  do {
    num /=10;
    cont++;
    }while (num !=0);

    return(cont);

}  // de contador digitos

//
void ordenar(numero v[],int cant)  //prot de la funcion que ordena un vector de structs
{
  int op;
  numero aux;
  int i,j;
  do{
    cout<<"1. Ascendente\n";
    cout<<"2. Descendente\n";
    cin>>op;
  }while((op<1)||(op>2));

  switch(op){
        case 1:
              for(i=1;i<cant-1;i++)
                 for(j=i+1;j<cant;j++)
                   if(v[i].nume>v[j].nume){
                       aux=v[i];
                       v[i]=v[j];
                       v[j]=aux;
                   }

              break;
        case 2:
              for(i=1;i<cant-1;i++)
                 for(j=i+1;j<cant;j++)
                   if(v[i].nume<v[j].nume){
                       aux=v[i];
                       v[i]=v[j];
                       v[j]=aux;
                   }
              break;
  }
}

