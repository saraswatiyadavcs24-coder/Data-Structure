#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node* create(int n) {
    struct node *head = NULL, *p, *q = NULL;
    for (int i = 0; i < n; i++) {
        p = malloc(sizeof(struct node));
        scanf("%d", &p->data);
        p->next = NULL;
        if (head == NULL)
            head = p;
        else
            q->next = p;
        q = p;
    }
    return head;
}

void display(struct node *head) {
    while (head) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

struct node* sort(struct node *head) {
    struct node *i, *j;
    int t;
    for (i = head; i != NULL; i = i->next) {
        for (j = i->next; j != NULL; j = j->next) {
            if (i->data > j->data) {
                t = i->data;
                i->data = j->data;
                j->data = t;
            }
        }
    }
    return head;
}

struct node* reverse(struct node *head) {
    struct node *prev = NULL, *curr = head, *next;
    while (curr) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}

struct node* concat(struct node *a, struct node *b) {
    if (a == NULL) return b;
    struct node *t = a;
    while (t->next)
        t = t->next;
    t->next = b;
    return a;
}

int main() {
    int n, m;

    printf("\nEnter size of list A: ");
    scanf("%d", &n);
    printf("\nEnter %d element(s) of list A:\n", n);
    struct node *A = create(n);

    printf("\nSorted List A: ");
    A = sort(A);
    display(A);

    printf("\nReversed List A: ");
    A = reverse(A);
    display(A);

    printf("\nEnter size of list B: ");
    scanf("%d", &m);
    printf("\nEnter %d elements of list B:\n", m);
    struct node *B = create(m);

    printf("\nList A+B: ");
    A = concat(A, B);
    display(A);

    return 0;
}
