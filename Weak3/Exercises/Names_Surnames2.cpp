//Дополните класс из предыдущей задачи «Имена и фамилии — 1» методом GetFullNameWithHistory:
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
  string GetFullNameWithHistory(int year) {
    // получить все имена и фамилии по состоянию на конец года year
  }
private:
  // приватные поля
};
//
//В отличие от метода GetFullName, метод GetFullNameWithHistory 
//должен вернуть не только последние имя и фамилию к концу данного года, 
//но ещё и все предыдущие имена и фамилии в обратном хронологическом порядке. 
//Если текущие факты говорят о том, что человек два раза подряд изменил 
//фамилию или имя на одно и то же, второе изменение при формировании истории нужно игнорировать.
//Для лучшего понимания формата см. примеры.
//Пример 1:
//Код
int main() {
  Person person;

  person.ChangeFirstName(1900, "Eugene");
  person.ChangeLastName(1900, "Sokolov");
  person.ChangeLastName(1910, "Sokolov");
  person.ChangeFirstName(1920, "Evgeny");
  person.ChangeLastName(1930, "Sokolov");
  cout << person.GetFullNameWithHistory(1940) << endl;
  
  return 0;
}
//Вывод
Evgeny (Eugene) Sokolov
//Пример 2:
//Код
int main() {
  Person person;
  
  person.ChangeFirstName(1965, "Polina");
  person.ChangeLastName(1967, "Sergeeva");
  for (int year : {1900, 1965, 1990}) {
    cout << person.GetFullNameWithHistory(year) << endl;
  }
  
  person.ChangeFirstName(1970, "Appolinaria");
  for (int year : {1969, 1970}) {
    cout << person.GetFullNameWithHistory(year) << endl;
  }
  
  person.ChangeLastName(1968, "Volkova");
  for (int year : {1969, 1970}) {
    cout << person.GetFullNameWithHistory(year) << endl;
  }
  
  person.ChangeFirstName(1990, "Polina");
  person.ChangeLastName(1990, "Volkova-Sergeeva");
  cout << person.GetFullNameWithHistory(1990) << endl;
  
  person.ChangeFirstName(1966, "Pauline");
  cout << person.GetFullNameWithHistory(1966) << endl;
  
  person.ChangeLastName(1960, "Sergeeva");
  for (int year : {1960, 1967}) {
    cout << person.GetFullNameWithHistory(year) << endl;
  }
  
  person.ChangeLastName(1961, "Ivanova");
  cout << person.GetFullNameWithHistory(1967) << endl;
  
  return 0;
}
//Вывод
Incognito
Polina with unknown last name
Polina Sergeeva
Polina Sergeeva
Appolinaria (Polina) Sergeeva
Polina Volkova (Sergeeva)
Appolinaria (Polina) Volkova (Sergeeva)
Polina (Appolinaria, Polina) Volkova-Sergeeva (Volkova, Sergeeva)
Pauline (Polina) with unknown last name
Sergeeva with unknown first name
Pauline (Polina) Sergeeva
Pauline (Polina) Sergeeva (Ivanova, Sergeeva)
//Пример 3:
//Код
int main() {
  Person person;

  person.ChangeFirstName(1965, "Polina");
  person.ChangeFirstName(1965, "Appolinaria");

  person.ChangeLastName(1965, "Sergeeva");
  person.ChangeLastName(1965, "Volkova");
  person.ChangeLastName(1965, "Volkova-Sergeeva");

  for (int year : {1964, 1965, 1966}) {
    cout << person.GetFullNameWithHistory(year) << endl;
  }

  return 0;
}
//Вывод
Incognito
Appolinaria Volkova-Sergeeva
Appolinaria Volkova-Sergeeva
//

