#include<stdio.h>
#include <stdlib.h>
#define SIZE 2

int queue[SIZE];
int front = -1, rear = -1;

void insert(int val){

    if((front == 0 && rear == SIZE-1) || (rear+1)%SIZE ==front) {
        printf("Queue overflow!\n");
        return;
    }
    if(front == -1) {
        front = rear = 0;
    } else {
        rear = (rear+1)%SIZE;
    }
    queue[rear] = val;
    printf("Inserted\n");
}

void delete() {
    if(front == -1 || front > rear) {
        printf("Queue underflow\n");
        return;
    }
    printf("%d deleted from the queue\n",queue[front]);
    if(front == rear) {
        front = rear = -1;
    } else {
        front = (front+1) % SIZE;
    }
}

void display() {
    if(front == -1) {
        printf("Circular queue is empty \n");
        return;
    }
    printf("Circular queue elements are: ");
    int i;
    for(i - front; i != rear; i= (i+1) % SIZE) {
        printf("%d ", queue[i]);
    }
    printf("%d\n",queue[rear]);
}

int main() {
    int choose,val;
    while(1) {
        printf("1. Insert\n2.Delete\n3.Display\n4.Exit\n");
        printf("Enter the choice: ");
        scanf("%d", &choose);
        
        switch(choose) {
            case 1:
                printf("Enter the value: ");
                scanf("%d",&val); 
                insert(val);
                break;
            case 2 : delete();
                    break;

            case 3 : display();
                    break;

            case 4 : exit(0);

            default: printf("Invalid choice try again\n");
        }
    }
    return 0;
}