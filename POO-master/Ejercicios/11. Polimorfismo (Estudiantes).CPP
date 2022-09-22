#include <iostream.h>
#include <conio.h>
#include <string.h>
#include <stdio.h>
class cEstudiante
{
    int tipo; //a que clase pertenece cada estudiante
    char nom[20]; //nombre
    char c[10]; //codigo
    int a; //asistencia
    int lim; //limite de asistencia
    float n1,n2,n3; //nota parciales
    float p; //nota principal
    float s; //nota suspenso
    float acum; //Notas acumuladas
    int e;

    public:
    cEstudiante();
    void setLimite(int newL);
    void setTipo(int newT);
    int getTipo();
    float getAcum();

    virtual void leer();
    void leernotas();
    void ComprobarNotas();
    virtual void mostrar();
    ~cEstudiante();
};

cEstudiante::cEstudiante()
{
    strcpy(nom,"");
    strcpy(c,"");
    a=n1=n2=n3=p=s=0;
    lim=70;
    e=-1;
    acum=0;
    tipo=0;
}

void cEstudiante::setLimite(int newL)
{
    lim=newL;
}
void cEstudiante::setTipo(int newT)
{
    tipo=newT;
}
int cEstudiante::getTipo()
{
    return(tipo);
}
float cEstudiante::getAcum()
{
    return(acum);
}

void cEstudiante::leer()
{
    cout<<"\nIngrese nombre: ";gets(nom);
    cout<<"\nIngrese codigo: ";gets(c);
    do{
       cout<<"\nIngrese asistencia: ";cin>>a;
       }while((a<0)||(a>100));
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
   ComprobarNotas();
}
void cEstudiante::ComprobarNotas()
{
   /*
     1. Exonerado
     2. Reprobado por asistencia
     3. Aprobado
     4. Reprobado por notas

   */
   acum=n1+n2+n3;
   if((acum>=25)&&(a>=lim)){
        e=1;
        acum+=12;
        }
        else{
            if(a<lim){
              e=2;
              }
              else{
                 if(acum>=16){
                     do{
                        cout<<"\nIngrese nota principal: ";cin>>p;
                     }while((p<0)||(p>12));
                     acum+=p;
                     if(acum>=28){
                        e=3;
                        }
                        else{
                           do{
                              cout<<"\nIngrese nota suspenso: ";cin>>s;
                           }while((s<0)||(s>20));
                           acum/=2;
                           acum+=s;
                           if(acum>=28)
                              e=3;
                           else
                              e=4;
                        }
                 }
                 else{
                     if(acum<16){
                        do{
                              cout<<"\nIngrese nota suspenso: ";cin>>s;
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
    cout<<"\nNombre: ";puts(nom);
    cout<<"\nCodigo: ";puts(c);
    cout<<"\nAsistencia: "<<a;
    cout<<"\nLimite de asistencia: "<<lim;
    cout<<"\nAcumulado de la materia: "<<acum;
    if(e==1)
         cout<<"\nExonerado......";
    if(e==2)
         cout<<"\nReprobado por asistencia......";
    if(e==3)
         cout<<"\nAprobado......";
    if(e==4)
         cout<<"\nReprobado por notas......";
}
cEstudiante::~cEstudiante()
{
}

class cDep : public cEstudiante{
    char dep[10],uc[10],lug[10];
    public:
    cDep();
    void leer();
    void mostrar();
    ~cDep();
};
cDep::cDep():cEstudiante()
{
    strcpy(dep,"");
    strcpy(uc,"");
    strcpy(lug,"");
}
void cDep::leer()
{
    setLimite(50);
    cEstudiante::leer();
    cout<<"\nIngrese el deporte que practica: ";gets(dep);
    cout<<"\nIngrese el ultimo campeonato: ";gets(uc);
    cout<<"\nIngrese el lugar del ultimo campeonato: ";gets(lug);
}
void cDep::mostrar()
{
    cEstudiante::mostrar();
    cout<<"\nIngrese el deporte que practica: ";puts(dep);
    cout<<"\nIngrese el ultimo campeonato: ";puts(uc);
    cout<<"\nIngrese el lugar del ultimo campeonato: ";puts(lug);
}
cDep::~cDep()
{
}

class cArt : public cEstudiante
{
    char act[20];

    public:

    cArt();
    void leer();
    void mostrar();
    ~cArt();
};

cArt::cArt():cEstudiante()
{
     strcpy(act,"");
}
void cArt::leer()
{
    setLimite(60);
    cEstudiante::leer();
    cout<<"\nIngrese la actividad que practica: ";gets(act);
}
void cArt::mostrar()
{
    cEstudiante::mostrar();
    cout<<"\nIngrese la actividad que practica: ";puts(act);
}
cArt::~cArt()
{
}
class cCurso
{
    char mat[20];
    char cod[20];
    int ne; //numero de estudiantes
    cEstudiante *vEs[20];   //Vector de punteros que apunta a clase cEstudiante 

    public:

    cCurso();
    void leer();
    void leerEN(int pos);
    void leerArt(int pos);
    void leerDep(int pos);
    void promedioCurso();
    void mostrar();
    ~cCurso();
};
cCurso::cCurso()
{
    strcpy(mat,"");
    strcpy(cod,"");
    ne=0;
}
void cCurso::leer()
{
    cout<<"\nIngrese materia: ";gets(mat);
    cout<<"\nIngrese codigo: ";gets(cod);
    do{
       cout<<"\nIngrese el numero de estudiantes: ";cin>>ne;
    }while((ne<1)||(ne>30));

    for(int i=1;i<=ne;i++)
    {
        int t;
        cout<<"\n__________________________________________________";
        cout<<"\nESTUDIANTE "<<i<<endl;

        do{
           cout<<"\n1. Estudiante ";
           cout<<"\n2. Deportista ";
           cout<<"\n3. Artista ";
           cout<<"\nIngrese tipo: ";cin>>t;
        }while((t<1)||(t>3));

        if(t==1)
           leerEN(i);
        else
            if(t==2)
               leerDep(i);
            else
               leerArt(i);
    }
}
void cCurso::leerEN(int pos)
{
      vEs[pos] = new cEstudiante;  //guarda direccion de memoria de objetos de este tipo -> cEstudiante
      vEs[pos] -> setTipo(1);
      vEs[pos] -> leer();
}
void cCurso::leerDep(int pos)
{
      vEs[pos] = new cDep;     //guarda direccion de memoria de objetos de este tipo -> cDep
      vEs[pos] -> setTipo(2);
      vEs[pos] -> leer();
}
void cCurso::leerArt(int pos)
{
      vEs[pos] = new cArt;   //guarda direccion de memoria de objetos de este tipo -> cArt
      vEs[pos] -> setTipo(3);
      vEs[pos] -> leer();
}
void cCurso::promedioCurso()
{
    float acum=0;
    for(int i=1;i<=ne;i++)
         acum+=vEs[i]->getAcum();
    if(acum!=0)
       cout<<"\nEl promedio del curso es: "<<acum/ne;
}
void cCurso::mostrar()
{
     for(int i=1;i<=ne;i++)
     {
         cout<<"\n__________________________________________________";
         cout<<"\nESTUDIANTE "<<i<<endl;

         vEs[i] -> mostrar();
     }
}
cCurso::~cCurso()
{
   for (int i=1;i<=ne;i++)
      delete(vEs[i]);
   ne=0;
}
void main()
{
    cCurso *obj;
    obj = new cCurso;
    obj->leer();
    clrscr();
    obj->mostrar();
    obj->promedioCurso();
getch();
}