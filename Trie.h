#include<iostream>
#include<fstream>
#include<vector>
using namespace std;
typedef struct info
{
    std::string password;
    std::string country;
}info;


class Trie_node {
private:
    Trie_node* child[26];
    bool isEndOfWord;
    info* Info;
public:
    Trie_node(); 

    ~Trie_node();

    void setEndOfWord(bool);

    bool getEndOfWord() const;

    bool hasChild(char) const; 

    void setChild(char , Trie_node*);

    Trie_node* getChild(char) const; 

    void setInfo(info*);

    info* getInfo();

    friend bool operator == (info*,const string&);
};



class Trie : public Trie_node
{
    protected:
    Trie_node* root;
    public:
    Trie();
    ~Trie();
    Trie_node* getRoot();
    void insert(const std::string&,info*);
    bool search(const std::string&);
    void Load_data();
    void update_data();
    // void Print_trie(Trie_node*,const std::string&);
    friend std::vector<std::string> get_all_user(Trie_node*,std::string);
    info* getInfo(const string&);
    void traverseTrie(Trie_node*,vector<pair<string, info*>> &,std::string);


};

