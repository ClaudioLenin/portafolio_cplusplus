#include<iostream>
#include <conio.h>
#include <string.h>
#include <stdio.h>

using namespace std;
void clrscr();
void clrscr() {
    system("cls");
}

class cAvion
{
	private:
    	char marca[10], modelo[10], codigo[10];
    	int tipo, estado, horasVuelo, horasVueloRecomendadas;

    public:
    	cAvion(){
    		strcpy(modelo,"");
    		strcpy(codigo,"");
    		sttrcpy(marca,"");
    		tipo = estado = horasVuelo = horasVueloRecomendadas = 0;
		}
    	void setTipo(int newTipo){tipo = newTipo;}
    	void setEstado(int newEstado){estado = newEstado;}
    	void setHorasVuelo(int newHorasVuelo){horasVuelo = newHorasVuelo;}
    	void setHorasVueloRecomendadas(int newHorasVueloR){horasVueloRecomendadas = newHorasVueloR;}
		char *getCodigo(){return(codigo);}
		int getTipo(){return tipo;}
    	int getEstado(){return estado;}
    	int getHorasVuelo(){return horasVuelo;}
    	int getHorasVueloRecomendadas(){return horasVueloRecomendadas;}
    	
    	virtual void createAvion(){
			cout<<"\nIngrese modelo: ";cin.ignore();gets(modelo);
    		cout<<"\nIngrese marca: ";cin.ignore();gets(marca);
    		cout<<"\nIngrese codigo: ";cin.ignore();gets(codigo);
    		do{
       			cout<<"\nIngrese horas de vuelo: ";cin>>horasVuelo;
       			cout<<"\nIngrese horas de vuelo recomendadas por el fabricante: ";cin>>horasVueloRecomendadas;
       		}while(horasVuelo < 0 || horasVueloRecomendadas < 0);    		
		}
		virtual void readAvion(){
			cout<<"\nModelo: ";puts(modelo);
    		cout<<"\nMarca: ";puts(marca);
    		cout<<"\nCodigo: ";puts(codigo);
    		cout<<"\nIngrese horas de vuelo: "<<horasVuelo;
    		cout<<"\nIngrese horas de vuelo recomendadas por el fabricante: "<<horasVueloRecomendadas;
		}
    	~cAvion(){}
};

class cAvionPasajeros : public cAvion
{
	private:
    	int pasajerosVip, turistas;

    public:
    	cAvionPasajeros() : cAvion(){
    		pasajerosVip = turistas=0;
		}
    	void createAvion(){
    		cAvion::createAvion();
    		cout<<"\nIngrese numero de pasajeros VIP: ";cin>>pasajerosVip;
    		cout<<"\nIngrese numero de pasajeros turistas: ";cin>>turistas;
		}
    	void readAvion(){
    		cAvion::readAvion();
			cout<<"\nIngrese numero de pasajeros VIP: ";cin>>pasajerosVip;
    		cout<<"\nIngrese numero de pasajeros turistas: ";cin>>turistas;    		
		}
    	~cAvionPasajeros(){}
};

class cAvionCarga : public cAvion
{
	private:
    	float capacidadCarga;

    public:
    	cAvionCarga() : cAvion() {
    		capacidadCarga = 0;
		}
    	void createAvion(){
    		cAvion::createAvion();
    		cout<<"\nIngrese capacidad de carga del avion: ";cin>>capacidadCarga;
		}
    	void readAvion(){
			cAvion::readAvion();
    		cout<<"\nCapacidad de carga del avion: "<<capacidadCarga;		
		}
    	~cAC(){}
};
/*
A PARTIR DE AQUI PARA ABAJO HAY QUE SEGUIR CORRIGIENDO
*/
class cAeropuerto
{
    char nombre[10], direccion[10];
    int nd;
    int nm;
    cAvion *vAD[20]; //aviones disponibles
    cAvion *vAM[20]; //aviones a mantenimiento

    public:

    cAerop();
    void leer();
    void moverAvionesAMantenimento();
    void moverDisponibleAMantenimento();
    void moverMantenimentoADisponible();
    void recorerD(int pos);
    int BuscarD(char *c);
    void recorerM(int pos);
    int BuscarM(char *c);
    void mostrarAvionesDisponibles();
    void mostrarAvionesMantenimiento();
    void eliminarAvion();
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
        }while((n<1)||(n>20));
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
           vAD[i] = new cAvion;
           vAD[i] -> setTipo(1);
           vAD[i] -> leer();
       }
       else
       {
           vAD[i] = new cAvion;
           vAD[i] -> setTipo(2);
           vAD[i] -> leer();
       }
    }
    moverAvionesAMantenimento();
}
void cAerop::moverAvionesAMantenimento()
{
   int j=0;
   for(int i=1;i<=nd;i++)
       if(vAD[i]->getHV()<=vAD[i]->getHR())
       {
          j++;
          vAM[j] = new cAvion;
          vAM[j] = vAD[i];
       }
   nm=j;

}

//______________________________________________________________________________
//______________________________________________________________________________
int cAerop::BuscarM(char *c)
{
    int i=1;
    int p=-1;

    while((i<=nm)&&(p==-1))
    {
       if(strcpy(c,vAM[i]->getCodigo())==0)
           p=i;
       i++;
    }
    return(p);
}
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
      }while(h<vAM[pos]->getHR());
          nd+=1;
          vAD[nd] = new cAvion;
          vAD[nd] -> setHV(h);
          vAD[nd] = vAM[pos];
      recorerM(int pos);
   }
   }
}
void cAerop::recorerD(int pos)
{
    for(int i=1;i<nd;i++)
       if(pos==i)
       {
          vAD[i]=vAD[i+1];
          pos++;
       }
}

//______________________________________________________________________________

//______________________________________________________________________________
int cAerop::BuscarD(char *c)
{
    int i=1;
    int p=-1;

    while((i<=nd)&&(p==-1))
    {
       if(strcpy(c,vAD[i]->getCodigo())==0)
           p=i;
       i++;
    }
    return(p);
}

void cAerop::moverDisponibleAMantenimento()
{
   char c[10];
   int h;
   int pos;
   cout<<"\nIngrese codigo de avion: ";gets(c);
   pos=BuscarD();
   if(pos!=-1)
       {
          do{
            cout<<"\nReescriba horas de vuelo: ";cin>>h;
            }while(h>vAM[pos]->getHR());
          nm+=1;
          vAM[nm] = new cAvion;
          vAM[nm] -> setHV(h);
          vAM[nm] = vAD[pos];
          recorerD(pos);
       }
}


void cAerop::recorerM(int pos)
{
    for(int i=1;i<nm;i++)
       if(pos==i)
       {
          vAM[i]=vAM[i+1];
          pos++;
       }
}
void cAerop::mostrarAvionesDisponibles()
{
}
void cAerop::mostrarAvionesMantenimiento()
{
}
void cAerop::eliminarAvion()
{
}
cAerop::~cAerop()
{
}

int main(){
	
	getch();
	return 0;
}
