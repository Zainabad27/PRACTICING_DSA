#include <iostream>
using namespace std;
struct node
{
    int data;
    node *next;

    node(int val)
    {
        this->data = val;
    }
    node() {}
};
class linked_list
{
    node *head;
    node *tail;
    int size = 0;

public:
    linked_list()
    {
        head = nullptr;
        tail = nullptr;
    }
    void pushback(int val)
    {
        if (head == nullptr)
        {
            node *new_node = new node(val);
            head = new_node;
            tail = new_node;
            new_node->next = head;
            tail->next = head;
            size++;
        }
        else
        {
            node *new_node = new node(val);
            tail->next = new_node;
            tail = new_node;
            new_node->next = head;
            size++;
        }
    }

    void show()
    {
        int c = 0;
        node *temp = head;
        while (c < 20)
        {
            cout << temp->data << " ";
            temp = temp->next;
            c++;
            if (temp == tail->next)
            {
                cout << '\n';
            }
        }
    }
};
int main()
{
    linked_list ll;
    ll.pushback(2);
    ll.pushback(6);
    // ll.pushback(89);
    // ll.pushback(15);
    // ll.pushback(9);

    ll.show();

    return 0;
}