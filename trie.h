//
// Created by avi on 08/01/2020.
//

#ifndef PROJECT4_TRIE_H
#define PROJECT4_TRIE_H
#define childrenNum 26


#include <stdbool.h>
#include <bits/types/FILE.h>

int toInteger(char x);



typedef struct trieNode
{
    struct trieNode *children[childrenNum];
    bool isLeaf;
    int numOfWords;

}trieNode;


trieNode *addNode(void);

void insert(trieNode *root, char *word);

void print(trieNode *root, char *ans,char *nums,int x);

void Lex(trieNode* root, char outWord[], int indexNum, bool toReverse);

void toLegal( char *word);

void toLittelChar( char *word);

void freeMemory(trieNode *root);

char *inputString(FILE* fp, size_t size);


#endif //PROJECT4_TRIE_H
