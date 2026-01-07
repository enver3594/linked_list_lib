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

Node* create_node(const void* data, size_t data_size) {
    if (data == NULL)
    {
        printf("Error: NULL data pointer\n");
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

bool is_empty(Node *head){
    return head == NULL;
}

void print_if_empty(Node *head){
    if (is_empty(head))
    {
        printf("List is empty\n");
    }
}

//Need to fix output later, because 
void output(Node *head){
    print_if_empty(head);
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
    DATA_CHECK_VOID(head);
    DATA_CHECK_VOID(data);

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


