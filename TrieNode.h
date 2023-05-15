#ifndef TRIENODE
#define TRIENODE
#include<list>
#include<string>
#include <vector>

class TrieNode {
    public:
       bool isEndOfWord;
       std::vector<TrieNode *> children;
       TrieNode();
};
#endif