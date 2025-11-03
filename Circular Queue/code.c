#include <stdio.h>
#define SIZE 5

int queue[SIZE];
int front = -1, rear = -1;

void enqueue(int value)
{
    if ((rear + 1) % SIZE == front) {
        printf("\nQueue Overflow");
        return;
    }
    if (front == -1) {
        front = rear = 0;
    } else {
        rear = (rear + 1) % SIZE;
    }
    queue[rear] = value;
    printf("\nValue of %d inserted in the queue.", value);
}

int dequeue()
{
    if (front == -1) {
        printf("\nQueue is empty, Underflow");
        return -1;
    }

    int item = queue[front];
    if (front == rear) {
        front = rear = -1;
    } else {
        front = (front + 1) % SIZE;
    }

    printf("\nValue of %d deleted from the queue.", item);
    return item;
}

void display()
{
    if (front == -1) {
        printf("\nQueue is empty.");
        return;
    }

    printf("\nQueue items are: ");
    int i = front;
    while (i != rear) {
        printf("%d, ", queue[i]);
        i = (i + 1) % SIZE;
    }
    printf("%d\n", queue[rear]);
}

int main()
{
    int choice, value;
    printf("\nOptions Available:\n");
    printf("1. EnQueue\n2. DeQueue\n3. Display\n4. Exit\n");

    while (1) {
        printf("\n---------------\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &value);
                enqueue(value);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                display();
                break;
            case 4:
                printf("Exiting program.\n");
                return 0;
            default:
                printf("Invalid choice\n");
        }
    }
}
