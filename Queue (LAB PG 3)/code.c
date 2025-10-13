#include <stdio.h>
#include <stdlib.h>

#define SIZE 5

int queue[SIZE];
int front = -1, rear = -1;


void enqueue() {
int value;
if (rear == SIZE - 1){
printf("\nQueue is FULL! Cannot insert more elements.\n");
} else {
printf("Enter the value to enqueue: ");
scanf("%d", &value);
if (front == -1) {
front = 0;
}
rear++;
queue[rear] = value;
printf("%d inserted into the queue.\n", value);
}
}

void dequeue() {
if (front == -1 || front > rear) {
printf("\nQueue is EMPTY! Nothing to dequeue.\n");
} else {
printf("%d removed from the queue.\n", queue[front]);
front++;
if (front > rear) {
front = rear = -1;
}
}
}

void peek() {
if (front == -1 || front > rear) {
printf("\nQueue is EMPTY! Nothing to peek.\n");
} else {
printf("\nFront element is: %d\n", queue[front]);
}
}


void display() {
if (front == -1 || front > rear) {
printf("\nQueue is EMPTY!\n");
} else {
printf("\nQueue elements are: ");
for (int i = front; i <= rear; i++) {
printf("%d ", queue[i]);
}
printf("\n");
}
}


int main() {
int choice;
while (1) {
printf("\nQUEUE OPERATIONS MENU\n");
printf("1. Enqueue (Insert)\n");
printf("2. Dequeue (Remove)\n");
printf("3. Peek (Front Element)\n");
printf("4. Display Queue\n");
printf("5. Exit\n");
printf("Enter your choice: ");
scanf("%d", &choice);

switch (choice) {
case 1:
enqueue();
break;
case 2:
dequeue();
break;
case 3:
peek();
break;
case 4:
display();
break;
case 5:
printf("\nExiting program... Goodbye!\n");
exit(0);
default:
printf("\nInvalid choice! Please try again.\n");
}
}
return 0;
}
