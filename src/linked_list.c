#include "linked_list.h"
#include <stdlib.h>
#include <string.h> // for memcpy


//macros for checking data allocarion
//added do-while for proper macros expansion
#define DATA_CHECK_VOID(ptr) \
    do { \
        if((ptr) == NULL) { \
            printf("Error: NULL data pointer at %s:%d", __FILE__, __LINE__); \
            return; \
        }\
    }while(0)

Node* ll_create_node(const void* data, size_t data_size) {
    if (data == NULL)
    {
        printf("Error: NULL data pointer\n");
        return NULL;
    }

    Node* new_node = (Node*)malloc(sizeof(Node));
    if(new_node == NULL)
    {
        printf("Error in memory allocation\n");
        return NULL;
    }


    new_node->data = malloc(data_size);
    if (new_node->data == NULL)
    {
        printf("Error in memory allocation");
        free(new_node);
        return NULL;
    }
    
    memcpy(new_node->data, data, data_size);
    new_node->data_size = data_size;
    new_node->next = NULL;
    return new_node;
}

bool ll_is_empty(Node *head){
    return head == NULL;
}

void ll_print_if_empty(Node *head){
    if (ll_is_empty(head))
    {
        printf("List is empty\n");
    }
    return;
}

void ll_output(Node *head, void (*print_funk)(const void*)){
    ll_print_if_empty(head);

    DATA_CHECK_VOID(print_funk);
    
    Node *current = head;
    while (current != NULL)
    {
        print_funk(current->data);

        if (current->next != NULL)
        {
            printf(" -> ");
        }
        current = current->next;
    }
    printf(" -> NULL\n");
}

//additional functions for output
void ll_print_int(const void* data){
    DATA_CHECK_VOID(data);
    //converting from an address to an integer variable
    int value = *(const int*)data;
    printf("%d", value);
}
void ll_print_size_t(const void* data){
    DATA_CHECK_VOID(data);
    size_t value = *(const size_t*)data;
    printf("%zu", value);
}
void ll_print_float(const void* data){
    DATA_CHECK_VOID(data);
    float value = *(const float*)data;
    printf("%g", value);
}
void ll_print_double(const void* data){
    DATA_CHECK_VOID(data);
    double value = *(const double*)data;
    printf("%g", value);
}
void ll_print_char(const void* data){
    DATA_CHECK_VOID(data);
    char value = *(const char*)data;
    printf("%c", value);
}
void ll_print_string(const void* data){
    DATA_CHECK_VOID(data);
    const char* str = (const char*)data;
    printf("\"%s\"", str);
}


void ll_destroy(Node** head){
    ll_print_if_empty(*head);

    Node *current = *head;
    while(current != NULL){
        Node* temp = current;
        current = current->next;

        free(temp);
    }
    *head = NULL;
}

void ll_push_back(Node** head, const void* data, size_t data_size){
    //add to the end of a list 
    DATA_CHECK_VOID(head);
    DATA_CHECK_VOID(data);

    Node *new_node = ll_create_node(data, data_size);
    if (new_node == NULL){return;}

    if (*head == NULL)
    {
        *head = new_node;
        return;
    }

    Node *current = *head;
    while (current->next != NULL)
    {
        current = current->next;
    }
    current->next = new_node;
}

void ll_push_front(Node** head, const void* data, size_t data_size){
    // add to the begining of a list 
    DATA_CHECK_VOID(head);
    DATA_CHECK_VOID(data);

    Node* new_node = ll_create_node(data, data_size);
    if (new_node == NULL){return;}

    new_node->next = *head;
    *head = new_node;
}

/*
void ll_insert_after_value(Node** head, const void* value, const void* data, size_t data_size){
    //insert after a value
    DATA_CHECK_VOID(head);
    DATA_CHECK_VOID(value);
    DATA_CHECK_VOID(data);

    Node* current = *head;

    while (current != NULL)
    {
        if (current->data == value)
        {
        }
        
        current = current->next;
    }
    
}
*/

void ll_insert_after_position(Node** head, const void* data, size_t data_size, size_t position){
    DATA_CHECK_VOID(head);
    DATA_CHECK_VOID(data);

    if (position == 0 && *head == NULL)
    {
        Node* new_node = ll_create_node(data, data_size);
        if (new_node == NULL){return;}

        new_node->next = *head;
        *head = new_node;
        return;
    }
    
    
    Node* current = *head;

    size_t count = 0;

    while (current != NULL)
    {
        if (count == position)
        {
            Node* new_node = ll_create_node(data, data_size);
            if (new_node == NULL){return;}

            new_node->next = current->next;
            current->next = new_node;
            return;
        }
        count += 1;
        current = current->next;
    }
    printf("Error, incorrect position input\n");
}