#include "Autocomplete.h"
#include <iostream>

Autocomplete::Autocomplete(){
    root = new TrieNode();
}

void Autocomplete::insert(std::string word){

    //initilise variables
    TrieNode* current = root;
    int letters = word.length();

    //loop through each letter of the word
    for(int i = 0; i < letters; i++){

        //create a new node if the letter doesnt exist yet
        if(current->children[word[i]-'a'] == nullptr){
            current->children[word[i]-'a'] = new TrieNode();

            //print for debugging
            std::cout<<word[i]-'a'<<std::endl;
        }

        //move to next node
        current = current->children[word[i]-'a'];
    }

    //set end of the word to true
    current->isEndOfWord = true;
    
}

std::vector<std::string> Autocomplete::getSuggestions(std::string partialWord){

    //initialise variables
    TrieNode* current = root;
    std::vector<std::string> complete;
    std::string word;
    int count = partialWord.length();
    int i = 0;

    //loop through every letter of the partial word
    while(i<count && current->children[partialWord[i]-'a'] != nullptr){

        //add the letter to word so it can be stored in the vector
        word.push_back(partialWord[i]);

        //print for debugging
        //std::cout<<word<<std::endl;

        //if you reach the end return the vector
        if(current->children[partialWord[i]-'a'] == nullptr){
            return complete;
        }
            
        //if the partial word exists as a word, push it to the vector
        if(current->isEndOfWord == true){
            complete.push_back(word);
        }
        
        //move to next node and next letter in word
        current = current->children[partialWord[i]-'a'];
        i++;
    }

    stillSearching(word,complete,current);
    
    return complete;
}

void Autocomplete::stillSearching(std::string word, std::vector<std::string>& complete, TrieNode* current){

    //assing the word to a new varibale to add new letter to it
    std::string call = word;

    //add words if they are at the end of the word
    if(current->isEndOfWord == true){
        complete.push_back(word);
    }

    // loop through each letter in the alphabet
    int j = 0;
    while(j<26){

        //if the children are not null pointer, add the letter to the word
        if(current->children[j] != nullptr){
            call.push_back(j+'a');

            //recursively call search until the looping stops when it meets the conditons
            stillSearching(call, complete, current->children[j]);
        }

        //increment j
        j++;
    }
}