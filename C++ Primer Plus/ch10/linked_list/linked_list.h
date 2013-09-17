#ifndef LINKED_LIST_H_
#define LINKED_LIST_H_

#include "node.h"

class LinkedList {
	private:
		Node * head;
		Node * tail;
	public:
		LinkedList();
		~LinkedList();
		void push(int n);
		void pop();
		void show() const;
};

#endif