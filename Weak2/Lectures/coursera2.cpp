//coursera
//Векторы
//кароче просто считываем вектор и выводим его
//вначале указываем количество строк в векторе
#include <iostream>
#include <vector>
#include <string>
using namespace std;

void PrintVector(const vector<string>& v){
    for(string s : v){
        cout << s << endl;
    }
}

int main()
{
    int n;
    cin >> n;
    vector<string> v(n);
    for(string& s : v){
        cin >> s;
    }
    /*
    //тот же самый ввод вектора, прост без указания общего кол-ва строк в векторе
    //мне этот вариант больше понравился, его надо иметь ввиду
    int n;
    cin >> n;
    vector<string> v;
    int i = 0;
    while(i < n){
        string s;
        cin >> s;
        v.push_back(s);
        ++i;
    }
    */
    PrintVector(v);
    return 0;
}



#include <iostream>
#include <vector>
#include <string>
using namespace std;
//программа где будет вектор, 
//который для каждого месяца в году будет хранить количество дней в этих месяцах
void PrintVector(const vector<int>& n){
    for(auto s : n){
        cout << s << endl;
    }
}

int main()
{
    vector<int> DaysInMonths = {31, 28, 31, 30, 31}; //январь, февраль, март, апрель, май
    if (true) { //если год высокосный
    DaysInMonths[1]++; //в феврале +1 день (кароче просто показ что тут можно юзать инкремент)
  }
    PrintVector(DaysInMonths);
    return 0;
}



#include <iostream>
#include <vector>
#include <string>
using namespace std;
//программа где будет вектор, 
//который для каждого дня в месяце, является ли он выходным или праздничным
//+обозначение индекса дня в месяце
void PrintVector(const vector<bool>& n){
    int i = 0;
    for(auto s : n){
        cout << i << ":" << s << endl;
    }
    i++;
}

int main()
{
    vector<bool> Holiday (28, false); //в феврале, почти все дни не праздничные
    Holiday[22] = true; //23 февраля праздничный
    PrintVector(Holiday);

    Holiday.assign(31, false); //изменение начальной длины вектора через assign, это март
    Holiday[7] = true; //8 марта праздничный
    PrintVector(Holiday);
    /*
    Holiday.clear(); //очистка вектора
    */
    return 0;
}

/*
 *
 *
 */