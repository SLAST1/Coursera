//Реализуйте класс ReversibleString, хранящий строку и 
//поддерживающий методы Reverse для переворота строки и ToString для получения строки.
//Пример:
//Код
int main() {
  ReversibleString s("live");
  s.Reverse();
  cout << s.ToString() << endl;
  
  s.Reverse();
  const ReversibleString& s_ref = s;
  string tmp = s_ref.ToString();
  cout << tmp << endl;
  
  ReversibleString empty;
  cout << '"' << empty.ToString() << '"' << endl;
  
  return 0;
}
//Вывод
evil
live
""
//

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class ReversibleString
{
private:
    string name;
 
public:
    ReversibleString(){}
    ReversibleString(const string& s){
         name = s;
    }

    void Reverse(){
        reverse(begin(name), end(name));
    }

    string ToString() const{
        return name;
    }
};
 
int main(){
    ReversibleString s("live");
    s.Reverse();
    cout << s.ToString() << endl;
 
    s.Reverse();
    const ReversibleString& s_ref = s;
    string tmp = s_ref.ToString();
    cout << tmp << endl;
 
    ReversibleString empty;
    cout << '"' << empty.ToString() << '"' << endl;
    return 0;
}





#include <algorithm>
#include <string>
using namespace std;

class ReversibleString{
public:
  ReversibleString(){}
  ReversibleString(const string& s){
    data = s;
  }

  void Reverse(){
    reverse(begin(data), end(data));
  }

  string ToString() const{
    return data;
  }
private:
  string data;
};