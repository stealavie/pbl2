#pragma once
#include<iostream>
#include<fstream>
#include<vector>
using namespace std;

class Trie_node {
protected:
    Trie_node* child[26];
    bool isEndOfWord;
    string info;
public:
    Trie_node(); 

    ~Trie_node();

    void setEndOfWord(bool);

    bool getEndOfWord() const;

    bool hasChild(char) const; 

    void setChild(char , Trie_node*);

    Trie_node* getChild(char) const; 

    void setInfo(const string&);

    string getInfo() const;

};



class Trie : public Trie_node
{
    protected:
    Trie_node* root;
    public:
    Trie();
    ~Trie();
    Trie_node* getRoot();
    virtual void Insert(const string&,const string&)=0;
    bool search(const std::string&);
    virtual void Load_data()=0;
    virtual void update_data()=0;
    friend std::vector<std::string> get_all_user(Trie_node*,std::string);
    void traverseTrie(Trie_node*,vector<string> &,string);
};
