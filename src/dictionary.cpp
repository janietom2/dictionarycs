#include <iostream>
#include <vector>
#include "hashtable.h"

using namespace std;

int main() {
    
    // cout << "======== COMPUTER SCIENCE BASIC GUIDE ========" << endl;
    
    // cout << "Please navigate through the menu by inserting the key and then press enter" << endl;
    
    // return 0;
    
    hashtable h(11);
    
    h.insert(22);
    h.insert(1200);

    h.printTable();

    return 0;
}
