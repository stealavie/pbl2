#include"UserEdit.h"

Profile::Profile()
{
    user=new UserLogin();
}

Profile::~Profile()
{
    delete user;
}

void Profile::EditCountry(const std::string& username, const std::string& password, const std::string& newCountry) 
{
        info* userInfo =user->GetUserInfo(username, password);
        if(userInfo) 
        {
            userInfo->country = newCountry;
            std::cout << "Country updated successfully.\n";
        } else 
        {
            std::cout << "Invalid username or password.\n";
        }
    }