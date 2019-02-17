/*Author: Chandana Rao csathyan@syr.edu*/

#include <iostream>
using namespace std;

class node {
public:
	int value;
	node * next;
	node * previous;
	node(int i) { value = i; next = previous = nullptr; }
	node() { next = previous = nullptr; }
};

class doubly_linked_list {
public:
	node * head;
	node * tail;
	doubly_linked_list() { head = tail = nullptr; }
	void make_random_list(int m, int n); //create m nodes with value randomly in 0 ... n-1
	void print_forward();
	void print_backward();
	void sort(node * p1, node * p2);	
};

void doubly_linked_list::sort(node * p1, node * p2)
{
	node *h, *t;
	node *pivot = p1;
	node *i = pivot;
	//Base conditions
	if (p1 == nullptr || p1->next == nullptr)
		return;
	if (p2 == nullptr)
		return;
	if (p1 == p2)
		return;
	if (p2 == p1->previous)
		return;
	node *j = p1->next;
	while (j != p2->next)
	{
		//Place the element before the pivot, if it is less than the pivot value
		if (j->value < pivot->value)
		{
			node *temp = j;
			j = j->next;
			if (j != nullptr)
				j->previous = temp->previous;
			if (p2 == temp)
				p2 = p2->previous;
			temp->previous->next = j;
			temp->previous = i->previous;
			temp->next = i;
			i->previous = temp;
			if (temp->previous != nullptr)
				temp->previous->next = temp;
			i = temp;

		}
		else
			j = j->next;
	}
	p1 = i;
	//Recurse on the left part of the pivot
	sort(p1, pivot->previous);
	//Recurse on the right part of the pivot
	sort(pivot->next, p2);
	//Finding the first node
	while (p1->previous != nullptr)
		p1 = p1->previous;
	//Finding the last node
	while (p2->next != nullptr)
		p2 = p2->next;
	head = p1;
	tail = p2;

}

void doubly_linked_list::make_random_list(int m, int n) {

	for (int i = 0; i < m; i++) {
		node * p1 = new node(rand() % n);
		p1->previous = tail;
		if (tail != nullptr) tail->next = p1;
		tail = p1;
		if (head == nullptr) head = p1;
	}
}

void doubly_linked_list::print_forward() {
	cout << endl;
	node * p1 = head;
	while (p1 != nullptr) {
		cout << p1->value << " ";
		p1 = p1->next;
	}
}

void doubly_linked_list::print_backward() {
	cout << endl;
	node * p1 = tail;
	while (p1 != nullptr) {
		cout << p1->value << " ";
		p1 = p1->previous;
	}
}

int main() {
	doubly_linked_list d1;
	d1.make_random_list(50, 20);
	d1.print_forward();
	d1.print_backward();

	d1.sort(d1.head, d1.tail);
	d1.print_forward();
	d1.print_backward();


	getchar();
	getchar();
	return 0;
}
