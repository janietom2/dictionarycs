#include <iostream>
#include <string>
#include <vector>

using namespace std;

#ifndef LOGIN_H_
#define LOGIN_H_


class login {

	private:
		string password;
		string username;
		vector <string> creds;
		//string hash(string target);

	public:
		login(string username);
		bool check(string username, string password);

};

#endif /* LOGIN_H_ */
