#include <iostream.h>
#include <conio.h>
#include <string.h>
#include <stdio.h>
class cResidencial
{
    char ci[10];
    char nom[20];
    char ap[20];
    int n_medidor;
    float lan; //lectura naterior
    float lac; //lectura actual
    float vmc; //precio de m3

    public:

    virtual int getTipo();
    char *getCI();
    int getNumMedidor();

    virtual float TotalDeuda();
    virtual void leer();
    virtual void mostrar();
};
int cResidencial::getTipo()
{
    return(1);
}
char *cResidencial::getCI()
{
    return(ci);
}
int cResidencial::getNumMedidor()
{
    return(n_medidor);
}
float cResidencial::TotalDeuda()
{
    return((lac-lan)*vmc);
}
void cResidencial::leer()
{
    cout<<"\nIngrese Cedula de identidad: ";gets(ci);
    cout<<"\nIngrese Nombre: ";gets(nom);
    cout<<"\nIngrese Apellido: ";gets(ap);
    cout<<"\nIngrese numero de medidor: ";cin>>n_medidor;
    cout<<"\nIngrese lectura anterior: ";cin>>lan;
    cout<<"\nIngrese lectura actual: ";cin>>lac;
    cout<<"\nIngrese valor de m3: ";cin>>vmc;
}
void cResidencial::mostrar()
{
    cout<<"\nCedula de identidad: ";puts(ci);
    cout<<"\nNombre: ";puts(nom);
    cout<<"\nApellido: ";puts(ap);
    cout<<"\nNumero de medidor: "<<n_medidor;
    cout<<"\nLectura anterior: "<<lan;
    cout<<"\nLectura actual: "<<lac;
    cout<<"\nValor de m3: "<<vmc;
}
class cEspecial: public cResidencial
{
    int FM;

    public:

    int getTipo();
    float TotalDeuda();
    void leer();
    void mostrar();
};
int cEspecial::getTipo()
{
    return(2);
}
float cEspecial::TotalDeuda()
{
    return(cResidencial::TotalDeuda()*FM);
}
void cEspecial::leer()
{
    cResidencial::leer();
    cout<<"\nIngrese Factor de Multiplicacion: ";cin>>FM;
}
void cEspecial::mostrar()
{
    cResidencial::mostrar();
    cout<<"\nFactor de Multiplicacion: "<<FM;
}
class cEmpA
{
    char dir[10];
    cResidencial *vFs[20];
    int nf;

    public:

    cEmpA();

    void leer();
    void leerR(int pos);
    void leerE(int pos);
    int menu();

    void mostraruncliente();

    void eliminarFactura();
    int buscarF(char *cd);
    void recorrervector(int pos);

    void promedioClientesEspeciales();
};
cEmpA::cEmpA()
{
     nf=0;
}
void cEmpA::leer()
{
     cout<<"\nIngrese direccion de la empresa: ";gets(dir);
     do{
        cout<<"\nIngrese numero de facturas: ";
        cin>>nf;
        }while((nf<1)||(nf>20));
     for(int i=1;i<=nf;i++)
     {
         cout<<"\n\t\t\tFACTURA "<<endl;
         if(menu()==1)
            leerR(i);
         else
            leerE(i);
     }
}
void cEmpA::leerR(int pos)
{
     vFs[pos] = new cResidencial;
     vFs[pos] -> leer();
}
void cEmpA::leerE(int pos)
{
     vFs[pos] = new cEspecial;
     vFs[pos] -> leer();
}
int cEmpA::menu()
{
     int op;
     do{
         cout<<"\n1. Residencial";
         cout<<"\n2. Especial";
         cout<<"\nEscoja opcion: ";
         cin>>op;
     }while((op<1)||(op>2));
     return(op);
}

void cEmpA::mostraruncliente()
{
     char cd[10];
     int acum=0;
     cout<<"\nIngrese cedula de identidad: ";gets(cd);
     for(int i=1;i<=nf;i++)
         if(strcmp(vFs[i]->getCI(),cd)==0)
         {
              acum+=vFs[i]->TotalDeuda();
         }
     if(acum!=0)
         cout<<"\nTotal a pagar por el cliente: "<<acum;
}

void cEmpA::eliminarFactura()
{
     char cd[10];
     cout<<"\nIngrese cedula de identidad: ";gets(cd);

     int pos=buscarF(cd);
     if(pos!=-1)
     {
          delete (vFs[pos]);
          recorrervector(pos);
     }

}
int cEmpA::buscarF(char *cd)
{
     int i=1;
     int p=-1;
     while((p==-1)&&(i<=nf))
     {
         if(strcmp(vFs[i]->getCI(),cd)==0)
             p=i;
         i++;
     }
     return(p);
}
void cEmpA::recorrervector(int pos)
{
     for(int i=pos; i<=nf-1;i++)
         vFs[i] = vFs[i+1];
     nf--;
}

void cEmpA::promedioClientesEspeciales()
{
     float acum=0.0;
     int cont=0;
     float x;
     cout<<"\nIngrese deuda: ";cin>>x;

     for(int i=1;i<=nf;i++)
        if(vFs[i]->getTipo()==2)
            if(vFs[i]->TotalDeuda()==x)
            {
                 acum+=vFs[i]->TotalDeuda();
                 cont++;
            }
     if(cont!=0)
        cout<<"\nEl Promedio es: "<<acum/cont;
}
void main()
{
     cEmpA *ptr;
     ptr = new cEmpA;
     ptr -> leer();
     ptr -> mostraruncliente();
     ptr -> eliminarFactura();
     ptr -> promedioClientesEspeciales();
     getch();
}
