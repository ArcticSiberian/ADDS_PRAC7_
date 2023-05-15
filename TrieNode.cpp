#include "TrieNode.h"

TrieNode::TrieNode(){
    isEndOfWord = false;
    children = std::vector <TrieNode *> (26,nullptr);
    routerNum = 0;
}

TrieNode::TrieNode(int n){
    isEndOfWord = false;
    children = std::vector <TrieNode *> (2,nullptr);
    routerNum = 0;
}