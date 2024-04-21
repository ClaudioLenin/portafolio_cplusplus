#include <iostream.h>
#include <conio.h>
#include <string.h>
#include <stdio.h>
class cFactura
{
     int nf; //numero de factura
     int nm; //numero de medidor
     float lec_ac; //lectura actual
     float lec_an; //lectura anterior
     char CI[10]; //C.I. de propietario
     float kwh; //Valor de Kwh

     public:

     cFactura();
     int getNF();
     float getLAC();
     float getLAN();
     char *getCI();
     float getKWH();

     void leerR();
     void mostrarR();
     float calTotalR();
     ~cFactura();

};
cFactura::cFactura()
{
    nf=nm=lec_ac=lec_an=kwh=0;
    strcpy(CI,"");
}
int cFactura::getNF()
{
    return(nf);
}
float cFactura::getLAC()
{
    return(lec_ac);
}
float cFactura::getLAN()
{
    return(lec_an);
}
char *cFactura::getCI()
{
    return(CI);
}
float cFactura::getKWH()
{
    return(kwh);
}

void cFactura::leerR()
{
    cout<<"\nIngrese el numero de factura: ";cin>>nf;
    cout<<"\nIngrese el numero de medidor: ";cin>>nm;
    cout<<"\nIngrese C.I. de propietario: ";gets(CI);
    do{
        cout<<"\nIngrese lectura anterior: ";cin>>lec_an;
        cout<<"\nIngrese lectura actual: ";cin>>lec_ac;
    }while((lec_an<1)||(lec_ac<1));
    cout<<"\nIngrese el valor KWH: ";cin>>kwh;
}
void cFactura::mostrarR()
{
    cout<<"\nNumero de factura: "<<nf;
    cout<<"\nNumero de medidor: "<<nm;
    cout<<"\nC.I. de propietario: ";puts(CI);
    cout<<"\nLectura anterior: "<<lec_an;
    cout<<"\nLectura actual: "<<lec_ac;
    cout<<"\nValor KWH: "<<kwh;
}
float cFactura::calTotalR()
{
   return((getLAC()-getLAN())*getKWH());
}
cFactura::~cFactura()
{
}
class cF_Industrial:public cFactura
{
    float FM;  //factor de multiplicacion
    public:
    float getFM();
    cF_Industrial();
    float calTotalI();
    void leerI();
    void mostrarI();
    ~cF_Industrial();
};
cF_Industrial::cF_Industrial():cFactura()
{
    FM=0;
}
float cF_Industrial::getFM()
{
   return(FM);
}
float cF_Industrial::calTotalI()
{
    return((getLAC()-getLAN())*getFM()*getKWH());
}
void cF_Industrial::leerI()
{
    cFactura::leerR();
    cout<<"\nIngrese factor de multiplicacion: ";cin>>FM;
}
void cF_Industrial::mostrarI()
{
    cFactura::mostrarR();
    cout<<"\nFactor de Multiplicacion: "<<FM;
}
cF_Industrial::~cF_Industrial()
{
}
class cEmpresa
{
    char nombre[20];
    char ciudad[20];
    int nfr;  //numero de facturas residenciales
    int nfi;  //numero de facturas industriales
    cFactura *vFr[20];
    cF_Industrial *vFi[20];
    public:

    cEmpresa();
    void leerE();
    void leerVR();
    void leerVI();
    void MostrarXCliente();
    void MostrarUnCliente();
    int buscarR(int c);
    int buscarI(int c);
    void eliminarTodo();
    void eliminarUnElemento();
    void recorrerVI(int ps);
    void recorrerVR(int ps);
    void mostrarTodo();

