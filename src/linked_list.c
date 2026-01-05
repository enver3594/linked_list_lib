#include "linked_list.h"
#include <stdlib.h>

Node* create_node(int data) {
    Node* new_node = (Node*)malloc(sizeof(Node));
    if (new_node == NULL) {
        printf("Ошибка выделения памяти!\n");
        return NULL;
    }
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

void output(Node *l){
    if (l == NULL)
    {
        printf("List is empty\n\n");
        return;
    }
    Node *current = l;
    while (current != NULL)
    {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("\n");
}

void add_to_back(Node **l, int data){
    //add to the end of a list 
    Node *new = malloc(sizeof(Node));
    if (new == NULL)
    {
        printf("ERROR of memory allocation\n");
        return NULL;
    }
    
    new->data = data;
    new->next = NULL;
    if (*l == NULL)
    {
        *l = new;
        return;
    }

    Node *current = *l;
    while (current->next != NULL)
    {
        current = current->next;
    }
    current->next = new;
}


