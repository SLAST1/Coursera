//Алгоритмы count и count_if, лямбда-функции
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;
//мы хотим подсчитать, 
//сколько конкретного значения элементов содержится в нашем контейнере. 
//Например, сколько раз двойка встречается в векторе.
bool Gt2(int x){
    if(x>2){
        return true;
    }
    return false;
}

bool Lt2(int x){
    if(x<2){
        return true;
    }
    return false;
}

int main()
{   
    vector<int> v{1, 2, 4, 5, 3};
    cout << count(begin(v), end(v), 2); //count для подсчёта

    cout << count_if(begin(v), end(v), Gt2);
    cout << endl;
    cout << count_if(begin(v), end(v), Lt2);
    //count_if для подсчёта с некоторым свойством
    //третьим аргументом ей нужна функция кототорая возвращает true или false
    return 0;
} //Это наша функция, которую мы определили для своих нужд. 



//При этом данная функция определена достаточно далеко от кода, 
//в котором мы ее используем. То есть смотрите: вот мы ее вызываем ("Gt2"), 
//но мы не видим ее определения при этом, нам надо туда переходить, 
//после этого мы видим внутренний код; и на самом деле велика вероятность, 
//что эта функция вообще будет использоваться всего один раз в вашей программе, 
//всего один раз в каком-то месте вам надо узнать, больше ли ваши элементы, 
//чем два (количество таких элементов). 
//Что в этом месте предлагает язык C++? Лямбда-выражения. 
//Лямбда-выражения — это способ написать функцию на лету, прямо по месту вызова
int main()
{   
    vector<int> v{1, 2, 4, 5, 3};
    cout << count_if(begin(v), end(v), [](int x){ //мы сделали функцию Gt2 в виде лямбда-функции
        if(x>2){
        return true;
    }
    return false;
    });
    return 0;
}



//но это мы захардкодили, надо сделать с вводом с консоли
int main()
{   
    vector<int> v{1, 2, 4, 5, 3};
    int N = 0;
    cin >> N; //принимаем число от которого будем сравнивать
    cout << count_if(begin(v), end(v), [N](int x){ //мы сделали функцию Gt2 в виде лямбда-функции
        if(x>N){
        return true;
    }
    return false;
    });
    return 0;
}

/*
min/max - вычисляют наименьшее/наибольшее из 2 элементов
sort - сортирует интервал
count(begin, end, elem) для подсчёта
count_if(begin, end, pred) для подсчёта с некоторым свойством
третьим аргументом ей нужна функция кототорая возвращает true или false
Лямбда-выражения - это способ написать функцию на лету, прямо по месту вызова
*/