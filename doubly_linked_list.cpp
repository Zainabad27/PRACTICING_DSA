#include <iostream>
using namespace std;
struct node
{
	int data;
	node* next;
	node* prev;

	node() {}
	node(int value)
	{
		this->data = value;
	}
};
class linked_list
{
	node* head;
	node* tail;

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
			// list is empty
			node* new_node = new node(val);
			new_node->next = nullptr;
			new_node->prev = nullptr;
			head = new_node;
			tail = new_node;
		}
		else
		{
			// list already has elements
			node* new_node = new node(val);
			new_node->next = nullptr;
			new_node->prev = tail;
			tail->next = new_node;
			tail = new_node;
		}
	}
	void pop_front()
	{
		if (head == nullptr)
		{
			return;
		}
		else
		{
			node* temp = head;
			head = head->next;
			if (head != nullptr) { head->prev = nullptr; }
			else { tail = nullptr; }

			delete temp;
		}
	}
	void show()
	{
		if (head == nullptr)
		{
			cout << "List is empty\n";
			return;
		}
		node* temp = head;
		while (temp != nullptr)
		{
			cout << temp->data << " ";
			temp = temp->next;
		}
		if (head->next != nullptr)
		{
			cout << "\nreverse triversal " << '\n';

			node* rtemp = tail;
			while (rtemp != nullptr)
			{
				cout << rtemp->data << " ";
				rtemp = rtemp->prev;
			}
		}
	}
   ~linked_list() {
    node* current = head;
    while (current != nullptr) {
        node* nextNode = current->next;
        delete current;
        current = nextNode;
    }
}

};
int main()
{
	linked_list ll;

	ll.pushback(22);
    ll.pushback(9);
    ll.pushback(90);
    ll.pushback(96);
    ll.pushback(19);
	ll.pop_front();
    ll.pushback(10000);
    ll.pop_front();
	ll.show();

	return 0;
}