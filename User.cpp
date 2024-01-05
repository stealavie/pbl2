
#include"User.h"
User::User()
{
    this->Username = "";
    this->Password = "";
    this->username = "";
    this->country = "";
    this->project_id = "";
}

void User::Load_data()
{
    std::ifstream ip("Data_test.csv");
    if (!ip.is_open())
    {
        std::cout << "ERROR! Unable to open the file." << std::endl;
        return;
    }
    else
    {
        std::cout << "File opened successfully!" << std::endl;
        while (std::getline(ip, this->Username, ',') &&
            std::getline(ip, this->Password, ',') && std::getline(ip,this->username,',') && std::getline(ip,this->country,',')
            && std::getline(ip,this->project_id,'\n'))
        {
            if (!this->Username.empty() && !this->Password.empty())
            {
                Insert(this->Username, this->Password,this->username,this->country,this->project_id);
                Print();
            }
            this->Username.clear();
            this->Password.clear();
            this->username.clear();
            this->country.clear();
            this->project_id.clear();
        }
        ip.close();
    }
}




void User::update_data()
{
    ofstream ip;
    ip.open("Data_test.csv", ofstream::out | ofstream::trunc);
    if (!ip.is_open())
    {
        std::cout << "ERROR! Unable to open the file for writing." << std::endl;
        return;
    }

    vector<pair<string, info*>> username;

    Trie::traverseTrie(this->root, username, "");


    std::cout << "Number of elements in vector: " << username.size() << std::endl;


    for (const auto& user : username)
    {
        ip << user.first << "," << user.second->password << "\n";
    }


    ip.close();
    if (ip.is_open())
    {
        std::cout << "ERROR! Unable to close the file." << std::endl;
        return;
    }
    std::cout << "File closed successfully!" << std::endl;
    std::cout << "Update success" << std::endl;
}




void User::Insert(const string& Username, const string& Password,const string& username, const string& country, const string& project_id)
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

    // Create a new info object and set its password
    info* Info = new info;
    Info->password = Password;
    Info->username = username;
    Info->country = country;
    Info->project_id = project_id;

    // Pass the info object to setInfo()
    node->setInfo(Info);
}

void User::Print()
{
    std::cout << "Username: " << Username << ", Password: " << Password << std::endl;
}
