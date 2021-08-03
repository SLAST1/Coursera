//coursera
//присваивание
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() //такая программа показывает что в языке с++ присваивание происходит
{          //полное глубокое копирование присваеваемой переменной
   string s = "hello";
   string t = s;
   t += ", world"; //произвели изменения в переменной t

   cout << "s = " << s << endl;
   cout << "t = " << t << endl;
   return 0;
}



int main() //то же самое происходит с переменными других типов
{
   vector<string> w = {"a", "b", "c"};
   vector<string> v;
   v = w;
   v[0] = "d";

   cout << w[0] << " " << w[1] << endl;
   cout << v[0] << " " << v[1] << endl;
   return 0;
}



int main()
{
   vector<string> original = {"Vector", "of", "strings"};
   vector<string> another = original;
   vector<string> empty;
   original = empty;
   
   cout << another[0] << endl;               //почему блять надо делать [?]??? 
                                             //почему нельзя просто указать переменную лол
   return 0;
}

/*ИТОГ:
 *Познакомился с особенностями присваевания
 */