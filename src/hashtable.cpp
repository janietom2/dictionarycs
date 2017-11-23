#include <iostream>
#include <vector>
#include "hashtable.h"

using namespace std;

hashtable::hashtable(int size) {
    tableSize = size;
    //Initialize 
    //this->List.resize(size,);

    for(int i = 0; i < size; i++) {
        hashentry he(-1);
        this->List.push_back(vector<hashentry>(size, he));
    }
    
}

void hashtable::printTable(){
    
    for(int i = 0; i < this->List.size(); i++) {
        //cout << "test " << i << endl;
    	cout << "Table " << i << endl;
        for(int j = 0; j < this->List.at(i).size(); j++) {
            cout << this->List.at(i).at(j).value << endl;
        }
    }
    
}

//Insertion can be boolean to check if it is inserted or not (This can be changed)
 void hashtable::insert(int key) {

    int hashed1 = this->hash(key);

    this->List.at(hashed1).at(hashed1).value = key;

 }


 int hashtable::hash(int key) {
     return key % this->List.size();
 }
