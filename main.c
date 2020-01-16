#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "trie.h"
//#define char Word[256]

int main(int argc, char **argv) {

    trieNode* root = addNode(); // Create an empty Trie
    bool toReverse = false;
    if (argc == 2) {
        if (!strncmp(argv[1], "r", 1))
            toReverse = true;
    }
    char word[256];
    char anyWord[256];


    while (scanf("%s", anyWord) != EOF)
        insert(root, anyWord);


    Lex(root,word,0,toReverse);
    freeMemory(root);

    return 0;
}