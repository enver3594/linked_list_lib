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

void ll_insert_after_value(Node **head, const void* value, const void* data, size_t data_size);
//insert after a value

void ll_insert_after_position(Node **head, const void* data, size_t data_size, size_t position);

void ll_insert_before_position(Node** head, const void* data, size_t data_size, size_t position);

void ll_remove(Node **head, size_t position);
// delete node at position

Node* ll_find(Node *head, size_t index);


//Informational
size_t ll_length(Node *head);
//size_t ll_length_recurtion(Node* head); 

Node* ll_get_first(Node *head);
//get first element

Node* ll_get_last(Node *head);

Node* ll_get_at(Node* head, size_t index);

void* ll_get_data_at(Node* head, size_t index);

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