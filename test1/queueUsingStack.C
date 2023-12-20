typedef struct {
    int data;
    struct Node* next;
} Node;

typedef struct {
    Node* top;
} Stack;

Stack* create() {
    Stack* st = (Stack*)malloc(sizeof(Stack));
    st -> top = NULL;
    return st;
}

void push(Stack* obj, int x) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode -> data = x;
    newNode -> next = obj -> top;
    obj -> top = newNode;
}

bool isEmpty(Stack* obj) {
    return obj -> top == NULL;
}

void pop(Stack* obj) {
    if (isEmpty(obj)) return;
    else {
        Node* temp = obj -> top;
        obj -> top = obj -> top -> next;
        free(temp);
        return ;
    }
}

int top(Stack* obj) {
    return obj -> top -> data;
}

typedef struct {
    Stack* inp;
    Stack* out;
} MyQueue;


MyQueue* myQueueCreate() {
    MyQueue* q = (MyQueue*)malloc(sizeof(MyQueue));
    q -> inp = create();
    q -> out = create();
    return q;
}

void myQueuePush(MyQueue* obj, int x) {
    push(obj -> inp, x);
}

int myQueuePop(MyQueue* obj) {
    if (!isEmpty(obj -> out)) {
        int ele = top(obj -> out);
        pop(obj -> out);
        return ele;
    }
    else {
        while (!isEmpty(obj -> inp)) {
            push(obj -> out, top(obj -> inp));
            pop(obj -> inp);
        }
        int ele = top(obj -> out);
        pop(obj -> out);
        return ele;
    }
}

int myQueuePeek(MyQueue* obj) {
    if (!isEmpty(obj -> out)) {
        int ele = top(obj -> out);
        return ele;
    }
    else {
        while (!isEmpty(obj -> inp)) {
            push(obj -> out, top(obj -> inp));
            pop(obj -> inp);
        }
        return top(obj -> out);
    }
}

bool myQueueEmpty(MyQueue* obj) {
    return isEmpty(obj -> inp) && isEmpty(obj -> out);
}

void myQueueFree(MyQueue* obj) {
    free(obj);
}

/**
 * Your MyQueue struct will be instantiated and called as such:
 * MyQueue* obj = myQueueCreate();
 * myQueuePush(obj, x);
 
 * int param_2 = myQueuePop(obj);
 
 * int param_3 = myQueuePeek(obj);
 
 * bool param_4 = myQueueEmpty(obj);
 
 * myQueueFree(obj);
*/
