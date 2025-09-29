#include <stdio.h>
#define N 5

int stack[N];
int top = -1;

void push() {
    int x;
    if (top == N - 1) {
        printf("Stack Overflow! Cannot push.\n");
    } else {
        printf("Enter data: ");
        scanf("%d", &x);
        stack[++top] = x;

        printf("%d pushed onto the stack.\n", x);
    }
}

void pop() {
    if (top == -1) {
        printf("Stack Underflow! Cannot pop.\n");
    } else {

        printf("%d popped from the stack.\n", stack[top--]);
    }
}

void display() {
    if (top == -1) {
        printf("Stack is empty!\n");
    } else {
        printf("Stack elements are:\n");
        for (int i = top; i >= 0; i--) {
            printf("%d\n", stack[i]);
        }
    }
}

int main() {
    int choice;
    while (1) {
        printf("\nStack Operations Menu:\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                push();
                break;
            case 2:
                pop();
                break;
            case 3:
                display();
                break;
            case 4:
                printf("Exiting the program.\n");
                return 0;
            default:
                printf("Invalid choice! Please try again.\n");
                break;
        }
    }
    return 0;
}
