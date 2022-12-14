// laba four.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
using namespace std;



struct times {
    int h;
    int m;
    int s;
};


int hms_to_secs(int h, int m,int s) {
    long result = h * 3600 + m * 60 + s; //Тело функции с переводом минут, часов в секунды ( 1 задание)
    return result;
}

int time_to_secs(times h1) {
    return hms_to_secs(h1.h, h1.m, h1.s); //Переводим переменную типа time в секунды
}

times secs_to_time(long secs) {
    times t3;
    t3.s = secs % 60;//Вычисляем количество секунд в итоге с помощью остатков
    t3.m = (secs % 3600 - t3.s) / 60; // Вычисляем количество минут с помощью остатков, помня, что мы уже заняли некоторые секунды
    t3.h = (secs - secs % 3600) / 3600; //Аналогично минутам, вычисляем для часов
    return t3;
}

void swap(int& a, int& b) {
    int c;//Временная перменная для хранения во время обмена
    c = a;
    a = b;
    b = c;
}

void swap(times& a, times& b) {
    times c;//Временная перменная для хранения во время обмена
    c = a;
    a = b;
    b = c;
}
//Перегрузили swap

int counter()
{
    static int o = 0;
    o++;
    return o;
}

int counter(int j)
{
    j++;
    return j;
}
// Перегрузили counter

int main()
{
    int h, m, s;//Объявляем переменные для часов, минут и секунд
    char j = 'y'; // Чтобы цикл запросов времени запустился
    cout << "---Задание 1---" << endl;
    while (j == 'y') {
        cout << "Введите часы, минуты, секунды >> ";
        cin >> h >> m >> s;//Вводим часы, минуты, секунды
        cout << "Общее количество секунд равно: " << hms_to_secs(h, m, s) << endl; //Выводим на экран 
        cout << "Продолжить? (y/n)" << endl;
        cin >> j;
    }


    cout << "---Задание 2---" << endl;
    times  timing;
    long secs; // Объявляем все переменные
    cout << "Введите количество секунд (первое время)>> ";
    cin >> secs;//Запрашиваем ввод секунд
    cout << "Введите часы, минуты, секунды (второе время) >> ";
    cin >> timing.h >> timing.m >> timing.s;//Запрашиваем ввод переменной типа times
    times p = secs_to_time(time_to_secs(timing) + secs);// Закидываем результат функции в переменную, чтобы хранить его для вывода
    cout << "Общее время: " << p.h << ':' << p.m << ':' << p.s << endl;


    cout << "---Задание 3---" << endl;
    int a, b;// Объявляем числа, которые будем менять
    cout << "Введите числа для обмена >>  ";
    cin >> a >> b;//Вводим
    swap(a, b);//Меняем их местами
    cout << "Числа, которые поменялись >> " << a <<' ' << b << endl;


    cout << "---Задание 4---" << endl;
    times t1, t2; // Объявляем две переменные типа times
    cout << "Введите первые часы, минуты, секунды >> ";
    cin >> t1.h >> t1.m >> t1.s; //Вводим первое время
    cout << "Введите вторые часы, минуты, секунды >> ";
    cin >> t2.h >> t2.m >> t2.s; //Вводим второе время
    swap(t1, t2);
    cout << "Измененное время: " << endl << t1.h << ':' << t1.m << ':' << t1.s << endl << t2.h << ':' << t2.m << ':' << t2.s << endl;

    cout << "---Задание 5 ---" << endl;
    cout << "(Локальная статическая переменная)" << endl;
    for (int i = 0;i <= 9;++i)
    {
        cout << "Вывали " << counter() << " раз" << endl;
    }
    cout << "(Глобальная переменная)" << endl;
    int l = 0;
    for (int i = 0;i <= 9;++i)
    {
        cout << "Вывали " << counter(l) << " раз" << endl;
        l++;
    }
}

