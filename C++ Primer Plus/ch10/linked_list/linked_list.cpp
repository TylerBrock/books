#include <cstdlib>
#include <iostream>
#include "linked_list.h"

LinkedList::LinkedList()
{
	head = NULL;
	tail = NULL;
}

LinkedList::~LinkedList()
{
	Node * current = head;
	Node * next = NULL;
	while (current) {
		next = current->next();
		std::cout << "Deleting ";
		current->show();
		delete current;
		current = next;
	}
}

void LinkedList::push(int n)
{
	Node * new_node = new Node(n);
	if (head == NULL) {
		head = new_node;
		tail = new_node;
	} else {
		tail->set_next(new_node);
		tail = new_node;
	}
}

void LinkedList::pop()
{
	// TODO: fill this shit in
}

void LinkedList::show() const
{
	Node * current = head;
	while (current) {
		current->show();
		current = current->next();
	}
}