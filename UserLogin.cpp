#include"UserLogin.h"


    UserLogin::UserLogin() {
        User = new Trie();
    }

    UserLogin::~UserLogin() {
        delete User;
    }

    void UserLogin::Register()
    {
        std::string username;
        std::cout<<"enter username:";
        std::cin>>username;
        std::string password;
        std::cout<<"\nenter password";
        info* new_info = new info;
        new_info->password = password;
        User->insert(username, new_info);
    }

    bool UserLogin::Login(const std::string& username,const std::string& password)
    {
        if(User->search(username)) {
            Trie_node* node = User->getRoot();
            for(char c : username) {
                node = node->getChild(c);
            }
            if(node->getInfo()->password == password) {
                return true;
            }
        }
        return false;
    }

    info* UserLogin::GetUserInfo(const std::string& username,const std::string& password)
    {
        Trie_node* node=User->getRoot();
        if(Login(username,password))
        {
             for(char c : username) 
             {
                node = node->getChild(c);
            }
        }
        return node->getInfo();
    }


