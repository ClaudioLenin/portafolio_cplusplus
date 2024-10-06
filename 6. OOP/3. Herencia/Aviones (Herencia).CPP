#include "iostream"
#include <conio.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
using namespace std;
class cAvion
{
    private:
		char mar[10];
    	char mod[10];
    	char cod[10];
     	int hv;
     	int hf;

    public:
		void setHV(int nhv){hv = nhv;}
     	char *getCodigo(){return(cod);}
     	int getHV(){return(hv);}
     	int getHF();
     

     	virtual void leer()
     	{
    		cout<<"\nIngrese marca: ";gets(mar);
    		cout<<"\nIngrese modelo: ";gets(mod);
    		cout<<"\nIngrese codigo: ";gets(cod);
    		cout<<"\nIngrese horas recomendadas por el fabricante: ";cin>>hf;
    		cout<<"\nIngrese horas de vuelo: ";cin>>hv;
		}
     	virtual void mostrar(){
     		cout<<"\nMarca: ";puts(mar);
    		cout<<"\nModelo: ";puts(mod);
    		cout<<"\nCodigo: ";puts(cod);
    		cout<<"\nHoras recomendadas por el fabricante: "<<hf;
    		cout<<"\nHoras de vuelo: "<<hv;
		}
     	virtual int getTipo(){return(-1);}

};

class cPasajero:public cAvion
{
    int nvip;
    int ntur;

    public:

    void leer();
    void mostrar();
    int getTipo();
};
void cPasajero::leer()
{
    cAvion::leer();
    cout<<"\nIngrese numero de pasajeros VIP: ";cin>>nvip;
    cout<<"\nIngrese numero de pasajeros turistas: ";cin>>ntur;
}
void cPasajero::mostrar()
{
    cAvion::mostrar();
    cout<<"\nNumero de pasajeros VIP: "<<nvip;
    cout<<"\nNumero de pasajeros turistas: "<<ntur;
}
int cPasajero::getTipo()
{
    return(1);
}
class cCarga : public cAvion
{
    int cc;

    public:

    void leer();
    void mostrar();
    int getTipo();
};
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
int cCarga::getTipo()
{
   return(2);
}

class cAerop
{
     char nom[10];
     char direc[10];
     cAvion *vAd[20];
     cAvion *vAm[20];
     int nd;
     int nm;

     public:

