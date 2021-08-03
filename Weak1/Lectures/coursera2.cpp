//coursera
//операции с простыми типами
#include <iostream>
#include <string>
using namespace std;

int main()
{
   int x = 4;
   int y = 5;
   cout << (x+y)*(x-y) << " \n";
   
   if (x == y) {        //сравнивание именно 2=
      cout << "equal\n";
   }  else {
      cout << "not equal\n";
   }
   
   string X = "abc";
   string Y = "aaabc";
   if (X < Y) {
      cout << "less\n";
   } else {
      cout << "not less\n";
   }


   return 0;
}
