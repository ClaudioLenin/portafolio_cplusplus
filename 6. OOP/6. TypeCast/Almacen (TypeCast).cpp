#include<iostream>
#include <conio.h>
#include <stdio.h>
#include <string.h>

using namespace std;

void clrscr();
void clrscr() {
    system("cls");
}

class cElectrodomestico{
    private:
		char color[10], marca[10], modelo[10], codigo[10];
		int capacidad;
    	
    public:
    	cElectrodomestico(){
    		strcpy(color,"");
    		strcpy(marca,"");
    		strcpy(modelo,"");
    		strcpy(codigo,"");
    		capacidad = 0;
		}
    	char *getColor(){return(color);}
     	char *getCodigo(){return(codigo);}
     	int getTipo(){return(-1);}
     	virtual void createElectrodomestico(){
			cout<<"\nIngrese marca: ";cin.ignore();gets(marca);
    		cout<<"\nIngrese modelo: ";cin.ignore();gets(modelo);
    		cout<<"\nIngrese codigo: ";cin.ignore();gets(codigo);
    		cout<<"\nIngrese color: ";cin.ignore();gets(color);
    		cout<<"\nIngrese capacidad: ";cin>>capacidad;	
		}
     	virtual void readElectrodomestico(){
     		cout<<"\nMarca: ";puts(marca);
    		cout<<"\nModelo: ";puts(modelo);
    		cout<<"\nCodigo: ";puts(codigo);
    		cout<<"\nColor: ";puts(color);
    		cout<<"\nCapacidad: "<<capacidad;
		}
		~cElectrodomestico(){}
};

class cLavadora : public cElectrodomestico{
	private:
		int numeroSecadoras; //numero de secadoras
    public:
    	cLavadora(){
    		numeroSecadoras = 0;
		}
    	int getNumeroSecadoras(){return numeroSecadoras;}
    	int getTipo(){return(1);}
    	void createElectrodomestico(){
    		cElectrodomestico::createElectrodomestico();
    		int secadoras;
    		do{
        		cout<<"\n1. Tiene secadoras";
        		cout<<"\n2. No tiene secadoras";
        		cin>>secadoras;
    		}while((secadoras < 1) || (secadoras > 2));
    		
    		if(secadoras == 1)
        		do{
            		cout<<"\nIngrese numero de secadoras: ";cin>>numeroSecadoras;
        		}while(numeroSecadoras < 1);
    		else
        		numeroSecadoras = -1;
		}
    	void readElectrodomestico(){
    		cElectrodomestico::readElectrodomestico();
    		if(numeroSecadoras != -1)
         		cout<<"\nNumero de secadoras: "<<numeroSecadoras;
		}
		~cLavadora(){}
};

class cRefrigeradora : public cElectrodomestico{
	private:
    	int numeroPuertas;
    public:
    	cRefrigeradora(){
    		numeroPuertas = 0;
		}
    	int getTipo(){return(2);}
    	int getNumeroPuertas(){return(numeroPuertas);}
    	void createElectrodomestico(){
    		cElectrodomestico::createElectrodomestico();
    		cout<<"\nIngrese numero de puertas: ";cin>>numeroPuertas;
		}
    	void readElectrodomestico(){
    		cElectrodomestico::readElectrodomestico();
    		cout<<"\nNumero de puertas: "<<numeroPuertas;
		}
		~cRefrigeradora(){}
};

