#include <iostream>
#include <string>
#include <vector>
using namespace std;
int main() 
{ //работа с контейнерами (тоесть типами которые хранят больше чем 1 значение)
   string s = "abcdef"; //перебираем все элементы этого контейнера и что-то с ними делаем
   for(char c : s) { 
      cout << c << ","; //например ставим запятую между каждым значением
   }

   vector<int> nums = {1, 2, 3, 4, 5}; //таким же образом перебираем все элементы вектора
   for(int c : nums) { //для переменной цикла тоже задаем другой тип (или можно использовать auto если забываешь постоянно менять тип)
      cout << c << ",";
   }
   return 0;
}



//а если нам надо к примеру посчитать из вектора чисел,
//количество какого-то одного числа
int main() 
{
   vector<int> nums = {1, 2, 3, 5, 6, 3, 7, 9, 5, 0, 4};
   int quantity = 0;     //задаем начало счётчика
   for (auto x : nums) { //если некое X из nums
      if (x == 5){       //равно 5
         quantity += 1;  //увеличивать счётчик на 1
      }
   }
   cout << "Здесь " << quantity << "пятёрок\n";
   return 0;  
}



//но использовать целых 6 строк для такого простого действия это тупо
//поэтому можно еще вот так сделать:
#include <algorithm> //count берется именно от сюда
int main() 
{
   vector<int> nums = {1, 2, 3, 5, 6, 3, 7, 9, 5, 0, 4};
   int quantity = count(begin(nums), end(nums), 5);
   cout << "Здесь " << quantity << "пятёрок\n";
   return 0;
}

//а еще можно через sort, этот контейнер тоже из библиотеки algorithm

int main() 
{
   vector<int> nums = {1, 2, 3, 5, 6, 3, 7, 9, 5, 0, 4};
   sort(begin(nums), end(nums));
   for (auto x : nums) {
      cout << x << " ";
   }
   return 0;
}
