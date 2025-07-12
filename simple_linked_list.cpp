
#include <iostream>
using namespace std;
class node
{
public:
    int data;
    node *next;
};
class linked_list
{

    node *head = nullptr;
    node *tail = nullptr;
    int size = 0;

public:
    void pushback(int element)
    {
        if (head == nullptr)
        {
            // list is empty
            node *n = new node;

            n->data = element;
            n->next = nullptr; // only one node is present in our list so its next pointer is nullptr.
            head = n;
            tail = n;
        }
        else
        { // the list is not empty
            node *new_node = new node;
            new_node->data = element;
            new_node->next = nullptr;
            tail->next = new_node;
            tail = new_node;
        }
        size++;
    }
    void push_front(int element)
    {
        if (head == nullptr)
        {
            // list is empty
            node *n_node = new node;
            n_node->data = element;
            n_node->next = nullptr;
            head = n_node;
            tail = n_node;
        }
        else
        {
            node *n2 = new node;
            n2->data = element;
            n2->next = head;
            head = n2;
        }
        size++;
    }
    void pop_front()
    {
        if (head == nullptr)
            return;
        node *temp = head->next;
        delete head;
        head = temp;
        size--;
    }
    void pop_back()
    {
        if (head == nullptr)
            return;
        if (head == tail)
        {
            // if only a single element is present.
            node *temporary = head;
            head = nullptr;
            tail = nullptr;
            delete temporary;
            return;
        }

        node *temp = head;
        while (temp->next != tail)
        {
            temp = temp->next;
        }
        delete tail;
        tail = temp;
        tail->next = nullptr;
        size--;
    }
    void show(node* h)
    {
        node *temp = h;
        while (temp != nullptr)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    void insert_at(int val, int pos)
    {
        int s = size;
        node *temp = head;
        if (pos == 0)
        {
            push_front(val);
            return;
        }
        else if (pos > s || pos < 0)
        {
            cout << pos << " is an Invalid index to insert." << endl;
            return;
        }
        else if (pos == s)
        {
            pushback(val);
            return;
        }
        else
        {
            // middle insertion
            for (int i = 0; i < pos - 1; i++)
            {
                temp = temp->next;
            }

            node *new_node = new node;
            new_node->data = val;
            new_node->next = temp->next;
            temp->next = new_node;

            size++;
        }
    }

    int search(int val)
    {
        int indx = 0;
        if (head == nullptr)
        {
            cout << "List is empty." << endl;
            return -1;
        }
        node *temp = head;
        while (temp != nullptr)
        {
            if (temp->data == val)
            {
                cout << val << " is Present in the list." << endl;
                return indx;
            }
            indx++;
            temp = temp->next;
        }
        return -1; // not found.
    }
    ~linked_list()
    {
        while (head != nullptr)
        {
            pop_front();
        }
    }
    void reverse_list()
    {
        if (head == nullptr)
        {
            return;
        }
        node *current = head;
        node *temp_behind = head;
        node *temp_ahead = head->next;
        head->next = nullptr;
        while (temp_ahead != nullptr)
        {
            current = temp_ahead;

            temp_ahead = temp_ahead->next;
            current->next = temp_behind;
            temp_behind = current;
        }
        tail = head;
        head = current;
    }
    int list_size()
    {
        return size;
    }

    node *r_head()
    {
        return head;
    }
    void set_head(node *head)
    {
        // this is here function are to copy a list
        this->head = head;
    }
    void set_size(int n)
    {
        // this is here function are to copy a list
        size = n;
    }
};
node *merge(node *h1, node *h2)
{
    if (h1 == nullptr)
    {
        return h2;
    }
    else if (h2 = nullptr)
    {
        return h1;
    }
    if (h1->data <= h2->data)
    {
        h1->next = merge(h1->next, h2);
        return h1;
    }
    else
    {
        h2->next = merge(h1, h2->next);
        return h2;
    }
}

linked_list copy_list(node *head)
{
    linked_list ll;
    node *temp = head;
    while (temp->next != nullptr)
    {
        ll.pushback(temp->data);
        temp = temp->next;
    }
    return ll;
}
void swap_nodes_data(node *h1)
{
    if (h1 == nullptr || h1->next == nullptr)
    {
        return;
    }
    node *first = h1;
    node *second = h1->next;
    node *temp = second->next;

    int val = first->data;
    first->data = second->data;
    second->data = val;

    swap_nodes_data(temp);
}

node *swap_nodes(node *head)
{
    if (head == nullptr || head->next == nullptr)
    {
        return head;
    }

    node *first = head;
    node *second = head->next;

    first->next = swap_nodes(second->next);
    second->next = first;

    return second; // New head after swapping
}

node *swapnodes(node *h1)
{
    if (h1 == nullptr || h1->next == nullptr)
    {
        return h1;
    }

    node *first = h1;
    node *second = first->next;
    node *prev = nullptr;
    while (first != nullptr && second != nullptr)
    {
        node* third=second->next;
        second->next = first;
        first->next = third;
        
        if (prev != nullptr)
        {
            prev->next = second;
        }
        else
        {
            h1=second;
        }


        prev=first;
        first=prev->next;
        if(first->next!=nullptr){
            second=third->next;
        }
        else{
            second=nullptr;
        }

    }
}

int main()
{
    linked_list ll;
    ll.pushback(2);
    ll.pushback(22);
    ll.pushback(12);
    ll.pushback(32);
    ll.pushback(28);
    ll.pushback(5);
    ll.pushback(95);
    ll.pushback(85);
    ll.pushback(65);
    ll.pushback(45);
    ll.pushback(51);
    ll.pushback(3);

    ll.show(ll.r_head());
    cout << "\n\n\n\n";

    node *new_head = swapnodes(ll.r_head()); 
    
    ll.show(new_head);

    return 0;
}
