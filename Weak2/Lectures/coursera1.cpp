//coursera
//Функции
#include <iostream>
using namespace std;

int main() //обычная программа
{
    int x, y;
    cin >> x >> y;
    cout << x+y << endl;
}



//программа с использованием вызова функции
int Sum (int x, int y) //для кадого параметра функции нужно указывать его тип
{                      //а для возврата значения именно RETURN
    return x+y;      //тк она завершает выполнение функции          
}                               

int main()
{
    int x, y;
    cin >> x >> y;
    cout << Sum(x, y);
    return 0;
}




//фунцкия найдет искомое слово среди вектора строк
bool Contains(vector<string> words, string w) 
{          
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



//то же самое, только функция которая не возвращает значения(поэтому VOID), а сразу делает
void PrintWords(vector<string> words)
{
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
 *то есть копии фактических параметров функции.
 *упрощают понимание кода
 *имя помогает понять ее тело
 *упрощает повторное использование
 *это единственный способ реализовать рекурсию
 */