#ifndef LINKES_LIST_H
#define LINKED_LIST_H

#include <stdio.h>

typedef struct Node{
    int data;
    struct Node *next;
}Node;

Node* create_node(int data);

void output(Node* l);

void add_to_back(Node **head, int data);

#endif