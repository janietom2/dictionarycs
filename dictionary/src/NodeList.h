#include <iostream>
#include <string>
#include "Node.h"

#ifndef node_h
#define node_h

class NodeList {

	public:
	Node* head;
	NodeList();
	void insert(std::string value);
	void printList();

};

#endif
