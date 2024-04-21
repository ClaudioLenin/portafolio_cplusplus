void burbuja(int vec[],int c) //funcion que permite ordenar un vector con el metodo de la burbuja
{
   int s;
   for(int j=0;j<c;j++)
    for(int i=0;i<(c-1);i++)
       if(vec[i]>vec[i+1]){
          s=vec[i];
          vec[i]=vec[i+1];
          vec[i+1]=s;
       }
}
//
void insercion(int vec[],int c) //funcion que permite ordenar un vector con el metodo de insercion
{
   int s;
   int k=2;
   for(int i=1;i<(c-1);i++){
    for(int j=0;j<k;j++)
       if(vec[k]<vec[j]){
          s=vec[k];
          vec[k]=vec[j];
          vec[j]=s;
       }
       else{
          vec[k]=vec[k];
          vec[j]=vec[j];
       }
    k++;
    }
}
//
void seleccion(int vec[],int c) //funcion que permite ordenar un vector con el metodo de seleccion
{
   int s;
   int min;
   for(int i=0;i<c;i++){
      min=i;
      for(int j=i+1;j<c;j++)
          if(vec[min]>vec[j])
             min=j;

      s=vec[min];
      vec[min]=vec[i];
      vec[i]=s;

    }
}
