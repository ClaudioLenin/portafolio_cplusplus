#include <iostream.h>
#include <conio.h>
#include <stdio.h>
#include <string.h>
class cTrabajador
{
   int tipo;
   char nombre[20];
   char codigo[20];

   public:

   cTrabajador();
   void setTipo(int newT);
   int getTipo();
   virtual void leer();
   virtual void mostrar();
   virtual float calSalario();

   ~cTrabajador();

};
cTrabajador::cTrabajador()
{
    strcpy(nombre,"");
    strcpy(codigo,"");
    tipo=0;
}
void cTrabajador::setTipo(int newT)
{
}
int cTrabajador::getTipo()
{
    return(tipo);
}
void cTrabajador::leer()
{
    cout<<"\nIngrese nombre: ";gets(nombre);
    cout<<"\nIngrese codigo: ";gets(codigo);
}
void cTrabajador::mostrar()
{
    cout<<"\nNombre: ";puts(nombre);
    cout<<"\nCodigo: ";puts(codigo);
}
float cTrabajador::calSalario()
{
    return(-1);
}

cTrabajador::~cTrabajador()
{
}
class cTN : public cTrabajador
{
    float sb; //salario basico
    float d; //descuento

    public:

    cTN();
    void leer();
    void mostrar();
    float calSalario();
    ~cTN();

};
cTN::cTN():cTrabajador()
{
    sb=d=0;
}
void cTN::leer()
{
    cTrabajador::leer();
    cout<<"\nIngrese salario basico: ";cin>>sb;
    cout<<"\nIngrese descuento: ";cin>>d;
}
void cTN::mostrar()
{
    cTrabajador::mostrar();
    cout<<"\nSalario Basico: "<<sb;
    cout<<"\nDescuento: "<<d;
    cout<<"\nSalario Mensual: "<<calSalario();
}
float cTN::calSalario()
{
    return(sb-d);
}
cTN::~cTN()
{
}
class cTC : public cTrabajador
{
    int ht; //horas trabajadas
    float vht; //valor horas trabajadas

    public:

    cTC();
    void leer();
    void mostrar();
    float calSalario();
    ~cTC();

};
cTC::cTC():cTrabajador()
{
    ht=vht=0;
}
void cTC::leer()
{
    cTrabajador::leer();
    cout<<"\nIngrese horas trabajadas: ";cin>>ht;
    cout<<"\nIngrese valor de horas trabajadas: ";cin>>vht;
}
void cTC::mostrar()
{
    cTrabajador::mostrar();
    cout<<"\nHoras Trabajadas: "<<ht;
    cout<<"\nValor de horas Trabajadas: "<<vht;
    cout<<"\nSalario Mensual: "<<calSalario();
}
float cTC::calSalario()
{
    return(ht*vht);
}
cTC::~cTC()
{
}
class cEmp
{
   char nombre[20];
   char codigo[20];
   int n;
   cTrabajador *vTs[30];

   public:
   cEmp();
   void leer();
   void nomina();
   float salarioTotal();
   ~cEmp();
};
cEmp::cEmp()
{
    strcpy(nombre,"");
    strcpy(codigo,"");
    n=0;
}
int tipo()
{
    int n;
    do{
        cout<<"\n1.- Trabajador con nombramiento";
        cout<<"\n2.- Trabajador de contrato";
        cout<<"\n\t\tEscoja opcion: ";cin>>n;
    }while((n<1)||(n>2));
    return(n);
}
void cEmp::leer()
{
    int tipo();
    cout<<"\nIngrese empresa: ";gets(nombre);
    cout<<"\nIngrese codigo: ";gets(codigo);
    do{
       cout<<"\nIngrese numero de trabajadores: ";cin>>n;
    }while((n<1)||(n>30));
    for(int i=1;i<=n;i++)
    {
        int t;
        cout<<"\n\t\t\tTRABAJADOR "<<i<<endl;
        cout<<"________________________________________\n";
        t=tipo();
        if(t==1)
        {
           vTs[i] = new cTN;
           vTs[i] -> setTipo(1);
           vTs[i] -> leer();
        }
        else
        {
           vTs[i] = new cTC;
           vTs[i] -> setTipo(2);
           vTs[i] -> leer();
        }

    }
}
void cEmp::nomina()
{
    float s;
    for(int i=1;i<=n;i++)
    {
        cout<<"\n\t\t\tTRABAJADOR "<<i<<endl;
        cout<<"________________________________________\n";
        vTs[i] -> mostrar();
    }
    s=salarioTotal();
    if(s!=0)
       cout<<"\nEl salario total a pagar la empresa es: "<<s;
}
float cEmp::salarioTotal()
{
    float acum=0;
    for(int i=1;i<=n;i++)
    {
        acum+=vTs[i] -> calSalario();
    }
   return(acum);
}
cEmp::~cEmp()
{
   for(int i=1;i<=n;i++)
      delete (vTs[i]);
   n=0;
}
void main(){
   cEmp *obj;
   obj = new cEmp;
   obj -> leer();
   clrscr();

   obj -> nomina();
   getch();
}
