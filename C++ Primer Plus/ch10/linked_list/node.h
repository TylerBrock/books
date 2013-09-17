#ifndef NODE_H
#define NODE_H

class Node {
	private:
		int data_val;
		Node * next_ptr;
		Node * prev_ptr;

	public:
		Node(int data = 0);
		void set_next(Node * next);
		Node * next();
		void show();
};

#endif