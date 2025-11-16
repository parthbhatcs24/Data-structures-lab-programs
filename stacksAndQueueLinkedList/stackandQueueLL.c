#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
} Node;

Node *stackTop = NULL;
Node *queueFront = NULL;
Node *queueRear = NULL;

Node* createNode(int value) {
    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}


void push(int value) {
    Node *newNode = createNode(value);
    newNode->next = stackTop;
    stackTop = newNode;
}

void pop() {
    if (stackTop == NULL) {
        printf("Stack Underflow!\n");
        return;
    }

    Node *temp = stackTop;
    printf("Popped: %d\n", temp->data);
    stackTop = stackTop->next;
    free(temp);
}

void displayStack() {
    if (stackTop == NULL) {
        printf("Stack is empty\n");
        return;
    }

    Node *temp = stackTop;
    printf("Stack (Top->Bottom): ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}


void enqueue(int value) {
    Node *newNode = createNode(value);

    if (queueRear == NULL) {
        queueFront = queueRear = newNode;
        return;
    }

    queueRear->next = newNode;
    queueRear = newNode;
}

void dequeue() {
    if (queueFront == NULL) {
        printf("Queue Underflow!\n");
        return;
    }

    Node *temp = queueFront;
    printf("Dequeued: %d\n", temp->data);

    queueFront = queueFront->next;
    if (queueFront == NULL)
        queueRear = NULL;

    free(temp);
}

void displayQueue() {
    if (queueFront == NULL) {
        printf("Queue is empty\n");
        return;
    }

    Node *temp = queueFront;
    printf("Queue (Front->Rear): ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}


int main() {
    int choice, value;

    while (1) {
        printf("\n----- MENU -----\n");
        printf("1. Push (Stack)\n");
        printf("2. Pop (Stack)\n");
        printf("3. Display Stack\n");
        printf("4. Enqueue (Queue)\n");
        printf("5. Dequeue (Queue)\n");
        printf("6. Display Queue\n");
        printf("7. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value: ");
                scanf("%d", &value);
                push(value);
                break;

            case 2:
                pop();
                break;

            case 3:
                displayStack();
                break;

            case 4:
                printf("Enter value: ");
                scanf("%d", &value);
                enqueue(value);
                break;

            case 5:
                dequeue();
                break;

            case 6:
                displayQueue();
                break;

            case 7:
                exit(0);

            default:
                printf("Invalid choice!\n");
        }
    }
}