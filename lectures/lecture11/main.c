#include "linked_list.h"

int main() {
    Node *head = NULL;

    insert_front(&head, "apple");
    insert_front(&head, "banana");
    insert_front(&head, "cherry");

    printf("Linked list after inserting three nodes:\n");
    display_list(head);

    printf("Deleting 'banana' from the list:\n");
    if (delete_node(&head, "banana")) {
        printf("'banana' deleted successfully\n");
    } else {
        printf("'banana' not found in the list\n");
    }

    display_list(head);

    free_list(&head);
    printf("Linked list after freeing all nodes:\n");
    display_list(head);

    return 0;
}
