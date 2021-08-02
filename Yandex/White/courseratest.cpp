#include <string>
#include <iostream>
#include <map>
#include <algorithm>
using namespace std;
 
class Person {
public:// тут лежат необходимые методы
    void ChangeFirstName(int year, const string& first_name) {
        // добавить факт изменения имени на first_name в год year
        Fullname firstname; // в привате создал тип переменной Fullname
        firstname.FirstName = first_name; // заношу в нее данные (первое имя)
        firstname.Year = year; // год перемены имени (первого имени)           
    }
    void ChangeLastName(int year, const string& last_name) {
        // добавить факт изменения фамилии на last_name в год year
        Fullname lastname; 
        lastname.LastName = last_name; //добавляем last name
        lastname.Year = year;// добавляем год перемены
        
        }
    string GetFullName(int year) {
        // получить имя и фамилию по состоянию на конец года year
        map<int, Fullname> Names; // создаем словарь для хранения пары  год - имя, фамилия
        for (const auto& i : Names) {// перебираем словарь чтобы отчленить пары значений
            if (year != i.first) { // проходимся по условиям задачи, если изменений имени, фамилии не проводилось, то...
                return "incognito";
        
            }
            else if (year == i.first && i.second.FirstName == "") {// если  имя отсутствует и менялась только фамилия, то 
                return i.second.LastName + " with unknown first name";
                
            }
            else if (year == i.first && i.second.LastName == "") { // если менялось только имя, а фамилии в словаре нет, то
                return i.second.FirstName + " with unknown last name";
            }
            else if (year == i.first && i.second.FirstName != "" && i.second.FirstName != "") { // ну а если менялось и то и то (и имя и фамилия имеются в словаре), то
                return i.second.FirstName + " " +  i.second.LastName;
            }
        }
        
 
    
            
        
    }
private:
    // приватные поля
    struct Fullname { // а вот и наша структура, которой мы пользовались выше
        int Year;
        string FirstName;
        string LastName;
 
    };
    
};
 
 
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