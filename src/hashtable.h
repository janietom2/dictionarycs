#include <iostream>
#include "hashentry.h"

using namespace std;

#ifndef hashtable_h
#define hashtable_h

class hashtable {
    
    public:
        hashtable(int size);
        void insert(int key);
        void print();
        void printByKey(int key);
        void printTable();
    
    private:
        vector< vector<hashentry> > List; // List
        int tableSize;
        int hash(int key);
};

/*
does that make sense
*/

#endif

