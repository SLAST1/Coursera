//цикл while
#include <iostream>
using namespace std;

int main()              //программа выводит сумму всех чисел, которые меньше указанного
{
   int n;
   cin >> n;

   if (n >= 1) {
         int sum = 0;
         while (n > 0) {
            sum += n;
            n--;
         }
   cout << sum << endl;
   } else {
      cout << "Please, enter positive number" << endl;
   }
   
   return 0;
}



#include <iostream>
using namespace std;

int main()              //программа загадала число
{                       //пользователь вводит своё число, пока не угадает
   int a = 5;
   int b;

   do {
      cout << "Guess the number: ";
      cin >> b;
   } while (a != b);
   cout << "U're right!" << endl;
   return 0;
} 