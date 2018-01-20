#include "ui.h"
#include "login.h"

using namespace std;


ui::ui(Topics table) {
	this->tp = table;
}

void ui::home(){

	int selection;
	cout << "Are you an admin?" << endl;

	cout << "1) Go to Login" << endl;
	cout << "2) Go to dictionary" << endl;

	cin >> selection;

	if(cin.fail()) {
		cout << "You must input a number" << endl;
		cin.clear();
		return;
	}

	switch(selection) {
		case 1:
			adminLogin();
			break;
		case 2:
			showDictionary();
			break;
		default:
			cout << "Invalid option" << endl;
			return home();
			break;
	}

	return;

}

void ui::adminLogin(){

	string password, username;

	cout << " Hi please set your credentials" << endl;

	cout << "Please Login" << endl;
	cout << " - Username: ";
	cin >> username;
	cout << "\n - Password: ";
	cin >> password;

	login lg(username);

	if(!lg.check(username, password)) {
		showAdminPanel(username);
	} else {
		cout << "Wrong Credentials, try again" << endl;
		return adminLogin();
	}

	return;

}

void ui::showAdminPanel(string username) {

	int selection = 0;
	string topicName;

	cout << "=============" << endl;
	cout << "Hi! " << username << endl;

	cout << "Please use one of the following options" << endl;

	cout << "1) Add topic" << endl;
	cout << "2) Exit" << endl; //Beta

	cin >> selection;

	switch(selection) {
		case 1:
			cout << "please insert the topic name: " << endl;
			cin >> topicName;
			this->tp.insert(topicName);
			break;
		case 2:
			cout << "Bye bye!" << endl;
			return;
		default:
			cout << "Choose a valid option" << endl;
			return;
	}

	return showAdminPanel(username);
}

void ui::showDictionary() {

	string selection = "";

	cout << "=============" << endl;
	cout << "These are the topics you can select of " << endl;

	this->tp.printTopics();

	cout << "Input the name of the Topic you want to choose :" << endl;

	cin >> selection;

	this->tp.getContent(selection);

	return showDictionary();

}
