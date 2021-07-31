//задача на палиндром
#include <iostream>
#include <string>
using namespace std;

bool IsPalindrom(string word){
    int len = word.length();
    for(int i = 0; i < len/2; ++i){
		if(word[i] != word[len-i-1]){
			return false;
		}
	}
    return true;
}

int main(){
    string word;
    cin >> word;
    cout << IsPalindrom(word);
    return 0;
}


//////////
bool IsPalindrom(string s) {
    // Замечание: более правильным было бы использовать здесь тип size_t вместо int
    // О причинах Вы узнаете на Жёлтом поясе
    for (int i = 0; i < s.size()/2; ++i) {
        if (s[i] != s[s.size()-i-1]) {
            return false;
        }
    }
    return true;
}





//задача на отбор палиндромов
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


//////////та же хуйня функции PF только компактнее
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





//задача на перемещение строк
#include <iostream>
#include <vector>
#include <string>
using namespace std;

void MoveStrings(vector<string>& source, vector<string>& destination){
    for (auto x : source) {
        destination.push_back(x);
    }
    source.clear();
}

int main(){
    vector<string> source = {"a", "b", "c"};
    vector<string> destination = {"z"};
    MoveStrings(source, destination);
    int i = 0;
    for (auto i : destination) {
        cout << i << " ";
    }
    return 0;
}





//задача на реверс последовательности
#include <iostream>
#include <vector>
using namespace std;

void Reverse(vector<int>& v){
    int size = v.size();
    vector<int> c = v;
    for (auto i : c){
        v[size - 1] = i;
        size--;
    }
}

int main(){
    vector<int> numb = {5,4,3,1,2}; 
    Reverse(numb);
    for (auto i : numb){
        cout << i << " ";
    }
    return 0;
}   


//////////
void Reverse(vector<int>& v) {
  int n = v.size();  // для удобства сохраним размер вектора в переменную n
  for (int i = 0; i < n/2; ++i) {
    // элемент с индексом i симметричен элементу с индексом n-1-i
    // поменяем их местами с помощью временной переменной tmp
    int tmp = v[i];
    v[i] = v[n-1-i];
    v[n-1-i] = tmp;
  }
}




//задача на реверс последовательности 2
#include <iostream>
#include <vector>
using namespace std;

vector<int> Reversed(const vector<int>& v){
    int size = v.size();
    vector<int> c = v;
    for (auto i : v){
        c[size - 1] = i;
        size--;
    }
    return c;
}

int main(){
    vector<int> numb = {5,4,3,1,2};
    for (auto i : Reversed(numb)){
        cout << i << " ";
    }
    return 0;
}


//////////
vector<int> Reversed(const vector<int>& input)
{
    vector<int> result;
    for (int i = input.size() - 1; i >= 0; --i) {
        result.push_back(input[i]);
    }
    return result;
}