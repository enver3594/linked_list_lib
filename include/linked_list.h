#ifndef LINKES_LIST_H
#define LINKED_LIST_H

#include <stdio.h>
#include<stdbool.h>

typedef struct Node{
    void* data;
    size_t data_size;
    struct Node *next;
}Node;

Node* create_node(const void* data, size_t data_size);

bool is_empty(Node *head);

void deallocation(Node **head);

void output(Node* head);

void create_random_element(Node **head);

void push_back(Node **head, const void* data, size_t data_size);
//add to back 

void push_front(Node **head, const void* data, size_t data_size);
//add to front

void insert_after(Node **head, int newData, int data);

void delete(Node **head, int data);

#endif