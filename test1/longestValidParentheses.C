typedef struct Node {
    int data;
    struct Node* next;
} Node;

typedef struct {
    Node* top;
} Stack;

typedef struct charNode {
    char data;
    struct charNode* next;
} charNode;

typedef struct {
    charNode* top;
} charStack;

Stack* create() {
    Stack* st = (Stack*)malloc(sizeof(Stack));
    st->top = NULL;
    return st;
}

charStack* create2() {
    charStack* st = (charStack*)malloc(sizeof(charStack));
    st->top = NULL;
    return st;
}

void push(Stack* st, int x) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = x;
    newNode->next = st->top;
    st->top = newNode;
}

void push2(charStack* st, char x) {
    charNode* newNode = (charNode*)malloc(sizeof(charNode));
    newNode->data = x;
    newNode->next = st->top;
    st->top = newNode;
}

bool isEmpty(Stack* st) {
    return st->top == NULL;
}

bool isEmpty2(charStack* st) {
    return st->top == NULL;
}

int peek(Stack* st) {
    return st->top->data;
}

char peek2(charStack* st) {
    return st->top->data;
}

int pop(Stack* st) {
    if (isEmpty(st)) return -1;
    else {
        Node* temp = st->top;
        int ans = temp->data;
        st->top = temp->next;
        free(temp);
        return ans;
    }
}

char pop2(charStack* st) {
    if (isEmpty2(st)) return -1;
    else {
        charNode* temp = st->top;
        char ans = temp->data;
        st->top = temp->next;
        free(temp);
        return ans;
    }
}

int longestValidParentheses(char* s) {
    charStack* parenStack = create2();
    Stack* indexStack = create();

    push(indexStack, -1);
    int i = 0;
    int len = 0;

    while (s[i] != '\0') {
        if (s[i] == '(') {
            push2(parenStack, s[i]);
            push(indexStack, i);
        }
        else {
            if (!isEmpty2(parenStack) && peek2(parenStack) == '(') {
                pop(indexStack);
                pop2(parenStack);
                if (i - peek(indexStack) > len) len = i - peek(indexStack);
            }
            else {
                push(indexStack, i);
            }
        }
        i++;
    }

    return len;
}
