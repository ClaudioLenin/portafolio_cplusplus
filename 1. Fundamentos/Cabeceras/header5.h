//archivo de cabecera con las funciones de manipulacion de vectores
void leer_vector(int v2[],int n1)   //funcion q permite el ingreso de los valores al arreglo
{ //de leer_vector
   int c; //contador de ciclo for
   for(c=0;c<n1;c++){  //ingreso de valores al arreglo
       cout<<"\nIngrese un valor a la posicion "<<c<<": ";
       cin>>v2[c];  //lectura del valor a ingresar en el arreglo
   }

} //de leer_vector
//
void imprime_vector(int v4[],int n3) //funcion q permite imprimir los valores del arreglo
{ //de imprime_vector
   int c; //contador de ciclo for
   for(c=0;c<n3;c++)
       cout<<"\nV["<<c<<"]: "<<v4[c];  //impresion de elemento del vector
} //de imprime_vector
//
int lee_n(int lim) //funcion que define la cantidad de elementos
{//de lee_n
   int aux; //variable que recibe la cantidad de elementos para el arreglo

   do{ //ciclo de ingreso de cantidad de valores
      cout<<"\nCantidad de valores: ";
      cin>>aux;
   }while((aux<1)||(aux>lim)); //repite mientras el numero ingresado sea negativo, cero o mayor al limite del arreglo
   return(aux); //retorna el valor ingresado
}//de lee_n
//
void determinar_ranking(int vec[],int cant,int num) //llamado a la funcion que permite calcular el ranking de un numero
{  //de determinar_ranking
   int i; //contador de ciclo
   float cont; //acumulador de posiciones del elemento
   int cont_cant=0; //contador de elementos que se van acumulando

   for(i=0,cont=0;i<cant;i++) //recorrido del arreglo para verificar la existencia del numero en el arreglo
      if(vec[i]==num) //si el numero ingresado es igual a cualquier elemento el arreglo entonces acumula en una variable
         {
         cont+=i;   //acumulador de posiciones del arreglo que contenga el numero pedido
         cont_cant++;  //contador de elementos que se estan acumulando
         }


   if(cont_cant!=0){  //Si el contador de elementos es distinto de cero entonces imprime el ranking sino imprime el mensaje de que no existe

         cont=cont/cont_cant; //calculo del promedio
         SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),GREEN);  //funcion que establece el color verde para la impresion del ranking
         cout<<"\nRANKING "<<num<<" = "<<cont<<"\n";   //imprime ranking
         }
   else{
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),MAGENTA); //funcion que establece el color magenta para la impresion del mensaje que no existe tal numero en el arreglo
        cout<<"\nRANKING "<<num<<" = NO EXISTE!!!!!\n";  //imprime mensaje
        }

}  //de determinar_ranking
