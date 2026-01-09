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

void output(Node* head, void (*print_funk)(const void*));
void print_int(const void* data);
void print_size_t(const void* data);
void print_float(const void* data);
void print_double(const void* data);
void print_char(const void* data);
void print_string(const void* data);


void create_random_element(Node **head);

void push_back(Node **head, const void* data, size_t data_size);
//add to back 

void push_front(Node **head, const void* data, size_t data_size);
//add to front

void insert_after(Node **head, int newData, int data);

void delete(Node **head, int data);

#endif