//
// Created by avi on 08/01/2020.
//

#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include "trie.h"
#include <stdio.h>
#define childrenNum 26



int toInteger(char x)
{
    int temp=(int)x-(int)'a';

    return temp;


}

void toLegal( char *word)
{

    int k=0;
    for (int i = 0; i < strlen(word) ; ++i) {
        int x= word[i];
        if(x<97 || x>122){

        }
        else{
            word[k]=(char)x;
            k++;
        }

    }
    word[k]='\0';
}


void toLittelChar( char *word){

    for (int i = 0; i < strlen(word) ; ++i) {
        int x= word[i];
        if(x>=65 && x<=90)
            word[i]=x+32;
        }


    }



/*
typedef struct trieNode
{
    struct trieNode *children[childrenNum];
    bool isLeaf;
    int numOfWords;
}trieNode;
*/

trieNode *addNode(void)
{

    trieNode *newNode=NULL;

    newNode=(trieNode *)malloc(sizeof(trieNode));
    if(newNode){
       newNode->isLeaf=false;
        for (int i = 0; i <childrenNum ; ++i) {
            newNode->children[i]=NULL;
            newNode->numOfWords=0;
        }


    }
    return newNode;
}


void insert(trieNode *root, char *word) {
    toLittelChar(word);
    toLegal(word);
    int letter;
    trieNode *current = root;
    int len =(int) strlen(word);
    for (int i = 0; i < len; ++i) {
        letter = toInteger(word[i]);
            if (!current->children[letter]) {
                current->children[letter] = addNode();
            }
            current = current->children[letter];
        }
        current->numOfWords++;
    current->isLeaf = true;

}


void Lex(trieNode* root, char ans[], int indexNum, bool toReverse){

    trieNode *current = root;

    if (current->numOfWords != 0 ) {
        ans[indexNum] = '\0';
        printf("%s\t %d\n", ans, root->numOfWords);

    }

    int index;
    for (int i = 0; i < childrenNum; ++i) {
        if (toReverse) {
            index = childrenNum - 1 - i;
        } else {
            index = i;
        }
        if (current->children[index] != NULL ) {
            ans[indexNum] = index + 'a';
            Lex(current->children[index], ans, indexNum + 1, toReverse);
        }

    }
}

void freeMemory(trieNode *root){

    trieNode *current=root;

    if(current->isLeaf )
    {
        free(current);
        return;
    }

    for (int i = 0; i <childrenNum ; ++i) {
        if(current->children[i])
        {
           // printf("%d\n",i+'a');
            freeMemory(current->children[i]);
        }
        if(i==25)
        {
            free(current);
        }
    }
}

/*
void freeMemory(trieNode* root){
    for (int i = 0; i < childrenNum; i++ ){
        if(root -> children[i] != NULL){
            freeMemory(root -> children[i]);
        }
    }
    if (root != NULL){
        free(root);
    }
}
 */