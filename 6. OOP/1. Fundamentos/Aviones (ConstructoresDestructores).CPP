#include<iostream>
#include <conio.h>
#include<string.h>
#include<stdio.h>


using namespace std;

class cAvion
{
    char marca[10];
    char modelo[10];
    char codigo[10];
    int tipo;
    int h;  //Horas de vuelo de cada avion
    int h1; //Horas de vuelo recomendadas por el fabricante de cada avion

    public:

    cAvion();
    void setTipo(int newT);
    int getTipo();
    void setEstado(int newE);
    int getEstado();
    void setHV(int newHV);
    int getHV();
    char *getCodigo();
    void setHR(int newHR);
    int getHR();

    virtual void leer();
    virtual void mostrar();

};
cAvion::cAvion()
{
    strcpy(modelo,"");
    strcpy(codigo,"");
    strcpy(marca,"");
    tipo=h=h1=0;
}
//SETTERS & GETTERS
char *cAvion::getCodigo()
{
    return(codigo);
}
void cAvion::setTipo(int newT)
{
    tipo=newT;
}
int cAvion::getTipo()
{
    return(tipo);
}
void cAvion::setHV(int newHV)
{
    h=newHV;
}
int cAvion::getHV()
{
    return(h);
}
void cAvion::setHR(int newHR)
{
    h1=newHR;
}
int cAvion::getHR()
{
    return(h1);
}
//LN
void cAvion::leer()
{
    cout<<"\nIngrese modelo: ";gets(modelo);
    cout<<"\nIngrese marca: ";gets(marca);
    cout<<"\nIngrese codigo: ";gets(codigo);
    do{
       cout<<"\nIngrese horas de vuelo: ";cin>>h;
       cout<<"\nIngrese horas de vuelo recomendadas por el fabricante: ";cin>>h1;
       }while((h<0)||(h1<0));
}
void cAvion::mostrar()
{
    cout<<"\nModelo: ";puts(modelo);
    cout<<"\nMarca: ";puts(marca);
    cout<<"\nCodigo: ";puts(codigo);
    cout<<"\nIngrese horas de vuelo: "<<h;
    cout<<"\nIngrese horas de vuelo recomendadas por el fabricante: "<<h1;
}

class cAP : public cAvion
{
    int nvip;  //numero de pasajeros vip
    int ntur;  //numero de pasajeros turistas

    public:

    cAP();
    void leer();
    void mostrar();
    ~cAP();

};
cAP::cAP():cAvion()
{
    nvip=ntur=0;
}
void cAP::leer()
{
    cAvion::leer();
    cout<<"\nIngrese numero de pasajeros VIP: ";cin>>nvip;
    cout<<"\nIngrese numero de pasajeros turistas: ";cin>>ntur;
}
void cAP::mostrar()
{
    cAvion::mostrar();
    cout<<"\nNumero de pasajeros VIP: "<<nvip;
    cout<<"\nNumero de pasajeros turistas: "<<ntur;
}
cAP::~cAP()
{
}
class cAC : public cAvion
{
    float cc; //capacidad de carga

    public:

    cAC();
    void leer();
    void mostrar();

    ~cAC();
};
cAC::cAC():cAvion()
{
    cc=0;
}
void cAC::leer()
{
    cAvion::leer();
    cout<<"\nIngrese capacidad de carga del avion: ";cin>>cc;
}
void cAC::mostrar()
{
    cAvion::mostrar();
    cout<<"\nCapacidad de carga del avion: "<<cc;
}
cAC::~cAC()
{
}
class cAerop
{
    char nombre[10];
    char direccion[10];
    int nd;
    int nm;
    cAvion *vAD[20]; //aviones disponibles
    cAvion *vAM[20]; //aviones a mantenimiento

    public:

