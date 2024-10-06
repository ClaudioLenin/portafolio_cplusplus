#include <iostream.h>
#include <conio.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
class cElectro{
    private:
       char color[10];
       char marca[10];
       char modelo[10];
       char codigo[10];
       float precio;
    public:
       cElectro();
       float getPrecio();
       char *getCodigo();
       void leerdatos();
       void mostrardatos();
       ~cElectro();
};
cElectro::cElectro(){
   strcpy(color,"");
   strcpy(marca,"");
   strcpy(modelo,"");
   strcpy(codigo,"");
   precio=0;
}
float cElectro::getPrecio(){
   return(precio);
}
char *cElectro::getCodigo(){
   return(codigo);
}
void cElectro::leerdatos(){
   cout<<"\nIngrese color: ";gets(color);
   cout<<"\nIngrese marca: ";gets(marca);
   cout<<"\nIngrese modelo: ";gets(modelo);
   cout<<"\nIngrese codigo: ";gets(codigo);
   cout<<"\nIngrese precio: ";cin>>precio;
}
void cElectro::mostrardatos(){
   cout<<"\nColor: ";puts(color);
   cout<<"\nMarca: ";puts(marca);
   cout<<"\nModelo: ";puts(modelo);
   cout<<"\nCodigo: ";puts(codigo);
   cout<<"\nPrecio: "<<precio;
}
cElectro::~cElectro(){

}
class cL_R : public cElectro{
   private:
       int n_puertas;
       int capacidad;
       int tipo;
   public:
       cL_R();
       int getTipo();
       int getN_puertas();
       void leerL_R();
       void mostrarL_R();
       ~cL_R();
};
cL_R::cL_R() : cElectro(){
     n_puertas=capacidad=tipo=0;
}
int cL_R::getTipo(){
     return(tipo);
}
int cL_R::getN_puertas(){
     return(n_puertas);
}
void cL_R::leerL_R(){
     cout<<"\n\t\t\tSELECCIONE TIPO";
     do{
        cout<<"\n1.- Refrigeradora";
        cout<<"\n2.- Lavadora\n";
        cin>>tipo;
     }while((tipo<1)||(tipo>2));

     cout<<"\nIngrese numero de puertas: ";cin>>n_puertas;
     cout<<"\nIngrese capacidad: ";cin>>capacidad;
     cElectro::leerdatos();
}
void cL_R::mostrarL_R(){
     cout<<"\nNumero de puertas: "<<n_puertas;
     cout<<"\nCapacidad: "<<capacidad;
     cElectro::mostrardatos();
}
cL_R::~cL_R(){
}
class cTV : public cElectro{
     private:
         float plg;
     public:
         cTV();
         void leerTV();
         void mostrarTV();
         ~cTV();
};
cTV::cTV():cElectro(){
     plg=0;
}
void cTV::leerTV(){
     cout<<"\nIngrese tamanio en pulgadas: ";cin>>plg;
     cElectro::leerdatos();
}
void cTV::mostrarTV(){
     cout<<"\nTamanio en pulgadas: "<<plg;
     cElectro::mostrardatos();
}
cTV::~cTV(){
}
class cAlmacen{
     private:
          char nombre[10];
          char direccion[10];
          int ne;
          int nt;
          cTV vTs[20];
          cL_R vLRs[20];
     public:
          cAlmacen();
          void leerA(); //Lee todos los datos del almacen
          void leerLRS(); //Lee lavadoras y refrigeradoras
          void leerTVS();  //Lee televisores

          void mostrarDAlmacen();  //Muestra todos los datos del almacen
          void mostrarTvs();  //Muestra el vector de televisores
          void mostrarL_R();  //Muestra el vector de Lavadoras y refrigeradoras

          void mostBusqLavadoras(); //Muestra las lavdoras x numero de puertas y precio
          int BusquedaL_R(char cad[10]); //Busca un elemento del vector de lavadoras y refrigeradoras
          int BusquedaTV(char cad[10]);  //Busca un elemento del vector de televisores
          void promRefrigeradoras();  //Muestra el promedio del precio de las refrigeradoras
          void inversionL_R();  //Muestra la inversion en lavadoras y refrigeradoras
          void modificarTV(); //Modifica un elemento del vector de lavadoras y refrigeradoras
          void modificarElectro(); //Modifica un elemento del vector de televisores
          ~cAlmacen();
};
cAlmacen::cAlmacen(){
      strcpy(nombre,"");
      strcpy(direccion,"");
      ne=nt=0;
}
void cAlmacen::leerA(){
      cout<<"\nIngrese nombre de almacen: ";gets(nombre);
      cout<<"\nIngrese direccion de almacen: ";gets(direccion);
      leerLRS();
      leerTVS();
}
void cAlmacen::leerLRS(){
      do{
         cout<<"\nIngrese numero de electrodomesticos: ";cin>>ne;
         }while((ne<1)||(ne>20));
      for(int i=1;i<=ne;i++){
          cout<<"\nELECTRODOMESTICO "<<i<<endl;
          vLRs[i].leerL_R();
      }
}
void cAlmacen::leerTVS(){
      do{
         cout<<"\nIngrese numero de televisores: ";cin>>nt;
      }while((nt<1)||(nt>20));
      for(int i=1;i<=nt;i++){
          cout<<"\nTELEVISOR "<<i<<endl;
          vTs[i].leerTV();
      }
}
void cAlmacen::mostrarDAlmacen(){
   cout<<"\nAlmacen: ";
   puts(nombre);
   cout<<"\nDireccion: ";
   puts(direccion);
   mostrarTvs();
   mostrarL_R();
}
void cAlmacen::mostrarTvs(){
   for(int i=1;i<=nt;i++){
      cout<<"\n================================================================\n";
      cout<<"\nTELEVISOR "<<i;
      vTs[i].mostrarTV();
      cout<<"\n================================================================\n";
      }
}
void cAlmacen::mostrarL_R(){
    for(int i=1;i<=ne;i++){
      cout<<"\n================================================================\n";
      cout<<"\nELECTRODOMESTICO "<<i;
      if(vLRs[i].getTipo()==1)
          cout<<"\nTipo: Refrigeradora\n";
      else
          cout<<"\nTipo: Lavadora\n";
      vLRs[i].mostrarL_R();
      cout<<"\n================================================================\n";
      }
}

