#include <iostream.h>
#include <conio.h>
#include <stdio.h>
#include <string.h>
class electro{
      int cd;
      char mr[10];

      public:

      electro();
      int getCodigo();
      char *getMarca();

      virtual int getTipo();
      virtual void leer();
      virtual void mostrar();

};

electro::electro()
{
     cd=0;
     strcpy(mr,"");
}
int electro::getCodigo()
{
     return(cd);
}
char *electro::getMarca()
{
     return(mr);
}
int electro::getTipo()
{
     return(-1);
}
void electro::leer()
{
     cout<<"\nIngrese codigo: ";
     cin>>cd;
     cout<<"\nIngrese marca: ";gets(mr);
}
void electro::mostrar()
{
     cout<<"\nCodigo: "<<cd;
     cout<<"\nMarca: ";puts(mr);
}
class lavadora:public electro{
     int np;
     int compart;
     public:

     lavadora();
     int getTipo();
     int getCompartimentos();
     void setCompartimentos(int newCom);
     void leer();
     void mostrar();
};
lavadora::lavadora():electro()
{
    np=compart=0;
}
int lavadora::getTipo()
{
    return(1);
}
int lavadora::getCompartimentos()
{
    return(compart);
}
void lavadora::setCompartimentos(int newCom)
{
    compart=newCom;
}
void lavadora::leer()
{
    electro::leer();
    cout<<"\nIngrese numero de puertas: ";cin>>np;
    cout<<"\nIngrese numero de compartimentos: ";cin>>compart;
}
void lavadora::mostrar()
{
    electro::mostrar();
    cout<<"\nNumero de Puertas: "<<np;
    cout<<"\nNumero de Compartimentos: "<<compart;
}

class televisor:public electro
{
    int plg;
    char color[10];
    public:
    int getTipo();
    void leer();
    void mostrar();
};

int televisor::getTipo()
{
    return(2);
}
void televisor::leer()
{
    electro::leer();
    cout<<"\nIngrese pulgadas: ";cin>>plg;
    cout<<"\nIngrese Color: ";gets(color);
}
void televisor::mostrar()
{
    electro::mostrar();
    cout<<"\nPulgadas: "<<plg;
    cout<<"\nColor ";puts(color);
}

class almacen
{
    int ds;
    int nds;

    electro *vDs[20];
    electro *vNs[20];

    public:

    almacen();
    void leer();
    void leerL(int pos);
    void leerT(int pos);
    void mostrar();
    int menu();
    void editar_lavadora();
    void mostrar_por_compartimento();
    int buscar(int var);


};
almacen::almacen()
{
    nds=ds=0;
}
void almacen::leer()
{
    cout<<"\nIngrese numero de electrodomesticos disponibles: ";
    cin>>ds;
    for(int i=1;i<=ds;i++)
    {

        if(menu()==1)
            leerL(i);
        else
            leerT(i);
    }
}
void almacen::leerL(int pos)
{
    vDs[pos] = new lavadora;
    vDs[pos] -> leer();
}
void almacen::leerT(int pos)
{
    vDs[pos] = new televisor;
    vDs[pos] -> leer();
}
void almacen::mostrar()
{

}
int almacen::menu()
{
    int op;
    cout<<"\n1. Lavadora";
    cout<<"\n2. Televisor";
    cin>>op;
    return(op);
}
void almacen::editar_lavadora()
{
    int c;
    cout<<"\nIngrese codigo de lavadora: ";cin>>c;
    int pos;
    pos=buscar(c);
    if(pos!=-1)
    {
        vDs[pos] -> leer();
    }
}
int almacen::buscar(int var)
{
     int i=1;
     int p=-1;
     while(i<=ds && p==-1)
     {
         if(vDs[i]->getTipo()==1)
            if(vDs[i]->getCodigo()==var)
               p=i;

               i++;
     }

     return(p);
}
void almacen::mostrar_por_compartimento()
{
    int c;
    cout<<"\nIngrese numero de compartimentos: ";
    cin>>c;

    for(int i=1;i<=ds;i++)
        if(vDs[i]->getTipo()==1)
        {
           lavadora *ptr;
           ptr = (lavadora*) vDs[i];

           if(ptr->getCompartimentos()==c)
              vDs[i] -> mostrar();
        }
}
void main()
{
almacen *a;
a = new almacen;
a->leer();
a->mostrar_por_compartimento();
    getch();
}
