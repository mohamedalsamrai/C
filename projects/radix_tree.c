#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define NUM_CHARS 256

typedef struct trienode {
    struct trienode *children[NUM_CHARS]; //each node can have other node max number of them is 256(all char in ascii code)
    bool terminal; // check if this node is end of string
} trienode;

trienode *createnode() {
    trienode *node = malloc(sizeof(trienode)); //creat node and reserve memory space 
    for (int i = 0; i < NUM_CHARS; i++) {
        node->children[i] = NULL; // put null value in all children because it is not have value yet
    }
    node->terminal = false; // for now all children not end of string
    return node;
}

void trieinsert(trienode **root, unsigned char *word) {
    if (*root == NULL) {
        *root = createnode();
    }

    trienode *current = *root;
    while (*word != 0) {
        if (current->children[*word] == NULL) {
            current->children[*word] = createnode();
        }
        current = current->children[*word];
        word++;
    }
    current->terminal = true;
}
void printtrie_rec(trienode *node, unsigned char *prefix, int length) {
    unsigned char newprefix[length + 2];
    memcpy(newprefix, prefix, length);
    newprefix[length + 1] = 0;

    if (node->terminal) {
        printf("WORD: %s\n", prefix);
    }

    for (int i = 0; i < NUM_CHARS; i++) {
        if (node->children[i] != NULL) {
            newprefix[length] = i;
            printtrie_rec(node->children[i], newprefix, length + 1);
        }
    }
}

void printtrie(trienode *root) {
    if (root == NULL) {
        printf("TRIE EMPTY!\n");
        return;
    }

    printtrie_rec(root, NULL, 0);
}


int main() {
    trienode *root = NULL;

    trieinsert(&root, "KIT");
    trieinsert(&root, "CATTLE");
    trieinsert(&root, "KIN");
    trieinsert(&root, "CAT");

    printtrie(root);

    return 0;
}
