//В стандартном потоке дана одна строка, состоящая из N + 1 целых чисел. 
//Первым числом идёт само число N. 
//Далее следуют ещё N чисел, обозначим их за массив A. 
//Между собой числа разделены пробелом.
//Отсортируйте массив А по модулю и выведите его в стандартный поток.
//Ограничения
//0 <= N <= 1000
//-1000000 <= A[i] <= 1000000
//Пример:
//Ввод
2 -4 3
//Вывод
3 -4
//Ввод
3 1 -3 2
//Вывод
1 2 -3
//

#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

int main()
{
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
        cout << i << " ";
    }
    return 0;
}





#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int main()
{  
  // считываем вектор
  int n;
  cin >> n;
  vector<int> v(n);
  for (int& x : v) {
    cin >> x;
  }

  // сортируем
  sort(begin(v), end(v),
       // функция, сравнивающая abs(l) и abs(r) — модули чисел l и r
       [](int l, int r) {
         return abs(l) < abs(r);
       }
  );
  // выводим отсорированный вектор
  for (int x : v) {
    cout << x << " ";
  }
  return 0;
}