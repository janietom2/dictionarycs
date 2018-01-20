#include <iostream>
#include <vector>
#include <string>
#include "Topics.h"
#include "ui.h"

using namespace std;

int main() {

	Topics tp = Topics(); //Load the information and set it up in a hashtable

    cout << "======== COMPUTER SCIENCE BASIC GUIDE ========" << endl;

    cout << "Please navigate through the menu by inserting the key and then press enter" << endl;

    //tp.printTopics();

    	ui gui(tp);

    	gui.home();

    return 0;
}
