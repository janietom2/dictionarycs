#include <iostream>
#include <vector>
#include "hashtable.h"

using namespace std;


//hashtable::hashtable() {
//	tableSize = 0;
//}

hashtable::hashtable(int size) {
	tableSize = size;

	for(int i = 0; i < size; i++) {
		this->List.push_back( vector<NodeList*>(size) );
		for (int j = 0; j < size; j++) {
			this->List.at(i).at(j) = new NodeList; // When new object is initialized it return a pointer
		}
	}

}

//void hashtable::initialize(int size) {
//	tableSize = size;
//
//	for(int i = 0; i < size; i++) {
//		this->List.push_back( vector<NodeList*>(size/2) );
//		for (int j = 0; j < size/2; j++) {
//			this->List.at(i).at(j) = new NodeList; // When new object is initialized it return a pointer
//		}
//	}
//
//}

void hashtable::printTable(){

	for(int i = 0; i < this->List.size(); i++) {

		cout << "Table " << i << endl;
		cout << "=============" << endl;

		for(int j = 0; j < this->List.at(i).size(); j++) {
			this->List.at(i).at(j)->printList();
		}
	}
	cout << "=============" << endl;

}

void hashtable::print() {
	for (int i = 0; i < this->List.size(); i++){
		for(int j = 0; j < this->List.at(i).size(); j++) {
			this->List.at(i).at(j)->printList();
		}

	}
}

//Insertion can be boolean to check if it is inserted or not (This can be changed)
void hashtable::insert(string key) {

	int firstHash  = this->hash(key);
	int doubleHash = this->doubleHash(key);

	//hashentry hse = hashentry (key, NULL);

	this->List.at(firstHash).at(doubleHash)->insert(key);

}

bool hashtable::searchByKey(string key) {

	int firstHash  = this->hash(key);
	int doubleHash = this->hash(key);

	for(Node* tmp = this->List.at(firstHash).at(doubleHash)->head; tmp != NULL; tmp = tmp->next) {
		if(tmp->data == key) return true;
	}

	return false;

}


int hashtable::hash(string key) {
	return key.size() % this->List.size();
}

int hashtable::doubleHash(string key) {
	return key.size() % tableSize;
}
