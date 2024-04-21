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
     int tipo;

     public:

     cFactura();
     int getNF();
     void setTipo(int newTipo);
     int getTipo();
     float getLAC();
     float getLAN();
     char *getCI();
     float getKWH();

     virtual void leer();
     virtual void mostrar();
     virtual float calTotal();
     ~cFactura();

};
cFactura::cFactura()
{
    nf=nm=lec_ac=lec_an=kwh=0;
    strcpy(CI,"");
    tipo=0;

}
void cFactura::setTipo(int newTipo)
{
    tipo=newTipo;
}
int cFactura::getTipo()
{
    return(tipo);
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

void cFactura::leer()
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
void cFactura::mostrar()
{
    cout<<"\nNumero de factura: "<<nf;
    cout<<"\nNumero de medidor: "<<nm;
    cout<<"\nC.I. de propietario: ";puts(CI);
    cout<<"\nLectura anterior: "<<lec_an;
    cout<<"\nLectura actual: "<<lec_ac;
    cout<<"\nValor KWH: "<<kwh;
}
float cFactura::calTotal()
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
    float calTotal();
    void leer();
    void mostrar();
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
float cF_Industrial::calTotal()
{
    return((getLAC()-getLAN())*getFM()*getKWH());
}
void cF_Industrial::leer()
{
    cFactura::leer();
    cout<<"\nIngrese factor de multiplicacion: ";cin>>FM;
}
void cF_Industrial::mostrar()
{
    cFactura::mostrar();
    cout<<"\nFactor de Multiplicacion: "<<FM;
}
cF_Industrial::~cF_Industrial()
{
}
class cEmpresa
{
    char nombre[20];
    char ciudad[20];
    int n;
    cFactura *vFs[20];

    public:

    cEmpresa();
    void leerE();
    void mostrarE();
    void MostrarXCliente();

    ~cEmpresa();
};
cEmpresa::cEmpresa()
{
    strcpy(nombre,"");
    strcpy(ciudad,"");
    n=0;
}
void cEmpresa::leerE()
{

    cout<<"\nIngrese nombre de la Empresa: ";gets(nombre);
    cout<<"\nIngrese ciudad de la Empresa: ";gets(ciudad);
    do{
       cout<<"\nIngrese el numero de facturas: ";
       cin>>n;
    }while(n<1);

    for(int i=1;i<=n;i++){
        int t;
        do{
           cout<<"\n\t\t\t1. RESIDENCIAL";
           cout<<"\n\t\t\t2. INDUSTRIAL";
           cout<<"\n\t\tIngrese opcion: ";
           cin>>t;
        }while((t<1)||(t>2));
         vFs[i] = new cFactura;
        if(t==1){

           vFs[i] -> setTipo(1);
           vFs[i] -> leer();
           }
        else{
            vFs[i] = new cF_Industrial;
            vFs[i] -> setTipo(2);
            vFs[i] -> leer();

           }


    }


}
void cEmpresa::mostrarE()
{
    cout<<"\nNombre de la Empresa: ";puts(nombre);
    cout<<"\nCiudad de la Empresa: ";puts(ciudad);

    for(int i=1;i<=n;i++){
        cout<<"\n\t\t\tFACTURA "<<i<<endl;
        cout<<"_____________________________________\n";
        //if(vFs[i]->getTipo()==1)
        //{
            vFs[i] -> mostrar();
        //}
        /*else
        {
            cF_Industrial *ptr = new cF_Industrial;
            ptr=vFs[i];
            ptr->mostrar();
        } */
    }


}

cEmpresa::~cEmpresa()
{
     for(int i=1;i<=n;i++)
     {
        delete(vFs[i]);
        cout<<"\nFactura "<<i<<" Destruido....";
     }
    
}

void main()
{
    cEmpresa *e;
    e = new cEmpresa;
    e -> leerE();
    e -> mostrarE();

    delete (e);

  getch();
}