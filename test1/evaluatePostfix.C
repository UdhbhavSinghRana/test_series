#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

typedef struct {
    Node* top;
} Stack;

Stack* create() {
    Stack* newStack = (Stack*)malloc(sizeof(Stack));
    newStack->top = NULL;
    return newStack;
}

void push(Stack* obj, int x) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = x;
    newNode->next = obj->top;
    obj->top = newNode;
}

bool isEmpty(Stack* obj) {
    return obj->top == NULL;
}

int pop(Stack* obj) {
    if (isEmpty(obj)) {
        return -1;
    } else {
        Node* temp = obj->top;
        int ans = temp->data;
        obj->top = obj->top->next;
        free(temp);
        return ans;
    }
}

int evaluatePostfix(char* str) {
    Stack* newStack = create();
    int i = 0;

    while (str[i] != '\0') {
        if (str[i] >= '0' && str[i] <= '9') {
            int num = 0;
            while (str[i] >= '0' && str[i] <= '9') {
                num = num * 10 + (str[i] - '0');
                i++;
            }
            push(newStack, num);
        } else if (str[i] == '+' || str[i] == '-' || str[i] == '*' || str[i] == '/') {
            int num1 = pop(newStack);
            int num2 = pop(newStack);
            int res = 0;
            switch (str[i]) {
                case '+':
                    res = num2 + num1;
                    break;
                case '-':
                    res = num2 - num1;
                    break;
                case '*':
                    res = num2 * num1;
                    break;
                case '/':
                    res = num2 / num1;
                    break;
            }
            push(newStack, res);
            i++;
        } else {
            i++;
        }
    }

    return pop(newStack);
}

int main() {
    int n;
    scanf("%d", &n);
    getchar();
    for(int i=0;i<n;i++){
        char str[200];
        fgets(str,sizeof(str),stdin);

        int result = evaluatePostfix(str);
        printf("%d\n", result);
    }
    return 0;
}
