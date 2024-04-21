#include<iostream>
#include <conio.h>
using namespace std;
class square{
   int side_;

   public:
   square(int side_length):side_(side_length){};
   int getArea() const{
       return side_*side_;
   };

};
int main(){
   square square(5);
   cout<<"Area"<<square.getArea();
   getch();
   return 0;

}
