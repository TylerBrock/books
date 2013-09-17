#include <iostream>
#include "node.h"

Node::Node(int data)
{
	data_val = data;
	next_ptr = NULL;
}

void Node::set_next(Node * next)
{
	next_ptr = next;
}

Node * Node::next()
{
	return next_ptr;
}

void Node::show()
{
	std::cout << "Node(" << data_val << ")" << std::endl;
}