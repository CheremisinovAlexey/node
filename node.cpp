#include <iostream>
#include "node.h"
using namespace std;

int main()
{
    system("chcp 1251");
    cout << "Введите длину списка: " << endl;
    int n;
    cin >> n;
    List list;
    cout << "Введите список: " << endl;
    for (int i = 0; i < n; i++)
    {
        int z;
        cin >> z;
        list.AddLast(z);
    }
    int x = 10;
    while (x != 0)
    {
        cout << "Выберите, какую операцию произвести со списком: " << endl;
        cout << "1. Проверить список на пустоту" << endl;
        cout << "2. Добавить элемент в начало списка" << endl;
        cout << "3. Добавить элемент в конец списка" << endl;
        cout << "4. Добавить элемент в позицию с заданным индексом" << endl;
        cout << "5. Удалить первый узел" << endl;
        cout << "6. Удалить последний узел" << endl;
        cout << "7. Удалить узел по индексу" << endl;
        cout << "8. Удалить узел по значению" << endl;
        cout << "9. Поиск номера узла по значению" << endl;
        cout << "0. Завершить выполнение программы" << endl;
        cin >> x;
        if (x > 9 || x < 0)
        {
            cerr << "Введите значение от 0 до 9" << endl;
        }
        if (x == 0)
            break;
        if (x == 1)
        {
            if (list.isEmpty())
                cout << "Список пуст" << endl;
            else
                cout << "Список не пуст" << endl;
        }
        if (x == 2)
        {
            cout << "Введите добавляемый элемент: " << endl;
            int d;
            cin >> d;
            list.AddFirst(d);
            list.Print();
        }
        if (x == 3)
        {
            cout << "Введите добавляемый элемент: " << endl;
            int d;
            cin >> d;
            list.AddLast(d);
            list.Print();
        }
        if (x == 4)
        {
            cout << "Введите добавляемый элемент и индекс: " << endl;
            int d;
            cin >> d;
            int index;
            cin >> index;
            list.Add(d, index);
            list.Print();
        }
        if (x == 5)
        {
            cout << "Первый узел удален" << endl;
            list.DelFirst();
            list.Print();
        }
        if (x == 6)
        {
            cout << "Последний узел удален" << endl;
            list.DelLast();
            list.Print();
        }
        if (x == 7)
        {
            cout << "Введите индекс: " << endl;
            int index;
            cin >> index;
            list.DelIndex(index);
            list.Print();
        }
        if (x == 8)
        {
            cout << "Введите значение: " << endl;
            int d;
            cin >> d;
            list.DelValue(d);
            list.Print();
        }
        if (x == 9)
        {
            cout << "Введите значение: " << endl;
            int d;
            cin >> d;
            int f = list.Search(d);
            cout << f;
        }
    }
}