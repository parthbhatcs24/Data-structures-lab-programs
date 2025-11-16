#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next;
} Node;

// Global heads
Node *head1 = NULL;
Node *head2 = NULL;

// Create a new node
Node *createNode(int value)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

// Insert at end (pass by value)
Node *insertEnd(Node *head, int value)
{
    Node *newNode = createNode(value);

    if (head == NULL)
        return newNode;

    Node *temp = head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
    return head;
}

// Display list (pass by value)
void display(Node *head)
{
    if (head == NULL)
    {
        printf("List is empty\n");
        return;
    }

    Node *temp = head;
    while (temp != NULL)
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Sort linked list (pass by value)
Node *sortList(Node *head)
{
    if (head == NULL)
        return head;

    Node *i, *j;
    int temp;

    for (i = head; i->next != NULL; i = i->next)
    {
        for (j = i->next; j != NULL; j = j->next)
        {
            if (i->data > j->data)
            {
                temp = i->data;
                i->data = j->data;
                j->data = temp;
            }
        }
    }

    return head;
}

// Reverse linked list (pass by value)
Node *reverseList(Node *head)
{
    Node *prev = NULL, *curr = head, *next = NULL;

    while (curr != NULL)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }

    return prev; // new head
}

// Concatenate two lists (pass by value)
Node *concatenate(Node *h1, Node *h2)
{
    if (h1 == NULL)
        return h2;
    if (h2 == NULL)
        return h1;

    Node *temp = h1;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = h2;
    return h1;
}

// MAIN
int main()
{
    int choice, value;

    while (1)
    {
        printf("\n----- MENU -----\n");
        printf("1. Insert into List 1\n");
        printf("2. Insert into List 2\n");
        printf("3. Sort List 1\n");
        printf("4. Reverse List 1\n");
        printf("5. Concatenate List1 & List2\n");
        printf("6. Display List 1\n");
        printf("7. Display List 2\n");
        printf("8. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter value: ");
            scanf("%d", &value);
            head1 = insertEnd(head1, value);
            break;

        case 2:
            printf("Enter value: ");
            scanf("%d", &value);
            head2 = insertEnd(head2, value);
            break;

        case 3:
            head1 = sortList(head1);
            printf("List 1 Sorted!\n");
            break;

        case 4:
            head1 = reverseList(head1);
            printf("List 1 Reversed!\n");
            break;

        case 5:
            head1 = concatenate(head1, head2);
            printf("Lists concatenated!\n");
            break;

        case 6:
            display(head1);
            break;

        case 7:
            display(head2);
            break;

        case 8:
            exit(0);

        default:
            printf("Invalid choice!\n");
        }
    }

    return 0;
}