//_________________________________LITERAL (a)__________________________________
//Mostrar lavadoras x numero de puertas y menor a un precio ingresado x el usuario
//______________________________________________________________________________
void cAlmacen::mostBusqLavadoras(){
     int np;
     int p1;
     cout<<"\nIngrese numero de puertas: ";cin>>np;
     cout<<"\nIngrese precio: ";cin>>p1;
     for(int i=1;i<=ne;i++)
        if(vLRs[i].getTipo()==2)
            if((vLRs[i].getN_puertas()==np)&&(vLRs[i].getPrecio()<=p1)){
                cout<<"\n=================================================================\n";
                vLRs[i].mostrarL_R();
                cout<<"\n=================================================================\n";
                }
}

//_________________________________LITERAL (b)__________________________________
//Precio promedio de las refrigeradoras
//______________________________________________________________________________
void cAlmacen::promRefrigeradoras(){
     float prom=0;
     int c=0;
     for(int i=1;i<=ne;i++)
         if(vLRs[i].getTipo()==1){
             prom+=vLRs[i].getPrecio();
             c++;
             }
     if(c!=0)
         cout<<"\nEl promedio es: "<<prom/c;
     else
         cout<<"\nNo hay Refrigeradoras.....";
}
//_________________________________LITERAL (c)__________________________________
//Mostrar la inversion en lavadoras y refrigeradoras
//______________________________________________________________________________
void cAlmacen::inversionL_R(){
     float inv=0;
     for(int i=1;i<=ne;i++)
         inv+=vLRs[i].getPrecio();
     cout<<"\nLa inversion es: "<<inv;
}

//_________________________________LITERAL (d)__________________________________
//Modificar Electrodomesticos
//______________________________________________________________________________
void cAlmacen::modificarElectro(){
    int pos;
    char cod[10];
    cout<<"\nIngrese codigo para buscar: ";gets(cod);
    pos=BusquedaL_R(cod);
    if(pos!=-1)
        vLRs[pos].leerL_R();
    else
        cout<<"\nCodigo no encontrado......";
}
void cAlmacen::modificarTV(){
    int pos;
    char cod[10];
    cout<<"\nIngrese codigo para buscar: ";gets(cod);
    pos=BusquedaTV(cod);
    if(pos!=-1)
        vTs[pos].leerTV();
    else
        cout<<"\nCodigo no encontrado......";

}
int cAlmacen::BusquedaL_R(char cad[10]){
     int i=1;
     do{
        if(strcmp(cad,vLRs[i].getCodigo())==0)
            return(i);
        i++;
     }while(i<=ne);
     return(-1);
}
int cAlmacen::BusquedaTV(char cad[10]){
     int i=1;
     do{
        if(strcmp(cad,vTs[i].getCodigo())==0)
            return(i);
        i++;
     }while(i<=nt);
     return(-1);
}
//------------------------------------------------------------------------------
cAlmacen::~cAlmacen(){
}
//******************************************************************************
void main(){
   cAlmacen a;
   a.leerA();
   int op;
   clrscr();
   do{
        do{
           cout<<"\n1.- Mostrar lavadoras x numero de puertas y precio\n";
           cout<<"2.- Mostrar precio promedio de refrigeradores\n";
           cout<<"3.- Mostrar inversion de lavadoras y refrigeradoras\n";
           cout<<"4.- Modificar Electrodomesticos\n";
           cout<<"5.- Mostrar todos los datos\n";
           cout<<"6.- Salir\n";
           cin>>op;
        }while((op<1)||(op>6));
        switch(op){
                case 1:
                      a.mostBusqLavadoras();
                      break;
                case 2:
                      a.promRefrigeradoras();
                      break;
                case 3:
                      a.inversionL_R();
                      break;
                case 4:
                      int ask;
                      do{
                          cout<<"\n1.- Televisor\n";
                          cout<<"2.- Electrodomesticos\n";
                          cin>>ask;
                         }while((ask<1)||(ask>2));
                      switch(ask){
                              case 1:
                                    a.modificarTV();
                                    break;
                              case 2:
                                    a.modificarElectro();
                                    break;
                      }
                      break;
                case 5:
                      a.mostrarDAlmacen();
                      break;
        }
        system("pause");
        clrscr();
   }while(op!=6);
   getch();
}

