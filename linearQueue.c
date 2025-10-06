#include <stdio.h>
#define SIZE 2

int queue[SIZE];
int front = -1, rear = -1;

void insert() {
    int value;
    if(rear == SIZE-1) {
        printf("\nQueue Overflow\n");
        return;
    }
    printf("Enter the value to insert ");
    scanf("%d", &value);
    if(front == -1) {
        front = 0;
    }

    queue[++rear] = value;
    printf("Inserted\n");
}

void delete() {
    if(front == -1 || front > rear) {
        printf("\n Queue underflow\n");
        return;
    }
    printf("Deleted element is %d\n",queue[front++]);
    if(front > rear) {
        front = rear = -1;
    }
}

void display() {
    if(front == -1){
        printf("Queue is empty\n");
    } else {
        printf("\n Elements are :");
        for(int i =  front ; i <= rear; i++) {
            printf("%d ", queue[i]);
        }
        printf("\n");
    }
}

int main() {
    int choose;
    while(1) {
        printf("1. Insert\n2.Delete\n3.Display\n4.Exit\n");
        printf("Enter the value: ");
        scanf("%d", &choose);
        
        switch(choose) {
            case 1: insert();
                    break;
            case 2 : delete();
                    break;

            case 3 : display();
                    break;

            case 4 : return 0;

            default: printf("Invalid choice try again\n");
        }
    }
    return 0;
}