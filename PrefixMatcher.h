#ifndef PREFIXMATCHER
#define PREFIXMATCHER
#include<string>
#include <vector>
#include "TrieNode.h"

class PrefixMatcher{

    private:
    TrieNode* root;
    
    public:
    PrefixMatcher();
    int selectRouter(std::string networkAddress);
    void insert(std::string address, int routerNumber);

};
#endif