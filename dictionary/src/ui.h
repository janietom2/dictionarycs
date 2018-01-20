#include <iostream>
#include <string>
#include "Topics.h"

#ifndef ui_h
#define ui_h

class ui {

    public:
		void home();
		ui(Topics table);

    private:
		void adminLogin();
		void showAdminPanel(std::string username);
		void showDictionary();
		Topics tp;

};

#endif

