#include <iostream.h>
#include <conio.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

class avion
  {
    private:
    char marca[20];
    char modelo[20];
    int af;
    int hv;
    int hvr;
    int tipo;
    char codigo[10];  
    public:
    avion();
    virtual void leer();
    virtual void mostrar();
    void sethv(int h);
    int gethv();
    int gethvr();
    void settipo(int tp);
    int gettipo(); 
    char *getcodigo();
    virtual int promedio() ; 
    ~avion();   
  };
 
avion::avion()
  {
   strcpy(marca,"");
   strcpy(modelo,"");
   strcpy(codigo,""); 
   af=0;
   hv=0;
   hvr=0;
   tipo=0;
   cout<<"\nConstruyendo avion"; 
  };
 
void avion::leer()
  {
   cout<<"\nIngrese la marca: ";
   gets(marca);
   cout<<"\nIngrese el modelo: ";
   gets(modelo);
   cout<<"\nIngrese el codigo: ";
   gets(codigo);
   cout<<"\nIngrese el anio de fabricacion: ";
   cin>>af;
   cout<<"\nIngrese las horas de vuelo: ";
   cin>>hv;
   cout<<"\nIngrese las horas de vuelo recomendadas: ";
   cin>>hvr;
  };


void avion::mostrar()
  {
   cout<<"\nMarca: ";
   puts(marca);
   cout<<"Modelo: ";
   puts(modelo);
   cout<<"Codigo: ";
   puts(codigo);
   cout<<"Anio de fabricacion: "<<af;
   cout<<"\nHoras de vuelo: "<<hv;
   cout<<"\nHoras de vuelo recomendadas: "<<hvr;
  };
 
int avion::promedio()
  {
   return(-1);
  };

void avion::sethv(int h)
  {
   hv=h;
  };

int avion::gethv()
  {
   return(hv);
  };     

int avion::gethvr()
  {
   return(hvr);
  };

void avion::settipo(int tp)
  {
   tipo=tp;
  };
   
int avion::gettipo()
  {
   return(tipo);
  };
char *avion::getcodigo()
  {
   return(codigo);
  };

avion::~avion()
  {
    cout<<"\nDestruyendo avion";
    getch();
  }


class avionC : public avion
  {
   private: 
   float cap;
   public:
   avionC();
   void leer();
   void mostrar();
   float getcarga();
   void set_cap(int nc); 
   ~avionC();  
  };
   
avionC::avionC() : avion()
  { 
   cout<<"\nConstruyendo avion de carga";
   cap=0;
  };

void avionC::leer()
  {
   avion::leer();
   cout<<"\nIngrese la capacidad de carga: ";
   cin>>cap;
  };

void avionC::mostrar()
  {
   avion::mostrar();
   cout<<"\nCapacida de carga: "<<cap; 
  };

float avionC::getcarga()
  {
   return(cap);
  };

void avionC::set_cap(int c)
  {
    cap=c;
  };


avionC::~avionC()
  {
   cout<<"\nDestruyendo avion de carga";
   getch();
  };



class avionP : public avion
  {
  private:
   int nTur;
   int nVIP;  
  public:
    avionP();
    void leer();
    void mostrar();
    int promedio();
    int get_nTur();
    int get_nVIP();
    void set_nTur(int nt);
    void set_nVIP(int nv); 
    ~avionP(); 
  };

avionP::avionP() : avion()
  { 
    nTur=0;
    nVIP=0; 
    cout<<"\nCostruyendo avion de pasajeros";
  };

void avionP::leer()
  {
   avion::leer();
   cout<<"\nIngrese el numero de pasajeros clase turista: ";
   cin>>nTur;
   cout<<"\nIngrese el numero de pasajeros clase VIP: ";
   cin>>nVIP;
  };


int avionP::promedio()
  {
   int tp; 
   tp=(nTur+nVIP);
   return(tp);
  };


void avionP::mostrar()
  {
   avion::mostrar();
   cout<<"\nNumero de pasajeros clase turista: "<<nTur;
   cout<<"\nNumero de pasajeros clase VIP: "<<nVIP; 
  };

int avionP::get_nTur()
  {
   return(nTur);
  };

int avionP::get_nVIP()
  {
   return(nVIP);
  };

void avionP::set_nTur(int nt)
  {
    nTur=nt;
  };

void avionP::set_nVIP(int nv)
  {
   nVIP=nv;
  };


