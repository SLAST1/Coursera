//В стандартном потоке дана одна строка, состоящая из числа N и следующих за ним N строк S. 
//Между собой число и строки разделены пробелом.
//Отсортируйте строки S в лексикографическом порядке по возрастанию, 
//игнорируя регистр букв, и выведите их в стандартный поток вывода.
//Ограничения
//0 <= N <= 1000
//1 <= |S| <= 15
//Каждая строка S[i] может состоять из следующих символов: [0-9,a-z,A-Z]
//Пример:
//Ввод
2 qq Aa  
//Вывод
Aa qq
//Ввод
3  aA Cc bb 
//Вывод
aA bb Cc
//

#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

string decrease(string& s){
   string tomain;
   for (auto& i : s){
      tomain += tolower(i);
   }
   return tomain;
}
 
int main()
{
   int N;
   string str;
   vector <string> v;
   cin >> N;
   for (N; N > 0; N--){
      cin >> str;
      v.push_back(str);
   } sort(begin(v), end(v), 
      []( string& str1,  string& str2){
      return decrease(str1) < decrease (str2);
   }
   );

   for (const auto& i : v) {
      cout << i << " ";
   }
   return 0;
}





#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
  int n;
  cin >> n;
  vector<string> v(n);
  for (string& s : v) {
    cin >> s;
  }

  sort(begin(v), end(v),
       // компаратор для сортировки — лямбда-функция, сравнивающая строки без учёта регистра
       [](const string& l, const string& r) {
         // сравниваем лексикографически...
         return lexicographical_compare(
             // ... все символы строки l ...
             begin(l), end(l),
             // ... со всеми символами строки r ...
             begin(r), end(r),
             // ..., используя в качестве компаратора сравнение отдельных символов без учёта регистра
             [](char cl, char cr) { return tolower(cl) < tolower(cr); }
         );
       }
  );

  for (const string& s : v) {
    cout << s << ' ';
  }
  return 0;
}