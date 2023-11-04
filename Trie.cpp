#include"Trie.h"

Trie_node::Trie_node() : isEndOfWord(false),Info(NULL)
{
    for(int i=0;i<26;i++)
    {
        this->child[i]=NULL;
    }
}


void Trie_node::setEndOfWord(bool val)
{
    this->isEndOfWord=val;
}

bool Trie_node::getEndOfWord() const
{
    return this->isEndOfWord;
}

bool Trie_node::hasChild(char c) const
{
        if(this->child[c-'a'] != nullptr)
            return true;
    return false;
}

void Trie_node::setChild(char c,Trie_node* node)
{
    this->child[c-'a']=node;
}

Trie_node* Trie_node::getChild(char c) const
{
    return this->child[c-'a'];
}

void Trie_node::setInfo(info* Info)
{
    this->Info=Info;
}

info* Trie_node::getInfo()
{
    
    return this->Info;
}

Trie::Trie()
{
    this->root=new Trie_node();
}

void Trie::insert(const std::string& word,info* Info)
{
    RSA* obj=new RSA();
  Trie_node* node = root;
        for (char i : word) {
            
            if (!node->getChild(i))
                node->setChild(i,new Trie_node());
            node = node->getChild(i);
        }
        node->setEndOfWord(true);
        node->setInfo(Info);
        std::string username_pass=node->getInfo()->password;
        obj->encrypt(username_pass);
        delete obj;
}

bool Trie::search(const std::string& word)
{
    Trie_node* node=this->root;
    for(char c : word)
    {
        if(!node->getChild(c))
        {
            return false;
        }
        node=node->getChild(c);
    }
    return node->getEndOfWord();
}

void Trie:: Load_data()
{
    std::ifstream ip("Data_test.csv");
    if(!ip.is_open()) 
    {
        std::cout<<"ERROR!"<<std::endl;
    }else
    {
        std::string username,password,country;
        while(std::getline(ip,username,',')&&
        std::getline(ip,password,',')&&
        std::getline(ip,country,'\n'))
        {
        info* new_info = new info;
        
        new_info->password = password;
        new_info->country = country;

        insert(username,new_info);

        username.clear();
        password.clear();
        country.clear();
    }
    ip.close();
    // std::ifstream ip("Data_test.csv");

    // if(!ip.is_open()) std::cout << "ERROR: File Open" << '\n';

    // std::string email;
    // std::string password;
    // std::string country;

    // while(ip.good()){

    //     std::getline(ip,email,',');
    //     std::getline(ip,password,',');
    //     std::getline(ip,country,'\n');

    //     info* new_info = new info;

    //     new_info->password = password;
    //     new_info->country = country;

    //     insert(email,new_info);

    //     email.clear();
    //     password.clear();
    //     country.clear();
    // }
    // ip.close();
}
}

void Trie::Print_trie(Trie_node* node, const std::string& str) {
    if (node->getEndOfWord()) {
        std::cout << str << ": " << node->getInfo()->country<<","<<node->getInfo()->password<< std::endl;
    }
    
    for (char ch = 'a'; ch <= 'z'; ch++) {
        Trie_node* child = node->getChild(ch);
        if (child != NULL) {
            Print_trie(child, str + ch);
        }
    }
}


void Trie::update_data( ){

    ofstream ip;
    ip.open("Data_test.csv",ofstream::out | ofstream::trunc);
    ip.close();

    ip.open("Data_test.csv");

    vector<pair<string, info*>> username;
    traverseTrie(this->root,username,"");

    for (auto &word : username) {
        ip << word.first;
        ip << endl;
    

    }
    ip.close();
}


Trie_node* Trie::getRoot()
{
    return this->root;
}


Trie::~Trie() {
    delete[] root;
}


Trie_node::~Trie_node()
{
    for(int i = 0; i < 26; ++i)
    delete [] child[i];
delete [] child;
delete this->Info;
}


void traverseTrie( Trie_node *root, vector<pair<string, info*>> &words, string word) {
    if (root->getEndOfWord())
        words.push_back(make_pair(word, root->getInfo()));
    for (char c = 'a'; c <= 'z'; ++c) {
        if (root->getChild(c))
            traverseTrie(root->getChild(c), words, word + c);
    }
}