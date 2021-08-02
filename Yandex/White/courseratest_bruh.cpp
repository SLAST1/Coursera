#include <string>
#include <iostream>
#include <vector>
using namespace std;

void Worry(int& i, vector<bool>& x) {
    x[i] = true; // помечаю i-тый элемент (единичкой в векторе)
}
void Quiet(int& i, vector<bool>& x) {
    x[i] = false; // помечаю i-тый элемент (нолем в векторе)
}
void Come(int n, vector<bool>& x) { //функция убрает или прибавляет к концу вектора элементы(старые значения не меняет) 
    int q = x.size(); // измерили исходный вектор
    x.resize(q + (n)); // изменяем размер, при расширении нолями дополнится, при уменьшении обрежется, оставшиеся значения не изменит
}
void Worry_count(const vector<bool>& x) { //выводит количество "сердитых" единичек
    int counts = 0;
    for (auto i : x) {
        if (i==1) { //если встретим единичку(true), то засчитываем её
            counts++;
        }
    }
    cout << counts << endl; //выводим сколько единичек нашли
}

int main() {
    int Q;
    cin >> Q; //ввели количество операций
    vector<bool> stack; //создали пустой вектор, принимающий только 0 или 1
    for (int i = 0; Q > i; i++) { //и пока лимит строк не закончится считываем их и выполняем по ходу
        string s; //текстовая составляющая
        int col; //циферка
        cin >> s; //прочитали текст...
        if (s == "WORRY_COUNT") { //если это запрос "вывести количество единичек" ...
            Worry_count(stack); //выводим функцией; а циферку не запрашиваем
        }
        else {
            cin >> col; //иначе запрашиваем циферку
            if (s == "WORRY") { //если запрос на "пометить сердитого", то ...
                Worry(col, stack); // помечаем
            }
            else if (s == "QUIET") { //иначе, если запрос на "убрать сердитость", то ...
                Quiet(col, stack); // убираем
            }
            else if (s == "COME") { //ну или обрезаем, или добавляем очередь
                Come(col, stack); //этой функцией
            }
        }
    }
    return 0;
}





#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
  int q;
  cin >> q;
  vector<bool> is_nervous;

  for (int i = 0; i < q; ++i) {
    string operation_code;
    cin >> operation_code;

    if (operation_code == "WORRY_COUNT") {
      
      // подсчитываем количество элементов в векторе is_nervous, равных true
      cout << count(begin(is_nervous), end(is_nervous), true) << endl;
      
    } else {
      if (operation_code == "WORRY" || operation_code == "QUIET") {
        
        int person_index;
        cin >> person_index;
        
        // выражение в скобках имеет тип bool и равно true для запроса WORRY,
        // поэтому is_nervous[person_index] станет равным false или true
        // в зависимости от operation_code
        is_nervous[person_index] = (operation_code == "WORRY");
        
      } else if (operation_code == "COME") {
        
        int person_count;
        cin >> person_count;
        
        // метод resize может как уменьшать размер вектора, так и увеличивать,
        // поэтому специально рассматривать случаи с положительным
        // и отрицательным person_count не нужно
        is_nervous.resize(is_nervous.size() + person_count, false);
        
      }
    }
  }

  return 0;
}
