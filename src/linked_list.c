#include "linked_list.h"
#include <stdlib.h>
#include <string.h> // for memcpy

//macros for checking memory allocation
//added do-while for proper macros expansion
#define MALLOC_CHECK(ptr, return_value) \
    do { \
        if((ptr) == NULL) { \
            printf("Error in memory allocation at %s:%d", __FILE__, __LINE__); \
            return return_value; \
        }\
    }while(0)

//macros for checking data allocarion
#define DATA_CHECK(ptr, return_value) \
    do { \
        if((ptr) == NULL) { \
            printf("Error: NULL data pointer at %s:%d", __FILE__, __LINE__); \
            return return_value; \
        }\
    }while(0)

#define DATA_CHECK_WITH_CLEANUP(ptr, free) \
    do { \
        if ((ptr) == NULL) { \
            printf("Error: failed to allocate memory for data\n"); \
            free; \
            return NULL; \
        } \
    }while(0)


Node* create_node(const void* data, size_t data_size) {
    DATA_CHECK(data, NULL);

    Node* new_node = (Node*)malloc(sizeof(Node));
    MALLOC_CHECK(new_node, NULL);


    new_node->data = malloc(data_size);
    DATA_CHECK_WITH_CLEANUP(new_node->data, free(new_node));

    memcpy(new_node->data, data, data_size);
    new_node->data_size = data_size;
    new_node->next = NULL;
    return new_node;
}

bool is_empty(Node *head){
    return head == NULL;
}

//Need to fix output later, because 
void output(Node *head){
    if (is_empty(head))
    {
        printf("List is empty\n\n");
        return;
    }
    Node *current = head;
    while (current != NULL)
    {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("\n");
}

void push_back(Node** head, const void* data, size_t data_size){
    //add to the end of a list 
    DATA_CHECK(data, );
    DATA_CHECK(head, );

    Node *new = create_node(data, data_size);
    
    if (*head == NULL)
    {
        *head = new;
        return;
    }

    Node *current = *head;
    while (current->next != NULL)
    {
        current = current->next;
    }
    current->next = new;
}


