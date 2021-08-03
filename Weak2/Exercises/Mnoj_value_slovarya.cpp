//Напишите функцию BuildMapValuesSet, принимающую на вход словарь map<int, 
//string> и возвращающую множество значений этого словаря:
set<string> BuildMapValuesSet(const map<int, string>& m) {
  // ...
}
//Пример:
set<string> values = BuildMapValuesSet({
    {1, "odd"},
    {2, "even"},
    {3, "odd"},
    {4, "even"},
    {5, "odd"}
});
for (const string& value : values) {
  cout << value << endl;
}
//Вывод
even
odd
//

#include <iostream>
#include <string>
#include <map>
#include <set>
using namespace std;

set<string> BuildMapValuesSet(const map<int, string>& m) {
  set<string> values;
  for (const auto& item : m) {
    values.insert(item.second);
  }
  return values;
}