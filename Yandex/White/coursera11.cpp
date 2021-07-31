//ФУНКЦИИ
//упрощают понимание кода
//имя помогает понять ее тело
//упрощает повторное использование
//это единственный способ реализовать рекурсию

#include <iostream>
using namespace std;

int main()          //обычная программа на +
{
    int x, y;
    cin >> x >> y;
    cout << x+y << endl;
}



#include <iostream>         //программа с использованием вызова функции
using namespace std;

int Sum (int x, int y){         //для кадого параметра функции нужно указывать его тип
    return x+y;                 //а для возврата значения именно RETURN
}                               //тк она завершает выполнение функции

int main()
{
    int x, y;
    cin >> x >> y;
    cout << Sum(x, y);
    return 0;
}



#include <iostream>
#include <string>
#include <vector> 
using namespace std;

bool Contains(vector<string> words, string w){          //фунцкия найдет искомое слово среди вектора строк
    for(auto s : words){
        if(s == w){
            return true;
        }
    }
    return false;
}

int main()
{
    cout << Contains({"fire", "water", "air"}, "water") << endl;
    return 0;
}



#include <iostream>         //то же самое, только функция которая не возвращает значения(поэтому VOID), а сразу делает
#include <string>
#include <vector> 
using namespace std;

void PrintWords(vector<string> words){
    for(auto w : words){
        cout << w << endl;
    }
}

int main()
{
    PrintWords({"fire", "water", "air"}, "water")
    return 0;
}

/*В функции передаются копии тех значений, которые переданы в нее в месте вызова,
то есть копии фактических параметров функции.
*/