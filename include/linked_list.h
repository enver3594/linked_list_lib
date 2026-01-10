#ifndef LINKES_LIST_H
#define LINKED_LIST_H

#include <stdio.h>
#include<stdbool.h>

typedef struct Node{
    void* data;
    size_t data_size;
    struct Node *next;
}Node;

Node* ll_create_node(const void* data, size_t data_size);
bool ll_is_empty(Node *head);
void ll_destroy(Node **head);

void ll_output(Node* head, void (*print_funk)(const void*));
void ll_print_int(const void* data);
void ll_print_size_t(const void* data);
void ll_print_float(const void* data);
void ll_print_double(const void* data);
void ll_print_char(const void* data);
void ll_print_string(const void* data);


void ll_create_random_element(Node **head);

void ll_push_back(Node **head, const void* data, size_t data_size);
//add to back 

void ll_push_front(Node **head, const void* data, size_t data_size);
//add to front

void ll_insert_after(Node **head, int newData, int data);
//insert after a value

void ll_remove(Node **head, int data);
// delete node at value

Node* ll_find(Node *l, int x);


//Informational
size_t ll_length(Node *l);

Node* ll_get_first();
//get first element

Node* ll_get_last();

Node* ll_get_at();

void* ll_get_data_at(Node* head, int index);

bool ll_contains();
//Is there an element?(true/false)
//like find_node(), but diffetent realization


//Advanced operations
void ll_reverse();

Node* ll_copy();

Node* ll_merge();
//merge two sorted lists


//Special operations
void ll_pop_front();
//delete first element

void ll_pop_back();
// delete last element 

void ll_remove_at();
// delete at index

void ll_insert_sorted();
// Insert in sorted list

bool ll_detect_cycle();
//detect a cycle in a list.

Node* ll_get_nth();
//get an element from n position 


#endif