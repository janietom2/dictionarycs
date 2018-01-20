#include <iostream>
#include <string>
#include <vector>
#include "NodeList.h"

using namespace std;

#ifndef hashtable_h
#define hashtable_h

class hashtable {
    
    public:
		//hashtable();
        hashtable(int size);
        //void initialize(int size);
        void insert(string key);
        void printByKey(string key);
        void printTable();
        void print();
        bool searchByKey(string key);
    
    private:
        vector< vector<NodeList*> > List; // List
        int tableSize;
        int hash(string key);
        int doubleHash(string key);
};

#endif

