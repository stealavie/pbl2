#include<iostream>
#include<fstream>
#include<string>
#include<map>
using namespace std;
class Data
{
private:
    map<string , string > account;
public:
    void AddAccount(string&, string&);
    bool checkAcc(const string&, const string&);
    bool checkExist(const string&);
};

