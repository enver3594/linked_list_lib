#include "linked_list.h"

/* (Bash)
gcc examples/example.c src/linked_list.c -Iinclude -o example
./example
*/

int main(){
    Node* head = NULL;
    for(;;){
        ///////////////////////////////// remove print from library functions 

        printf("Enter element to add in the end\n");
        int a;
        scanf("%d", &a);
        ll_push_back(&head, &a, sizeof(a));
        ll_output(head, ll_print_int);

        printf("Enter element to add in the beginning\n");
        int b;
        scanf("%d", &b);
        ll_push_front(&head, &b, sizeof(b));
        ll_output(head, ll_print_int);

        int position, data;
        printf("Enter position\n");
        scanf("%d", &position);
        printf("Enter data\n");
        scanf("%d", &data);
        ll_insert_after_position(&head, &data, sizeof(data), position);
        ll_output(head, ll_print_int);

        int position2, data2;
        printf("Enter position2\n");
        scanf("%d", &position2);
        printf("Enter data\n");
        scanf("%d", &data2);
        ll_insert_before_position(&head, &data2, sizeof(data2), position2);
        ll_output(head, ll_print_int);

        int pos = 0;
        printf("remove element, enter position\n");
        scanf("%d", &pos);
        ll_remove(&head, pos);
        ll_output(head, ll_print_int);

        /*
        printf("find node at index\n");
        int index = 0;
        scanf("%d", &index);
        //////////////////////////////////////// FFFFFFIIIIIIIIXXXXX
        */

        printf("reverse\n");
        ll_reverse(&head);
        ll_output(head, ll_print_int);

        printf("copy list\n");
        Node* copy = ll_copy(head);
        ll_output(copy, ll_print_int);
    }
}