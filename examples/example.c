#include "linked_list.h"

/* (Bash)
gcc examples/example.c src/linked_list.c -Iinclude -o example
./example
*/

int main(){
    Node* head = NULL;
    for(;;){
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
    }
}