     cAerop();
     void leer();
     int menu();
     void leerAP(int pos);
     void leerAC(int pos);
     void pasar_a_mantenimiento();
     void recorrerdisponibles(int pos);
     void pasar_a_disponible();
     int buscarM(char *cd);
     void recorrermantenimiento(int pos);
     void eliminar_avion();
     int buscarD(char *cd);
     void mostrardisponibles();
     void mostrarmantenimiento();
     void agregardisponible();
     ~cAerop();
};
cAerop::cAerop()
{
    nd=nm=0;
}
void cAerop::leer()
{
    cout<<"\nIngrese nombre del aeropuerto: ";gets(nom);
    cout<<"\nIngrese direccion del aeropuerto: ";gets(direc);
    do{
        cout<<"\nIngrese numero total de aviones: ";cin>>nd;
    }while((nd<1)||(nd>20));

    for(int i=1;i<=nd;i++)
    {
         cout<<"\nAVION "<<i;
         cout<<"\n____________________________________\n";
         if(menu()==1)
             leerAP(i);
         else
             leerAC(i);
    }
}
int cAerop::menu()
{
    int op;
    do{
        cout<<"\n1. Avion de pasajeros";
        cout<<"\n2. Avion de carga";
        cout<<"\n\t\tseleccione opcion: ";cin>>op;
    }while((op<1)||(op>2));
    return(op);
}
void cAerop::leerAP(int pos)
{
    vAd[pos] = new cPasajero;
    vAd[pos] -> leer();
}
void cAerop::leerAC(int pos)
{
    vAd[pos] = new cCarga;
    vAd[pos] -> leer();
}
/*
________________________________________________________________________________
                                    LITERAL A
________________________________________________________________________________
*/
void cAerop::pasar_a_mantenimiento()
{
    for(int i=1;i<=nd;i++)
         if(vAd[i]->getHV()>vAd[i]->getHF())
         {
             nm++;
             vAm[nm] = vAd[i];
             recorrerdisponibles(i);
             i--;
         }
}
void cAerop::recorrerdisponibles(int pos)
{
     for(int i=pos;i<=nd-1;i++)
          vAd[i] = vAd[i+1];
     nd--;
}
/*
________________________________________________________________________________
                                    LITERAL B
________________________________________________________________________________
*/
void cAerop::pasar_a_disponible()
{
     char c[10];
     int pos;
     cout<<"\nIngrese codigo: ";gets(c);
     pos=buscarM(c);
     if(pos!=-1)
     {
         vAm[pos] -> setHV(0);
         nd++;
         vAd[nd] = vAm[pos];
         recorrermantenimiento(pos);
     }
     else
     {
         cout<<"\nNo se encontro el avion........";
     }
}
int cAerop::buscarM(char *cd)
{
    int i=1;
    int p=-1;

    while((i<=nm)&&(p==-1))
    {
        if(strcmp(vAm[i]->getCodigo(),cd)==0)
            p=i;
        i++;
    }
    return(p);
}
void cAerop::recorrermantenimiento(int pos)
{
    for(int i=pos;i<=nm-1;i++)
       vAm[i] = vAm[i+1];
    nm--;
}
/*
________________________________________________________________________________
                                    LITERAL C
________________________________________________________________________________
*/
void cAerop::eliminar_avion()
{
    char c[10];
    int pos;
    cout<<"\nIngrese codigo de avion: ";gets(c);
    pos=buscarD(c);
    if(pos!=-1)
    {
        delete(vAd[pos]);
        recorrerdisponibles(pos);
    }
    else
    {
        cout<<"\nAvion no encontrado.........";
    }
}
int cAerop::buscarD(char *cd)
{
    int i=1;
    int p=-1;
    while((i<=nd)&&(p==-1))
    {
         if(strcmp(vAd[i]->getCodigo(),cd)==0)
              p=i;
         i++;
    }

    return(p);
}
/*
________________________________________________________________________________

________________________________________________________________________________
*/
void cAerop::mostrardisponibles()
{
    for(int i=1;i<=nd;i++)
    {
         cout<<"\nAVION DISPONIBLE "<<i;
         cout<<"\n______________________________________\n";
         vAd[i] -> mostrar();
    }
}
void cAerop::mostrarmantenimiento()
{
    for(int i=1;i<=nm;i++)
    {
         cout<<"\nAVION EN MANTENIMIENTO "<<i;
         cout<<"\n______________________________________\n";
         vAm[i] -> mostrar();
    }
}

void cAerop::agregardisponible()
{
    if(nd<20)
    {
        nd++;
        cout<<"\n\t\t\tAGREGAR AVION\n";
        if(menu()==1)
            leerAP(nd);
        else
            leerAC(nd);
    }
    else
    {
       cout<<"\nCapacidad ecxedida....";
    }
}
cAerop::~cAerop()
{
}
int main()
{
    cAerop *ae = new cAerop;
    ae->leer();
    int op;
    do{
         do{
             cout<<"\n1. Pasar aviones a mantenimiento";
             cout<<"\n2. Pasar aviones a disponible";
             cout<<"\n3. Eliminar un avion disponible";
             cout<<"\n4. Mostrar aviones disponibles";
             cout<<"\n5. Mostrar aviones en mantenimiento";
             cout<<"\n6. Agregar avion disponible";
             cout<<"\n7. Salir";
             cout<<"\n\t\tSeleccion opcion: ";cin>>op;
           }while((op<1)||(op>6));
           switch(op){
                case 1:
                      ae->pasar_a_mantenimiento();
                      break;
                case 2:
                      ae->pasar_a_disponible();
                      break;
                case 3:
                      ae->eliminar_avion();
                      break;
                case 4:
                      ae->mostrardisponibles();
                      break;
                case 5:
                      ae->mostrarmantenimiento();
                      break;
                case 6:
                      ae->agregardisponible();
                      break;
           }
    }while(op!=7);
    getch();
    return 0;
}