avionP::~avionP()
  {
   cout<<"\nDestruyendo avion de pasajeros";
   getch();
  };



class aeropuerto
  {
    private:
     char nombre[20];
     char direccion[20];
     int na;
     int nam;
     avion *vAD[30];
     avion *vAM[30];
    public:
     aeropuerto();
     void ingresar_datos();
     void ingresar_aviones();
     void leer_avion(int pos,int t);
     void ingresar_nuevo();
     void most_prom();
     int compara(int np, int nb);
     void enviar_mant();
     int evaluar(int p);
     void mover_vector(int p);
     void mant_dispon();
     void mantenimiento(int p);
     void mover_vm(int p);
     void avion_dest();
     int buscar_cod(char cod[]);
     void mover_vect(int pos);
     void mostrar_datos();
     void mostrar_aviones(); 
     int promedio_total();
     void menu();
     void funciones(int op);
     ~aeropuerto();
     void dest_AvDisp();
     void dest_AvMant();
  };

aeropuerto::aeropuerto()
  {
   strcpy(nombre,"");
   strcpy(direccion,"");
   na=0;
   nam=0;
   cout<<"\nConstruyendo aeropuerto";
  };


void aeropuerto::ingresar_datos()
  {
    cout<<"\nIngresar nombre del aeropuerto:" ;
    gets(nombre);
    cout<<"\nIngrese direccion del aeropuerto: ";
    gets(direccion);
    cout<<"\nIngrese el numero de aviones: ";
    cin>>na;
    ingresar_aviones();
  };

void aeropuerto::ingresar_aviones()
  {
   int op;
   cout<<"\nEscoja el tipo de avion";
   for (int i=0;i<na;i++)
    {
     cout<<"\n1. Avion de carga";
     cout<<"\n2. Avion de pasajeros";
     cout<<"\nopcion: ";
     cin>>op;
     leer_avion(i,op);
    };
  };

void aeropuerto::leer_avion(int pos,int t)
  {
    switch(t)
    {
     case 1: vAD[pos]=new avionC;
             vAD[pos]->leer();
             vAD[pos]->settipo(t);
             break;

     case 2: vAD[pos]=new avionP;
             vAD[pos]->leer();
             vAD[pos]->settipo(t);
             break;
      default: cout<<"\n''Error de ingreso''";
    };
  };



void aeropuerto::ingresar_nuevo()
  {
   int t;
   int p;
   if (na<30)
    {
      p=na++;
      cout<<"\nEscoja el tipo de avion";
      cout<<"\n1. Avion de carga";
      cout<<"\n2. Avion de pasajeros";
      cout<<"\nopcion: ";
      cin>>t;
      leer_avion(p,t);
    }
    else
      cout<<"\nNo existe espacio para ingreasar un nuevo avion";

  };




void aeropuerto::most_prom()
  {
   int ntp;
   int prt;
   int c;
   cout<<"\nIngrese una cantidad promedio de pasajeros: ";
   cin>>ntp;
   prt=promedio_total();
   c=compara(prt,ntp);
   if(c==1)
       cout<<"\nEl promedio de pasajeros mayor al ingresado por el usuario es: "<<prt;
        else
          cout<<"\nNo existe una cantidad promedio aproximada a la ingresada";
  };

int aeropuerto::promedio_total()
  {
   int s=0;
   int ca=0;
   for (int i=0;i<na;i++)
     {
       if(vAD[i]->gettipo()==2)
             
          {
            s+=(vAD[i]->promedio());
            ca++;
          };
     };
   if(ca>=1)
        return(s/ca);
       else
         return(0);
  };

int aeropuerto::compara(int np, int nb)
  {
    if(np>=nb)
       return(1);
      else
        return(0);
  };



void aeropuerto::enviar_mant()
  {
    int cont=0;

    for(int i=0;i<na;i++)
     {
        if(evaluar(i)==1)
          {
           vAM[cont++]=vAD[i];
           mover_vector(i);   
           na--;
           cout<<"\nAvion "<<i<<" enviado a mantenimiento";
          };      
     };  
     
    nam=cont;
 
  };

int aeropuerto::evaluar(int p)
  {
   if (vAD[p]->gethv() > vAD[p]->gethvr()) 
         return(1); 
           else
             return(0);
  }; 
   
void aeropuerto::mover_vector(int p)
  {
   while(p<na)
    {
      vAD[p]= vAD[++p];
    };

  };



