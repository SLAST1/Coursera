//Реализуйте класс для человека, поддерживающий историю изменений человеком своих фамилии и имени.
class Person {
public:
  void ChangeFirstName(int year, const string& first_name) {
    // добавить факт изменения имени на first_name в год year
  }
  void ChangeLastName(int year, const string& last_name) {
    // добавить факт изменения фамилии на last_name в год year
  }
  string GetFullName(int year) {
    // получить имя и фамилию по состоянию на конец года year
  }
private:
  // приватные поля
};
//
//Считайте, что в каждый год может произойти не более одного 
//изменения фамилии и не более одного изменения имени. 
//При этом с течением времени могут открываться всё новые факты из прошлого человека, 
//поэтому года́ в последовательных вызовах методов ChangeLastName и ChangeFirstName не обязаны возрастать.
//Гарантируется, что все имена и фамилии непусты.
//Строка, возвращаемая методом GetFullName, 
//должна содержать разделённые одним пробелом имя и фамилию человека по состоянию на конец данного года.
//Если к данному году не случилось ни одного изменения фамилии и имени, верните строку "Incognito".
//Если к данному году случилось изменение фамилии, но не было ни одного изменения имени, верните "last_name with unknown first name".
//Если к данному году случилось изменение имени, но не было ни одного изменения фамилии, верните "first_name with unknown last name".
//Пример:
//Код
int main() {
  Person person;
  
  person.ChangeFirstName(1965, "Polina");
  person.ChangeLastName(1967, "Sergeeva");
  for (int year : {1900, 1965, 1990}) {
    cout << person.GetFullName(year) << endl;
  }
  
  person.ChangeFirstName(1970, "Appolinaria");
  for (int year : {1969, 1970}) {
    cout << person.GetFullName(year) << endl;
  }
  
  person.ChangeLastName(1968, "Volkova");
  for (int year : {1969, 1970}) {
    cout << person.GetFullName(year) << endl;
  }
  
  return 0;
}
//
//Вывод
Incognito
Polina with unknown last name
Polina Sergeeva
Polina Sergeeva
Appolinaria Sergeeva
Polina Volkova
Appolinaria Volkova
//

#include <iostream>
#include <string>
#include <map>
using namespace std;

struct FullName
{
    string Name;
    string Soname;
};
class Person
{
public:
    void ChangeFirstName(int year, const string& first_name){
        if (YearNameSoname.count(year) == 0) YearNameSoname[year].Soname = ""; //если такого года еще нет, то добавим пустую фамилию в этот год
        YearNameSoname[year].Name = first_name; //добавим указанное имя
    }
    void ChangeLastName(int year, const string& last_name){
        if (YearNameSoname.count(year) == 0) YearNameSoname[year].Name = ""; //если такого года еще нет, то добавим пустое имя в этот год
        YearNameSoname[year].Soname = last_name; //и добавим указанную фамилию
    }
    string GetFullName(int year){
        if (YearNameSoname.size() == 0){
            return "Incognito";
        }
        else{
            for (const auto& i : YearNameSoname){
                if (year < i.first) 
                return "Incognito"; //если искомый год меньше первого года изменения
                break;
            }
        }
        //иначе
        string nm = "";
        string sn = "";
        for (const auto& i : YearNameSoname){ //листаем структуру
            //и будем присваивать переменной sn значение фамилии, если она не пустая и пока искомый год больше текущего(в структуре)
            if (i.first <= year && i.second.Soname != "") sn = i.second.Soname;
            //тоже самое с именем
            if (i.first <= year && i.second.Name != "") nm = i.second.Name;
        }
        if(nm == "") return sn + " with unknown first name";
        else if(sn == "") return nm + " with unknown last name";
        else return nm + " " + sn;
    }
private:
    map<int, FullName> YearNameSoname;
};





#include <map>
#include <string>

// если имя неизвестно, возвращает пустую строку
string FindNameByYear(const map<int, string>& names, int year){
  string name;  // изначально имя неизвестно
  // перебираем всю историю по возрастанию ключа словаря, то есть в хронологическом порядке
  for (const auto& item : names){
    // если очередной год не больше данного, обновляем имя
    if (item.first <= year){
      name = item.second;
    } else{
      // иначе пора остановиться, так как эта запись и все последующие относятся к будущему
      break;
    }
  }
  
  return name;
}

class Person
{
public:
  void ChangeFirstName(int year, const string& first_name){
    first_names[year] = first_name;
  }
  void ChangeLastName(int year, const string& last_name){
    last_names[year] = last_name;
  }
  string GetFullName(int year){
    // получаем имя и фамилию по состоянию на год year
    const string first_name = FindNameByYear(first_names, year);
    const string last_name = FindNameByYear(last_names, year);
    
    // если и имя, и фамилия неизвестны
    if (first_name.empty() && last_name.empty()){
      return "Incognito";
    
    // если неизвестно только имя
    } else if (first_name.empty()){
      return last_name + " with unknown first name";
      
    // если неизвестна только фамилия
    } else if (last_name.empty()){
      return first_name + " with unknown last name";
      
    // если известны и имя, и фамилия
    } else{
      return first_name + " " + last_name;
    }
  }

private:
  map<int, string> first_names;
  map<int, string> last_names;
};