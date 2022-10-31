#include <iostream>
#include <string>
#include <cstring>
#include <Windows.h>
using namespace std;


class Fraction
{
private:
    int chisl,znam;
public:
    Fraction(): chisl(0),znam(0) {}
    Fraction(int a,int b): chisl(a),znam(b){}
    void display()
    {
        cout << "Дробь равна: " << chisl << '/' << znam <<endl;
    }
    void getfr()
    {
        char ch;
        
        cout << "Введите дробь: ";
        cin >> chisl >> ch>> znam;
    }
    void add_fr(Fraction , Fraction );//метод сложения двух дробей
       
    void sokr()
    {
       int x = chisl;
        int y = znam;
        if (x<y){
            swap(x,y);
        }
        while (x%y != 0) {          //Сокращение дроби
            x %= y;
            swap(x,y);
                        
        }
        znam /= y;
        chisl /= y;
    }
    void divide(Fraction f1 ,int n)
    {
        znam = f1.znam * n;
    }
};
void Fraction::add_fr(Fraction f1 , Fraction f2)
{
    
        chisl = f1.chisl * f2.znam + f1.znam * f2.chisl; 
        znam = f1.znam * f2.znam;
    
}


void maxint(int nums[],int N)
{
    int pos=0,max=0;
    for(int i = 0;i <=N;i++)
    {
        if (nums[i] > max)
        {
            max = nums[i];
            pos = i;
            //Если текущий элемент больше текущего максимума, то запоминаем его и его позицию
        }
    }
    cout << "Максимальный элемент равен " << max << " и стоит под номером " << pos << endl;
}

void reversit( char s [])
{

    int len = strlen(s);       
    for(int j = 0; j < len/2; j++)
    {
        char temp = s[j];        
        s[j] = s[len-j-1];      
        s[len-j-1] = temp;//меняем местами последний и первый элемент(до середины)
    }

}

struct employee
{
    long number;
    char name [50];
    void getdata()
    {
        cout << "Введите имя сотрудника:";
        cin.ignore();
        cin.getline(name,15);
        cout << "Введите его номер: ";
        cin >> number;
    }
    void putdata()
    {
        cout << "Имя сотрудника " << name << endl << "Его номер " << number<< endl;
    }
};
struct Distance
{
    int feet;
    int inch;
    void getdistn()
    {
        cout << "Введите футы и дюймы: ";
        cin >> feet>>inch;
        //Функция для ввода
    }
    int  summofdisnt();
   
};
int Distance::summofdisnt()
{
    long totalinch = feet*12+inch; //посчитали общее количество дюймов
    return totalinch;
}
void srednie(Distance arr[],int n)
{
    long totalinch = 0;
    for (int i = 0;i<5;++i)
    {
        totalinch += arr[i].summofdisnt(); //нашли общее количество дюймов
    }
    totalinch /= n;
    cout << "Среднее значение равно " << totalinch/12 <<" футов " << totalinch - totalinch/12 *12<< " дюймов" << endl;
    //Поделили дюймы на количество, перевели их в стандартный вид
}

int main()
{
   
    cout << "***Задание 1***" << endl;
    int N;
    Fraction fraction[100];
    cout << "Введите длину массива: ";
    cin >> N;
    for (int i =0;i<N;++i) //ввод дробей в массив
        {
        fraction[i].getfr();
        }
    Fraction frsum = fraction[0];
    for(int j = 1;j <N;++j)
    {
        frsum.add_fr(frsum,fraction[j]);//По очереди складываем дроби
    }
    cout << "Средняя  ";
    frsum.divide(frsum,N);//Находим среднее
    frsum.sokr();
    frsum.display();//и выводим его
    system("pause");
    
    cout << "***Задание 2***" << endl;
    int n;
    cout << "Введите длину массива: ";
    cin >> n;
    int nums[100] = {0};//Заполнили массив нулями
    for (int i =0;i<n;++i) //ввод чисел в массив
        {
        cout << "Введите число: ";
        cin >> nums[i];
        }
    maxint(nums,N);

    cout << "***Задание 3***" << endl;
    char  str [1000];
    cout <<"Введите строку: " << endl;
    cin.ignore(); 
    cin.getline( str,1000);//Ввели строку
    reversit(str);//Перевернули строку
    cout <<"Перевернутая строка: " <<  str << endl; //Вывели строку

    cout << "***Задание 4***" << endl;
    employee n1,n2,n3;//Объявили переменные типа employee
    cout << "Введите данные о первом сотруднике >> ";
    n1.getdata();
    cout << "Введите данные о втором сотруднике >> ";
    n2.getdata();
    cout << "Введите данные о третьем сотруднике >> ";
    //ввели данные о сотрудниках
    n3.getdata();
    n1.putdata();
    n2.putdata(); // Вывели данные о сотрудниках
    n3.putdata();

    cout << "***Задание 5***" << endl;
    Distance arr[5];
    for(int i=0;i<5;++i)
    {
        arr[i].getdistn();
    }
    srednie(arr,5);
  
    
}