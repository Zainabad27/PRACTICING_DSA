#include <iostream>
using namespace std;
class linked_list
{
public:
    int data;
    linked_list *next;
    linked_list() {}
    linked_list(int data)
    {
        this->data = data;
        this->next = nullptr;
    }
};

void show(linked_list obj)
{
    while (obj.next != nullptr)
    {
        cout << "value: " << obj.data << endl;
        obj = (*(obj.next));
    }
    cout << "value: " << obj.data << endl;
}

void insert(linked_list *obj1, linked_list *obj2, linked_list *obj_insert)
{
    obj1->next = obj_insert;
    obj_insert->next = obj2;
}

int main()
{
    int a = 5, b = 8, z = 2345678, c = 34, d = 456;
    linked_list first(a), second(b), qwer(z), third(c), fourth(d);
    first.next = &second;
    second.next = &qwer;
    qwer.next = &third;
    third.next = &fourth;
    fourth.next = nullptr;
    int p=77777;
    linked_list inst(p);
    insert(&third,&fourth,&inst);
    show(first);
    return 0;
}