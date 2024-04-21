#include <iostream.h>
#include <conio.h>
#include <string.h>
#include <stdio.h>
class cElectro{
     char marca[10];
     char modelo[10];
     char codigo[10];
     char color[10];

     public:

     char *getCodigo();
     char *getColor();

     virtual int getTipo();

     virtual void leer();
     virtual void mostrar();
};
char *cElectro::getCodigo()
{
     return(codigo);
}
char *cElectro::getColor()
{
     return(color);
}

int cElectro::getTipo()
{
     return(-1);
}
void cElectro::leer()
{
     cout<<"\nIngrese marca: ";
     gets(marca);
     cout<<"\nIngrese modelo: ";
     gets(modelo);
     cout<<"\nIngrese codigo: ";
     gets(codigo);
     cout<<"\nIngrese color: ";
     gets(color);
}
void cElectro::mostrar()
{
     cout<<"\nMarca: ";
     puts(marca);
     cout<<"\nModelo: ";
     puts(modelo);
     cout<<"\nCodigo: ";
     puts(codigo);
     cout<<"\nColor: ";
     puts(color);
}
class cR: public cElectro
{
     int np;

     public:
     int getTipo();

     int getNumPuertas();
     void leer();
     void mostrar();
};
int cR::getTipo()
{
     return(1);
}
int cR::getNumPuertas()
{
    return(np);
}
void cR::leer()
{
    cElectro::leer();
    cout<<"\nIngrese numerode puertas: ";cin>>np;
}
void cR::mostrar()
{
    cElectro::mostrar();
    cout<<"\nNumero de puertas: "<<np;
}
class cL: public cElectro{
     int sec;

     public:

     cL();
     int getTipo();
     int getSecadoras();
     void leer();
     void mostrar();
};
cL::cL()
{
    sec=-1;
}
int cL::getTipo()
{
    return(2);
}
int cL::getSecadoras()
{
    return(sec);
}
void cL::leer()
{
    cElectro::leer();
    int op;
    do{
        cout<<"\n1. Tiene secadoras ";
        cout<<"\n2. No tiene secadoras";
        cout<<"\nIngrese opcion: ";
        cin>>op;
    }while((op<1)||(op>2));
    if(op==1)
    {
       do{
         cout<<"\nIngrese numero de secadoras: ";
         cin>>sec;
         }while(sec<1);
    }
}
void cL::mostrar()
{
    cElectro::mostrar();
    if(sec!=-1)
       cout<<"\nNumero de secadoras: "<<sec;
}
class cEmp
{
    char nom[10];
    char dir[10];
    cElectro *vVs[20];  //lista de electrodomesticos vendidos
    cElectro *vEs[20];  //lista de electrodomesticos en venta
    int nv;  //vendidos
    int ne;  //en venta

    public:

    cEmp();
    void leer();
    void leerR(int pos);
    void leerL(int pos);
    int menu();

    void pasaravendidos();
    int buscarEV(char *cd);
    void recorrerEV(int pos);

    void mostrarlavadorasconsecadoras(); //vendidos

    void mostrarxnumerodepuertas();  //en venta

    void mostrarelectroblancos();  //en venta
};
cEmp::cEmp()
{
    nv=ne=0;
}
void cEmp::leer()
{
    cout<<"\nIngrese nombre de la empresa: ";gets(nom);
    cout<<"\nIngrese direccion de la empresa: ";gets(dir);
    do
    {
         cout<<"\nIngrese numero de electrodomesticos: ";
         cin>>ne;
    }while((ne<1)||(ne>20));
    for(int i=1;i<=ne;i++)
        if(menu()==1)
            leerR(i);
        else
            leerL(i);

}
int cEmp::menu()
{
    int op;
    do{
        cout<<"\n1. Refrigeradora";
        cout<<"\n2. Lavadora ";
        cin>>op;
    }while(op<1||op>2);
    return(op);
}
void cEmp::leerR(int pos)
{
    vEs[pos] = new cR;
    vEs[pos] -> leer();
}
void cEmp::leerL(int pos)
{
    vEs[pos] = new cL;
    vEs[pos] -> leer();
}

void cEmp::pasaravendidos()
{
    char cd[10];
    cout<<"\nIngrese codigo del electrodomestico en venta: ";
    gets(cd);
    int pos;
    pos=buscarEV(cd);
    if(pos!=-1)
    {
         nv++;
         vVs[nv] = vEs[pos];
         recorrerEV(pos);
    }

}
int cEmp::buscarEV(char *cd)
{
    int i=1;
    int p=-1;

    while((i<=ne)&&(p==-1))
    {
          if(strcmp(vEs[i]->getCodigo(),cd)==0)
               p=i;
          i++;
    }
    return(p);
}
void cEmp::recorrerEV(int pos)
{
    for(int i=pos;i<ne-1;i++)
       vEs[i]=vEs[i+1];

    ne--;
}

void cEmp::mostrarlavadorasconsecadoras() //vendidos
{
    int c=0;
    for(int i=0;i<=nv;i++)
        if(vVs[i]->getTipo()==2)
        {
            cL *ptr;
            ptr= (cL*)vVs[i];
            if(ptr->getSecadoras()!=-1)
                 c++;
        }
    if(c!=0)
        cout<<"\nLavadoras con secadoras: "<<c;
}

void cEmp::mostrarxnumerodepuertas()  //en venta
{
    int p;
    cout<<"\nIngrese numero de puertas: ";
    cin>>p;
    int c=0;
    for(int i=1;i<=ne;i++)
       if(vEs[i]->getTipo()==1)
       {
           cR *ptr;
           ptr = (cR*)vEs[i];
           if(ptr->getNumPuertas()==p)
           {
              vEs[i]->mostrar();
              c++;
           }
       }
    if(c!=0)
       cout<<"\nRefrigeradoras con "<<p<<" puertas: "<<c;
}

void cEmp::mostrarelectroblancos()  //en venta
{
     int c=0;
     for(int i=1;i<=ne;i++)
     if(strcmp(vEs[i]->getColor(),"blanco")==0)
          c++;
     if(c!=0)
        cout<<"\nElectrodomesticos blancos: "<<c;
}
void main()
{
     getch();
}
