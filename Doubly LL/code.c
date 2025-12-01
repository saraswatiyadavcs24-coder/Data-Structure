#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *prev, *next;
};


struct Node *head = NULL;
struct Node *tail = NULL;


void createList(int n) {
    int i, data;
    struct Node *newNode;

    for (i = 1; i <= n; i++) {
        printf("Enter data for node %d: ", i);
        scanf("%d", &data);

        newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->data = data;
        newNode->prev = newNode->next = NULL;

        if (head == NULL) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }
}


void insertAtFront(int data) {
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = head;

    if (head == NULL)
        head = tail = newNode;
    else {
        head->prev = newNode;
        head = newNode;
    }
}


void insertAtEnd(int data) {
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = tail;

    if (tail == NULL)
        head = tail = newNode;
    else {
        tail->next = newNode;
        tail = newNode;
    }
}


void insertAtPosition(int data, int pos) {
    int i;
    struct Node *newNode, *temp = head;

    if (pos == 1) {
        insertAtFront(data);
        return;
    }

    newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;

    for (i = 1; i < pos - 1 && temp != NULL; i++)
        temp = temp->next;

    if (temp == NULL || temp->next == NULL) {
        insertAtEnd(data);
        return;
    }

    newNode->next = temp->next;
    newNode->prev = temp;
    temp->next->prev = newNode;
    temp->next = newNode;
}


void deleteAtFront() {
    struct Node *temp;

    if (head == NULL) {
        printf("List is empty!\n");
        return;
    }

    temp = head;
    head = head->next;

    if (head != NULL)
        head->prev = NULL;
    else
        tail = NULL;

    free(temp);
}


void deleteAtEnd() {
    struct Node *temp;

    if (tail == NULL) {
        printf("List is empty!\n");
        return;
    }

    temp = tail;
    tail = tail->prev;

    if (tail != NULL)
        tail->next = NULL;
    else
        head = NULL;

    free(temp);
}


void deleteByValue(int value) {
    struct Node *temp = head;

    if (head == NULL) {
        printf("List is empty!\n");
        return;
    }

    while (temp != NULL && temp->data != value)
        temp = temp->next;

    if (temp == NULL) {
        printf("Value not found!\n");
        return;
    }

    if (temp == head)
        deleteAtFront();
    else if (temp == tail)
        deleteAtEnd();
    else {
        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;
        free(temp);
    }
}


void search(int value) {
    struct Node *temp = head;
    int pos = 1;

    while (temp != NULL) {
        if (temp->data == value) {
            printf("Value %d found at position %d\n", value, pos);
            return;
        }
        temp = temp->next;
        pos++;
    }

    printf("Value %d not found in the list.\n", value);
}


void displayForward() {
    struct Node *temp = head;
    printf("List (Forward): ");

    while (temp != NULL) {
        printf("%d <-> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}


void displayBackward() {
    struct Node *temp = tail;
    printf("List (Backward): ");

    while (temp != NULL) {
        printf("%d <-> ", temp->data);
        temp = temp->prev;
    }
    printf("NULL\n");
}


int main() {
    int n;

    printf("Enter number of nodes to create: ");
    scanf("%d", &n);
    createList(n);

    displayForward();
    displayBackward();

    insertAtFront(10);
    insertAtEnd(99);
    insertAtPosition(77, 3);

    displayForward();

    deleteAtFront();
    deleteAtEnd();
    deleteByValue(77);

    displayForward();

    search(99);

    return 0;
}
