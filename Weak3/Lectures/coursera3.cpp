//range-based-for
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

//представим что нам нужно все элементы увеличить на 1
void Print(const vector<int>&, const string& title){
    cout << title << ": "
    for(const auto& i:v){ //тут только читай(страхуем себя)
        cout << i << ' ';
    }
}

int main()
{   
    vector<int> v{1, 2, 4, 5, 3};
    Print(v, "init");
    for(auto& i : v){ //не забыть дописать ссылку &
        ++i;
    }
    cout << endl;
    Print(v, "incr");
    return 0;
}

/*
for(auto& item : vec){
    можно модифицировать эл item из vec
}

for(const auto& item : vec){
    можно использовать немодифицирующие 
    для item из vec
}
*/