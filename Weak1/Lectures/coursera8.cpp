//coursera
//цикл for
#include <iostream>
#include <vector>
using namespace std;

int main() //перебор некоторого набора значений
{          //суммируем все значения в нашем векторе
   vector<int> a = {1, 2, 4, 6, 8, 10};
   
   int sum = 0;
   for(auto i: a){
      sum += i;
   }

   cout << sum << endl;
   return 0;
}



int main()
{
   map<string, int> b = {   {"a",1}, {"b",2}, {"c",3}   };

   int sum = 0;
   string concat;
   for(auto i: b){
      concat += i.first; //конкатенация всех значений строк
      sum += i.second; //сумма всех чисел которые соответствуют значениям строк
   }

   cout << concat << endl;
   cout << sum << endl;
   return 0;
}



int main() //мы будем выводить номера символов в строке которые равные букве А
{
   string abc = "asdasddfvksmasxasagbve";

   int i = 0;
   for (auto n : abc){
      if (n == 'a'){
         cout << i << endl;
      }
      i++;
   }

   return 0;
}



int main() //то же самое что выше, но чуть по другому
{          //другая вариация использования for
   string abc = "sdasddfvksmasxasagbve";

   for (int i=0; i < abc.size(); i++){
      if (abc[i] == 'a'){
         cout << i << endl;
         //break;       //если добавить вот это, то цикл остановится когда найдёт первую А
      }
   }

   cout << "end" << endl;
   return 0;
}

/*ИТОГ:
 *Познакомился с циклом for
 *понял как работает range based for
 */