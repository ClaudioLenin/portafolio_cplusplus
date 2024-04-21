#include <iostream.h>
#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

class avion{  //Clase Avion
     public:
          char modelo[30]; //Modelo de cada avion
          char marca[30];  //Marca de cada avion
          int e;  //Estado de cada avion, "0" no esta disponible y, "1" si esta disponible
          int h;  //Horas de vuelo de cada avion
          int h1; //Horas de vuelo recomendadas por el fabricante de cada avion

          avion ();  //Constructor del objeto avion, inicializa los atributos declarados en la clase

          void leer_datos();   //Prototipo de la funcion que permite leer los datos del avion
          void mostrar_datos();  //Prototipo de la funcion que permite mostrar los datos del avion
          int est_avion(); //Prototipo de la funcion que permite determinar el estado del avion

          ~avion ();  //Destructor de el objeto avion

}; //Clase Avion

avion::avion(){  //Funcion que contruye un objeto
    cout<<"\nAvion creado..........";
    strcpy(modelo," ");
    strcpy(marca," ");
    e=0;
    h=0;
    h1=0;
}

void avion::leer_datos(){ //Funcion que permite leer los datos del avion
    cout<<"Modelo: ";
    gets(modelo);
    cout<<"Marca: ";
    gets(marca);
    do{
        cout<<"\nIngrese horas de vuelo del avion: ";
        cin>>h;
    }while(h<0);
    do{
        cout<<"\nIngrese horas recomendadas por el fabricante: ";
        cin>>h1;
    }while(h1<0);
}
void avion::mostrar_datos(){ //Funcion que permite mostrar los datos del avion
    cout<<"\n___________________________________________________________\n";
    cout<<"Modelo: ";
    puts(modelo);
    cout<<"Marca: ";
    puts(marca);
    cout<<"Horas de vuelo del avion: "<<h<<endl;
    cout<<"Horas recomendadas por el fabricante: "<<h1<<endl;
    cout<<"\n___________________________________________________________\n";
}
int avion::est_avion(){ //Funcion que permite determinar el estado del avion
    if(h<=h1)  //Si las horas de vuelo son menores a las horas recomendadas entonces esta disponible "1" sino no lo esta "0"
        e=1;
    else
        e=0;
    return(e);
}
avion::~avion(){
   cout<<"\nAvion Destruido........!";
}


class aeropuerto{
    public:
          char nombre[20];  //Nombre del aeropuerto
          avion vAs[50];   //Vector de aviones que posee el aeropuerto
          int n;   //Numero de aviones que posse el aeropuerto

          aeropuerto();//Constructor del objeto aeropuerto, inicializa los atributos declarados en la clase

          void leer_datos();  //Prototipo de la funcion que permite leer los datos del aeropuerto
          void ingresar_aviones();  //Prototipo de la funcion que permite leer los aviones que posee el aeropuerto
          void mostrar_aviones_disponibles(); //Prototipo de la funcion que permite mostrar los datos de los aviones disponibles en el aeropuerto
          void mostrar_aviones_no_disponibles(); //Prototipo de la funcion que permite mostrar los datos de los aviones no disponibles en el aeropuerto
          void mostrar_todos_los_aviones();  //Prototipo de la funcion que permite mostrar los datos de todos los aviones del aeropuerto

          ~aeropuerto(); //Destructor del objeto aeropuerto
};

aeropuerto::aeropuerto(){
    cout<<"\nAeropuerto Construido.......";
    strcpy(nombre," ");
    n=0;
}
void aeropuerto::leer_datos(){
    cout<<"\nIngrese nombre del aeropuerto: ";
    gets(nombre);
}
void aeropuerto::ingresar_aviones(){
    do{
        cout<<"Ingrese cantidad de aviones: ";
        cin>>n;
    }while(n<0);
    for(int i=1;i<=n;i++){
        cout<<"\nAVION "<<i<<endl;
        vAs[i].leer_datos();
    }
}

void aeropuerto::mostrar_aviones_disponibles(){
    for(int i=1;i<=n;i++)
         if(vAs[i].est_avion()==1)
             vAs[i].mostrar_datos();
}

void aeropuerto::mostrar_aviones_no_disponibles(){
    for(int i=1;i<=n;i++)
         if(vAs[i].est_avion()==0)
             vAs[i].mostrar_datos();
}

void aeropuerto::mostrar_todos_los_aviones(){
    for(int i=1;i<=n;i++)
         if(vAs[i].est_avion()==1){
             vAs[i].mostrar_datos();
             cout<<"\nDISPONIBLE\n";
             }
         else{
             vAs[i].mostrar_datos();
             cout<<"\nNO DISPONIBLE\n";
         }

}
aeropuerto::~aeropuerto(){
    cout<<"\nAeropuerto Destruido.......";
}
void main(){

aeropuerto a;

system("pause");
clrscr();
int op;
a.leer_datos();
a.ingresar_aviones();
clrscr();
do{
   cout<<"\n\t\tMENU DE OPCIONES\n";
   cout<<"1.- Mostrar aviones disponibles\n";
   cout<<"2.- Mostrar aviones no disponibles\n";
   cout<<"3.- Mostrar todos los aviones\n";
   cout<<"4.- Volver a ingresar Datos\n";
   cout<<"5.- Salir\n";
   cin>>op;
   switch(op){
              case 1:
                     a.mostrar_aviones_disponibles();
                     break;
              case 2:
                     a.mostrar_aviones_no_disponibles();
                     break;
              case 3:
                     a.mostrar_todos_los_aviones();
                     break;
              case 4:
                     a.leer_datos();
                     a.ingresar_aviones();
                     break;

   }
   system("pause");
   clrscr();
}while(op!=5);
a.~aeropuerto();
getch();
}

