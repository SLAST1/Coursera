//контейнер MAP (словари)
#include <iostream>
#include <map>
#include <string>
using namespace std;

void PrintMap(const map<int, string>& d){ //так мы перебираем все пары ключ-значение
   cout << "Size = " << d.size() << endl; //у словаря есть метод size
   for(auto item : d){
      cout << item.first << ": " << item.second << endl;
   }
}

void PrintReversedMap(const map<string, int>& d){
   for(auto item : d){
      cout << item.first << ": " << item.second << endl;
   }
}

map<string, int> BuildReverseMap(const map<int, string>& d){
   map<string, int> result;
   for(auto item : d){
      result[item.second] = item.first;
   }
   return result;
}


int main(){
   map<int, string> events;
   events[1941] = "Dennis Ritchie's birth";
   events[1950] = "Bjarne Stroustrup's birth";
   events[1970] = "UNIX epoch start";
   PrintMap(events);

   cout << events[1950] << endl; //а так мы обращаемся к конкретному значению по ключу
   //синтаксис мапа оч похож на синтаксис вектора
   //те же самые []

   events.erase(1941); //мы еще можем удалять с помощью метода erase


   //Я теперь захочу не по году, как вот здесь я делал, 
   //получать названия событий, а, наоборот, по названию события получать год,
   //когда оно случилось. делаем BuildReverseMap

   //для вывода создадим еще PrintReversedMap
   PrintReversedMap(BuildReverseMap(events));
   
   //теперь мы можем обращаться по названиям событий, получать их год.
   map<string, int> event_for_year = BuildReverseMap(events);
   cout << event_for_year["UNIX epoch start"] << endl;
   return 0;
}

/*
Итак, словарь в своих ключах может иметь не только числа, но и строки.
Поскольку он был изначально похож на вектор,
он хранит для каждого индекса-ключа некоторые значения,
словари часто называют ассоциативными массивами:
они ассоциируют с неким ключом некоторые значения.
*/