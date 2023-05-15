#ifndef TRIENODE
#define TRIENODE
#include<list>
#include<string>
#include <vector>

class TrieNode {
    public:
       bool isEndOfWord;
       int routerNum;
       std::vector<TrieNode *> children;
       TrieNode();
       TrieNode(int n);
};
#endif