    ~cEmpresa();
};
cEmpresa::cEmpresa()
{
    strcpy(nombre,"");
    strcpy(ciudad,"");
    nfr=nfi=0;
}
void cEmpresa::leerE()
{
    cout<<"\nIngrese nombre de la Empresa: ";gets(nombre);
    cout<<"\nIngrese ciudad de la Empresa: ";gets(ciudad);
    leerVR();
    leerVI();
}
void cEmpresa::leerVR()
{
    clrscr();
    do{
        cout<<"\nIngrese numero de facturas residenciales: ";cin>>nfr;
    }while((nfr<1)||(nfr>20));
    for(int i=1;i<=nfr;i++)
    {
        cout<<"\n\t\t\tFACTURA RESIDENCIAL "<<i<<endl;
        cout<<"_____________________________________\n";
        vFr[i] = new cFactura;
        vFr[i] -> leerR();
    }
}
void cEmpresa::leerVI()
{
    clrscr();
    do{
         cout<<"\nIngrese numero de facturas industriales: ";cin>>nfi;
    }while((nfi<1)||(nfi>20));
    for(int i=1;i<=nfi;i++)
    {
        cout<<"\n\t\t\tFACTURA INDUSTRIAL "<<i<<endl;
        cout<<"_____________________________________\n";
        vFi[i] = new cF_Industrial;
        vFi[i] -> leerI();
    }
}
void cEmpresa::mostrarTodo()
{
    cout<<"\nNombre de la Empresa: ";puts(nombre);
    cout<<"\nCiudad de la Empresa: ";puts(ciudad);
    cout<<"\n___________________________________________________________________\n";
    if(nfr!=0)
     for(int i=1;i<=nfr;i++)
    {
        cout<<"\n\t\t\tFACTURA RESIDENCIAL "<<i<<endl;
        cout<<"_____________________________________\n";
        vFr[i] -> mostrarR();
    }
    else
       cout<<"\nNo existen Facturas Residenciales.......\n";
    if(nfi!=0)
      for(int i=1;i<=nfi;i++)
    {
        cout<<"\n\t\t\tFACTURA INDUSTRIAL "<<i<<endl;
        cout<<"_____________________________________\n";
        vFi[i] -> mostrarI();
    }
    else
      cout<<"\nNo existen Facturas Industriales.......\n";

}
/*______________________________________________________________________________
                                  LITERAL A
  ______________________________________________________________________________
*/
void cEmpresa::MostrarXCliente()
{
    char c[10];
    float acum=0;
    cout<<"\nIngrese C.I.: ";gets(c);
    for(int i=1;i<=nfr;i++)
    {
       if(strcmp(vFr[i] -> getCI(),c)==0)
        {
            cout<<"\n_____________________________________\n";
            vFr[i] -> mostrarR();
            cout<<"\n_____________________________________\n";
            acum+=vFr[i] -> calTotalR();
        }
    }

    for(int j=1;j<=nfi;j++)
    {
       if(strcmp(vFi[j] -> getCI(),c)==0)
       {
           cout<<"\n_____________________________________\n";
           vFi[j] -> mostrarI();
           acum+=vFi[j] -> calTotalI();
           cout<<"\n_____________________________________\n";
       }
    }

    if(acum!=0)
        cout<<"\nLa cantidad Total a pagar es: "<<acum;
}
/*______________________________________________________________________________
                                  LITERAL B
  ______________________________________________________________________________
*/
void cEmpresa::MostrarUnCliente()
{
    int f;
    int pos;
    cout<<"\nIngrese numero de factura: ";cin>>f;
    pos=buscarR(f);
    if(pos!=-1)
    {
        cout<<"\n_____________________________________\n";
        vFr[pos] -> mostrarR();
        cout<<"\nEl Total a pagar es: "<<vFr[pos] -> calTotalR();
        cout<<"\n_____________________________________\n";
    }
    pos=buscarI(f);
    if(pos!=-1)
    {
        cout<<"\n_____________________________________\n";
        vFi[pos] -> mostrarI();
        cout<<"\nEl Total a pagar es: "<<vFi[pos] -> calTotalI();
        cout<<"\n_____________________________________\n";
    }
}
//******************************BUSCADORES***************************************
int cEmpresa::buscarR(int c)
{
    int p=-1;
    int i=1;
    while((i<=nfr)&&(p==-1))
    {
        if(vFr[i] -> getNF()==c)
           p=i;
        i++;
    }
    return(p);
}
int cEmpresa::buscarI(int c)
{
    int i=1;
    int p=-1;
    while((i<=nfi)&&(p==-1))
    {
        if(vFi[i] -> getNF()==c)
            p=i;
        i++;
    }
    return(p);
}
/*
________________________________________________________________________________
                                  LITERAL  C
________________________________________________________________________________
*/
void cEmpresa::eliminarTodo()
{
    for(int i=1;i<=nfr;i++)
       delete(vFr[i]);
    for(int i=1;i<=nfi;i++)
       delete(vFi[i]);
    nfi=nfr=0;
}
/*
________________________________________________________________________________
                                  LITERAL  D
________________________________________________________________________________
*/
void cEmpresa::eliminarUnElemento()
{
   int f;
   int pos;
   cout<<"\nIngrese numero de factura: ";cin>>f;
   pos=buscarR(f);
       if(pos!=-1)
       {
           delete(vFr[pos]);
           recorrerVR(pos);
           nfr--;
       }

   pos=buscarI(f);
       if(pos!=-1)
       {
           delete(vFi[pos]);
           recorrerVI(pos);
           nfi--;
       }


}
void cEmpresa::recorrerVI(int ps)
{
   for(int i=1;i<=nfi-1;i++)
      if(i==ps)
      {
         vFi[ps]=vFi[i+1];
         ps++;
      }
}
void cEmpresa::recorrerVR(int ps)
{
   for(int i=1;i<=nfr-1;i++)
      if(i==ps)
      {
         vFr[ps]=vFr[i+1];
         ps++;
      }
}
cEmpresa::~cEmpresa()
{
}
void main()
{
    cEmpresa *e;
    e = new cEmpresa;
    e -> leerE();
    int op;
    do{
      do{
        cout<<"\n1.- Mostrar la informacion de todas las facturas de un cliente\n";
        cout<<"2.- Mostrar toda la informacion de un cliente x numero de factura\n";
        cout<<"3.- Eliminar Todas las facturas\n";
        cout<<"4.- Eliminar Una Factura\n";
        cout<<"5.- Mostrar Todos los Datos Almacenados\n";
        cout<<"6.- Salir";
        cout<<"\nSeleccione opcion: ";
        cin>>op;
        clrscr();

        switch(op){
             case 1:
                    e -> MostrarXCliente();
                    break;
             case 2:
                    e -> MostrarUnCliente();
                    break;
             case 3:
                    e -> eliminarTodo();
                    break;
             case 4:
                    e -> eliminarUnElemento();
                    break;
             case 5:
                    e -> mostrarTodo();
                    break;

        }
    }while((op<1)||(op>6));
    }while(op!=6);
    delete (e);

  getch();
}
