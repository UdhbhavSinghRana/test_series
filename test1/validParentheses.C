#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Node {
    char data;
    struct Node* next;
} Node;

typedef struct {
    Node* top;
} Stack;

void initializeStack(Stack* stack) {
    stack->top = NULL;
}

bool isEmpty(Stack* stack) {
    return stack->top == NULL;
}

void push(Stack* stack, char val) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode != NULL) {
        newNode->data = val;
        newNode->next = stack->top;
        stack->top = newNode;
    }
}

void pop(Stack* stack) {
    if (isEmpty(stack)) return;
    else {
        Node* temp = stack->top;
        stack->top = stack->top->next;
        free(temp); // Free the memory of the popped node
    }
}

char peek(Stack* stack) {
    if (isEmpty(stack)) return '\0'; // Return special char for empty stack
    else {
        return stack->top->data;
    }
}

bool isValid(char* s) {
    Stack* stack = (Stack*)malloc(sizeof(Stack)); // Allocate memory for the stack
    if (stack == NULL) return false; // Check for memory allocation failure
    initializeStack(stack);

    while (*s != '\0') {
        if (*s == '(' || *s == '{' || *s == '[') push(stack, *s);
        else {
            if (*s == ')' && peek(stack) == '(') pop(stack);
            else if (*s == '}' && peek(stack) == '{') pop(stack);
            else if (*s == ']' && peek(stack) == '[') pop(stack);
            else {
                free(stack); // Free the allocated memory in case of mismatch
                return false;
            }
        }
        s++; // Move to the next character in the string
    }

    bool valid = isEmpty(stack);
    free(stack); // Free the allocated memory
    return valid;
}

int main() {
    char* testString = "{[()]}";
    if (isValid(testString)) {
        printf("The string is valid!\n");
    } else {
        printf("The string is not valid!\n");
    }
    return 0;
}

