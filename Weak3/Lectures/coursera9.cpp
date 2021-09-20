//Деструкторы
//Рассмотрим снова наш класс маршрута. В нём уже есть конструкторы: 
//конструктор без параметров, конструктор с параметрами, и методы GetSource, GetDestination, GetLength и тд. 
//Давайте вот что сделаем. 
//Мы в нашем классе вызываем метод UpdateLength периодически, 
//и как будто бы в реальной жизни он может быть долгим - это сейчас у меня написано 
//как заглушка для функции ComputeDistance какое-то странное вычисление 
//расстояния между городами - на самом деле нет, 
//в реальности это может быть вхождение в какую-то базу данных. 
//Поэтому этот метод может быть долгим и поэтому в какой-то момент может получиться так, что наш класс работает долго.

//Мы хотим понять почему, подозреваем в замедлении работы метод UpdateLength, 
//даже функцию ComputeDistance, и хотим как-то замерить для конкретного объекта маршрута, 
//для каких городов мы вызывали на протяжении всей жизни этого объекта метод UpdateLength.

#include <iostream>
#include <string>
using namespace std;

int ComputeDistance(const string& source, const string& destination){
    return source.lenght() - destination.lenght();
}

class Route
{
    public:
        Route(){
            source = "Moscow";
            destination = "Piter";
            UpdateLenght();
        }

        Route(const string& new_source, const string& new_destination){
            source = new_source;
            destination = new_destination;
            UpdateLenght();
        }

        ~Route(){ //сам деструктор
            for(const string& entry : compute_distance_log){
                cout << entry << "\n"
            }
        }

        string GetSource() const{
            return source;
        }

        string GetDestination() const{
            return destination;
        }

        int GetLenght() const{
            return lenght;
        }

        void SetSource(const string& new_source){
            source = new_source;
            UpdateLenght();
        }

        void SetDestination(const string& new_destination){
            destination = new_destination;
            UpdateLenght();
        }

    private:
        void UpdateLenght(){
            lenght = ComputeDistance(source, destination);
            compute_distance_log.push_back(source + " - " + destination);
        }
        string source;
        string destination;
        int lenght;
        vector<string> compute_distance_log; //лог вызовов функции ComputeDistance.
};

int main()
{   
    Route route("Moscow", "Piter");
    route.SetSource("Almaty");
    route.GetDestination("Astana");
    return 0;
}
/*
Деструктор - это обратное конструктору
Вызывается при уничтожении объекта
Назначение - откат действий, сделанных в конструкторе или других методах:
>закрытие открытого файла
>освобождение выделенной вручную памяти
Можно осуществлять любые другие действие, например, вывод какой то информации
На практике писать деструктор самому нужно очень редко
*/