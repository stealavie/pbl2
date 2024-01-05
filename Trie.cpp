#include"Trie.h"

Trie_node::Trie_node() : isEndOfWord(false), Info(NULL)
{
    for (int i = 0; i < 26; i++)
    {
        this->child[i] = NULL;
    }
}


void Trie_node::setEndOfWord(bool val)
{
    this->isEndOfWord = val;
}

bool Trie_node::getEndOfWord() const
{
    return this->isEndOfWord;
}

bool Trie_node::hasChild(char c) const
{
    if (this->child[c - 'a'] != nullptr)
        return true;
    return false;
}

void Trie_node::setChild(char c, Trie_node* node)
{
    this->child[c - 'a'] = node;
}

Trie_node* Trie_node::getChild(char c) const
{
    return this->child[c - 'a'];
}

void Trie_node::setInfo(info* Info)
{
    this->Info = Info;
}

info* Trie::getInfo(const string& password)
{
    Trie_node* node = this->root;
    for (char c : password)
    {
        if (!node->getChild(c))
        {
            break;
        }
        node = node->getChild(c);
    }
    return node->getInfo();
}

Trie::Trie()
{
    this->root = new Trie_node();
}


bool Trie::search(const std::string& word)
{
    Trie_node* node = this->root;
    for (char c : word)
    {
        if (!node->getChild(c))
        {
            return false;
        }
        node = node->getChild(c);
    }
    return node->getEndOfWord();
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
    for (int i = 0; i < 26; ++i)
        delete[] child[i];
    delete[] child;
    delete this->Info;
}


void Trie::traverseTrie(Trie_node* root, vector<pair<string, info*>>& words, string word) {
    if (root->getEndOfWord())
        words.push_back(make_pair(word, root->getInfo()));
    for (char c = 'a'; c <= 'z'; ++c) {
        if (root->getChild(c))
            traverseTrie(root->getChild(c), words, word + c);
    }
}

bool operator==(info* infor, const string& password)
{
    if (infor->password == password) return true;
    else return false;
}

info* Trie_node::getInfo()
{
    return this->Info;
}
