#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node* next;
};

struct Node* head = NULL;

void create(int n)
{
    struct Node *newNode, *temp;
    int data, i;
    if (n <= 0) return;
    for (i = 0; i < n; i++)
    {
        newNode = (struct Node*)malloc(sizeof(struct Node));
        scanf("%d", &data);
        newNode->data = data;
        newNode->next = NULL;
        if (head == NULL)
            head = newNode;
        else
        {
            temp = head;
            while (temp->next != NULL)
                temp = temp->next;
            temp->next = newNode;
        }
    }
}

void insertAtBeginning(int data)
{
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = head;
    head = newNode;
}

void insertAtEnd(int data)
{
    struct Node *newNode, *temp;
    newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    if (head == NULL)
        head = newNode;
    else
    {
        temp = head;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = newNode;
    }
}

void insertAtPosition(int data, int pos)
{
    int i;
    struct Node *newNode, *temp;
    newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    if (pos == 1)
    {
        newNode->next = head;
        head = newNode;
        return;
    }
    temp = head;
    for (i = 1; i < pos - 1 && temp != NULL; i++)
        temp = temp->next;
    if (temp == NULL) return;
    newNode->next = temp->next;
    temp->next = newNode;
}

void display()
{
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    int n, choice, data, pos;
    printf("Enter number of initial nodes to create: ");
    scanf("%d", &n);
    printf("Enter %d elements: ", n);
    create(n);
    printf("\nLinked List Menu\n1. Insert at Beginning\n2. Insert at End\n3. Insert at Position\n4. Display\n5. Exit\n");

    while (1) {
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter data: ");
                scanf("%d", &data);
                insertAtBeginning(data);
                break;
            case 2:
                printf("Enter data: ");
                scanf("%d", &data);
                insertAtEnd(data);
                break;
            case 3:
                printf("Enter data: ");
                scanf("%d", &data);
                printf("\nEnter pos");
                scanf("%d",&pos);
                insertAtPosition(data, pos);
                break;
            case 4:
                printf("Linked List: ");
                display();
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}
