//Классы
//Начнём с изучения того, что же такое приватная секция. 
//Давайте рассмотрим другой пример. 

//Пусть мы теперь хотим работать с маршрутами, например, с железнодорожными. 
//Каждый маршрут будет представлять собой название двух городов. 
//А именно, будет поле source — название города, где маршрут начинается, 
//и поле destination с названием города, где маршрут заканчивается. 
//Кроме того, у нас будет уже написанная кем-то отличная функция — ComputeDistance, 
//которая принимает на вход две строки — название двух городов — и возвращает расстояние между ними. 
//При этом, вероятно, эта функция какая-то тяжёлая, долгая, она, 
//возможно, ходит в какую-то базу данных, где для каждого города берёт его координаты. 
//Вероятно, она потом вычисляет расстояние на земной поверхности между координатами этих городов. 
//В любом случае мы хотим как-то оптимизировать нашу программу,
//не хотим постоянно вызывать функцию ComputeDistance от наших городов. 

//Что же мы придумываем? 
//Мы придумываем сохранить в нашей структуре маршрута ещё одно поле:
//длину этого маршрута, целочисленное поле. В чём же проблема такого подхода? 
//Конечно, можем написать программу так, что она будет отлично работать. 
//Мы не будем вызывать много раз функцию ComputeDistance, мы один раз её вызовем и сохраним в наше поле. 
//А что если мы потом захотим поменять какой-то из городов? 
//Не забудем ли мы вызвать ещё раз функцию ComputeDistance, 
//не забудем ли мы обновить значение нашего поле length? 
//Не поменяем ли мы случайно значение поля length, не поменяв названия города? 
//Нас подстерегает много опасностей в этом месте. 
//Хочется как-то минимизировать количество возможных ошибок при написании нашего кода.

//Нужно запретить прямой доступ к полям, сделать их приватными
struct Route
{
    private:
        string source;
        string destination;
        int length;
};
//если мы закроем доступ, мы не сможем ни поменять содержимое, ни прочитать содержимое
//но доступ к полям можно получить используя МЕТОДЫ:
struct Route
{   
    public:
        string GetSource(){
            return source;
        }
        string GetDestination(){
            return destination;
        }
        int GetLength(){
            return length;
        }
    private:
        string source;
        string destination;
        int length;
};
//таким методом мы дали доступ к полям только для ЧТЕНИЯ
//изменять содержимое мы пока не можем
//НО
//можно вернуть из метода неконстантную ссылку на поле, и тогда с помощью этой ссылки можно будет менять содержимое поля
Route route;
route.GetSource() = "Moscow";
    //бесполезно, поле не изменится
cout << route.GetLength();
    //так теперь можно: доступ на чтение
int destination_name_length = 
    route.GetDestination().length();
    //и так можно

/*
структура(struct) - набор публичных полей
>используем, его консистентность контролировать не нужно
класс(class) скрывает данные, предоставляя определенный интерфейс доступа к ним
>используем, если поля связаны друг с другом и эту связь нужно контролировать
методы вызываются в контексте конкретного объекта
*/