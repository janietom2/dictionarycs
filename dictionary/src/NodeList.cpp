#include <iostream>
#include "NodeList.h"

using namespace std;

NodeList::NodeList() {
	head = NULL;
}


void NodeList::insert(string value) {

	Node* tmp  = new Node;
	tmp->data  = value;
	tmp->next  = head;
	head 	   = tmp;

}

void NodeList::printList() {

	Node* tmp = head;
	while(tmp != NULL) {
		cout << " ~ "<< tmp->data << endl;
		tmp = tmp->next;
	}

}
