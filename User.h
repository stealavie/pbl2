#pragma once
#include"Trie.h"

class User : public Trie
{
private:
    std::string Username, Password,username,country,project_id;
public:
    User();
    void Load_data();
    void update_data();
    void Insert(const string&, const string&, const string& ="", const string & = "", const string& ="");

    void Print();

};
