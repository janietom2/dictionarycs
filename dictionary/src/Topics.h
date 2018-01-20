#include <iostream>
#include <string>
#include "NodeList.h"
#include "hashtable.h"

#ifndef topics_h
#define topics_h

class Topics {

	public:
		Topics(); // 1) Generate the hashtable and fill with the existent topics (Which are on a .txt file)
		bool insert(std::string title); // This will load
		void printTopicsWithTable();
		void printTopics();
		bool getContent(string key);
		bool searchByKey(string key);
		hashtable* topicsTable;
		vector <string> topics; //Temp array

	private:
		void save();
};

#endif