    cAerop();
    void leer();
    void moverAvionesAMantenimento();
    void moverMantenimentoADisponible();
    void recorerD(int pos);
    int BuscarD(char *c);
    void recorerM(int pos);
    int BuscarM(char *c);
    void mostrarAvionesDisponibles();
    void mostrarAvionesMantenimiento();
    void eliminarAvion();
    void MoverMantenimiento();
    ~cAerop();

};
cAerop::cAerop()
{
    strcpy(nombre,"");
    strcpy(direccion,"");
    nd=nm=0;
}
void cAerop::leer()
{
    cout<<"\nIngrese nombre de aeropuerto: "; gets(nombre);
    cout<<"\nIngrese direccion de aeropuerto: ";gets(direccion);
    do{
        cout<<"\nIngrese numero de aviones: ";cin>>nd;
        }while((nd<1)||(nd>20));
    for(int i=1;i<=nd;i++)
    {
       int op;
       do{
            cout<<"\n1.- Avion de carga\n";
            cout<<"\n2.- Avion de pasajeros\n";
            cout<<"\n\tEscoja una opcion: ";cin>>op;
          }while((op<1)||(op>2));
       if(op==1)
       {
           vAD[i] = new cAC;
           vAD[i] -> setTipo(1);
           vAD[i] -> leer();
       }
       else
       {
           vAD[i] = new cAP;
           vAD[i] -> setTipo(2);
           vAD[i] -> leer();
       }
    }
}
//______________________________________________________________________________
//______________________________________________________________________________
void cAerop::moverAvionesAMantenimento()
{
   int j=0;
   for(int i=1;i<=nd;i++)
       if(vAD[i]->getHV()>vAD[i]->getHR())
       {
          j++;
          vAM[j] = new cAvion;
          vAM[j] = vAD[i];
       }
   nm=j;
   MoverMantenimiento();

}
void cAerop::MoverMantenimiento(){

    int j=0;
    cAvion *vAUX[20];
    for(int i=1;i<=nd;i++)
       if(vAD[i]->getHV()<vAD[i]->getHR())
       {
           j++;
           vAUX[j] = new cAvion;
           vAUX[j] = vAD[i];
       }
     for(int i=1;i<=j;i++)
     {
          vAD[i] = new cAvion;
          vAD[i] = vAUX[i];
     }
     nd=j;

}

//______________________________________________________________________________
//______________________________________________________________________________

void cAerop::moverMantenimentoADisponible()

{

   int pos;
   char c[10];
   int h;
   cout<<"\nIngrese codigo de avion: ";gets(c);
   pos=BuscarM(c);
   if(pos!=-1)
   {
   do{
       cout<<"\nReescriba horas de vuelo: ";cin>>h;
      }while(h>vAM[pos]->getHR());
          nd+=1;
          vAD[nd] = new cAvion;
          vAD[nd] -> setHV(h);
          vAD[nd] = vAM[pos];
      recorerM(pos);
      nm--;
   }
   else{
     cout<<"\nAvion no encontrado......";
     }
}
void cAerop::recorerM(int pos)
{
    for(int i=1;i<=nm;i++)
       if(pos==i)
       {
          vAM[i]=vAM[i+1];
          pos++;
       }
}
int cAerop::BuscarM(char *c)
{
    int i=1;
    int p=-1;

    while((i<=nm)&&(p==-1))
    {
       if(strcmp(c,vAM[i]->getCodigo())==0)
           p=i;
       i++;
    }
    return(p);
}


//______________________________________________________________________________
//______________________________________________________________________________
void cAerop::eliminarAvion()
{
     char c[10];
     cout<<"\nIngrese el codigo del avion: ";gets(c);
     int pos;
     pos=BuscarD(c);
     if(pos=-1)
     {
         vAD[pos]=vAD[nd];
         nd--;
         cout<<"\nAvion eliminado....";
     }
     else
     {
         cout<<"\nAvion no encontrado........";
     }
}

int cAerop::BuscarD(char *c)
{
    int i=1;
    int p=-1;

    while((i<=nd)&&(p==-1))
    {
       if(strcmp(c,vAD[i]->getCodigo())==0)
           p=i;
       i++;
    }
    return(p);
}
//______________________________________________________________________________
//______________________________________________________________________________

void cAerop::mostrarAvionesDisponibles()
{
    for(int i=1;i<=nd;i++)
    {
        cout<<"\nAVION DISPONIBLE "<<i;
        cout<<"\n__________________________________\n";
        if(vAD[i]->getTipo()==1)
        {
           cout<<"\nAvion de carga\n";
           vAD[i]->mostrar();
        }
        else
        {
           cout<<"\nAvion de pasajeros\n";
           vAD[i]->mostrar();
        }
    }
}
void cAerop::mostrarAvionesMantenimiento()
{
    for(int i=1;i<=nm;i++)
    {
        cout<<"\nAVION NO DISPONIBLE "<<i;
        cout<<"\n__________________________________\n";
        if(vAM[i]->getTipo()==1)
        {
           cout<<"\nAvion de carga\n";
           vAM[i]->mostrar();
        }
        else
        {
           cout<<"\nAvion de pasajeros\n";
           vAM[i]->mostrar();
        }
    }
}

cAerop::~cAerop()
{
    for(int i=1;i<=nd;i++)
        delete(vAD[i]);
    nd=0;
}
int main(){
   cAerop *obj;
   obj = new cAerop;
   obj->leer();
   obj->moverAvionesAMantenimento();
   obj->mostrarAvionesDisponibles();
   obj->mostrarAvionesMantenimiento();
   cout<<"\n\n\t\t\tMOVER MANTENIMIENTO - DISPONIBLE\n";
   obj->moverMantenimentoADisponible();
   cout<<"\n\n\t\t\tELIMINAR AVION DISPONIBLE\n";
   obj->eliminarAvion();
   getch();
   
   return 0;
}