#include <iostream>
#include <string>
#include <vector>
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
        if (YearNameSoname.count(year) == 0) YearNameSoname[year].Soname = ""; //если такого года еще нет, то добавим пустую фамилию
        YearNameSoname[year].Name = first_name; //добавим указанное имя
    }

    void ChangeLastName(int year, const string& last_name){
        if (YearNameSoname.count(year) == 0) YearNameSoname[year].Name = ""; //если такого года еще нет, то добавим пустое имя
        YearNameSoname[year].Soname = last_name; //и добавим указанную фамилию
    }

    string GetFullName(int year){
        if (YearNameSoname.size() == 0){
            return "Incognito";
        }
        else{
            for (const auto& i : YearNameSoname){
                if (year < i.first) return "Incognito"; //если искомый год меньше первого года изменения
                break;
            }
        }
        //иначе
        string nm = "";
        string sn = "";
        for (const auto& i : YearNameSoname){ //листаем структуру
            //и будем присваивать переменной sn значение фамилии, если она не пустая и пока искомый год больше текущего(в структуре)
            if (i.first <= year && i.second.Soname != "") sn = i.second.Soname;
            if (i.first <= year && i.second.Name != "") nm = i.second.Name; //тоже самое с именем
        }
        if(nm == "") return sn + " with unknown first name"; //условие, если имя пустое(вывод фамилии и текста)
        else if(sn == "") return nm + " with unknown last name"; //условие, если фамилия пуста (вывод имени и текста)
        else return nm + " " + sn; //вывод имени и фамилии
    }
    string GetFullNameWithHistory(int year){
        if (YearNameSoname.size() == 0){
            return "Incognito";
        }
        else{
            for (const auto& i : YearNameSoname){
                if (year < i.first) return "Incognito"; //если искомый год меньше первого года изменения
                break;
            }
        }
        //иначе
        string nm = "";
        string sn = "";
        vector<string> secondnames;
        vector<string> firstnames;
        for (const auto& i : YearNameSoname){ //листаем структуру
            //и будем присваивать переменной sn значение фамилии, если она не пустая и пока искомый год больше текущего(в структуре)
            if (i.first <= year && i.second.Soname != ""){ //если Фамилия непуста
                if (i.second.Soname != sn && sn != ""){ //и не повторяется
                    secondnames.push_back(sn);
                }
                sn = i.second.Soname; //тут присваиваем
            }
            if (i.first <= year && i.second.Name != ""){ //то же самое с Именем
                if (i.second.Name != nm && nm != ""){
                    firstnames.push_back(nm);
                }
                nm = i.second.Name;
            }
        }
        //инициализируем переменные в которые будем складывать фамилии и имена в обратном порядке
        string secnames_string = "", firstnames_string = "";
        if (secondnames.size() > 0){
            secnames_string += " (" + secondnames[secondnames.size() - 1]; //добавим в строку пробел, скобку и предыдущую фамилию
            if (secondnames.size() > 1){
                for (int i = secondnames.size() - 1; i > 0; --i){ //в обратном порядке
                    secnames_string += ", " + secondnames[i - 1]; //добавим в строку остальные фамилии
                }
            }
            secnames_string += ")";
        }
        //аналогично с именами
        if (firstnames.size() > 0){
            firstnames_string += " (" + firstnames[firstnames.size() - 1];
            if (firstnames.size() >1){
                for (int i = firstnames.size() - 1; i > 0; --i){
                    firstnames_string += ", " + firstnames[i - 1];
                }
            }
            firstnames_string += ")";
        }
        //в зависимости от наличия Имени и Фамилии, вернем соответствующие сообщения
        if (nm == "") return sn + secnames_string + " with unknown first name";
        else if (sn == "") return nm + firstnames_string + " with unknown last name";
        else return nm + firstnames_string + " " + sn + secnames_string;
    }
private:
    map<int, FullName> YearNameSoname;
};





#include <algorithm>
#include <map>
#include <vector>
#include <string>
using namespace std;

vector<string> FindNamesHistory(const map<int, string>& names_by_year,
                                int year){
  vector<string> names;
  // перебираем всю историю в хронологическом порядке
  for (const auto& item : names_by_year){
    // если очередное имя не относится к будущему и отличается от предыдущего,
    if (item.first <= year && (names.empty() || names.back() != item.second)){
      // добавляем его в историю
      names.push_back(item.second);
    }
  }
  return names;
}

string BuildJoinedName(vector<string> names){
  // нет истории — имя неизвестно
  if (names.empty()){
    return "";
  }
  // меняем прямой хронологический порядок на обратный
  reverse(begin(names), end(names));
  
  // начинаем строить полное имя с самого последнего
  string joined_name = names[0];
  
  // перебираем все последующие имена
  for (int i = 1; i < names.size(); ++i){
    if (i == 1){
      // если это первое «историческое» имя, отделяем его от последнего скобкой
      joined_name += " (";
    } else{
      // если это не первое имя, отделяем от предыдущего запятой
      joined_name += ", ";
    }
    // и добавляем очередное имя
    joined_name += names[i];
  }
  
  // если в истории было больше одного имени, мы открывали скобку — закроем её
  if (names.size() > 1){
    joined_name += ")";
  }
  // имя со всей историей готово
  return joined_name;
}

// см. решение предыдущей задачи
string BuildFullName(const string& first_name, const string& last_name){
  if (first_name.empty() && last_name.empty()){
    return "Incognito";
  } else if (first_name.empty()){
    return last_name + " with unknown first name";
  } else if (last_name.empty()){
    return first_name + " with unknown last name";
  } else{
    return first_name + " " + last_name;
  }
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
    // найдём историю изменений имени и фамилии
    // в данном случае это излишне, так как нам достаточно узнать последние имя и фамилию, но почему бы не использовать готовые функции?
    const vector<string> first_names_history = FindFirstNamesHistory(year);
    const vector<string> last_names_history = FindLastNamesHistory(year);
    
    // подготовим данные для функции BuildFullName: возьмём последние имя и фамилию или оставим их пустыми, если они неизвестны
    string first_name;
    string last_name;
    if (!first_names_history.empty()){
      first_name = first_names_history.back();
    }
    if (!last_names_history.empty()){
      last_name = last_names_history.back();
    }
    return BuildFullName(first_name, last_name);
  }
  
  string GetFullNameWithHistory(int year){
    // получим полное имя со всей историей
    const string first_name = BuildJoinedName(FindFirstNamesHistory(year));
    // получим полную фамилию со всей историей
    const string last_name = BuildJoinedName(FindLastNamesHistory(year));
    // объединим их с помощью готовой функции
    return BuildFullName(first_name, last_name);
  }

private:
  vector<string> FindFirstNamesHistory(int year){
    return FindNamesHistory(first_names, year);
  }
  vector<string> FindLastNamesHistory(int year){
    return FindNamesHistory(last_names, year);
  }

  map<int, string> first_names;
  map<int, string> last_names;
};