//cousera
#include <iostream>
#include <string>
#include <vector>
#include <map> //словарь
using namespace std;

struct Person //создали свою структуру для описание к примеру человека
{
    string Name;
    string Surname;
    int age;
};

int main()
{   
    vector<Person> staff; //пользовательский тип (вектор типа Person)
    staff.push_back({"Ivan", "Ivanov", 25}); //добавляем по описанию из 3 аргументов
    staff.push_back({"Petr", "Petrov", 32});
    cout << staff[0].Name << " \n"; //узнаем результат определенного аргумента по номеру индекса указанного в [] относящемуся к Нашему типу
                                    //указываем после точки по какому именно параметру вести отсчёт (индексация с 0 кста)

    //std::cout << "hello world\n";

    int n = -5;
    float pi = 3.15;
    bool blabla = true;
    char symba = 'Z';

    string ppz = "priver, privet zdarova!";
    
    vector<int> nums = {1, 4, 7, 9}; //это значит что дан ВЕКТОР ЦЕЛЫХ ЧИСЕЛ
    //тоесть то что в кавычках означает вектор КАКОГО типа данных у меня хранится в переменной nums
    
    map<string, int> String_to_Value; //map это структура данных которая может помогать отображать один тип вместе в другим
    String_to_Value["one"] = 1; //привязывая один тип к другому
    String_to_Value["two"] = 2; //вот как тут string и int
    String_to_Value["three"] = 3;
    //cout << "two is " << String_to_Value["two"] << "\n";

    return 0;
}


/*ИТОГ:
 *Познакомился с базовыми типами int, float, double, char, bool
 *Познакомился с типами vector, string, map
 *Увидел как создавать свои типы и интергировать их в другие*/