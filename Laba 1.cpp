
#include <iostream>
#include <locale.h>
#include <cmath>
using namespace std;


int main()
{
    setlocale(LC_ALL, "");

    int j = 1;
    char dummychar = '/';
    while (j != 0) {
        cout << "Введите номер задания (0 для выхода):" << endl;
        cin >> j;
        if ((j > 5) || (j < 0)) {
            cout << "Некорректный номер задания" << endl;;
            continue;
        }                                                   // Создаем условия для повторного выбора задания, либо выхода
        if (j == 0) {
            return 0;
        }
        switch (j)
        {
        case 1:
            cout << "Задание N1" << endl;
            cout << "Всё тихо — полная луна…" << endl
                << "Всё тихо — полная луна…" << endl
                << "Блестит меж ветел над прудом," << endl
                << "И возле берега волна" << endl               //Выводим строчки через endl
                << "С холодным резвится лучом." << endl
                << "М.Ю Лермонтов, 1830 год"
                << '\n';
            continue;
        case 2:
            cout << "Задание N2" << endl;
            float p;
            cout << "Температура по Цельсию:\n";
            cin >> p;
            cout << "Температура по Фаренгейту: " << p * 9 / 5 + 32 << endl; //Запрашиваем число, пересчитываем, выводим
            cout << '\n';
            continue;
        case 3:
            cout << "Задание N3" << endl;
            int a, b, c, d;

            cout << "Введите первую дробь: ";
            cin >> a >> dummychar >> b;
            cout << "Введите вторую дробь: ";
            cin >> c >> dummychar >> d;
            if ((b == 0) || (d == 0)) {
                cout << "На ноль делить нелья" << endl;
                continue;
            }
            cout << "Сумма равна: " << (a * d + b * c) << dummychar << b * d << endl; //Запрашиваем дроби, проверяем, чтобы в знаменателе не было ноля, считаем  , выводим
            cout << '\n';
                continue;
        case 4:
            cout << "Задание N4" << endl;
            int pounds, shillings2, pens2;
            cout << "Фунты:";
            cin >> pounds;
            cout << "Шиллинги:";
            cin >> shillings2;
            cout << "Пенсы:";
            cin >> pens2;
            if (pounds < 0 || shillings2 < 0 || pens2 < 0) {
                cout << "Введено отрицательное число, ошибка" << endl;
                continue;
            }
            cout << "Десятичные фунты: " << pounds + round(((shillings2 * 12 + pens2) / 2.4)) /100 << endl; //Запрашиваем все величины, проверка на положительность, переводим в соответствии с изменением ценности 
            cout << '\n';
            continue;
        case 5:
            cout << "Задание N5" << endl;
            float decpound, freepens, shillings, pens1;
            int pens;
            cout << "Введите количество  десятичных фунтов: ";
            cin >> decpound;
            if (decpound < 0) {
                cout << "Введено отрицательное число, ошибка" << endl;
                continue;
            }
            pens1 = decpound * 240;
            decpound = static_cast<int>(decpound);
            freepens = pens1 - decpound * 240;
            shillings = static_cast<int>(freepens / 12);
            pens = -shillings * 12 + freepens;
            cout << decpound << '.' << shillings << '.' << pens << endl; /*Запрашиваем, проверяем на отрицательность, находим свободные пенсы, которые не участвуют в формировании фунтов, 
                                                                            находим сколько шиллингов они могу формировать, находим оставшиеся пенсы, все выводим*/
            cout << '\n';
            continue;

            }
        }
    }

