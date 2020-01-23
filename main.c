#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "trie.h"
//#define char Word[256]

int main(int argc, char **argv) {
/*
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
*/

    bool toReverse = false;
    if (argc == 2) {
        if (!strncmp(argv[1], "r", 1))
            toReverse = true;
    }


    trieNode* root = addNode();
    int index = 0;
    int max = 0;
    char* word = (char*)malloc(sizeof(char)*2);
    if (word == NULL){
        perror("malloc error");
    }
    *word = 0;
    *(word+ 1) = 0;
    char letter;
    while (scanf("%c",&letter) == 1 ) {
        if (letter != '\0' && letter != '\t' && letter != '\n' && letter != ',' && letter != ' ') {
            word[index] = letter;
            index++;
            word = (char *) realloc(word, index + 2);

        } else {
            if (index != 0) {
            insert(root, word);
            free(word);
            word = (char *) malloc(sizeof(char) * 2);

            *word = 0;
            *(word + 1) = 0;
            if (index >= max) {
                max = index;
            }
            index = 0;
          }
        }
    }
    if (index > 0){
        insert(root,word);
        free(word);
    }
    if (index == 0){
        free(word);
    }

    char length[max];

    Lex(root,length,0, toReverse );

    freeMemory(root);

    return 0;
}
