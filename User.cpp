
#include"User.h"

User::User() 
{
    this->Username="";
    this->Password="";
}

void User::Load_data() 
{
    std::ifstream ip("C:/Users/USER/Desktop/pbl2/Data_test.csv");
    if (!ip.is_open()) 
    {
        std::cout << "ERROR! Unable to open the file." << std::endl;
        return;
    }
    else
    {
        std::cout << "File opened successfully!" << std::endl;
        while (std::getline(ip, this->Username, ',') &&
               std::getline(ip, this->Password, '\n'))
        {
            if (!this->Username.empty() && !this->Password.empty())
            {
                Insert(this->Username, this->Password);
            }
            this->Username.clear();
            this->Password.clear();
        }
        ip.close();

        // // In ra toàn bộ dữ liệu sau khi đọc từ file
        // Trie_node* root = this->getRoot();
        // std::vector<std::pair<std::string, info*>> allUserData;
        // this->traverseTrie(root, allUserData, "");

        // for (const auto& userData : allUserData) {
        //     std::cout << "Username: " << userData.first << ", Password: " << userData.second->password << std::endl;
        // }
    }
}


// void User::update_data() 
// {
//     ofstream ip;
//     ip.open("C:/Users/USER/Desktop/pbl2/Data_test.csv",ofstream::out | ofstream::trunc);
//     ip.close();
//     ip.open("C:/Users/USER/Desktop/pbl2/Data_test.csv");


//     vector<pair<string, info*>> username;
//     Trie::traverseTrie(this->root,username,"");

//     for (auto &user : username) 
//     {
//         ip << user.first<<","<<user.second->password<<"\n";
//     }

//     ip.close();
//     std::cout<<"update success"<<std::endl;
    
// }


void User::update_data() 
{
    ofstream ip;
    ip.open("C:/Users/USER/Desktop/pbl2/Data_test.csv", ofstream::out | ofstream::trunc);
    if (!ip.is_open()) 
    {
        std::cout << "ERROR! Unable to open the file for writing." << std::endl;
        return;
    }

    // Vector để lưu dữ liệu từ Trie
    vector<pair<string, info*>> username;
    // Duyệt cây Trie và lưu dữ liệu vào vector
    Trie::traverseTrie(this->root, username, "");

    // In ra số lượng phần tử trong vector để kiểm tra
    std::cout << "Number of elements in vector: " << username.size() << std::endl;

    // Ghi dữ liệu từ vector vào file
    for (const auto &user : username) 
    {
        ip << user.first << "," << user.second->password << "\n";
    }

    // Đóng file và kiểm tra
    ip.close();
    if (ip.is_open()) 
    {
        std::cout << "ERROR! Unable to close the file." << std::endl;
        return;
    }
    std::cout << "File closed successfully!" << std::endl;
    std::cout << "Update success" << std::endl;
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

void User::Print()
{
    std::cout << "Username: " << Username << ", Password: " << Password << std::endl;
}
