//условия и циклы
#include <iostream>
#include <vector>
#include <string>
using namespace std;
int main()
{
   int x = 3;
   int y = 5;
   cout << x+y;
}

int main()              //обычное условие if else
{
   int x = 3;
   int y = 5;
   if (x == y){
      cout << "equal";
   } else {
      cout << "not equal";
   }
}

int main()              //цикл for для перебора значений из вектора переменных
{
   vector<int> nums = {1, 2, 3, 4, 5};
   for (auto x : nums){
      ................................
   }
}

int main()              //цикл for для подсчёта суммы чисел от 1 до n
{
   int n = 5;
   int sum = 0;
   for (int i=1; i<=n; i++){
      sum += i;
   }
   cout << sum;
   return 0;
}

int main()              //тоже самое только через цикл while
{
   int n = 5;
   int sum = 0;
   int i = 1;
   while (i <= n){
      sum += i;
      i += 1;
   }
   cout << sum;
   return 0;
}

