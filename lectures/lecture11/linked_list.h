#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    char *data;
    struct Node *next;
} Node;

Node* create_node(const char *str);

void insert_front(Node **head, const char *str);

int delete_node(Node **head, const char *str);

void display_list(Node *head);

void free_list(Node **head);

#endif
