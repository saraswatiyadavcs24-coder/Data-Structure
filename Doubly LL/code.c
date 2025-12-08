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
printf("Enter data for node %d : ", i);
scanf("%d", &data);

newNode = (struct Node*) malloc(sizeof(struct Node));
newNode->data = data;
newNode->prev = NULL;
newNode->next = NULL;

if (head == NULL) {
head = tail = newNode;
}
else {
tail->next = newNode;
newNode->prev = tail;
tail = newNode;
}
}
}

void insertAtFront(int data) {
struct Node *newNode = (struct Node*) malloc(sizeof(struct Node));

newNode->data = data;
newNode->prev = NULL;
newNode->next = head;

if (head != NULL) {
head->prev = newNode;
}
else {
tail = newNode;
}
head = newNode;
}

/* Insert to the LEFT of given value */
void insertLeft(int key, int data) {
struct Node *temp = head;
struct Node *newNode;

while (temp != NULL && temp->data != key) {
temp = temp->next;
}

if (temp == NULL) {
printf("Node not found.\n");
return;
}

newNode = (struct Node*) malloc(sizeof(struct Node));
newNode->data = data;

newNode->next = temp;
newNode->prev = temp->prev;

if (temp->prev != NULL)
temp->prev->next = newNode;
else
head = newNode;

temp->prev = newNode;
}

/* Delete by value */
void deleteValue(int key) {
struct Node *temp = head;

while (temp != NULL && temp->data != key) {
temp = temp->next;
}

if (temp == NULL) {
printf("Value not found.\n");
return;
}

if (temp->prev != NULL)
temp->prev->next = temp->next;
else
head = temp->next;

if (temp->next != NULL)
temp->next->prev = temp->prev;
else
tail = temp->prev;

free(temp);
}

/* Display */
void display() {
struct Node *temp = head;

printf("\nList : ");
while (temp != NULL) {
printf("%d ", temp->data);
temp = temp->next;
}
printf("\n");
}

int main() {
int n, ch, data, key;

printf("Enter number of nodes : ");
scanf("%d", &n);

createList(n);
display();

while (1) {
printf("\n1. Insert Left\n");
printf("2. Delete\n");
printf("3. Display\n");
printf("4. Exit\n");
printf("Enter choice : ");
scanf("%d", &ch);

switch (ch) {
case 1:
printf("Enter existing value : ");
scanf("%d", &key);
printf("Enter data : ");
scanf("%d", &data);
insertLeft(key, data);
break;

case 2:
printf("Enter value to delete : ");
scanf("%d", &key);
deleteValue(key);
break;

case 3:
display();
break;

case 4:
exit(0);
}
}

return 0;
}
