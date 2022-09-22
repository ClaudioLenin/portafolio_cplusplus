#include <iostream.h>
#include <conio.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#define MAX 40
class cEst{

          char nom[MAX];
          char cod[MAX];
          int n1;  //primer parcial
          int n2;  //segundo parcial
          int n3;  //tercer parcial
          int p;   //examen principal
          int s;   //Examen suspencion
          int as;  //Porcentaje de asistencia
          int acum;//Total de notas acumuladas
          int lim;  //Limite de asistencia
     public:

          cEst();
          int getEs();
          int getAcum();
          void setLimite(int l);
          int getLimite();

          void leerdatos();
          void mostrardatos();
          void primero();
          void segundo();
          void tercero();
          void principal();
          void suspenso();
          int comp_asistencia();

          ~cEst();
};

cEst::cEst(){
    strcpy(nom,"");
    strcpy(cod,"");
    n1=n2=n3=p=s=as=acum=0;
}
//______________________________________________________________________________
void cEst::setLimite(int l){
   lim=l;
}
int cEst::getLimite(){
   return(lim);
}

int cEst::getAcum(){
    return(acum);
}
//______________________________________________________________________________


void cEst::leerdatos(){
   cout<<"\nIngrese el nombre: ";
   gets(nom);
   cout<<"\nIngrese el codigo: ";
   gets(cod);
   do{
      cout<<"\nIngrese porcentaje de asistencia (0 - 100): ";
      cin>>as;
   }while((as<0)||(as>100));
   cout<<"\n\t\t\tPRIMER PARCIAL\n";
   primero();
   cout<<"\n\t\t\tSEGUNDO PARCIAL\n";
   segundo();
   cout<<"\n\t\t\tTERCER PARCIAL\n";
   tercero();
   acum=n1+n2+n3;
   setLimite(70);
}
void cEst::primero(){
   do{
      cout<<"\nIngrese Nota: ";
      cin>>n1;
      }while((n1<0)||(n1>8));
}
void cEst::segundo(){
   do{
      cout<<"\nIngrese Nota: ";
      cin>>n2;
      }while((n2<0)||(n2>10));
}
void cEst::tercero(){
   do{
      cout<<"\nIngrese Nota: ";
      cin>>n3;
      }while((n3<0)||(n3>10));
}
int cEst::comp_asistencia(){

    cout<<getLimite();
    //COMPRUEBA EXONERACION
    if((as>=getLimite())&&(acum>=25)){
        acum=acum+12;
        return(1);
        }

    //COMPRUEBA ASISTENCIA
    if(as<getLimite())
        return(2);

    //COMPRUEBA APROBACION POR NOTAS
    if(acum>=16){
       principal();
       if(acum>=28){
          return(3);
       }
       else{
          suspenso();
          if(acum>=28)
              return(3);
          else
              return(4);
       }
    }

    //COMPRUEBA APROBACION POR NOTAS DIRECTO A SUSPENSION
    if(acum<=15){
       suspenso();
       if(acum>=28)
          return(3);
       else
          return(4);
    }

    return(4);

}
void cEst::principal(){
      do{
        cout<<"\nIngrese examen principal: ";
        cin>>p;
        }while((p<1)||(p>12));
    acum=acum+p;
}
void cEst::suspenso(){
    do{
       cout<<"\nIngrese examen suspension: ";
       cin>>s;
    }while((s<1)||(s>20));
    acum=(acum/2)+s;
}

void cEst::mostrardatos(){
   cout<<"\nNombre: ";
   puts(nom);
   cout<<"\nCodigo: ";
   puts(cod);
   cout<<"\nAcumulado: ";
   cout<<acum;
   cout<<"\nPromedio: ";
   cout<<acum/2;
   if(comp_asistencia()==1)
      cout<<"\nEXONERADO..................";
   else
      if(comp_asistencia()==2)
         cout<<"\nREPROBADO POR ASISTENCIA.................";
      else
         if(comp_asistencia()==3)
            cout<<"\nAPROBADO..............";
         else
            cout<<"\nREPROBADO POR NOTAS...............";
   cout<<"\nAsistencia: "<<as;
}

cEst::~cEst(){
}
class cDep : public cEst{
         char dep[MAX];
         char uc[MAX];
         char lug[MAX];

     public:
         cDep();
         void leerdatos();
         void mostrardatos();

         ~cDep();
};

cDep::cDep():cEst(){
     strcpy(dep,"");
     strcpy(uc,"");
     strcpy(lug,"");
}


