#include <iostream>
#include "node.h"
using namespace std;

int main()
{
    system("chcp 1251");
    cout << "������� ����� ������: " << endl;
    int n;
    cin >> n;
    List list;
    cout << "������� ������: " << endl;
    for (int i = 0; i < n; i++)
    {
        int z;
        cin >> z;
        list.AddLast(z);
    }
    int x = 10;
    while (x != 0)
    {
        cout << "��������, ����� �������� ���������� �� �������: " << endl;
        cout << "1. ��������� ������ �� �������" << endl;
        cout << "2. �������� ������� � ������ ������" << endl;
        cout << "3. �������� ������� � ����� ������" << endl;
        cout << "4. �������� ������� � ������� � �������� ��������" << endl;
        cout << "5. ������� ������ ����" << endl;
        cout << "6. ������� ��������� ����" << endl;
        cout << "7. ������� ���� �� �������" << endl;
        cout << "8. ������� ���� �� ��������" << endl;
        cout << "9. ����� ������ ���� �� ��������" << endl;
        cout << "0. ��������� ���������� ���������" << endl;
        cin >> x;
        if (x > 9 || x < 0)
        {
            cerr << "������� �������� �� 0 �� 9" << endl;
        }
        if (x == 0)
            break;
        if (x == 1)
        {
            if (list.isEmpty())
                cout << "������ ����" << endl;
            else
                cout << "������ �� ����" << endl;
        }
        if (x == 2)
        {
            cout << "������� ����������� �������: " << endl;
            int d;
            cin >> d;
            list.AddFirst(d);
            list.Print();
        }
        if (x == 3)
        {
            cout << "������� ����������� �������: " << endl;
            int d;
            cin >> d;
            list.AddLast(d);
            list.Print();
        }
        if (x == 4)
        {
            cout << "������� ����������� ������� � ������: " << endl;
            int d;
            cin >> d;
            int index;
            cin >> index;
            list.Add(d, index);
            list.Print();
        }
        if (x == 5)
        {
            cout << "������ ���� ������" << endl;
            list.DelFirst();
            list.Print();
        }
        if (x == 6)
        {
            cout << "��������� ���� ������" << endl;
            list.DelLast();
            list.Print();
        }
        if (x == 7)
        {
            cout << "������� ������: " << endl;
            int index;
            cin >> index;
            list.DelIndex(index);
            list.Print();
        }
        if (x == 8)
        {
            cout << "������� ��������: " << endl;
            int d;
            cin >> d;
            list.DelValue(d);
            list.Print();
        }
        if (x == 9)
        {
            cout << "������� ��������: " << endl;
            int d;
            cin >> d;
            int f = list.Search(d);
            cout << f;
        }
    }
}