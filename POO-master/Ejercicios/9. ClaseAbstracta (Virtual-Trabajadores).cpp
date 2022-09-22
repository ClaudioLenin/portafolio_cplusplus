

#include <iostream.h>
#include <conio.h>
#include <stdio.h>
#include <string.h>
# define MAX 100


class c_trabajadores {
  private:
	char nombre[75], apellido[75], ci[13];

  public:

  	virtual void leer(){
   	cout <<"\n Ingrese su nombre: ";
   	gets(nombre);
   	cout << "\n Ingrese su apellido: ";
   	gets(apellido);
  	}

   char *get_cedula()
 	{
   	return (ci);
 	}

   void set_cedula(char *ced)
 	{
  		strcpy(ci,ced);
 	}

   virtual float salario(){
		return(-1,0);
   }
   void mostrar(){
   	cout <<"\n Su nombre es: ";
   	puts(nombre);
   	cout << "\n Su apellido es: ";
   	puts(apellido);
   	cout << "\n Su numero de cedula es: ";
   	puts(ci);

  	}


     void mostrar_lista(){
   	cout <<"\t";
   	puts(nombre);
   	cout << "\t";
   	puts(apellido);
   	cout << "\t";
   	puts(ci);

  	}

};

class c_Tnombramiento: public c_trabajadores {
  private:

  float sueldo, descuento;

  public:

  c_Tnombramiento(){

  }

  	void leer(){

      c_trabajadores::leer();
   	cout << "\n Ingrese su sueldo: ";
 		cin >> sueldo;
   	cout << "\n Ingrese su descuento: ";
 		cin >> descuento;
  	}

   float salario(){
		return(sueldo - descuento);
   }

  	void mostrar(){

      c_trabajadores::mostrar();
   	cout << "\n Su sueldo es: " << sueldo;
   	cout << "\n su descuento es: " << descuento;
  	}

};


class c_Tcontrato: public c_trabajadores {
  private:

  float val_horas;
  int cant_horas;

  public:

  c_Tcontrato(){

  }

  	void leer(){

      c_trabajadores::leer();
   	cout << "\n Ingrese el valor de la hora: ";
 		cin >> val_horas;
   	cout << "\n Ingrese la cantidad de horas: ";
 		cin >> cant_horas;
  	}

   float salario(){
		return(val_horas * cant_horas );
   }

  	void mostrar(){

      c_trabajadores::mostrar();
   	cout << "\n Su sueldo es: " << val_horas;
   	cout << "\n su descuento es: " << cant_horas;
   }
};

class c_Tdestajo: public c_trabajadores {
  private:

  float sueldo, valor_ventas;
  int porc;

  public:

  c_Tdestajo(){

  }

  	void leer(){

      c_trabajadores::leer();
   	cout << "\n Ingrese el sueldo del trabajador: ";
 		cin >> sueldo;
   	cout << "\n Ingrese el valor de las horas: ";
 		cin >> valor_ventas;
      cout << "\n Ingrese el porcentaje a recibir x las ventas: ";
 		cin >> porc;

  	}

   float salario(){
		return(sueldo + (porc*valor_ventas) );
   }

  	void mostrar(){

      c_trabajadores::mostrar();
   	cout << "\n Su sueldo es: ";
 		cin >> sueldo;
   	cout << "\n El valor de las horas es: ";
 		cin >> valor_ventas;
      cout << "\n El porcentaje a recibir por  las ventas es: ";
 		cin >> porc;
   }

};

class c_Empresa {

  private:

  char nombre[70], direccion[70];
  int num_tra;
  c_trabajadores *vTrabajadores[MAX];

  public:

  void leer(){
     cout << "\n Ingrese el nombre de la empresa: ";
     gets(nombre);
     cout << "\n Ingrese la direccion de la empresa: ";
     gets(direccion);
     cout << "Ingrese el numero de trabajadores:  ";
     cin >> num_tra;
     ingreso();
  }

