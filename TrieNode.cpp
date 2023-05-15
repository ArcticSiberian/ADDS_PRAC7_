#include "TrieNode.h"

TrieNode::TrieNode(){
    isEndOfWord = false;
    children = std::vector <TrieNode *> (26,nullptr);
}