class cAlmacen{
    private:
		char nombre[10];
     	char direccion[10];
     	cElectrodomestico *vVendidos[20];
     	cElectrodomestico *vEnVenta[20];
     	int numeroVendidos;
     	int numeroEnVenta;
    public:
     	cAlmacen(){
     		numeroVendidos = numeroEnVenta = 0;
		}
     	void createElectrodomesticos(){
			int electrodomesticos, tipo;
			cout<<"\nIngrese nombre de la empresa: ";cin.ignore();gets(nombre);
     		cout<<"\nIngrese direccion de la empresa: ";cin.ignore();gets(direccion);
     		do{
         		cout<<"\nIngrese cantidad total de electrodomesticos: ";
         		cin>>electrodomesticos;
     		}while((electrodomesticos < 1) || (electrodomesticos > 20));
     		for(int i = 1; i <= electrodomesticos; i ++){
         		cout<<"\nELECTRODOMESTICO "<<i;
         		do{
             		cout<<"\n1. Lavadora Vendida";
             		cout<<"\n2. Lavadora en Venta";
             		cout<<"\n3. Refrigeradora Vendida";
             		cout<<"\n4. Refrigeradora en Venta";
             		cout<<"\nEscoja opcion: ";
             		cin>>tipo;
         		}while(tipo != 1 && tipo != 2 && tipo != 3 && tipo != 4);
         		if(tipo == 1 || tipo == 3){
         			if(tipo == 1)
         				vVendidos[numeroVendidos] = new cLavadora();
					else
						vVendidos[numeroVendidos] = new cRefrigeradora();
					vVendidos[numeroVendidos] -> createElectrodomestico();
         			numeroVendidos++;	
				}else{
					if(tipo == 2)
         				vEnVenta[numeroEnVenta] = new cLavadora();
    				else
						vEnVenta[numeroEnVenta] = new cRefrigeradora();
					vEnVenta[numeroEnVenta] -> createElectrodomestico();
					numeroEnVenta++;
				}
     		}
		}
		int readElectrodomesticoEnVenta(char *codigo){
			int position =- 1;
    		int i = 1;
    		while((i <= numeroEnVenta) && (position == -1)){
        		if(strcmp(vEnVenta[i] -> getCodigo(), codigo) == 0)
              		position = i;
        		i++;
    		}
    		return(position);
		}
		void readLavadorasConSecadoras(){
			int cantidad = 0;
    		for(int i = 1; i <= numeroVendidos; i ++)
        		if(vVendidos[i] -> getTipo() == 1){
        			//Uso de TypeCast
             		cLavadora *ptrLavadora;
             		ptrLavadora = (cLavadora*)vVendidos[i];
             		if(ptrLavadora -> getNumeroSecadoras() != -1){
                 		cantidad++;
                 		vVendidos[i] -> readElectrodomestico();
                	}
        		}
    		if(cantidad != 0)
       			cout<<"\nSe tiene "<<cantidad<<" lavadoras con secadoras vendidas";
		}
		void readRefrigeradorasConPuertas(){
			int numeroPuertas = 0;
    		int cantidad = 0;
    		cout<<"\nIngrese numero de puertas: ";cin>>numeroPuertas;
    		for(int i = 1; i <= numeroEnVenta; i ++)
    			if(vEnVenta[i] -> getTipo() == 2){
        			cRefrigeradora *ptrRefrigeradora;
        			ptrRefrigeradora = (cRefrigeradora*)vEnVenta[i];
        			if(ptrRefrigeradora -> getNumeroPuertas() == numeroPuertas){
            			cantidad++;
            			vEnVenta[i] -> readElectrodomestico();
        			}
    			}
    		if(cantidad != 0)
       			cout<<"\nSe tiene "<<cantidad<<" refrigeradoras con "<<numeroPuertas<<" puertas";
		}
		void readElectrodomesticosBlancos(){
			int cantidad = 0;
    		for(int i = 1; i <= numeroEnVenta; i ++)
    			if(strcmp(vEnVenta[i] -> getColor(),"blanco") == 0)cantidad++;
    		if(cantidad != 0)
      			cout<<"\nSe tiene "<<cantidad<<" electrodomestico(s) de color blanco";
		}
		void updateElectrodomesticosVendidos(){
			int position;
    		char codigo[10];
    		cout<<"\nIngrese codigo: ";cin.ignore();gets(codigo);
    		position = readElectrodomesticoEnVenta(codigo);
    		if(position != -1){
         		numeroVendidos++;
         		vVendidos[numeroVendidos] = vEnVenta[position];
         		deleteElectrodomesticosEnVenta(position);
    		}
		}
        void deleteElectrodomesticosEnVenta(int position){
        	for(int i = position; i <= numeroEnVenta; i ++)
        		vEnVenta[i] = vEnVenta[i+1];
    		numeroEnVenta--;
		}
        ~cAlmacen(){}
};

int main(){
	cAlmacen objAlmacen;
	objAlmacen.createElectrodomesticos();
   	//objAlmacen.readElectrodomesticoEnVenta();
   	cout<<"LAVADORAS CON SECADORAS"<<endl;
   	objAlmacen.readLavadorasConSecadoras();
   	cout<<"REFRIGERADORAS CON PUERTAS"<<endl;
   	objAlmacen.readRefrigeradorasConPuertas();
   	cout<<"ELECTRODOMESTICOS BLANCOS"<<endl;
   	objAlmacen.readElectrodomesticosBlancos();
	getch();
	return 0;
}
