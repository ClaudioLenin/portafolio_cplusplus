//archivo de cabecera con las funciones de manipulacion de vectores
   void leer_vector(int v2[],int n1)   //funcion q permite el ingreso de los valores al arreglo
   {
   int c; //contador de ciclo for
   for(c=0;c<n1;c++){ //ciclo de lectura
       cout<<"\nIngrese un valor a la posicion "<<c<<": ";
       cin>>v2[c];
   }

   }
//
int lee_n(int lim) //cantidad de elementos a ingresar al vector
{ //de lee_n
   int aux; //variable que recibe el valor ingresado por el usuario
   do{
      cout<<"\nCantidad de valores de [1...."<<lim<<"]:";
      cin>>aux;
   }while((aux<1)||(aux>lim)); //repite mientras el numero ingresado sea 0 o negativo
   return(aux);  //retorna valor de elementos
} //de lee_n
//
void imprime_vector(int v4[],int n3) //funcion q permite imprimir los valores del arreglo
   {//de imprime vector
   int c;//contador de ciclo for
   for(c=0;c<n3;c++)
       cout<<"\nV["<<c<<"]: "<<v4[c];
   }//de imprime vector
//
void leer_vector_flotante(float v2[],int n1)   //funcion q permite el ingreso de los valores al arreglo
   {
   int c; //contador de ciclo for
   for(c=0;c<n1;c++){ //ciclo de lectura
       cout<<"\nIngrese un valor a la posicion "<<c<<": ";
       cin>>v2[c];
   }

   }
