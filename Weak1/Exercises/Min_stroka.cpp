//В стандартном потоке даны три строки, разделённые пробелом. 
//Каждая строка состоит из строчных латинских букв и имеет длину не более 30 символов. 
//Выведите в стандартный вывод лексикографически минимальную из них.

#include <iostream>
#include <string>
using namespace std;

int main()
{  
   string A, B, C;
   cin >> A >> B >> C;

   if(A <= B && A <= C) {
        cout << A;
   } else if (A >= B && B <= C) {
        cout << B;
   }  else {
        cout << C;
   }

   return 0;
}





#include <iostream>
#include <string>
using namespace std;

int main() 
{
  string a, b, c;
  cin >> a >> b >> c;
  
  if (a <= b && a <= c) {
    cout << a;
  } else if (b <= a && b <= c) {
    cout << b;
  } else {
    cout << c;
  }
  return 0;
}