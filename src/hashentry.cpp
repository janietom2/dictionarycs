#include <iostream>
#include "hashentry.h"

using namespace std;

hashentry::hashentry(int value) {
    this->value = value; 
}

int hashentry::getValue() {
	return this->value;
}
