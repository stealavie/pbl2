#pragma once
#include<iostream>
#include<fstream>
#include<vector>
#include<string>
using namespace std;
typedef struct info
{
    std::string password;
    std::string country;
    std::string username;
    std::string project_id;
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
    void setChild(char, Trie_node*);
    Trie_node* getChild(char) const;
    void setInfo(info*);
    info* getInfo();
    friend bool operator == (info*, const string&);
};


class Trie : public Trie_node
{
protected:
    Trie_node* root;
public:
    Trie();
    ~Trie();
    Trie_node* getRoot();
    bool search(const std::string&);
    info* getInfo(const string&);
    void traverseTrie(Trie_node*, vector<pair<string, info*>>&, std::string);
};

