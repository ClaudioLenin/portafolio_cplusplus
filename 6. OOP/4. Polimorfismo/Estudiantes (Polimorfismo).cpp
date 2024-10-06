#include<iostream>
#include <conio.h>
#include <string.h>
#include <stdio.h>
using namespace std;
void clrscr();
void clrscr() {
    system("cls");
}

class cEstudiante{
	private:
    	char nombre[20], codigo[10];
    	int asistencia, tipo, limiteAsistencia, estado;
    	float nota1,nota2,nota3, acumuladoNotas, examenPrincipal, examenSuspenso;
    public:
    	cEstudiante(){
    		strcpy(nombre,"");
    		strcpy(codigo,"");
    		acumuladoNotas = nota1 = nota2 = nota3 = examenPrincipal = examenSuspenso = tipo = 0;
    		limiteAsistencia = 70;
    		examenSuspenso = -1;
		}
		void setLimiteAsistencia(int newLimite){limiteAsistencia = newLimite;}
    	void setTipo(int newTipo){tipo = newTipo;}
    	int getTipo(){return(tipo);}
    	float getAcumuladoNotas(){return(acumuladoNotas);}
    	
    	virtual void createEstudiante(){
    		cout<<"\nIngrese nombre: ";cin.ignore();gets(nombre);
    		cout<<"\nIngrese codigo: ";cin.ignore();gets(codigo);
			cout<<"\nIngrese asistencia: ";cin>>asistencia;
			cout<<"\nIngrese primer parcial: ";cin>>nota1;
			cout<<"\nIngrese segundo parcial: ";cin>>nota2;
			cout<<"\nIngrese tercer parcial: ";cin>>nota3;
			comprobarCalificaciones();	
		}
		virtual void readEstudiante(){
    		cout<<"\nNombre: ";puts(nombre);
    		cout<<"\nCodigo: ";puts(codigo);
    		cout<<"\nAsistencia: "<<asistencia;
    		cout<<"\nLimite de asistencia: "<<limiteAsistencia;
    		cout<<"\nAcumulado de la materia: "<<acumuladoNotas;
    		if(estado == 1)cout<<"\nExonerado......";
    		if(estado == 2)cout<<"\nReprobado por asistencia......";
    		if(estado == 3)cout<<"\nAprobado......";
    		if(estado == 4)cout<<"\nReprobado por notas......";
		}
		void comprobarCalificaciones(){
			/*
    		1. Exonerado
     		2. Reprobado por asistencia
     		3. Aprobado
     		4. Reprobado por notas
   			*/
   			acumuladoNotas = nota1 + nota2 + nota3;
   			if((acumuladoNotas >= 25) && (asistencia >= limiteAsistencia)){
        		estado = 1;
        		acumuladoNotas += 12;
    		}else if(asistencia < limiteAsistencia)
        		estado=2;
    		else if(acumuladoNotas >= 16){
        		do{
        			cout<<"\nIngrese nota principal: ";cin>>examenPrincipal;
        		}while((examenPrincipal < 0) || (examenPrincipal > 12));
        		acumuladoNotas += examenPrincipal;
        		if(acumuladoNotas >= 28) estado=3;
				else{
            		do{
                		cout<<"\nIngrese nota suspenso: ";cin>>examenSuspenso;
            		}while((examenSuspenso < 0) || (examenSuspenso > 20));
            		acumuladoNotas /= 2;
            		acumuladoNotas += examenSuspenso;
            		if(acumuladoNotas >= 28)estado = 3;
					else estado = 4;
        		}
    		}else if(acumuladoNotas < 16){
				do{
            		cout<<"\nIngrese nota suspenso: ";cin>>examenSuspenso;
        		}while((examenSuspenso < 0) || (examenSuspenso > 20));
				acumuladoNotas /= 2;
				acumuladoNotas += examenSuspenso;
				if(acumuladoNotas >= 28)estado = 3;
				else estado=4;
    		}
		}
		~cEstudiante(){}
};

