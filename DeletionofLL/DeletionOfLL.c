#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node *createNode(int data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

struct Node *createList(struct Node *head)
{
    int n, data;
    printf("Enter number of nodes: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        printf("Enter data for node %d: ", i + 1);
        scanf("%d", &data);

        struct Node *newNode = createNode(data);
        if (head == NULL)
        {
            head = newNode;
        }
        else
        {
            struct Node *temp = head;
            while (temp->next != NULL)
                temp = temp->next;
            temp->next = newNode;
        }
    }
    return head;
}

struct Node *deleteFirst(struct Node *head)
{
    if (head == NULL)
    {
        printf("List is empty.\n");
        return head;
    }

    struct Node *temp = head;
    head = head->next;
    printf("Deleted first element: %d\n", temp->data);
    free(temp);

    return head; // return new head
}

struct Node *deleteLast(struct Node *head)
{
    if (head == NULL)
    {
        printf("List is empty.\n");
        return head;
    }

    if (head->next == NULL)
    {
        printf("Deleted last element: %d\n", head->data);
        free(head);
        return NULL;
    }

    struct Node *temp = head;
    while (temp->next->next != NULL)
        temp = temp->next;

    printf("Deleted last element: %d\n", temp->next->data);
    free(temp->next);
    temp->next = NULL;

    return head;
}

struct Node *deleteSpecific(struct Node *head, int value)
{
    if (head == NULL)
    {
        printf("List is empty.\n");
        return head;
    }

    struct Node *temp = head;
    struct Node *prev = NULL;

    if (head->data == value)
    {
        head = head->next;
        printf("Deleted element: %d\n", temp->data);
        free(temp);
        return head;
    }

    while (temp != NULL && temp->data != value)
    {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL)
    {
        printf("Element %d not found.\n", value);
        return head;
    }

    prev->next = temp->next;
    printf("Deleted element: %d\n", temp->data);
    free(temp);

    return head;
}

void displayList(struct Node *head)
{
    if (head == NULL)
    {
        printf("List is empty.\n");
        return;
    }

    struct Node *temp = head;
    printf("Linked List: ");
    while (temp != NULL)
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main()
{
    struct Node *head = NULL;
    int choice, value;

    while (1)
    {
        printf("\n--- Singly Linked List Menu ---\n");
        printf("1. Create Linked List\n");
        printf("2. Delete First Element\n");
        printf("3. Delete Specific Element\n");
        printf("4. Delete Last Element\n");
        printf("5. Display List\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            head = createList(head);
            break;
        case 2:
            head = deleteFirst(head);
            break;
        case 3:
            printf("Enter element to delete: ");
            scanf("%d", &value);
            head = deleteSpecific(head, value);
            break;
        case 4:
            head = deleteLast(head);
            break;
        case 5:
            displayList(head);
            break;
        case 6:
            exit(0);
        default:
            printf("Invalid choice! Try again.\n");
        }
    }
    return 0;
}