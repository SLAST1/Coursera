//контейнер SET (множества)
#include <iostream>
#include <string>
using namespace std;

int main() //мы захотим сохранить для каждого человека, является ли он известным
{
   map<string, bool> is_famous_person;
   is_famous_person["Stroustrup"] = true;
   is_famous_person["Ritchie"] = true;
   return 0;
}



//Зачем мне их хранить, если я могу хранить только тех, 
//кто является известными? Хорошо, тогда у меня в словаре значения всегда будут только true. 
//Вопрос: зачем мне хранить эти значения? Наверное, нет. 
//Наверное, я не хотел сохранить словарь, у которого ключ – какая-то осмысленная строчка, 
//а значение – просто true. 
//Наверное, речь все-таки идет о множестве людей, которые являются известными.
//Надо использовать set.

#include <set> //заголовочный файл для юза множеств

void PrintSet(const set<string>& s){
   cout << "Size = " << s.size() << endl; //можно вывести размер множества
   for(auto x : s){ //контейнер set сам проверяет на уникальность множество
      cout << x << endl; //хранит только уникальные элементы
}

int main()
{
   set<string> famous_persons;
   famous_persons.insert("Stroustrup"); //добавление в множество через insert
   famous_persons.insert("Ritchie");
   famous_persons.insert("Anton");
   PrintSet(famous_persons);
   famous_persons.erase("Anton"); //удаление из множества через erase
   PrintSet(famous_persons);

   set<string> month_names = {"January", "February", "March"};
   PrintSet(month_names);

   cout << month_names.count("January") << endl; //выведет сколько Январей в множестве
   return 0;
}



#include <set> 
#include <vector>

int main() //Кроме того, мы, например, по вектору можем создать словарь.
{
   vector<string> v = {"a", "b", "a"}; //могут быть повторяющиеся элементы
   set<string> s(begin(v), end(v)); 
   PrintSet(s); //Попав во множество, элементы вектора избавились от дублей и упорядочились.
   return 0;
}

/*
Множества хранят элементы в отсортированном порядке и не хранят дублирующиеся элементы.
Можно выводит количество элементов
Добавление через insert, удаление через erase
*/