class cEstudianteDeportista : public cEstudiante{
	private:
    	char deporte[10],ultimoCampeonato[10],lugarCampeonato[10];
    public:
    	cEstudianteDeportista() : cEstudiante(){
    		strcpy(deporte,"");
    		strcpy(ultimoCampeonato,"");
    		strcpy(lugarCampeonato,"");
		}
    	void createEstudiante(){
    		setLimiteAsistencia(50);
    		cEstudiante::createEstudiante();
    		cout<<"\nIngrese el deporte que practica: ";cin.ignore();gets(deporte);
    		cout<<"\nIngrese el ultimo campeonato: ";cin.ignore();gets(ultimoCampeonato);
    		cout<<"\nIngrese el lugar del ultimo campeonato: ";cin.ignore();gets(lugarCampeonato);
		}
    	void readEstudiante(){
    		cEstudiante::readEstudiante();
    		cout<<"\nDeporte que practica: ";puts(deporte);
    		cout<<"\nUltimo campeonato: ";puts(ultimoCampeonato);
    		cout<<"\nLugar de ultimo campeonato: ";puts(lugarCampeonato);
		}
    	~cEstudianteDeportista(){}
};

class cEstudianteArtista : public cEstudiante{
	private:
    	char actividad[20];
    public:
    	cEstudianteArtista(){
    		strcpy(actividad,"");
		}
    	void createEstudiante(){
    		setLimiteAsistencia(60);
    		cEstudiante::createEstudiante();
    		cout<<"\nIngrese la actividad que practica: ";cin.ignore();gets(actividad);
		}
    	void readEstudiante(){
    		cEstudiante::readEstudiante();
    		cout<<"\nActividad que practica: ";puts(actividad);
		}
    	~cEstudianteArtista(){}
};

class cCurso
{
	private: 
    	char materia[20], codigo[20];
    	int numeroEstudiantes;
    	cEstudiante *vEstudiantes[20];
    public:
    	cCurso(){
    		strcpy(materia,"");
    		strcpy(codigo,"");
    		numeroEstudiantes = 0;
		}
    	void createCurso(){
    		cout<<"\nIngrese materia: ";cin.ignore();gets(materia);
    		cout<<"\nIngrese codigo: ";cin.ignore();gets(codigo);
    		do{
       			cout<<"\nIngrese el numero de estudiantes: ";cin>>numeroEstudiantes;
    		}while((numeroEstudiantes < 1) || (numeroEstudiantes > 30));

    		for(int i = 1; i <= numeroEstudiantes; i ++){
        		int tipoEstudiante;
        		cout<<"\n__________________________________________________";
        		cout<<"\nESTUDIANTE "<<i<<endl;
        		do{
           			cout<<"\n1. Estudiante Normal";
           			cout<<"\n2. Estudiante Deportista ";
           			cout<<"\n3. Estudiante Artista ";
           			cout<<"\nIngrese tipo: ";cin>>tipoEstudiante;
        		}while((tipoEstudiante < 1) || (tipoEstudiante > 3));

        		if(tipoEstudiante == 1)
        			vEstudiantes[i] = new cEstudiante;
        		else if(tipoEstudiante==2)
        			vEstudiantes[i] = new cEstudianteDeportista();
            	else
            		vEstudiantes[i] = new cEstudianteArtista;
    			vEstudiantes[i] -> setTipo(tipoEstudiante);
    			vEstudiantes[i] -> createEstudiante();
			}
		}
		void readCurso(){
    		for(int i = 1; i <= numeroEstudiantes; i ++){
        		cout<<"\n__________________________________________________";
         		cout<<"\nESTUDIANTE "<<i<<endl;
         		vEstudiantes[i] -> readEstudiante();
     		}
     	}
    	void promedioCurso(){
    		float acumulado = 0;
    		for(int i = 1; i <= numeroEstudiantes; i ++)
         		acumulado += vEstudiantes[i] -> getAcumuladoNotas();
    		if(acumulado!=0)
       		cout<<"\nEl promedio del curso es: "<<acumulado/numeroEstudiantes;
		}
    	~cCurso(){
			for (int i = 1; i <= numeroEstudiantes; i ++)
      			delete(vEstudiantes[i]);
   			numeroEstudiantes=0;
		}
};

int main(){
	cCurso *objCurso;
    objCurso = new cCurso;
    objCurso->createCurso();
    clrscr();
    objCurso->readCurso();
    objCurso->promedioCurso();
	getch();
	return 0;
}
