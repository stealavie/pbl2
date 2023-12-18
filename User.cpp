
#include"User.h"

User::User() 
{
    this->Username="";
    this->Password="";
}

void User::Load_data() 
{
    std::ifstream ip("C:/Users/USER/Desktop/pbl2/Data_test.csv");
    if(!ip.is_open()) 
    {
        std::cout<<"ERROR!"<<std::endl;
        return;
    }else
    {
        std::cout<<"open success!"<<std::endl;
        while(std::getline(ip,this->Username,',')&&
        std::getline(ip,this->Password,'\n'))
        {
        Insert(this->Username,this->Password);
        // if (!this->Username.empty() && !this->Password.empty())
        //     {
        //         Insert(this->Username, this->Password);
        //     }
        this->Username.clear();
        this->Password.clear();
        }   
    ip.close();
    }
}

void User::update_data() 
{
    ofstream ip;
    ip.open("C:/Users/USER/Desktop/pbl2/Data_test.csv",ofstream::out | ofstream::trunc);
    ip.close();
    ip.open("C:/Users/USER/Desktop/pbl2/Data_test.csv");


    vector<pair<string, info*>> username;
    Trie::traverseTrie(this->root,username,"");

    for (auto &user : username) 
    {
        ip << user.first<<","<<user.second->password<<"\n";
    }

    ip.close();
    std::cout<<"update success"<<std::endl;
    
}

void User::Insert(const string& Username, const string& Password)
{
    Trie_node* node = this->root;
    for (char c : Username)
    {
        if (!node->hasChild(c))
        {
            Trie_node* newNode = new Trie_node();
            node->setChild(c, newNode);
        }
        node = node->getChild(c);
    }
    node->setEndOfWord(true);
    // node->setInfo(Password);

    // Create a new info object and set its password
    info* Info = new info;
    Info->password = Password;
    
    // Pass the info object to setInfo()
    node->setInfo(Info);
}


