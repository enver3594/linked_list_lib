#include "linked_list.h"

/* (Bash)
gcc examples/example.c src/linked_list.c -Iinclude -o example
./example
*/

int main(){
    Node* head = NULL;
    for(;;){
        printf("Enter element to add in the end\n");
        float a;
        scanf("%lf", &a);
        printf("%g\n", a);
        push_back(&head, &a, sizeof(a));
        output(head, print_double);
    }
}