void cDep::leerdatos(){
     cEst::leerdatos();
     cout<<"\nDeporte que practica: ";
     gets(dep);
     cout<<"\nUltimo Campeonato: ";
     gets(uc);
     cout<<"\nLugar de Campeonato: ";
     gets(lug);
     setLimite(50);
}
void cDep::mostrardatos(){
     cEst::mostrardatos();
     cout<<"\nDeporte que practica: ";
     puts(dep);
     cout<<"\nUltimo Campeonato: ";
     puts(uc);
     cout<<"\nLugar de Campeonato: ";
     puts(lug);
}

cDep::~cDep(){
}
class cArt : public cEst{
        char prac[MAX];
    public:

        cArt();

        void leerdatos();
        void mostrardatos();
        ~cArt();
};

cArt::cArt():cEst(){
     strcpy(prac,"");
}
//______________________________________________________________________________
void cArt::leerdatos(){
     cEst::leerdatos();
     cout<<"\nArte que practica: ";
     gets(prac);
     setLimite(60);
}
void cArt::mostrardatos(){
     cEst::mostrardatos();
     cout<<"\nArte que practica: ";
     puts(prac);
}

cArt::~cArt(){
}
class cCurso{
        char mat[MAX];
        char cod[MAX];

        int nn;
        int nd;
        int na;

        cEst vEs[MAX];
        cDep vEd[MAX];
        cArt vEa[MAX];


   public:
        cCurso();


        void ing_curso();
        void ing_estudiantes();   //Ingresa todos los estudiantes
        void mostrar_exonerados();  //muestra todos los estudiantes exonerados
        void mostrar_aprobados();   //muestra todos los estudiantes aprobados
        void mostrar_reprobados();   //muestra todos los estudiantes reprobados
        void reprobados_por_asistencia();   //muestra todos los estudiantes reprobados x asistencia
        void promedios_curso();

        ~cCurso();
};

cCurso::cCurso(){
    strcpy(mat,"");
    strcpy(cod,"");
    nn=nd=na=0;
}

