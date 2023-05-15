#include "PrefixMatcher.h"
#include <iostream>

PrefixMatcher :: PrefixMatcher(){
    root = new TrieNode(4);
}

void PrefixMatcher::insert(std::string address, int routerNumber){

    //initilise variables
    TrieNode* current = root;
    int number = address.length();

    

    //loop through each number of the address
    for(int i = 0; i < number; i++){

        //create a new node if the letter doesnt exist yet
        if(current->children[address[i]-48] == nullptr){
            current->children[address[i]-48] = new TrieNode();

            //print for debugging
            std::cout<<address[i]-48<<std::endl;
        }

        //move to next node
        current = current->children[address[i]-48];
    }

    //set end of the word to true and set the router number
    current->isEndOfWord = true;
    current->routerNum = routerNumber;
    
}


int PrefixMatcher::selectRouter(std::string networkAddress){

    //initilise variables
    TrieNode* current = root;
    int number = networkAddress.length();
    int router = -1;
    int i = 0;

    //loop through each number of the address
    while(i<number && current->children[networkAddress[i]-48] != nullptr){

        //if you get to the end of the address return -1 because it doesnt exist
        if(current->children[networkAddress[i]-48] == nullptr){
            return router;
        }

        //go to next address
        current = current->children[networkAddress[i]-48];
        i++;
    }

    //go to the one with the longest match and check its router number
    while(current->children[0] != nullptr || current->children[1] != nullptr){

        // conditions to go to the next number depending on which pointer is null
        if(current->children[0] == nullptr){

            current = current->children[1];

        }else if(current->children[1] == nullptr){

            current = current->children[0];

        }
    }

    //return the address
    return current->routerNum;

}

