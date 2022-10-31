
#include <iostream>
using namespace std;

struct employee {
    int number;
    float zarplata; // Структура для первого задания
};

enum etype { laborer, secretary, manager, accountant, executive, researcher }; // Должности из условия второго задания

struct jober {
    etype dolzn; //Структура для записи должности во втором задании
};

struct fraction {
    int chislitel; //Структура для дробей
    int znamenatel;
};

struct times {
    int hours;
    int seconds;
    int minutes;
};

int main()
{
    long totalsecs; //Для хранения общих секунд
    times t1;
    times t2; //Объявили три объекта для хранения времени
    times t3;
    char dummychar = '/'; //Для дробей
    char ch = ':'; // Для времени
    int j = 1; //Цикл для ввода номера задания
    int x;
    int y; //Замены для сокращения дробей
    int result_chisl;
    int result_znam; //Для подсчетов результата
    while (j != 0) {
        cout << "Введите номер задания (Ноль для выхода): " << endl;
        cin >> j;
        switch(j)
        {
            case 1:
                employee num_1;
                num_1.number = 1;
                employee num_2;
                num_1.number = 2;
                employee num_3;
                num_1.number = 3;
                setlocale(LC_ALL, "");
                cout << "Введите номер первого сотрудника и его зп: " << endl;
                cin >> num_1.number >>num_1.zarplata;
                cout << "Введите номер второго сотрудника и его зп:" << endl; //Вводим з/п всех сотрудников
                cin>> num_2.number >> num_2.zarplata;
                cout << "Введите номер третьего сотрудника и его зп:" << endl;
                cin >> num_3.number>> num_3.zarplata;
                cout << "Зарпалата " <<  num_1.number <<" сотрудника: " << num_1.zarplata << endl;
                cout << "Зарпалата " <<  num_2.number <<" сотрудника: " << num_2.zarplata << endl; //Выводим зп всех сотрудников
                cout << "Запралата " <<  num_3.number <<" сотрудника: " << num_3.zarplata << endl;
                continue;
            case 2:
                char dolzn;//Для ввода букв
                jober job1;// Для сохранения должности
                cout << "Введите первую букву должности (laborer, secretary, manager, accountant, executive, researcher):" << endl; 
                cin >> dolzn; //Запрашиваем букву должности
                switch (dolzn)
                {
                case 'l': job1.dolzn = laborer;break;
                case 's': job1.dolzn = secretary;break;
                case 'm': job1.dolzn = manager;break;  //Находим должности по букве
                case 'a': job1.dolzn = accountant;break;
                case 'e': job1.dolzn = executive;break;
                case 'r': job1.dolzn = researcher;break;
                }
                cout << "Полное название должности: ";
                switch (job1.dolzn)
                {
                case laborer: cout << "laborer" << endl;;break;
                case secretary: cout << "secretary" << endl;;break;
                case manager: cout << "manager" << endl;break;     //Присваиваем должности соотвествующую строку и выводим ее
                case accountant: cout << "accountant" << endl;break;
                case executive:  cout <<"executive"<< endl;break;
                case researcher: cout <<"researcher"<<endl;break;
                };
           
                continue;
            case 3:
             fraction first;
                fraction second;
                cout << "Введите первую дробь: " << endl;
                cin >> first.chislitel >> dummychar >> first.znamenatel;
                cout << "Введите вторую дробь: " << endl;
                cin >> second.chislitel >> dummychar >> second.znamenatel;
                result_chisl = first.chislitel * second.znamenatel + second.chislitel * first.znamenatel;
                result_znam =  first.znamenatel * second.znamenatel;
                x = result_chisl;
                y = result_znam;
                if (x<y){
                      swap(x,y);
                }
                while (x%y != 0) {          //Сокращение дроби
                        x %= y;
                        swap(x,y);
                        
                }
                result_znam /= y;
                result_chisl /= y;
                cout << "Результат сложения равен: " <<  result_chisl << dummychar <<result_znam << endl;
                continue;
            case 4:
                cout << "Введите часы, минуты, секунды: ";
                cin >> t1.hours >> t1.minutes >> t1.seconds; //Запрашиваем данные для него
                totalsecs = t1.hours * 3600 + t1.minutes * 60 + t1.seconds; //Считаем количество секунд
                cout << "Общее количество секунд: " << totalsecs << endl; //Выводим их
                continue;
            case 5:
                cout << "Введите первые часы, минуты, секунды: ";
                cin >> t1.hours >> ch >>t1.minutes >> ch >> t1.seconds; //Запрашиваем данные
                cout << "Введите вторые часы, минуты, секунды: ";
                cin >> t2.hours >> ch >> t2.minutes >> ch >> t2.seconds; //Запрашиваем данные
                totalsecs = t1.hours * 3600 + t1.minutes * 60 + t1.seconds + t2.hours * 3600 + t2.minutes * 60 + t2.seconds; //Считаем все секунды
                t3.seconds = totalsecs % 60;//Вычисляем количество секунд в итоге с помощью остатков
                t3.minutes = (totalsecs % 3600 - t3.seconds) / 60; // Вычисляем количество минут с помощью остатков, помня, что мы уже заняли некоторые секунды
                t3.hours = (totalsecs - totalsecs % 3600) / 3600; //Аналогично минутам, вычисляем для часов
                cout << "Общее количество времени: " << t3.hours << ch << t3.minutes << ch << t3.seconds << endl;
                continue;
        }
        
    }
}

