#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node* next;
};

struct node* push(struct node* top, int x){
    struct node* p = malloc(sizeof(struct node));
    p->data = x;
    p->next = top;
    return p;
}

struct node* pop(struct node* top){
    if(top){
        printf("Popped %d\n",top->data);
        struct node* t = top;
        top = top->next;
        free(t);
    } else {
        printf("Stack is empty\n");
    }
    return top;
}

struct node* enqueue(struct node* rear, struct node** front, int x){
    struct node* p = malloc(sizeof(struct node));
    p->data = x;
    p->next = NULL;

    if(*front == NULL) *front = p;
    else rear->next = p;

    printf("Enqueued %d\n", x);
    return p;
}

struct node* dequeue(struct node* front){
    if(front){
        printf("Dequeued %d\n",front->data);
        struct node* t = front;
        front = front->next;

        free(t);
    } else {
        printf("Queue is empty\n");
    }
    return front;
}

void display(struct node* head){
    if(head == NULL){
        printf("Empty\n");
        return;
    }
    while(head){
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

int main(){
    struct node *top = NULL, *front = NULL, *rear = NULL;
    int c, x;

    printf("\nMENU\n");
    printf("1. Stack - Push\n");
    printf("2. Stack - Pop\n");
    printf("3. Queue - Enqueue\n");
    printf("4. Queue - Dequeue\n");
    printf("5. Stack - Display\n");
    printf("6. Queue - Display\n");
    printf("7. Exit\n");
    printf("\n");

    while(1){
        printf("\nEnter choice: ");
        scanf("%d", &c);

        switch(c){

            case 1:
                printf("Enter value to push: ");
                scanf("%d", &x);
                top = push(top, x);
                printf("Pushed %d\n", x);
                break;

            case 2:
                top = pop(top);
                break;

            case 3:
                printf("Enter value to enqueue: ");
                scanf("%d", &x);
                rear = enqueue(rear, &front, x);
                break;

            case 4:
                front = dequeue(front);
                if(front == NULL) rear = NULL;
                break;

            case 5:
                printf("Stack contents: ");
                display(top);
                break;

            case 6:
                printf("Queue contents: ");
                display(front);
                break;

            case 7:
                printf("Exiting program.\n");
                return 0;

            default:
                printf("Invalid choice. Try again.\n");
        }
    }
}