void aeropuerto::mant_dispon()
  { 
   char cb[10];
   cout<<"\nIngrese el codigo a buscar: ";
   gets(cb);
   for(int i=0;i<nam;i++)
    {
     if(strcmp(vAM[i]->getcodigo(),cb)==0)
        {
         mantenimiento(i); 
         vAM[i]=vAD[na++];
         mover_vm(i);
         nam--; 
        } 
    }
   
  };


void aeropuerto::mantenimiento(int p)
  {

   //if (vAM[p]->gettipo()==1)*/

   vAM[p]->sethv(0);

  /*
           vAM[p]->set_cap(0);
      else
         if (vAM[p]->gettipo()==2)
           {
              vAM[p]->set_nTur(0);
              vAM[p]->set_nVIP(0);
            }                     */
  };

void aeropuerto::mover_vm(int p)
  {
     while(p<nam)
        {
           vAM[p]=vAM[++p];
        };     
  };



void aeropuerto::avion_dest()
  {
   char cb[10];
   int p;
   cout<<"\nIngrese el codigo del avion accidentado: ";
   gets(cb);
   p=buscar_cod(cb);
   if (p!=-1)
     {
      delete (vAD[p]);
      mover_vect(p); 
     }
  };

int aeropuerto::buscar_cod(char cod[])
  {
   int i=0;
   int pos=-1; 
   while ((i<na)&&(pos==-1))
     {
      if(strcmp(vAD[i]->getcodigo(),cod)==0) 
                pos=i;
      i++; 
     };
   return(pos);
  };

void aeropuerto::mover_vect(int pos)
  {
   for(int i=pos;i<(na-1);i++)
       vAD[i]=vAD[i++];

  }; 


void aeropuerto::mostrar_datos()
  {   
    cout<<"\nNombre del aeropuerto:" ;
    puts(nombre);
    cout<<"Direccion del aeropuerto: ";
    puts(direccion);
    cout<<"\tAviones disponibles: \n";
    mostrar_aviones();
         
  }; 
void aeropuerto::mostrar_aviones()
  {
   if (na >=1){ 
        for(int i=0;i<na;i++)
              vAD[i]->mostrar();
         }
        else
           cout<<"\nActualmente no hay aviones disponibles";
    cout<<"\n\tAviones en mantenimiento: \n";
    if (nam>=1)   
        {
        for(int j=0;j<nam;j++)
              vAM[j]->mostrar();
        }
        else 
           cout<<"\nActualmente no hay aviones en mantenimiento";


  }; 

void aeropuerto::menu()
  {
   int op;
   char sn;
   cout<<"\nIngreso de datos: ";
   ingresar_datos();  
   do
   {
    clrscr();
    cout<<"\n1. Ingresar nuevo avion";
    cout<<"\n2. Promedio de pasajeros segun cantidad ingresada";
    cout<<"\n3. Enviar aviones a mantenimiento";
    cout<<"\n4. Enviar aviones de mantenimiento a disponibles";
    cout<<"\n5. Eliminar avion accidentado";
    cout<<"\n6. Mostrar todos los datos";
    cin>>op; 
    funciones(op);
    cout<<"\nRelizar otra accion (s/n): ";  
    cin>>sn;
   }while((sn=='s')||(sn=='S'));
  };
    

void aeropuerto::funciones(int op)
  {
   switch(op)
    {
     case 1: ingresar_nuevo();
             break; 
     case 2: most_prom();
             break;
     case 3: enviar_mant();
             break;
     case 4: mant_dispon();
             break; 
     case 5: avion_dest();
             break;
     case 6: mostrar_datos();
             break;
     default: "\n''Error de ingreso''"; 
    }
  };

aeropuerto::~aeropuerto()
  {
   cout<<"\nEliminando aeropuerto";
   cout<<"\nDestruyendo lista de aviones"; 
   dest_AvDisp();
   dest_AvMant();
   getch();  
  };

void aeropuerto::dest_AvDisp()
   {
      for(int i=0;i<na;i++)
      {
        cout<<"\nEliminando disp.";
        delete(vAD[i]);
      }       
   };
void aeropuerto::dest_AvMant()
   {
     for(int i=0;i<nam;i++)
      {
       cout<<"\nEliminando mant."; 
       delete(vAM[i]);
      }
   };

void main()
  {
   aeropuerto Aer;
   Aer.menu();
  }
