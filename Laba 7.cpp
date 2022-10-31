#include <iostream>
#include <ctype.h>

#include <string>
using namespace std;

struct person 
{
    
    char* Name;
    float salary;
    void getdata()
    {
        Name = new char;
        cout << "Введите имя сотрудника: ";
        cin >> Name;
        cout << "Введите его зарплату: ";
        cin >> salary;
    }
    void displaydata()
    {
        cout << "Зарплата сотрудника " << Name << " равна " << salary<< endl;
    }
};
int compstr (const char* a, const char* b)
{
    
    while(*a && *b && (*a == *b))//Идем по строки посимвольно
    {
        a++; b++;
    }
    if (*a > *b) return 1;
    if (*a < *b) return -1; 
    return 0;
    //Возвращаем различные значения, в зависимости от резульатат
}
void sortbysalary(person *array[],int arrlen)
{
    while(arrlen--)
    {
        bool swapped = false;
		
        for(int i = 0; i < 4; i++)
        {
            if(array[i]->salary > array[i + 1]->salary)
            {
                swap(array[i], array[i + 1]);//Метод пузырьковой сортировки
                swapped = true;
            }
        }
		
        if(swapped == false)
            break;
    }
    
}
void addarrays(float *N1,float *N2,float *N3)
{
    for(int i = 0;i<9;++i)
    {
        N3[i] = N1[i]+N2[i];//Сложение данных из ячеек массивов, в соответствующуюю в третьем
    }
}
int main()
{
    cout << "___Задание 1___" << endl;
    float N1[] = {1,2,3,4,5,6,7,8,9};
    float N2[] = {11,12,13,14,15,16,17,18,19};
    //Инициализировали первые два массива
    float N3 [9]{0};//Заполнили третий массив нулями
    cout << "Массив до функции: " << endl;
    for(int i = 0; i < 9; i++)
    {
        cout << "N3[" << i << "]= " << N3[i] << "\n"; // На экран через пробелы выводятся все элементы массива
    }
    addarrays(N1,N2,N3);
    cout << "После: " << endl;
    
    for(int i = 0; i < 9; i++)
    {
        cout << "N3[" << i << "]= " << N3[i] << "\n"; // На экран через пробелы выводятся все элементы массива
    }
    
    cout << "___Задание 2___" << endl;
    cout << "Сравниваем: abc и  abc "<< compstr("abc", "abc") << endl;
    cout << "Сравниваем: adc и  abd "<< compstr("adc", "abd") << endl;
    cout << "Сравниваем: aba и  abc "<< compstr("aba", "abc") << endl;
    
    cout << "___Задание 3___" << endl;
    const int SIZE = 10;
    int a0[SIZE] = {1, 2, 3, 4, 5, 6, 7, 8,9, 10},
    a1[SIZE] = {11, 12, 13, 14, 15, 16, 17, 18,19, 20},
    a2[SIZE] = {21, 22, 23, 24, 25, 26, 27, 28 ,29 , 30},
    a3[SIZE] = {41, 42, 43, 44, 45, 46, 47, 48,49, 50},
    a4[SIZE] = {51, 52, 53, 54, 55, 56, 57, 58 ,59 , 60},
    a5[SIZE] = {61, 62, 63, 64, 65, 66, 67, 68,69, 70},
    a6[SIZE] = {71, 72, 73, 74, 75, 76, 77, 78 ,79 , 80},
    a7[SIZE] = {81, 82, 83, 84, 85, 86, 87, 88,89, 90},
    a8[SIZE] = {91, 92, 93, 94, 95, 96, 97, 98 ,99 , 100},
    a9[SIZE] = {101, 102, 103, 104, 105, 106, 107, 108 ,109 , 110};
    //Объявили десять массивов, по десять символов в каждом
    int **ap = new int* [SIZE];//Выделяем память для двумерного массива
    ap[0] = a0;
    ap[1] = a1;
    ap[2] = a2;
    ap[3] = a3;
    ap[4] = a4;
    ap[5] = a5;
    ap[6] = a6;
    ap[7] = a7;
    ap[8] = a8;
    ap[9] = a9;
    //Инициализируем ячейки массива
    for(int o = 0;o<10;++o)
    {
        for(int j = 0;j< 10;++j)
        {
            cout << "ap[" << o << "]["<<j<<"]= " << ap[o][j] << "\n"; // На экран через пробелы выводятся все элементы массива
        }
    }
    system("cls"); 
    cout << "___Задание 4___" << endl;
    int *ap1[SIZE];
    int NUMARRAYS = 10;
    for ( int l = 0;l < NUMARRAYS; l++ )	// создаем NUMARRAYS массивов
    {
        ap1[l] = new int [ SIZE ];//no MAXSIZE целых чисел в каждом
        ap1[l] = ap[l];//Заполняем массив сразу, используя, массив из предыдущего задания
    }
    for(int o = 0;o<10;++o)
    {
        for(int j = 0;j< 10;++j)
        {
            cout << "ap1[" << o << "]["<<j<<"]= " << ap1[o][j] << "\n"; // На экран через пробелы выводятся все элементы массива
        }
    }
    
    cout << "___Задание 5___" << endl;
    person *array[5];
    for(int l = 0;l<5;++l)
    {
        array[l] = new person;//Выделили память
        array[l]->getdata();//Добавили туда значения
    }
    system("cls"); 
    cout << "Адрес начала массива до сортировки: " << &array[0]<<endl;
    cout << "Массив до сортировки:" << endl;
    for(int l = 0;l<5;++l)
    {
        array[l]->displaydata();
    }
    sortbysalary(array,5);//Сортировка
    cout << "Адрес начала массива после сортировки: " << &array[0]<<endl;
    cout << "Массив после сортировки:" << endl;
    for(int l = 0;l<5;++l)
    {
        array[l]->displaydata();
    }
    

    
    
}