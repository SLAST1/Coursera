//Функции min, max, sort
#include <iostream>
using namespace std;

int Min(int a, int b){ //функция принимает 2 числа, вычислять минимальное
    if(a<b){
        return a;
    }
    return b;
}

int Max(int a, int b){ //функция принимает 2 числа, вычислять максимальное
    if(a>b){
        return a;
    }
    return b;
}

int main()
{
    cout << Min(2,3) << endl;
    cout << Max(2,3) << endl;
    reutrn 0;
}



//но всё это слишком долго и много кода
//все те же действия есть в стандартной библиотеке algorithm
//и займёт минимум места
#include <algorithm>
int main()
{
    cout << min(2,3) << endl;
    cout << max(2,3) << endl;
    return 0;
}



#include <algorithm>
#include <string>
int main() //всё так же работает для строк
{   
    string s1 = "abc";
    string s2 = "bca";
    cout << min(s1,s2) << endl;
    cout << max(s1,s2) << endl;
    return 0;
}



//так же есть функция sort
#include <algorithm>
#include <string>
#include <vector>
void Print(const vector<int>&, const string& title){
    cout << title << ": "
    for(auto i:v){
        cout << i << ' ';
    }
}

int main()
{   
    vector<int> v{1, 2, 4, 5, 3};
    
    Print(v, "init");
    sort(begin(v), end(v));
    cout << endl;
    Print(v, "sort");
    return 0;
}

/*
min/max - вычисляют наименьшее/наибольшее из 2 элементов
sort - сортирует интервал
*/