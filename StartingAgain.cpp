#include <iostream>

class Node
{
public:
    Node(int val)
    {
        this->data = val;
    }
    int data;
    Node *next;
};

class LinkedList
{
public:
    Node *head;
    LinkedList(int val)
    {
        head = new Node(val);
        head->next = nullptr;
    }

    void AddElement(int val)
    {
        Node *temp;
        temp = head;
        Node *NewNode = new Node(val);

        while (temp->next != nullptr)
        {
            temp = temp->next;
        }
        temp->next = NewNode;
        NewNode->next = nullptr;
    }

    void triverse(Node *head)
    {
        Node *temp = head;

        while (temp != nullptr)
        {
            std::cout << temp->data << "\n";
            temp = temp->next;
        }
    }

    ~LinkedList()
    {

        if(head==nullptr){
            return;
        }
        // Node* temp=head;
        while (head!= nullptr)
        {
            Node *temp = head;
            temp = temp->next;
            delete head;
            head = temp;
        }

    }
};

int main()
{
    LinkedList ll(5);
    ll.AddElement(6);
    ll.AddElement(7);
    ll.AddElement(8);
    ll.AddElement(9);
    ll.AddElement(10);
    ll.AddElement(11);
    ll.AddElement(12);
    ll.AddElement(13);
    ll.AddElement(14);

    ll.triverse(ll.head);
}