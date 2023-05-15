#ifndef AUTOCOMPLETE
#define AUTOCOMPLETE
#include<string>
#include <vector>
#include "TrieNode.h"

class Autocomplete{
    private:
    TrieNode* root;
    
    public:
        Autocomplete();
        void stillSearching(std::string word, std::vector<std::string>& complete, TrieNode* current);
        std::vector<std::string> getSuggestions(std::string partialWord);  
        void insert(std::string word); 
};
#endif