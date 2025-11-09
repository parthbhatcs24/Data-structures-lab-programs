#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next;
} Node;

// Create a new node
Node *createNode(int data)
{
    Node *newNode = malloc(sizeof(Node));
    if (newNode == NULL)
    {
        printf("Error: Memory allocation failed!\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Insert at first
Node *insertAtFirst(Node *head, int data)
{
    Node *newNode = createNode(data);
    newNode->next = head;
    return newNode;
}

// Insert at end
Node *insertAtEnd(Node *head, int data)
{
    Node *newNode = createNode(data);
    if (head == NULL)
        return newNode;

    Node *temp = head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
    return head;
}

// Insert at any position
Node *insertAtPos(Node *head, int data, int pos)
{
    if (pos < 1)
    {
        printf("Invalid position. Must be 1 or greater.\n");
        return head;
    }

    if (pos == 1)
        return insertAtFirst(head, data);

    Node *newNode = createNode(data);
    Node *temp = head;

    for (int i = 1; i < pos - 1; i++)
    {
        if (temp == NULL)
        {
            printf("Invalid position. Position %d is out of bounds.\n", pos);
            free(newNode);
            return head;
        }
        temp = temp->next;
    }

    if (temp == NULL)
    {
        printf("Invalid position. Position %d is out of bounds.\n", pos);
        free(newNode);
        return head;
    }

    newNode->next = temp->next;
    temp->next = newNode;
    return head;
}

// Display the list
void display(Node *head)
{
    if (head == NULL)
    {
        printf("List is empty.\n");
        return;
    }

    Node *temp = head;
    printf("List contents: ");
    while (temp != NULL)
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Free all nodes
void freeList(Node *head)
{
    Node *temp;
    while (head != NULL)
    {
        temp = head;
        head = head->next;
        free(temp);
    }
}

// Main menu
int main()
{
    Node *head = NULL;
    int choice, data, pos;

    while (1)
    {
        printf("\n--- Singly Linked List Menu ---\n");
        printf("1. Insert at First\n");
        printf("2. Insert at End\n");
        printf("3. Insert at Any Position\n");
        printf("4. Display List\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter data to insert at first: ");
            scanf("%d", &data);
            head = insertAtFirst(head, data);
            display(head);
            break;

        case 2:
            printf("Enter data to insert at end: ");
            scanf("%d", &data);
            head = insertAtEnd(head, data);
            display(head);
            break;

        case 3:
            printf("Enter data: ");
            scanf("%d", &data);
            printf("Enter position (1-based): ");
            scanf("%d", &pos);
            head = insertAtPos(head, data, pos);
            display(head);
            break;

        case 4:
            display(head);
            break;

        case 5:
            printf("Exiting... Freeing all memory.\n");
            freeList(head);
            exit(0);

        default:
            printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
