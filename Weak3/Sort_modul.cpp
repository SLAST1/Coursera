//задача на сортировку по модулю
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

int main() {
    int N, num;
    cin >> N;
    vector<int> v;
    for (N; N > 0; --N){
        cin >> num;
        v.push_back(num);
    }
    sort(begin(v), end(v), 
        [](const int& x, const int& y){ //лямбда-функция
        return abs(x) < abs(y);
    }
    );
    for(const auto& i : v){ 
        cout << i << " "; //выводим отсортированные числа
    }
    return 0;
}



////////
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> v(n);
  for (int& x : v) {
    cin >> x;
  }

  sort(begin(v), end(v),
       [](int l, int r) {
         return abs(l) < abs(r);
       }
  );

  for (int x : v) {
    cout << x << " ";
  }

  return 0;
}





//задача на сортировку без учета регистра
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





////////
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