  /*
  void ingreso(){

   for(int i=0; i< num_tra ; i++)

   	switch(menu()){
       case 1: ingresarN(i);
       	break;
       case 2: ingresarC(i);
       	break;
       case 3: ingresarD(i);
       	break;
      }
  }

  int menu(){
    int op;
    cout << "\n INGRESO DE TRABAJADORES ";
    cout << "\n 1. Trabajador a Nombramiento ";
    cout << "\n 2. Trabajador a Contrato ";
    cout << "\n 3. Trabajador a Destajo ";
    cin >> op;
   return(op);
  }

  void ingresarN(int i){

  cout << " Tabajador " << (i+1) <<"\n" ;
  vTrabajadores[i] = new c_Tnombramiento();
  vTrabajadores[i]->leer();

  }

  void ingresarC(int i){

  cout << " Tabajador " << (i+1) <<"\n" ;
  vTrabajadores[i] = new c_Tcontrato();
  vTrabajadores[i]->leer();

  }

  void ingresarD(int i){

  cout << " Tabajador " << (i+1) <<"\n" ;
  vTrabajadores[i] = new c_Tdestajo();
  vTrabajadores[i]->leer();

  }

  */

//---------------------------------------------------------
  void ingreso(){

   for(int i=0; i< num_tra ; i++)

   	switch(menu()){
       case 1: ingresarN(i);
       	break;
       case 2: ingresarC(i);
       	break;
       case 3: ingresarD(i);
       	break;
      }
  }

  int menu(){
    int op;
    cout << "\n INGRESO DE TRABAJADORES ";
    cout << "\n 1. Trabajador a Nombramiento ";
    cout << "\n 2. Trabajador a Contrato ";
    cout << "\n 3. Trabajador a Destajo ";
    cin >> op;
   return(op);
  }

  void ingresarN(int i){

  char aux[13];
  	cout << " Tabajador " << (i+1) <<"\n" ;


    do{
    	cout << "\n Ingrese su numero de cedula: " ;
   	gets(aux);

     if(comparacion(aux, i))
      	cout << "\n Trabajador existente, por favor ingrese otro ";
     else{
		vTrabajadores[i] = new c_Tnombramiento();
      vTrabajadores[i]->set_cedula(aux);
  		vTrabajadores[i]->leer();
     }
    }while(comparacion(aux, i));

  }

  void ingresarC(int i){
  char aux[13];
  cout << " Tabajador " << (i+1) <<"\n" ;

    do{
    	cout << "\n Ingrese su numero de cedula: " ;
   	gets(aux);

     if(comparacion(aux, i))
      	cout << "\n Trabajador existente, por favor ingrese otro ";
     else{
  		vTrabajadores[i] = new c_Tcontrato();
      vTrabajadores[i]->set_cedula(aux);
  		vTrabajadores[i]->leer();
     }
    }while(comparacion(aux, i));

  }

  void ingresarD(int i){
    char aux[13];
  cout << " Tabajador " << (i+1) <<"\n" ;


	do{
    	cout << "\n Ingrese su numero de cedula: " ;
   	gets(aux);

     if(comparacion(aux, i))
      	cout << "\n Trabajador existente, por favor ingrese otro ";
     else{
      vTrabajadores[i] = new c_Tdestajo();
      vTrabajadores[i]->set_cedula(aux);
  		vTrabajadores[i]->leer();
     }
   }while(comparacion(aux, i));
  }



  bool comparacion(char aux[], int n){

 	if(n == 0)
 		return(false);
 	else{

      	for(int i=0 ; i< num_tra ; i++){
         	if(strcmp(aux, vTrabajadores[i]->get_cedula()) == 0 )
            	return(true);
         }
         return (false);
 		}
 }

//---------------------------------------------------------



















  void nomina(){
   cout << "\n\n NOMINA DE TRABAJADORES DE LA EMPRESA";
   puts(nombre);

   cout << "\t NOMBRE";
   cout << "\t APELLIDO";
   cout << "\t CEDULA";
   cout << "\t SUELDO MENSUAL";



   listado();

   cout << "\t\t" << total();

  }

  void listado(){

   for(int i=0 ; i< num_tra ; i++){
    cout << "\n";
   	vTrabajadores[i]->mostrar_lista();
      cout << vTrabajadores[i]->salario();

   }
  }




  float total(){
  	float sum=0;
   	for(int i=0; i<num_tra ; i++)
   		sum += vTrabajadores[i]->salario();
   return(sum);
  }









 ~c_Empresa(){
   int i;

   	for(i=0; i<num_tra ; i++)
      	delete vTrabajadores[i];
   }


};

void main(){
c_Empresa o_coca;
o_coca.leer();
getch();
clrscr();
o_coca.nomina();

getch();
}