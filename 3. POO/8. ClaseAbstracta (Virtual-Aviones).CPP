#include <iostream.h>
#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
class cAvion
{
   char marca[10];
   char modelo[10];
   char codigo[10];
   int hv;  //horas de vuelo
   int hf;  //horas recomendadas por el fabricante

   public:

   cAvion();
   void setHV(int newhv);
   int getHV();
   int getHF();
   char *getCodigo();

   virtual int getTipo();

   virtual void leer();
   virtual void mostrar();
   ~cAvion();

};
cAvion::cAvion()
{
    strcpy(marca,"");
    strcpy(modelo,"");
    strcpy(codigo,"");
    hv=hf=0;
}
char *cAvion::getCodigo()
{
    return(codigo);
}
void cAvion::setHV(int newhv)
{
    hv=newhv;
}
int cAvion::getHV()
{
    return(hv);
}
int cAvion::getHF()
{
    return(hf);
}
int cAvion::getTipo()
{
    return(-1);
}
void cAvion::leer()
{
    cout<<"\nIngrese marca: ";gets(marca);
    cout<<"\nIngrese modelo: ";gets(modelo);
    cout<<"\nIngrese codigo: ";gets(codigo);
    do{
       cout<<"\nIngrese horas recomendadas por fabricante: ";cin>>hf;
       cout<<"\nIngrese horas de vuelo: ";cin>>hv;
       }while((hf<0)||(hv<0));
}
void cAvion::mostrar()
{
    cout<<"\nMarca: ";puts(marca);
    cout<<"\nModelo: ";puts(modelo);
    cout<<"\nCodigo: ";puts(codigo);
    cout<<"\nHoras recomendadas por fabricante: "<<hf;
    cout<<"\nHras de vuelo: "<<hv;
}
cAvion::~cAvion()
{
}
class cPasajero : public cAvion
{
    int nvip;
    int ntur;

    public:

    cPasajero();
    int getTipo();
    void leer();
    void mostrar();
    ~cPasajero();
};
cPasajero::cPasajero() : cAvion()
{
    nvip=ntur=0;
}
int cPasajero::getTipo()
{
   return(1);
}
void cPasajero::leer()
{
   cAvion::leer();
   cout<<"\nIngrese numero de pasajeros vip: ";cin>>nvip;
   cout<<"\nIngrese numero de pasajeros turistas: ";cin>>ntur;

}
void cPasajero::mostrar()
{
    cAvion::mostrar();
    cout<<"\nNumero de pasajeros vip: "<<nvip;
    cout<<"\nNumero de pasajeros turistas: "<<ntur;
}
cPasajero::~cPasajero()
{
}
class cCarga : public cAvion
{
    int cc;  //capacidad de carga

    public:

    cCarga();
    int getTipo();
    void leer();
    void mostrar();
    ~cCarga();

};
cCarga::cCarga():cAvion()
{
    cc=0;
}
int cCarga::getTipo()
{
    return(2);
}
void cCarga::leer()
{
    cAvion::leer();
    cout<<"\nIngrese capacidad de carga: ";cin>>cc;
}
void cCarga::mostrar()
{
    cAvion::mostrar();
    cout<<"\nCapacidad de carga: "<<cc;
}
cCarga::~cCarga()
{
}
class cAeropuerto
{
     char nombre[10];
     char direccion[10];
     cAvion *vAd[20];
     cAvion *vAm[20];
     int nd;  //numero de aviones disponibles
     int nm;  //numero de aviones en mantenimiento

     public:

