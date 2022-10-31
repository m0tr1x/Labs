    #include <string>
    #include <iostream>
    #include <locale.h>
    #include <cmath>
    using namespace std;


    int main()
    {
   
        setlocale(LC_ALL, "");
        int j = 1;
        int o = 1;
        int p = 1; // Чтобы работал цикл  
        int vklad, vremya;
        float percent, total,vznos;
        char otv = 'y';
        long long platez = 0;
        long long summary = 0;
        while (j != 0) 
        {
            cout << "Введите номер задания (0 для выхода):" << endl;
            cin >> j;
            if ((j > 5) || (j < 0)) 
            {
                cout << "Некорректный номер задания" << endl;;
                continue;
            }
            if (j == 0) 
            {
                return 0;
            }
            switch (j)
            {
            case 1:
                for (int i = 1;i <= 20;++i)
                {
                    cout << string(20 - i, ' ') << string(i, 'X') << endl; // Выводим строки из пробелов длинами 20-i и i соответственно
                }
                continue;
            case 2:
                
                while (p != 0)
                {
                    cout << "Введите число для факториала (Ноль для выхода): " << endl;
                    cin >> p;
                    if (p == 0) {
                        break;
                    }
                    int l = 1; //Болванка для факториала
                    for (int u = 1;u <= p;++u)
                    {
                        l *= u;
                    }
                    cout << "Факториал числа " << p << " равен " << l << endl;
                  
                }
                continue;
            case 3:
                total = 0;
                cout << "Введите начальный вклад: ";
                cin >> vklad;
                total += vklad;
                cout << "Введите количество лет: ";
                cin >> vremya;
                cout << "Введите процентную ставку ";
                cin >> percent;
                percent = 1 + percent / 100;
                for (int i = 1;i <= vremya;++i)
                {
                    total *= percent;
                    cout << "В конце " << i << "-го года у вас будет " << total << endl;
                } 
                cout << "Через " << vremya << " лет вы получите вы получите " << total << endl;
                continue;
            case 4:
            
                cout << "Введите общую цену: ";
                cin >> total;
                cout << "Введите начальный взнос: ";
                cin >> vznos;
                total -= vznos;
                cout << "Введите количество лет: ";
                cin >> vremya;
                cout << "Введите процентную ставку ";
                cin >> percent;
                percent =percent / 100;
                for (int i = 1;i <= vremya;++i) {
                    platez = (total * percent*(vremya-i+1)/vremya)+total/vremya;
                    cout << "За " << i << "-й год вы заплатите " << platez << endl;
                    summary += platez;
                }
                cout << "Общие выплаты: " << summary << endl;
                continue;

            case 5:
            
                while (otv == 'y')
                {
                int pounds, pounds1, pounds2,shillings,shillings1, shillings2,pens,pens1, pens2;
                char space = ' ';
                cout << "Введите первую сумму: ";
                cin >> pounds1 >>shillings1 >> pens1;
                cout << "Введите вторую сумму: ";
                cin >> pounds2 >>shillings2 >> pens2;
                pens = pens1 + pens2;
                shillings = shillings1 + shillings2;
                pounds = pounds1 + pounds2;
                cout << "Всего: " << pounds + static_cast<int>(shillings / 20) << space << shillings % 20 + static_cast<int>(pens / 12) << space << pens % 12 << endl;
                cout << "Продолжить?(y/n)" << endl;
                cin >> otv;
                }
            
                cout << '\n';
            }

        }
    }

