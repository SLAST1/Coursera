//Параметризованные конструкторы
//Конструктор — это специальный метод класса, 
//у которого нет возвращаемого значения, потому что понятно, 
//что конструктор должен просто создать объект.
//Он не может вернуть число, если у меня класс маршрута, это было бы довольно странно. 
//Итак, возвращаемого типа нет, а название этого метода совпадает с названием класса. 
//То есть чтобы объявить в классе конструктор, 
//я должен написать название типа вместо названия метода и затем уже в круглых скобках 
//привычный нам список параметров. 
//Если я хочу конструктор, который будет принимать на вход названия двух городов, 
//я в этом методе (как бы методе, а на самом деле — конструкторе) 
//приму два параметра, две строки — new_source и new_destination. 
//И затем уже в теле этого конструктора я могу уже написать тот код, 
//который я уже писал и без конструктора: вызвать методы SetSource и SetDestination, 
//соответственно, проинициализировав поля source и destination. 

class Route
{
    public:
        Route(const string& new_source,
              const string& new_destination){
            SetSource(new_source);
            SetDestination(new_destination);
        }
};

Route route("Moscow", "Piter");
    //теперь работает
cout << "Route from Moscow to Piter " << "has lenght " << route.GetLenght() << "\n"

//У меня есть конструктор, я могу создавать переменную удобно. 
//Я могу после названия переменной в круглых скобках писать, какими должны быть названия городов. 
//Итак, я могу легко создать переменную и затем обратиться к какому-то методу этой переменной. 
//Но если подумать, что я делал в конструкторе?
//Я вызывал метод SetSource и метод SetDestination. 
//А что происходило внутри этих методов? 
//Внутри метода SetSource просто выставилось значение поля source и вызвался метод UpdateLength.

//НО
//Зачем-то дважды вычисляется расстояние между двумя городами. 
//Давайте перепишем наш конструктор. 
//Давайте не будем использовать методы, которые предназначены для того, чтобы вызывать их снаружи для каких-то объектов.

class Route
{
    public:
        Route(const string& new_source,
              const string& new_destination){
            source = new_source;
            destination = new_destination;
        }
        //...
};



//Примеры использования конструкторов

//Что если у вас есть конкретные названия городов, 
//вы хотите создать маршрут между ними и передать его в функцию? 
//В этом случае опять же вы можете в списке аргументов функции 
//написать название типа Route и в круглых скобках сразу, не создавая никакой переменной, 
//перечислить названия городов, перечислить аргументы параметризованного конструктора. 
//Или использовать уже известный синтаксис с фигурными скобками: 
//не указывая названия типа Route, просто в списке аргументов функции 
//поставить фигурные скобки и в них перечислить аргументы параметризованного конструктора, 
//просто перечислить названия городов. 
//То есть, по сути, читая эту строчку, любой программист поймет: 
//ага, тот, кто писал этот код, хочет распечатать маршрут от Звенигорода до Истры.

void PrintRoute(const Route& route);

PrintRoute(Route()); //по умолчанию
PrintRoute({}); //тип понятен из заголовка функции

//параметризированный
PrintRoute(Route("Moscow", "Piter"));
PrintRoute({"Moscow", "Piter"});



//Тот же самый удобный синтаксис с фигурными скобками можно использовать, 
//если вы хотите вернуть конкретный маршрут из какой-то функции. 
//Например, мы пишем простейшую глупую функцию GetRoute, 
//которая принимает флажочек is_empty, и если этот флажочек — true, 
//то мы хотим вернуть пустой маршрут, маршрут по умолчанию. 
//Как мы это сделаем? Если флажочек — true, напишем if, и в этой ветке напишем return, 
//и в return'е явно напишем, что мы хотим вызвать конструктор по умолчанию, что мы хотим вернуть маршрут по умолчанию.

Route GetRoute(boot is_empty){
    if(is_empty){
        return {};
    } else{
        return {"Moscow", "Piter"};
    }
}



//Итак, в теле конструктора просто присваиваю новое значение полю source, 
//новое значение полю destination, и вызываю метод UpdateLength, 
//чтобы в поле length оказалось расстояние между городами source и destination. 
//Отлично. У нас есть так называемый параметризованный конструктор. 

/*
Конструктор - это специальный метод класса, 
у которого нет возвращаемого значения, потому что понятно, 
что конструктор должен просто создать объект.
Он принимает на вход два параметра и помогает нам создать объект 
с конкретными названиями городов, создать объект по этим параметрам.
Структуры не нуждаются в конструкторах!
Если нужен только конструктор по умолчанию, достаточно задать значения по умолчанию для полей
*/