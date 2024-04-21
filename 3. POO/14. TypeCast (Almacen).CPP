#include <iostream.h>
#include <conio.h>
#include <stdio.h>
#include <string.h>
class cElectro{
     char color[10];
     int capacidad;
     char marca[10];
     char modelo[10];
     char codigo[10];
     public:
     char *getColor();
     char *getCodigo();
     int getTipo();
     virtual void leer();
     virtual void mostrar();
};
char *cElectro::getColor()
{
    return(color);
}
char *cElectro::getCodigo()
{
    return(codigo);
}
int cElectro::getTipo()
{
    return(-1);
}
void cElectro::leer()
{
    cout<<"\nIngrese marca: ";gets(marca);
    cout<<"\nIngrese modelo: ";gets(modelo);
    cout<<"\nIngrese codigo: ";gets(codigo);
    cout<<"\nIngrese color: ";gets(color);
    cout<<"\nIngrese capacidad: ";cin>>capacidad;
}
void cElectro::mostrar()
{
    cout<<"\nMarca: ";puts(marca);
    cout<<"\nModelo: ";puts(modelo);
    cout<<"\nCodigo: ";puts(codigo);
    cout<<"\nColor: ";puts(color);
    cout<<"\nCapacidad: "<<capacidad;
}

class cL:public cElectro{
    int sec; //numero de secadoras
    public:
    int getSec();
    int getTipo();
    void leer();
    void mostrar();
    int menu();
};

int cL::getTipo()
{
    return(1);
}
int cL::getSec()
{
    return(sec);
}
void cL::leer()
{
    cElectro::leer();
    if(menu()==1)
        do{
             cout<<"\nIngrese numero de secadoras: ";cin>>sec;
        }while(sec<1);
    else
        sec=-1;
}
void cL::mostrar()
{
    cElectro::mostrar();
    if(sec!=-1)
         cout<<"\nNumero de secadoras: "<<sec;
}
int cL::menu()
{
    int op;
    do{
        cout<<"\n1. Tiene secadoras";
        cout<<"\n2. No tiene secadoras";
        cin>>op;
    }while((op<1)||(op>2));
    return(op);
}
class cR:public cElectro{
     int npuertas;
     public:
     int getTipo();
     int getNumpuertas();
     void leer();
     void mostrar();
};

int cR::getTipo()
{
    return(2);
}
int cR::getNumpuertas()
{
     return(npuertas);
}
void cR::leer()
{
     cElectro::leer();
     cout<<"\nIngrese numero de puertas: ";cin>>npuertas;
}
void cR::mostrar()
{
     cElectro::mostrar();
     cout<<"\nNumero de puertas: "<<npuertas;
}
class cAlm{
     char nom[10];
     char dir[10];
     cElectro *vVs[20];
     cElectro *vEs[20];
     int nv;
     int ne;
     public:
     cAlm();
     void leer();
        void leerLE(int pos); //lavadora en venta
        void leerRE(int pos); //refrigeradora en venta
        void leerLV(int pos); //lavadora vendida
        void leerRV(int pos); //refrigeradora vendida
        int menu();
     void Eventa_Evedidos();
        int BuscarEnVenta(char *cd);
        void recorrerEnVenta(int pos);
     void mostrarLavConSecadoras();
     void mostrarRefXpuertas();
     void ElectroBlancos();
};
cAlm::cAlm(){
     nv=ne=0;
}
void cAlm::leer()
{
     cout<<"\nIngrese nombre de la empresa: ";gets(nom);
     cout<<"\nIngrese direccion de la empresa: ";gets(dir);
     int n,op;
     do{
         cout<<"\nIngrese cantidad total de electrodomesticos: ";
         cin>>n;
     }while((n<1)||(n>20));
     for(int i=1;i<=n;i++)
     {
         cout<<"\nELECTRODOMESTICO "<<i;
         do{
             cout<<"\n1. Vendido";
             cout<<"\n2. En venta";
             cout<<"\nEscoja opcion: ";
             cin>>op;
         }while((op<1)||(op>2));
         if(op==1) //vendido
            if(menu()==1){  //lavadora
                nv++;
                leerLV(nv);
                }
            else{ //refrigeradora
                nv++;
                leerRV(nv);
            }
         else //en venta
            if(menu()==1)  //lavadora
            {
                ne++;
                leerLE(ne);
            }
            else
            {
                ne++;
                leerRE(ne);
            }
     }
}
int cAlm::menu(){
    int op;
    do{
        cout<<"\n1. Lavadora";
        cout<<"\n2. Refrigeradora";
        cin>>op;
    }while((op<1)||(op>2));
    return(op);
}
void cAlm::leerLE(int pos) //lavadora en venta
{
    vEs[pos] = new cL;
    vEs[pos] -> leer();
}
void cAlm::leerRE(int pos) //refrigeradora en venta
{
    vEs[pos] = new cR;
    vEs[pos] -> leer();
}
void cAlm::leerLV(int pos) //lavadora vendida
{
    vVs[pos] = new cL;
    vVs[pos] -> leer();
}
void cAlm::leerRV(int pos) //refrigeradora vendida
{
    vVs[pos] = new cR;
    vVs[pos] -> leer();
}
void cAlm::Eventa_Evedidos()
{
    int p;
    char cd[10];
    cout<<"\nIngrese codigo: ";
    gets(cd);
    p=BuscarEnVenta(cd);
    if(p!=-1)
    {
         nv++;
         vVs[nv]=vEs[p];
         recorrerEnVenta(p);
    }
}
int cAlm::BuscarEnVenta(char *cd)
{
    int pos=-1;
    int i=1;
    while((i<=ne)&&(pos==-1))
    {
        if(strcmp(vEs[i]->getCodigo(),cd)==0)
              pos=i;
        i++;
    }
    return(pos);
}
void cAlm::recorrerEnVenta(int pos)
{
    for(int i=pos;i<=ne;i++)
        vEs[i]=vEs[i+1];
    ne--;
}
void cAlm::mostrarLavConSecadoras()
{
    int c=0;
    for(int i=1;i<=nv;i++)
    {
        if(vVs[i]->getTipo()==1)  //Uso de TypeCast
        {
             cL *ptr;
             ptr = (cL*)vVs[i];
             if(ptr->getSec()!=-1){
                 c++;
                 vVs[i]->mostrar();
                 }
        }
    }
    if(c!=0)
       cout<<"\nSe tiene "<<c<<" lavadoras con secadoras vendidas";
}
void cAlm::mostrarRefXpuertas()
{
    int n;
    int c=0;
    cout<<"\nIngrese numero de puertas: ";cin>>n;
    for(int i=1;i<=ne;i++)
    if(vEs[i]->getTipo()==2)
    {
        cR *ptr;
        ptr=(cR*)vEs[i];
        if(ptr->getNumpuertas()==n)
        {
            c++;
            vEs[i]->mostrar();
        }
    }
    if(c!=0)
       cout<<"\nSe tiene "<<c<<" refrigeradoras con "<<n<<" puertas";
}
void cAlm::ElectroBlancos()
{
    int c=0;
    for(int i=1;i<=ne;i++)
    if(strcmp(vEs[i]->getColor(),"blanco")==0)
         c++;
    if(c!=0)
      cout<<"\nSe tiene "<<c<<" electrodomestico(s) de color blanco";
}
void main(){
   cAlm oAlm;
   oAlm.leer();
   oAlm.ElectroBlancos();
   getch();
}
