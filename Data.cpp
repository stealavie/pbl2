#include "Data.h"
using namespace std;

void Data::AddAccount( string& username, string& password)
{
	account[username] = password;
	ofstream file("Account.txt", ios::app);
	for (auto& kv : account)
	{
		file << kv.first << ' ' << kv.second << endl;
	}
	file.close();
}

bool Data::checkAcc(const string& username, const string& password)
{
	if (account.find(username) != account.end() && account[username] == password) {
		return true;
	}
	return false;
}

bool Data::checkExist(const string& email)
{
	if (account.find(email) != account.end()) return true;
	else return false;
}
