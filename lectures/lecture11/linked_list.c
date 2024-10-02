#include "linked_list.h"

Node* create_node(const char *str) {
    Node *new_node = (Node*)malloc(sizeof(Node));
    if (new_node == NULL) {
        fprintf(stderr, "Error allocating memory\n");
        exit(EXIT_FAILURE);
    }
    new_node->data = strdup(str);
    new_node->next = NULL;
    return new_node;
}

void insert_front(Node **head, const char *str) {
    Node *new_node = create_node(str);
    new_node->next = *head;
    *head = new_node;
}

int delete_node(Node **head, const char *str) {
    Node *temp = *head, *prev = NULL;

    if (temp != NULL && strcmp(temp->data, str) == 0) {
        *head = temp->next;
        free(temp->data);
        free(temp);
        return 1;
    }

    while (temp != NULL && strcmp(temp->data, str) != 0) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) return 0;

    prev->next = temp->next;
    free(temp->data);
    free(temp);
    return 1;
}

void display_list(Node *head) {
    Node *current = head;
    while (current != NULL) {
        printf("%s -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

void free_list(Node **head) {
    Node *current = *head;
    Node *next;

    while (current != NULL) {
        next = current->next;
        free(current->data);
        free(current);
        current = next;
    }

    *head = NULL;
}
