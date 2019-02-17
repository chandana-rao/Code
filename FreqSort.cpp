/*Author: Chandana Rao csathyan@syr.edu*/

#include <iostream>
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
	void make_random_list(int m, int n);
	void print_forward();
	void print_backward();
  
	void sort();//sort all values based on frequency.
						  //In case of ties, the values occur earlier will appear earlier
						  //Example:  for list with values  7 6 12 4 33 12 6 6 7
						  //sorted results: 6 6 6 7 7 12 12 4 33
	void insert(int k);
	//after insert(12) to the above,
	//we have 6 6 6 12 12 12 7 7 4 33
	//Insert value k to a frequency_sorted list
	//After insert, the list remains frequency_sorted

	void remove(int k, int n); //remove value k n times from a frequency_sorted list.
							   //if there are fewer than n occurances of k, then remove all occurnces of k
							   //The final result will remain a frequency_sorted list.
							   //For example, if the list is 7 7 7 2 2 4 4 5 5 44 3
							   //After remove(2,5), the list will become 7 7 7 4 4 5 5 44 3
};


void doubly_linked_list::remove(int k, int n)
{
	node *p = head;
	while (p != NULL && n > 0)
	{
		if (p->value == k)
		{
			if (p == head)
			{
				node *temp = p;
				head = head->next;
				p = p->next;
				delete temp;
			}
			else if (p == tail)
			{
				node *temp = p;
				tail = tail->previous;
				p = p->next;
				delete temp;
			}
			else
			{
				node *temp = p;
				p = p->next;
				p->previous = temp->previous;
				temp->previous->next = p;
				delete temp;
			}
			n--;
		}
		else
			p = p->next;
	}
	sort();
}

void doubly_linked_list::insert(int k)
{
	node *p = new node(k);
	tail->next = p;
	p->previous = tail;
	p->next = nullptr;
	tail = p;
	sort();
}

void doubly_linked_list::sort()
{
	node *p1, *temp2;
	p1 = head;
	temp2 = tail;
	int max, data = 0;
	max = -1;
	node *p2 = new node();
	tail->next = p2;
	p2->previous = tail;
	while (head != tail->next)
	{
		//To calculate the element with max frequency
		while (p1 != tail->next)
		{
			node *traverse = p1->next;
			int c = 1;
			while (traverse != tail->next)
			{
				if (p1->value == traverse->value)
					c++;
				traverse = traverse->next;
				if (max < c)
				{
					data = p1->value;
					max = c;
				}
			}
			p1 = p1->next;
		}
		//Placing the element with maximum frequency after tail  node
		p1 = head;
		while (p1 != tail->next)
		{
			if (p1->value == data)
			{
				p2->value = p1->value;
				node *temp1 = p1;
				p1 = p1->next;
				if (temp1 == head)
				{
					if (temp1 == tail) {
						temp2 = p2;
						head = head->next;
					}
					else
					{
						head = head->next;
						delete temp1;
					}
				}
				else if (temp1 == tail)
				{
					tail = tail->previous;
					tail->next = p1;
					p1->previous = tail;
					delete temp1;
				}
				else
				{
					p1->previous = temp1->previous;
					temp1->previous->next = p1;
					delete temp1;
				}
				temp2 = p2;
				p2 = new node();
				p2->previous = temp2;
				temp2->next = p2;
			}
			else
				p1 = p1->next;
		}
		//Finding the element that has the next maximum frequency (loop again)
		p1 = head;
		max = -1;
		data = head->value;
	}
	//placing tail at the end of the list
	p2->value = tail->value;
	node *delTail = tail;
	tail = temp2;
	delete delTail;
	tail->next = nullptr;
	head->previous = nullptr;
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

	d1.sort();
	d1.print_forward();
	d1.print_backward();

	d1.insert(16);
	d1.print_forward();
	d1.print_backward();

	d1.insert(16);
	d1.print_forward();
	d1.print_backward();

	d1.insert(16);
	d1.print_forward();
	d1.print_backward();

	d1.insert(16);
	d1.print_forward();
	d1.print_backward();

	d1.remove(4,3);
	d1.print_forward();
	d1.print_backward();

	getchar();
	getchar();
	return 0;
}
