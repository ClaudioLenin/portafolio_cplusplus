#include <iostream.h>
#include <conio.h>
void main(){
   int c[10];
   int n=10;
   for(int i=1;i<=n;i++)
   {
      cin>>c[i];
      cout<<"\n";
   }
   int aux;
   for(int i=1;i<=n-1;i++)
      for(int j=i+1;j<=n;j++)
         if (c[i] < c[j])
         {
              aux = c[i];
              c[i] = c[j];
              c[j] = aux;
         }
   cout<<"\n____________________\n";
   for(int i=1;i<=n;i++)
   {

      cout<<c[i]<<endl;
   }
   cout<<"\n____________________\n";
   for(int i=1;i<=n;i++)
   {
     if(c[i]==2)
     {
      c[i]=c[n--];
      i--;
      }
   }
     cout<<"\n____________________\n";
     for(int i=1;i<=n;i++)
   {

      cout<<c[i]<<endl;
   }

getch();
}
