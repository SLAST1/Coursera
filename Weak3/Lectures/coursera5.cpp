//Инициализация переменных
#include <iostream>
#include <string>
#include <vector>
using namespace std;

void PrintInt(){
    int x;
    cout << x << endl;
}

void PrintDouble(){
    double pi = 3.14;
    cout << pi << endl;
}

int main()
{
    PrintInt(); //выведет 0
    PrintDouble(); //выведет 3.14
    PrintInt(); //но вот если мы второй раз сделаем вызов этой функции, то выводить будет рандом хуйню
    return 0;
}
//Принцип языка с++ - ты не платишь за то, что не используешь (Zero overhead principle)
//int value; //мне всё равно, что будет в переменной
//int value = 0; //мне необходимо, чтобы в value был ноль



void PrintParity(int x){
    string parity;
    if(x%2 == 0){
        parity = "even";
    } else{
        parity = "odd";
    }
    cout << x << " is " << parity;
}

int main()
{
    PrintParity(5); //вывод 5 is odd
    return 0;
}



//но можно было куда проще сделать и короче, используя Тернарный оператор
void PrintParity(int x){
    string parity = (x%2 == 0) ? "even" : "odd";
    cout << x << " is " << parity;
}

int main()
{
    PrintParity(5); //вывод 5 is odd (всё так же)
    return 0;
}
//благодаря тернарному оператору мы смогли проинциализировать переменную в месте объявления



void PrintPositivity(int x){
    string positivity;
    if(x>0){
        positivity = "positive"
    } else if(x<0){
        positivity = "negative"
    } else{
        positivity = "zero"
    }
    cout << x << " is " << positivity;
}

int main()
{
    PrintPositivity(2);
    PrintPositivity(0);
    PrintPositivity(-5);
    return 0;
}
//всё работает, но мы никак не проинциализировали переменную
//тернарный оператор нам уже не поможет, тк вариантов больше двух
//тогда надо просто условие вынести в отдельную функцию
string GetPositivity(int x){
    if(x>0){
        return "positive"
    } else if(x<0){
        return "negative"
    } else{
        return "zero"
    }
}

void PrintPositivity(int x){
    string positivity = GetPositivity(x);
    cout << x << " is " << positivity;
}

int main()
{
    PrintPositivity(2);
    PrintPositivity(0);
    PrintPositivity(-5);
    return 0;
}
//вот теперь более правильно

/*
я изучил полезную технику как инициализировать переменную в месте где кажется что ее инициализировать нельзя
значение неициализированной переменной неопределено
надо стараться инициализировать переменные при объявлении
в этом помогают тернарный оператор и выделение функций
*/