void cCurso::ing_curso(){
     cout<<"\nMateria: ";
     gets(mat);
     cout<<"\nCodigo de Materia: ";
     gets(cod);
     ing_estudiantes();
}
void cCurso::ing_estudiantes(){   //Ingresa todos los estudiantes
     int i;
     do{
        cout<<"\nCantidad de Estudiantes Regulares: ";
        cin>>nn;
        }while((nn<1)||(nn>MAX));
     for(i = 1;i <= nn;i ++){
        cout<<"\n__________________________________________________\n";
        cout<<"ESTUDIANTE "<<i<<endl;
        cout<<"\n__________________________________________________\n";
        vEs[i].leerdatos();
     }


     do{
        cout<<"\nCantidad de Estudiantes Deportistas: ";
        cin>>nd;
        }while((nd<1)||(nd>MAX));
     for(i = 1;i <= nd;i ++){
        cout<<"\n__________________________________________________\n";
        cout<<"ESTUDIANTE "<<i<<endl;
        cout<<"\n__________________________________________________\n";
        vEd[i].leerdatos();
     }
     do{
        cout<<"\nCantidad de Estudiantes Artistas: ";
        cin>>na;
        }while((na<1)||(na>MAX));
     for(i = 1;i <= na;i ++){
        cout<<"\n__________________________________________________\n";
        cout<<"ESTUDIANTE "<<i<<endl;
        cout<<"\n__________________________________________________\n";
        vEa[i].leerdatos();
     }
}
void cCurso::mostrar_exonerados(){  //muestra todos los estudiantes exonerados
    cout<<"\n\t\t\tEXONERADOS\n";
    int i;
    for(i = 1;i <= nn;i ++)
       if(vEs[i].comp_asistencia()==1){
        cout<<"\n__________________________________________________\n";
        vEs[i].mostrardatos();
        cout<<"\n__________________________________________________\n";
       }
    for(i = 1;i <= nd;i ++)
       if(vEd[i].comp_asistencia()==1){
        cout<<"\n__________________________________________________\n";
        vEd[i].mostrardatos();
        cout<<"\n__________________________________________________\n";
       }
    for(i = 1;i <= na;i ++)
       if(vEa[i].comp_asistencia()==1){
        cout<<"\n__________________________________________________\n";
        vEa[i].mostrardatos();
        cout<<"\n__________________________________________________\n";

       }

}
void cCurso::reprobados_por_asistencia(){   //muestra todos los estudiantes reprobados x asistencia
    cout<<"\n\t\tREPROBADOS POR ASISTENCIA\n";
    int i;
    for(i = 1;i <= nn;i ++)
       if(vEs[i].comp_asistencia()==2){
        cout<<"\n__________________________________________________\n";
        vEs[i].mostrardatos();
        cout<<"\n__________________________________________________\n";
       }
    for(i = 1;i <= nd;i ++)
       if(vEd[i].comp_asistencia()==2){
        cout<<"\n__________________________________________________\n";
        vEd[i].mostrardatos();
        cout<<"\n__________________________________________________\n";
       }
    for(i = 1;i <= na;i ++)
       if(vEa[i].comp_asistencia()==2){
        cout<<"\n__________________________________________________\n";
        vEa[i].mostrardatos();
        cout<<"\n__________________________________________________\n";

       }
}
void cCurso::mostrar_aprobados(){  //muestra todos los estudiantes aprobados
    cout<<"\n\t\t\tAPROBADOS\n";
    int i;
    for(i = 1;i <= nn;i ++)
       if(vEs[i].comp_asistencia()==3){
        cout<<"\n__________________________________________________\n";
        vEs[i].mostrardatos();
        cout<<"\n__________________________________________________\n";
       }
    for(i = 1;i <= nd;i ++)
       if(vEd[i].comp_asistencia()==3){
        cout<<"\n__________________________________________________\n";
        vEd[i].mostrardatos();
        cout<<"\n__________________________________________________\n";
       }
    for(i = 1;i <= na;i ++)
       if(vEa[i].comp_asistencia()==3){
        cout<<"\n__________________________________________________\n";
        vEa[i].mostrardatos();
        cout<<"\n__________________________________________________\n";

       }
}
void cCurso::mostrar_reprobados(){   //muestra todos los estudiantes reprobados
    cout<<"\n\t\t\tREPROBADOS\n";
    int i;
    for(i = 1;i <= nn;i ++)
       if(vEs[i].comp_asistencia()==4){
        cout<<"\n__________________________________________________\n";
        vEs[i].mostrardatos();
        cout<<"\n__________________________________________________\n";
       }
    for(i = 1;i <= nd;i ++)
       if(vEd[i].comp_asistencia()==4){
        cout<<"\n__________________________________________________\n";
        vEd[i].mostrardatos();
        cout<<"\n__________________________________________________\n";
       }
    for(i = 1;i <= na;i ++)
       if(vEa[i].comp_asistencia()==4){
        cout<<"\n__________________________________________________\n";
        vEa[i].mostrardatos();
        cout<<"\n__________________________________________________\n";

       }
}

void cCurso::promedios_curso(){
    int pr1=0;
    int i;
    for(i = 1;i <= nn;i ++){
        pr1+=vEs[i].getAcum();
     }
    for(i = 1;i <= nd;i ++){
        pr1+=vEd[i].getAcum();
     }
    for(i = 1;i <= na;i ++){
        pr1+=vEa[i].getAcum();
     }

    cout<<"\nEl promedio Acumulado del curso es: "<<pr1/(nn+na+nd);
    cout<<"\nEl promedio de rendimiento del curso es: "<<pr1/2<<endl;
}


cCurso::~cCurso(){
}
void main(){
   cCurso c;//invoca al costructor
   int op;

   c.ing_curso();

 do{
   do{
       cout<<"\n\t\tMENU DE OPCIONES\n";
       cout<<"___________________________________________________________\n";
       cout<<"1.- Mostrar Promedios del curso\n";
       cout<<"2.- Mostrar Estudiantes Exonerados\n";
       cout<<"3.- Mostrar Estudiantes Aprobados\n";
       cout<<"4.- Mostrar Estudiantes Reprobados por notas\n";
       cout<<"5.- Mostrar Estudiantes Reprobados por asistencia\n";
       cout<<"6.- Salir\n";
       cin>>op;
       switch(op){
                case 1:
                       clrscr();
                       c.promedios_curso();
                       break;
                case 2:
                       c.mostrar_exonerados();
                       break;
                case 3:
                       c.mostrar_aprobados();
                       break;
                case 4:
                       c.mostrar_reprobados();
                       break;
                case 5:
                       c.reprobados_por_asistencia();
                       break;
       }
       system("pause");
       clrscr();
   }while((op<1)||(op>6));
   }while(op!=6);

   c.~cCurso();

   getch();
}