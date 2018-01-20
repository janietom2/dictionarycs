#include "Topics.h"
#include "hashtable.h"
#include <iostream>
#include <fstream>

Topics::Topics() {

	string line;
	ifstream topicsFile ("topics.txt"); // Topics
	int counter = 0;

	if(topicsFile.is_open()) {

		while( getline(topicsFile,line) ) {
			//cout << line << endl;
			this->topics.push_back(line);
			counter++;
		}

	} else {
		 cout << "Error getting the file" << endl;
	}

	topicsTable = new hashtable(15);

	for(int i = 0; i < counter; i++) {
		this->topicsTable->insert(this->topics.at(i));
	}


}

bool Topics::insert(string title) {

	if(!searchByKey(title)) {

		this->topics.push_back(title); // Save on temp array
		this->topicsTable->insert(title);
		this->save();

		ofstream newFile;

		newFile.open(title+".txt");

		newFile << "Write here definition" << endl;

		newFile.close();


		return true;

	} else {
		cout << title << " has already been inserted" << endl;
		return false;
	}

}

void Topics::printTopicsWithTable() {

	this->topicsTable->printTable();

}

bool Topics::getContent(string key) {

	if(!searchByKey(key)) { // Check if it exists
		cout << "Content not found!" << endl;
		return false;
	}

	ifstream tmpFile;
	string line;

	tmpFile.open(key+".txt");

	if (tmpFile.is_open())
	  {
		cout << "===========================================" << endl;
		cout << key << endl;
		cout << "===========================================" << endl;
	    while ( getline (tmpFile,line) )
	    {
	      cout << line << '\n';
	    }
	    tmpFile.close();
	    return true;
	  } else {
		  cout << "File not found" << endl;
		  return false;
	  }


}

void Topics::save() {
	  ofstream tmpFile; // Temp file

	  tmpFile.open("topics.txt");

	  for(int i = 0; i < topics.size(); i++) {
		  tmpFile << topics.at(i) << "\n";
	  }

	  tmpFile.close();

}

bool Topics::searchByKey(string key) {

	return this->topicsTable->searchByKey(key);

}

void Topics::printTopics() {
	this->topicsTable->print();
}

