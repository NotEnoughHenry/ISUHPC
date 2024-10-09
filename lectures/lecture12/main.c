// Author: Henry Eichten
#include <stdio.h>
#include <termios.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

// Define a node for the stack
typedef struct Node {
    void* data;
    struct Node* next;
} Node;

// Push an element onto the stack
void push(Node** top, void* data, size_t data_size) {
    // Allocate memory for the new node
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (!newNode) {
        return;
    }

    // Allocate memory for the data and copy the data to the new node
    newNode->data = malloc(data_size);
    memcpy(newNode->data, data, data_size);

    // Link the new node to the stack
    newNode->next = *top;
    *top = newNode;
}

// Pop an element from the stack
void pop(Node** top, void* data, size_t data_size) {
    if (*top == NULL) {
        return;
    }

    // Copy the top data to the given memory location
    memcpy(data, (*top)->data, data_size);

    // Remove the top node and free its memory
    Node* temp = *top;
    *top = (*top)->next;
    free(temp->data);
    free(temp);
}

// Check if the stack is empty
int isEmpty(Node* top) {
    return top == NULL;
}

// Peek the top element of the stack (without popping)
void peek(Node* top, void* data, size_t data_size) {
    if (top == NULL) {
        return;
    }

    memcpy(data, top->data, data_size);
}

// Function to disable buffered input (no Enter needed)
void disableBufferedInput() {
    struct termios t;
    tcgetattr(STDIN_FILENO, &t);        // Get current terminal settings
    t.c_lflag &= ~ICANON;               // Disable canonical mode (unbuffered input)
    t.c_lflag &= ~ECHO;                 // Disable echo
    tcsetattr(STDIN_FILENO, TCSANOW, &t); // Apply settings immediately
}

// Function to enable buffered input back
void enableBufferedInput() {
    struct termios t;
    tcgetattr(STDIN_FILENO, &t);        // Get terminal settings
    t.c_lflag |= ICANON;                // Enable canonical mode
    t.c_lflag |= ECHO;                  // Enable echo
    tcsetattr(STDIN_FILENO, TCSANOW, &t); // Apply settings immediately
}

void clearTerminal()
{
    system("clear");
}

int main() {
    disableBufferedInput();

    Node* undoStack = NULL;

    const char controlsText[] = "Type what you like! Pressing [Enter] will exit the program.\n\nControls:\n<:\tundo\n>:\tredo (Note: resume type after undo will not allow you to redo and there is no backspace)\n\n";
    int index = 0;
    char fullText[10000] = "";

    char ch;
    clearTerminal();
    printf("%s", controlsText);
    while ((ch = getchar()) != '\n') {
        clearTerminal();
        if (ch == '<') { // undo character
            char undoCh = fullText[index - 1];
            fullText[index - 1] = '\0';
            index--;
            push(&undoStack, &undoCh, sizeof(char));
        } else if (ch == '>') { // redo character
            if (!isEmpty(undoStack)) {
                char redoCh;
                pop(&undoStack, &redoCh, sizeof(char));
                fullText[index] = redoCh;
                index += 1;
            }
        } else {
            while (!isEmpty(undoStack)) {
                char ignore;
                pop(&undoStack, &ignore, sizeof(char));
            }
            fullText[index++] = ch;
            fullText[index] = '\0';
        }
        printf("%s", controlsText);
        printf("%s\n", fullText);
    }

    enableBufferedInput();

    return 0;
}

void example()
{
    Node* stack = NULL;

    // Example 1: Push integers onto the stack
    int num1 = 10, num2 = 20, num3 = 30;
    push(&stack, &num1, sizeof(int));
    push(&stack, &num2, sizeof(int));
    push(&stack, &num3, sizeof(int));

    int poppedValue;
    pop(&stack, &poppedValue, sizeof(int));
    printf("Popped node: %d\n", poppedValue);

    // Example 2: Push a string onto the stack
    char str1[] = "Hello";
    char str2[] = "World";
    push(&stack, str1, strlen(str1) + 1);  // Note: +1 for the null terminator
    push(&stack, str2, strlen(str2) + 1);

    char poppedStr[100];
    pop(&stack, poppedStr, strlen(str2) + 1);
    printf("Popped node: %s\n", poppedStr);

    // Example 3: Push chars onto the stack
    char char1 = 'a', char2 = 'b', char3 = 'c';
    push(&stack, &char1, sizeof(char));
    push(&stack, &char2, sizeof(char));
    push(&stack, &char3, sizeof(char));

    char poppedChar;
    pop(&stack, &poppedChar, sizeof(char));
    printf("Popped node: %c\n", poppedChar);
}