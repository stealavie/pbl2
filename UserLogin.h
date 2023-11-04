#include <iostream>
#include <string>
#include "Trie.h"


class UserLogin
{
    private:
    Trie* User;
    public:
    UserLogin();
    ~UserLogin();
    void Register();
    bool Login(const std::string&,const std::string&);
    info* GetUserInfo(const std::string& ,const std::string& );
};