     cAeropuerto();
     void leer();
     void mostrar();
     void leerAviones();
     int menu();
     void disponibles_a_mantenimento();
     void mantenimiento_a_disponibles();
     void eliminar_avion_disponible();
     void recorrerVectorM(int pos);
     void recorrerVectorD(int pos);
     void mostrar_disponibles();
     void mostrar_mantenimiento();
     int BuscarD(char *c);
     int BuscarM(char *c);
     ~cAeropuerto();
};
cAeropuerto::cAeropuerto()
{
     strcpy(nombre,"");
     strcpy(direccion,"");
     nd=nm=0;
}
void cAeropuerto::leer()
{
     cout<<"\nIngrese nombre del Aeropuerto: ";gets(nombre);
     cout<<"\nIngrese direccion del Aeropuerto: ";gets(direccion);
     leerAviones();
}
void cAeropuerto::leerAviones()
{
     do{
        cout<<"\nIngrese numero de aviones que tiene el aeropuerto: ";cin>>nd;
     }while((nd<1)||(nd>20));
     for(int i=1;i<=nd;i++)
     {
         int op;
         cout<<"\n\t\t\tAVION "<<i<<endl;
         cout<<"____________________________________\n";
         op=menu();
         if(op==2)
         {
            vAd[i] = new cCarga;
            vAd[i] -> leer();
         }
         else{
            vAd[i] = new cPasajero;
            vAd[i] -> leer();
         }
     }

}
int cAeropuerto::menu()
{
    int op;
    do{
       cout<<"\n1. Ingresar avion de pasajeros";
       cout<<"\n2. Ingresar avion de carga";
       cout<<"\n\t\tIngrese opcion: ";cin>>op;
       }while((op<1)||(op>2));
    return(op);
}
//______________________________________________________________________________
//Colocar a los aviones de disponibles a mantenimiento
//______________________________________________________________________________
void cAeropuerto::disponibles_a_mantenimento()
{
    for(int i=1;i<=nd;i++)
         if(vAd[i]->getHV()>=vAd[i]->getHF())
         {
              nm++;
              vAm[nm] = vAd[i];
              recorrerVectorD(i);
              //vAd[i] = vAd[nd--];
              i--;
             /* if(vAd[i]->getTipo()==2)
              {
                 vAm[nm] = new cCarga;
                 vAm[nm] = vAd[i];
                 vAd[i] = vAd[nd--];
              }
              else
              {
                 vAm[nm] = new cPasajero;
                 vAm[nm] = vAd[i];
                 vAd[i] = vAd[nd--];
              }*/
         }
}
//______________________________________________________________________________
////Colocar a los aviones de mantenimiento a disponibles
//______________________________________________________________________________
void cAeropuerto::mantenimiento_a_disponibles()
{
    char c[10];
    int pos;
    cout<<"\nIngrese codigo del avion para dar disponibilidad: ";gets(c);
    pos=BuscarM(c);
    if(pos!=-1)
    {
          vAm[pos]->setHV(0);
          nd++;
          vAd[nd]=vAm[pos];
          recorrerVectorM(pos);
    }
    else
    {
        cout<<"\nNo se encontro el avion........";
    }
}
void cAeropuerto::recorrerVectorM(int pos)
{
    for(int i=1;i<=nm;i++)
        if(pos==i)
        {
           vAm[i]=vAm[i+1];
           pos++;
        }
    nm--;
}
int cAeropuerto::BuscarM(char *c)
{
    int i=1;
    int p=-1;
    while((i<=nm)&&(p==-1))
    {
        if(strcmp(vAm[i]->getCodigo(),c)==0)
            p=i;
        i++;
    }
    return(p);
}
//______________________________________________________________________________
//Eliminar un avion
//______________________________________________________________________________
void cAeropuerto::eliminar_avion_disponible()
{
     char c[10];
     int pos;
     cout<<"\nIngrese codigo del avion a eliminar: ";gets(c);
     pos=BuscarD(c);
     if(pos!=-1)
     {
         delete vAd[pos];
         recorrerVectorD(pos);
     }
     else
     {
         cout<<"\nNo se encontro el avion........";
     }
}
void cAeropuerto::recorrerVectorD(int pos)
{
     for(int i=1;i<=nd;i++)
         if(pos==i)
         {
            vAd[i]=vAd[i+1];
            pos++;
         }
     nd--;
}
int cAeropuerto::BuscarD(char *c)
{
     int i=1;
     int p=-1;
     while((i<=nd)&&(p==-1))
     {
         if(strcmp(vAd[i]->getCodigo(),c)==0)
              p=i;
         i++;
     }
     return(p);
}
//______________________________________________________________________________
//______________________________________________________________________________
//______________________________________________________________________________

void cAeropuerto::mostrar_disponibles()
{
    for(int i=1;i<=nd; i++)
    {
       cout<<"\n___________________________________";
       cout<<"\nAVION DISPONIBLE";
       if(vAd[i]->getTipo()==1)
       {
           cout<<"\n\t\tAvion de pasajeros\n";
           vAd[i]->mostrar();
       }
       else
       {
           cout<<"\n\t\tAvion de carga\n";
           vAd[i]->mostrar();
       }
    }
}
void cAeropuerto::mostrar_mantenimiento()
{
    for(int i=1;i<=nm; i++)
    {
       cout<<"\n___________________________________";
       cout<<"\nAVION A MANTENIMIENTO";
       if(vAm[i]->getTipo()==1)
       {
           cout<<"\n\t\tAvion de pasajeros\n";
           vAm[i]->mostrar();
       }
       else
       {
           cout<<"\n\t\tAvion de carga\n";
           vAm[i]->mostrar();
       }
    }
}
cAeropuerto::~cAeropuerto()
{
     for(int i=1;i<=nd;i++)
         delete(vAd[i]);
     for(int i=1;i<=nm;i++)
         delete(vAm[i]);
}
void main()
{
    int op;
    cAeropuerto *obj;
    obj = new cAeropuerto;
    obj -> leer();
 clrscr();
 clrscr();
 do{
    do{
         cout<<"\n1. Pasar aviones de disponibles a mantenimiento";
         cout<<"\n2. Pasar un avion de mantenimiento a disponible";
         cout<<"\n3. Eliminar un avion disponible";
         cout<<"\n4. Mostrar aviones disponibles";
         cout<<"\n5. Mostrar aviones en mantenimiento";
         cout<<"\n6. Salir";
         cin>>op;
    }while((op<1)||(op>6));
         switch(op){
               case 1:
                     obj -> disponibles_a_mantenimento();
                     break;
               case 2:
                     obj -> mantenimiento_a_disponibles();
                     break;
               case 3:
                     obj -> eliminar_avion_disponible();
                     break;
               case 4:
                     obj -> mostrar_disponibles();
                     break;
               case 5:
                     obj -> mostrar_mantenimiento();
                     break;
         };

    }while(op!=6);
    getch();
}
