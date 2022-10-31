#include <iostream>
using namespace std;

class Date// Объявляем другой класс
{
private:
    int day;
    int month;//Объявляем объекты класса
    int year;
    char ch = '/';
public:
    void getdate()
    {
        cout << "Введите дату в формате DD/MM/YY >> " ;
        cin >> day >> ch >> month >> ch >> year;
        if ((day > 31) || (month > 12))
        {
            day =  month = year = 0;
        }
        
    }
    void showdate()
    {
        if ((day == 0)&&(month==0)&&(year==0)){
        cout << "Вы ввели неверную дату" << endl;
        }
        else
        {
            cout << "дата:  " << day << ch << month << ch << year << endl;
        }
        
    }
    
};


class Double //Объявляем класс
{
    private:
        double bi; //Объявляем объект класса
    public:
        Double() : bi(0){} //Стандартный случай, где по умолчанию число = 0
        void getdouble() // Метод для ввода
        {
            cout << "Введите число типа double:" << endl;
            cin >> bi;
            }
        void outdouble()
        {
            cout << "Число равно >> " << bi << endl;  //Метод для вывода
        }
    void addition(Double,Double); // Метод сложения(Прототип)
};
void Double::addition(Double d1 , Double d2)
{
    bi = d1.bi + d2.bi;
} //Сама функция


class employee // Объявляем другой класс
{
private:
    enum etype { laborer, secretary, manager, accountant, executive, researcher }; // Должности 
    int number;
    float salary; //Объявляем объекты класса
    Date data;
    char post;
    etype profession;
public:
    void priem()
    {
        data.getdate();
    }
    void getnumber_and_salary()
    {
        cout << "Введите номер сотрудника >> ";
        cin >> number;
        cout << "Введите з/п сотрудника >> ";
        cin >> salary;
    }
    //Метод для ввода  з/п и номера
    void display()
    {
        cout << "З/п сотрудника №" << number << " равна " << salary<< endl;
    }
    //Функция для вывода данных

    void putemploy()
    {
        cout << "Введите первую букву должности сотрудника: ";
        cin >> post;
        switch (post)
        {
        case 'l': profession = laborer;break;
        case 's': profession = secretary;break;
        case 'm': profession = manager;break;  //Находим должности по букве
            case 'a': profession = accountant;break;
        case 'e': profession = executive;break;
        case 'r': profession = researcher;break;
        }
    }
    void getemployee(){
        cout << "Полное название должности: ";
        switch (profession)
        {
        case laborer: cout << "laborer" << endl;;break;
        case secretary: cout << "secretary" << endl;;break;
        case manager: cout << "manager" << endl;break;     //Присваиваем должности соотвествующую строку и выводим ее
            case accountant: cout << "accountant" << endl;break;
        case executive:  cout <<"executive"<< endl;break;
        case researcher: cout <<"researcher"<<endl;break;
        };
    }
    void fulldisplay()
    {
        display();
        getemployee();
        cout << "Когда приняли на работу ";
        data.showdate();
        // Выводим все данные о сотруднике
    }
    
};

class  Time
{
private:
     int secs;
     int mins;
     int hrs;
     char point = ':';
public:
    Time():secs(0),mins(0),hrs(0) {}
    Time(int scs,int ms,int h): secs(scs),mins(ms),hrs(h){}
    void showtime()
    {
        cout << "Время в формате SS/MM/HH >> "<< secs << point << mins << point << hrs << endl; //Вывод времени
         
    }
    void  additionoftimes(Time,Time);//Прототип метода
};
void Time::additionoftimes(Time t1 , Time t2)
{
    long totalsecs;
    totalsecs = t1.hrs * 3600 + t1.mins * 60 + t1.secs + t2.hrs * 3600 + t2.mins * 60 + t2.secs; //Считаем все секунды
    secs = totalsecs % 60;//Вычисляем количество секунд в итоге с помощью остатков
    mins = (totalsecs % 3600 - secs) / 60; // Вычисляем количество минут с помощью остатков, помня, что мы уже заняли некоторые секунды
    hrs = (totalsecs - totalsecs % 3600) / 3600; //Аналогично минутам, вычисляем для часов
}

int main()
{
   
    cout << "***Задание 1***" << endl;
    Double t1,t2,t3; // Объявляем переменные 
    t1.getdouble();
    t2.getdouble();
    //Вводим числа
    t3.addition(t1,t2);//Складываем их
    t3.outdouble();//Выводим их
    system("pause");

    cout << "***Задание 2***" << endl;
    employee n1,n2,n3;// Объявляем переменные 
    n1.getnumber_and_salary();
    n2.getnumber_and_salary();
    n3.getnumber_and_salary();
    //Запрашиваем данные для каждого сотрудника
    n1.display();
    n2.display();
    n3.display();
    //Выводим данные для каждого сотрудника
    system("pause");

    cout << "***Задание 3***" << endl;
    Date d1;// Объявляем переменную
    d1.getdate();//Запрашиваем дату
    d1.showdate();//Выводим ее
    system("pause");

    cout << "***Задание 4***" << endl;
    Time const time1(1,2,3); 
    Time  const time2(4,5,6);
    //Объявили два const времени
    Time time3;
    time3.additionoftimes(time1,time2);// Сложили
    time3.showtime();//Вывели
    system("pause");

    cout << "***Задание 5***" << endl;
    employee emp1,emp2,emp3;
    emp1.priem();
    emp1.getnumber_and_salary();
    emp1.putemploy();
    //Вводим все данные для 1 сотрудника
    emp2.priem();
    emp2.getnumber_and_salary();
    emp2.putemploy();
    //Аналогично для второго
    emp3.priem();
    emp3.getnumber_and_salary();
    emp3.putemploy();
    //И для третьего
    emp1.fulldisplay();
    emp2.fulldisplay();
    emp3.fulldisplay();
    
}
