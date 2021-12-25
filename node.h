#include <iostream>
using namespace std;

class Node
{
    int field;
    class Node *ptr;
    friend class List;
};

class List
{
    Node *head;
    int count = 0;
public:
    List() { head = NULL; }
    int getCount() { return count; }
    bool isEmpty() { return head == NULL; }
    int getValue(Node* p) { return p->field; }
    Node* Next(Node *);
    Node* AddFirst(int);
    Node* AddLast(int);
    Node* Add(int, int);
    Node* DelFirst();
    Node* DelLast();
    Node* DelIndex(int);
    Node* DelValue(int);
    int Search(int);
    void Print();

    friend ostream& operator<<(ostream&, const List);
};

Node* List::AddFirst(int num)
{
    Node *elem = new Node();
    elem ->field = num;
    count++;
    if (head == NULL) {
        elem->ptr = NULL;
        head = elem;
    }
    else {
        elem->ptr = head;
        head = elem;
    }
    return elem;
}

Node* List::AddLast(int num)
{
    Node *elem = new Node();
    elem ->field = num;
    count++;
    if (head == NULL) {
        elem->ptr = NULL;
        head = elem;
    }
    else {
        Node *p = head;
        while (Next(p) != NULL)
            p = Next(p);
        elem->ptr = p->ptr;
        p->ptr = elem;
        return elem;
    }
}

Node* List::Add(int num, int index)
{
    if (count + 1 < index)
    {
        cerr << "Индекс больше числа элементов в списке" << endl;
    }
    Node *elem = new Node();
    elem ->field = num;
    count++;
    if (index == 1) {
        elem->ptr = head;
        head = elem;
    }
    else {
        Node *p = head;

        for (int i = 2; i < index; i++)
            p = Next(p);
        elem->ptr = p->ptr;
        p->ptr = elem;
        return elem;
    }
}

Node* List::DelFirst()
{
    if (count == 0)
    {
        cerr << "Список пустой: нечего удалять" <<endl;
    }
    Node* node = head;
    head = node->ptr;
    delete node;
    count--;
    return head;
}

Node* List::DelLast()
{
    if (count == 0)
    {
        cerr << "Список пустой: нечего удалять" <<endl;
    }
    Node *p = head;
    for (int i = 1; i < count - 1; i++)
        p = Next(p);
    Node *x = Next(p);
    p->ptr = NULL;
    delete x;
    count--;
    return p;
}

Node* List::DelIndex(int index)
{
    if (count == 0)
    {
        cerr << "Список пустой: нечего удалять" <<endl;
    }
    if (count < index)
    {
        cerr << "Индекс больше числа элементов в списке" << endl;
    }
    if (index == 1) {
        Node* node = head;
        head = node->ptr;
        delete node;
        count--;
        return head;
    }
    else {
        Node *p = head;
        for (int i = 1; i < index - 1; i++)
            p = Next(p);
        Node *x = Next(p);
        p->ptr = x->ptr;
        delete x;
        count--;
        return p;
    }
}

Node* List::DelValue(int value)
{
    int x = 0;
    Node *p = head;
    Node* y = p;
    if (count == 0)
    {
        cerr << "Список пустой: нечего удалять" <<endl;
    }
    if (head->field == value)
    {
        Node* node = head;
        head = node->ptr;
        delete node;
        count--;
        return head;
    }
    while (Next(p) != NULL && x == 0)
    {
        if (p->field == value)
        {
            x = 1;
            y->ptr = p->ptr;
            delete p;
            count--;
            return y;
        }
        y = p;
        p = Next(p);
    }
    if (p->field == value)
    {
        x = 1;
        y->ptr = NULL;
        delete p;
        count--;
        return y;
    }
    cerr << "Нет узла с таким значением" <<endl;
}

int List::Search(int value)
{
    Node *p = head;
    int index = 1;
    while (p != NULL)
    {
        if(p->field == value)
        {
            return index;
        }
        index++;
        p = Next(p);
    }
    cerr << "Нет узла с данным значением" <<endl;
}

void List::Print()
{
    if (isEmpty()) { cout << "Список пуст" << endl; return; }
    Node *p = head;
    do {
        cout << getValue(p) << " ";
        p = Next(p);
    } while (p != NULL);
    cout << endl;
}

Node* List::Next(Node* node)
{
    if (isEmpty()) return NULL;
    return node->ptr;
}