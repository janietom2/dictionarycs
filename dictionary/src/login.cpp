#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include "login.h"

using namespace std;

login::login(string username) {

	string line;
	ifstream credentialFile ("credentials_"+username+".txt"); // Get credential file

	if(credentialFile.is_open()) {
		while( getline(credentialFile,line) ) {
			 this->creds.push_back(line);
		 }
	 } else {
		 cout << "Error getting the file" << endl;
	 }

}

bool login::check(string username, string password) {

	if( this->creds[0].compare(username) == 0 && this->creds[1].compare(password) == 0 ) {
		return true;
	}

	return false;
}


