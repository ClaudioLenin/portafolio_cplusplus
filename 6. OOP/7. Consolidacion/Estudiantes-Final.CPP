#include <iostream.h>
#include <conio.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#define M 30

class cEstudiante{
      char nombre[M];
      char codigo[M];
      int asis;
      int lim;
      int tipo;
      int e;

      int n1;
      int n2;
      int n3;
      int p;
      int s;
      int acum;

      public:

      cEstudiante();

      int getAcum();
      int getEstado();
      char *getCodigo();
      void setLimite(int newLim);
      void setTipo(int newTipo);
      int getTipo();
      virtual void leer();
      void leernotas();
      virtual void mostrar();
      ~cEstudiante();


};
cEstudiante::cEstudiante()
{
    strcpy(nombre,"");
    strcpy(codigo,"");
    asis=n1=n2=n3=p=s=0;
    lim=70;
    tipo=0;
    e=0;
}
int cEstudiante::getEstado()
{
   return(e);
}
char *cEstudiante::getCodigo()
{
   return(codigo);
}
void cEstudiante::setTipo(int newTipo)
{
   tipo=newTipo;
}
int cEstudiante::getTipo()
{
   return(tipo);
}
void cEstudiante::setLimite(int newLim)
{
    lim=newLim;
}
int cEstudiante::getAcum()
{
    return(acum);
}
void cEstudiante::leer()
{
    cout<<"\nIngrese el nombre: ";gets(nombre);
    cout<<"\nIngrese el codigo: ";gets(codigo);
    do{
       cout<<"\nIngrese asistencia (0 - 100): ";cin>>asis;
       }while((asis<0)||(asis>100));
   leernotas();

}
void cEstudiante::leernotas()
{
    do{
        cout<<"\nIngrese primer parcial: ";cin>>n1;
    }while((n1<0)||(n1>8));
    do{
        cout<<"\nIngrese segundo parcial: ";cin>>n2;
    }while((n2<0)||(n2>10));
    do{
        cout<<"\nIngrese tercer parcial: ";cin>>n3;
    }while((n3<0)||(n3>10));
    acum=n1+n2+n3;

    if((acum>=25)&&(asis>=lim))
    {
         acum+=12;
         e=1;
    }
    else
    {
        if(asis<lim)
        {
            e=2;
        }
        else
        {
            if(acum>=16)
            {
                do{
                   cout<<"\nIngrese nota de examen principal: ";cin>>p;
                }while((p<0)||(p>12));
                acum+=p;
                if(acum>=28)
                {
                    e=3;
                }
                else
                {
                    do{
                        cout<<"\nIngrese nota de examen suspenso: ";cin>>s;
                    }while((s<0)||(s>20));
                    acum/=2;
                    acum+=s;
                    if(acum>=28)
                        e=3;
                    else
                        e=4;
                }
            }
            else
            {
                if(acum<16)
                {
                    do{
                        cout<<"\nIngrese nota de examen suspenso: ";cin>>s;
                    }while((s<0)||(s>20));
                    acum/=2;
                    acum+=s;
                    if(acum>=28)
                        e=3;
                    else
                        e=4;
                }
            }
        }

    }
}
void cEstudiante::mostrar()
{
    cout<<"\nNombre: ";puts(nombre);
    cout<<"\nCodigo: ";puts(codigo);
    cout<<"\nLimite de asistencia: "<<lim;
    cout<<"\nAsistencia: "<<asis;
    cout<<"\nAcumulado: "<<acum;
}
cEstudiante::~cEstudiante()
{
}
class cDep: public cEstudiante
{
    char deporte[M];
    char campeonato[M];
    char lugar[M];

    public:

    cDep();
    void leer();
    void mostrar();
    ~cDep();
};
cDep::cDep():cEstudiante()
{
    strcpy(deporte,"");
    strcpy(campeonato,"");
    strcpy(lugar,"");
}
void cDep::leer()
{
    setLimite(50);
    cEstudiante::leer();
    cout<<"\nDeporte que practica: ";gets(deporte);
    cout<<"\nUltimo campeonato: ";gets(campeonato);
    cout<<"\nLugar: ";gets(lugar);
}
void cDep::mostrar()
{
    cEstudiante::mostrar();
    cout<<"\nDeporte que practica: ";puts(deporte);
    cout<<"\nUltimo campeonato: ";puts(campeonato);
    cout<<"\nLugar: ";puts(lugar);
}
cDep::~cDep()
{
}
class cArt : public cEstudiante
{
     char actividad[M];

     public:

     cArt();
     void leer();
     void mostrar();
     ~cArt();
};
cArt::cArt():cEstudiante()
{
     strcpy(actividad,"");
}
void cArt::leer()
{
     setLimite(60);
     cEstudiante::leer();
     cout<<"\nActividad que practica: ";gets(actividad);
}
void cArt::mostrar()
{
     cEstudiante::mostrar();
     cout<<"\nActividad que practica: ";puts(actividad);
}
cArt::~cArt()
{
}
class cCurso
{
     char materia[M];
     char codigo[M];
     cEstudiante *vEs[M];
     int n;

     public:

     cCurso();
     void leer();
     void leerE(int pos,int t);
     void leerD(int pos,int t);
     void leerA(int pos,int t);
     void mostrarAprobados();
     void mostrarExonerados();
     void mostrarReprobadosXasistencia();
     void mostrarReprobadosXnotas();
     void mostrarTodo();
     void eliminarUno();
     void recorrerVector(int pos);
     void promedio();
     int Buscar(char *cd);
     ~cCurso();
};
cCurso::cCurso()
{
   strcpy(materia,"");
   strcpy(codigo,"");
   n=0;
}

