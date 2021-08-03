//Напишите функцию, которая называется PalindromFilter
//возвращает vector<string>
//принимает vector<string> words и int minLength и возвращает все 
//строки из вектора words, которые являются палиндромами и имеют длину не меньше minLength
//Входной вектор содержит не более 100 строк, длина каждой строки не больше 100 символов.

//На проверку пришлите файл с реализацией функции PalindromFilter. 
//Ваш файл может содержать и другие функции, если они вам необходимы.
//В этой задаче ваша программа не обязана что-то считывать из stdin 
//и записывать в stdout — тестирующая система будет вызывать вашу функцию PalindromFilter напрямую

#include <iostream>
#include <string>
#include <vector>
using namespace std;

bool IsPalindrom(string s){
    string temp;
    for(int i = s.size()-1; i >= 0; --i){
        temp += s[i];
    }
    if(s == temp) 
        return true;
    else
        return false;
}

vector<string> PalindromFilter(vector<string> words, int minLength){
    vector<string> result;
    for(auto i : words){
        if(i.size() >= minLength){
            if(IsPalindrom(i))
                result.push_back(i);
        }
    }
    return result;
}

int main(){
    vector<string> vec = {"abba", "weew", "bro", "code", "abacaba"};
    vector<string> b;
    b = PalindromFilter(vec, 3);    
    for(auto i : b){
        cout << i << " ";
    }
    getchar();
    return 0;

}





//та же хуйня функции PF только компактнее
vector<string> PalindromFilter(vector<string> words, int min_length) {
  vector<string> result;
  for (auto s : words) {
    // если требуеые условия выполняются, добавляем s к ответу
    if (s.size() >= min_length && IsPalindrom(s)) {
      result.push_back(s);
    }
  }
  return result;
}
