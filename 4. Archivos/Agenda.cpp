#include "iostream"
#include <conio.h>
#include <stdio.h>
#include <cstring>

using namespace std;
void clrscr();
void clrscr() {
    system("cls");
}
struct agenda{
	char nombres[100];
	char numero[10];
	char email[250];
};
int main(){
	int option;
	void createData();
	void readData();
	void deleteData();
	void updateData();
	
	do{
		agenda strAgenda;
		do{
		 	cout<<"\n____________________________________________________________\n";
            cout<<"\n\n\t\t\tMENU DE OPCIONES\n";
            cout<<"____________________________________________________________\n";
            cout<<"1. Aniadir valores al fichero\n";
            cout<<"2. Eliminar valores del fichero\n";
            cout<<"3. Modificar valores del fichero\n";
            cout<<"4. Listar ordenadamente los valores del fichero\n";
            cout<<"5. Salir\n";
            cin>>option;				
		}while(option<1||option>5);	
		switch(option){
			case 1:
        		createData();
        		cout<<"\nGuardado...";
				break;
			case 2:
				deleteData();
				cout<<"\nEliminado...";
				break;
			case 3:
				updateData();
				cout<<"Modificar valor";
				break;
			case 4:
				readData();
				cout<<"\nDatos leidos...";
				break;
			case 5:
				cout<<"Saliendo...";
				break;
			default:
				cout<<"Opción no encontrada";
				break;
		}
		getch();
		clrscr();
	}while(option!=5);
	
	getch();
	return 0;
}
void createData(){
	FILE *file;
	agenda strAgenda;
	
	cout<<"Ingresar contacto...\n";
	cout <<"\tNombres: " ;
	cin.ignore(); 
    cin.getline(strAgenda.nombres, 100);
    cout <<"\tNumero: " ;
    cin.getline(strAgenda.numero, 10);
    cout <<"\tEmail: " ;
    cin.getline(strAgenda.email, 250);
	
	file = fopen("agenda.txt","ab");
	fwrite(&strAgenda,sizeof(strAgenda),1,file);
	fclose(file);
}
void readData(){
	FILE *file;
    agenda strAgenda;
    
    file = fopen("agenda.txt", "rb");
    fread(&strAgenda, sizeof(strAgenda), 1, file);
    while(!feof(file)){
    	cout<<"\n\tNombres: "<< strAgenda.nombres <<", Numero: " << strAgenda.numero <<  ", Email: " << strAgenda.email;
    	fread(&strAgenda, sizeof(strAgenda), 1, file);
	}
	fclose(file);
}
void updateData(){
	FILE *file;
	agenda vectorAgenda[100];
	agenda strAgenda;
	agenda auxAgenda;
	int i=1;
	int pos;
	int c;
	
	cout<<"Ingresar contacto a modificar...\n";
	cout <<"\tNombres: " ;
	cin.ignore(); 
    cin.getline(auxAgenda.nombres, 100);
    cout <<"\tNumero: " ;
    cin.getline(auxAgenda.numero, 10);
    cout <<"\tEmail: " ;
    cin.getline(auxAgenda.email, 250);
	cout<<"\nIngrese la posicion en la que va ha suplantar: ";
	cin>>pos;
	file = fopen("agenda.txt", "rb");
	fread(&strAgenda, sizeof(strAgenda), 1, file);
	if(file!=NULL){
        while(!feof(file)){
        	vectorAgenda[i]=strAgenda;
            fread(&strAgenda, sizeof(strAgenda), 1, file);
            i++;
        }
		fclose(file);
   		file = fopen("agenda.txt", "wb");

   		for(int j=1;j<i;j++)
       		if(j==pos){
         		fwrite(&auxAgenda, sizeof(auxAgenda), 1, file);
        	}else{
         		fwrite(&vectorAgenda[j], sizeof(vectorAgenda[j]), 1, file);
         	}
   		fclose(file);
	}else{
		cout<<"\nEl fichero no contiene datos.......=(\n";
	}
}
void deleteData(){
	FILE *file;
	agenda vectorAgenda[100];
	agenda strAgenda;
	char nombres[100];
	int i=1;
	void readData();
	
	readData();
	cin.ignore(); 
	cout<<"\nIngrese el nombre a eliminar: ";
	cin.getline(nombres, 100);
	file = fopen("agenda.txt", "rb");
	fread(&strAgenda, sizeof(strAgenda), 1, file);
	if(file!=NULL){
        while(!feof(file)){
        	if(strcmp(strAgenda.nombres, nombres) != 0){
            	vectorAgenda[i]=strAgenda;
            	i++;
            }
        	fread(&strAgenda, sizeof(strAgenda), 1, file);
        }
		fclose(file);
   		file = fopen("agenda.txt", "wb");
   		for(int j=1;j<i;j++)
       		fwrite(&vectorAgenda[j], sizeof(vectorAgenda[j]), 1, file);
   		fclose(file);
	}else cout<<"\nEl fichero no contiene datos.......=(\n";
}

