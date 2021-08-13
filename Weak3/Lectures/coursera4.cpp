//Области видимости переменных
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main()//такая программа не скомпилируется
{
    {
    int x = 5;
    {
        cout << x;
    }
    cout << x;
    }
    cout << x; //но если закоментировать эту строку, всё будет работать
}



int main()//такая программа тоже не скомпилируется
{
    if(1>0){
        int x = 5;
    }
    cout << x; //потом что переменная объявлена внутри тела оператора
}

/*
переменная видна после объявления и до конца блока, в котором она объявлена
переменные, которые объявлены внутри тела, они за пределами этого тела не видны
слишком большая область видимости переменных может приводить к ошибкам
надо стараться минимизировать видимость переменных
*/