void cCurso::leer()
{
   int menu();
   cout<<"\nIngrese nombre de la materia: ";gets(materia);
   cout<<"\nIngrese codigo de la materia: ";gets(codigo);
   do{
      cout<<"\nIngrese cantidad de estudiantes: ";cin>>n;
   }while((n<1)||(n>M));

   int es;

   for(int i=1;i<=n;i++)
   {
      cout<<"\n\t\t\tESTUDIANTE "<<i<<endl;
      cout<<"_________________________________\n";
      es=menu();
      if(es==1)
         leerE(i,es);
      else
         if(es==2)
            leerD(i,es);
         else
           if(es==3)
               leerA(i,es);

   }
}
int menu()
{
      int op=-1;
      do{
         cout<<"\n1. Estudiante Regular\n";
         cout<<"2. Estudiante Deportista\n";
         cout<<"3. Estudiante Artista\n";
         cout<<"Escoja opcion: ";cin>>op;
      }while((op<1)||(op>3));
      return(op);
}
void cCurso::leerE(int pos,int t)
{
    vEs[pos] = new cEstudiante;
    vEs[pos] -> leer();
    vEs[pos] -> setTipo(t);
}
void cCurso::leerD(int pos,int t)
{
    vEs[pos] = new cDep;
    vEs[pos] -> leer();
    vEs[pos] -> setTipo(t);
}
void cCurso::leerA(int pos,int t)
{
    vEs[pos] = new cArt;
    vEs[pos] -> leer();
    vEs[pos] -> setTipo(t);
}

void cCurso::mostrarAprobados()
{
 for(int i=1;i<=n;i++)
    {
        if(vEs[i]->getEstado()==3){
           cout<<"\n_____________________________________";
           vEs[i] -> mostrar();
           cout<<"\n_____________________________________";
           }
    }
}
void cCurso::mostrarExonerados()
{
 for(int i=1;i<=n;i++)
    {
        cout<<vEs[i]->getEstado()<<endl;
        if(vEs[i]->getEstado()==1)
        {
           cout<<"\n_____________________________________";
           vEs[i] -> mostrar();
           cout<<"\n_____________________________________";
        }
    }
}
void cCurso::mostrarReprobadosXasistencia()
{
    for(int i=1;i<=n;i++)
    {
        if(vEs[i]->getEstado()==2)
        {
           cout<<"\n_____________________________________";
           vEs[i] -> mostrar();
           cout<<"\n_____________________________________";
        }
    }
}
void cCurso::mostrarReprobadosXnotas()
{
 for(int i=1;i<=n;i++)
    {
        if(vEs[i]->getEstado()==4)
        {
           cout<<"\n_____________________________________";
           vEs[i] -> mostrar();
           cout<<"\n_____________________________________";
        }
    }
}
void cCurso::mostrarTodo()
{
   for(int i=1;i<=n;i++)
   {
      cout<<"\n\t\t\tESTUDIANTE "<<i<<endl;
      cout<<"_________________________________\n";
      vEs[i] ->mostrar();
      cout<<"\n_________________________________\n";
   }
}
void cCurso::eliminarUno()
{
    char c[M];
    int pos;
    cout<<"\nIngrese codigo: ";gets(c);
    pos=Buscar(c);
    if(pos!=-1)
    {
       delete(vEs[pos]);
       recorrerVector(pos);
       n--;
    }
    else
    {
       cout<<"\nEstudiante no encontrado......";
    }

}
int cCurso::Buscar(char *cd)
{
    int i=1;
    int p=-1;
    while((i<=n)&&(p==-1))
    {
       if(vEs[i]->getCodigo()==cd)
            p=i;
       i++;
    }
    return(p);
}
void cCurso::promedio()
{
    int acum=0;
    for(int i=1;i<=n;i++)
      acum+=vEs[i]->getAcum();

    if(acum!=0)
       cout<<"\nEl promedio del curso es: "<<acum/n;
}

void cCurso::recorrerVector(int pos)
{
   for(int i=1;i<=n;i++)
      if(i==pos)
      {
         vEs[i]=vEs[i+1];
         pos++;
      }
}
cCurso::~cCurso()
{
    for(int i=1;i<=n;i++)
       delete(vEs[i]);
    n=0;
}
void main()
{
   cCurso *oCurso;
   oCurso = new cCurso;
   oCurso -> leer();
   oCurso -> mostrarTodo();
   clrscr();
   int op;
do{
   do{
      cout<<"\n1.- Mostrar estudiantes exonerados";
      cout<<"\n2.- Mostrar estudiantes reprobados por asistencia";
      cout<<"\n3.- Mostrar estudiantes aprobados";
      cout<<"\n4.- Mostrar estudiantes reprobados por notas";
      cout<<"\n5.- Elminar todos los estudiantes";
      cout<<"\n6.- Eliminar un estudiante";
      cout<<"\n7.- Mostrar Todo";
      cout<<"\n8.- Promedio del Curso";
      cout<<"\n9.- Salir";
      cout<<"\nEscoja una opcion: ";
      cin>>op;
   }while((op<1)||(op>9));
   switch(op){
         case 1:
               oCurso -> mostrarExonerados();
               break;
         case 2:
               oCurso -> mostrarReprobadosXasistencia();
               break;
         case 3:
               oCurso -> mostrarAprobados();
               break;
         case 4:
               oCurso -> mostrarReprobadosXnotas();
               break;
         case 5:
               oCurso -> ~cCurso();
               break;
         case 6:
               oCurso -> eliminarUno();
               break;
         case 7:
               oCurso -> mostrarTodo();
               break;
         case 8:
               oCurso -> promedio();
               break;
   }
   system("pause");
   clrscr();
}while(op!=9);
   getch();
}
