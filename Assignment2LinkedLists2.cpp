#include<stdio.h>
#include<stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

void insertStart(struct Node** head, int data);
void display(struct Node* node);

int main()
{
    struct Node* head = NULL;
    struct Node* node2 = NULL;
    struct Node* last = NULL;



    head = (struct Node*)malloc(sizeof(struct Node));
    node2 = (struct Node*)malloc(sizeof(struct Node));
    last = (struct Node*)malloc(sizeof(struct Node));

    printf("Please enter the data of node 1: ", head->data);
    scanf_s("%d", &head->data);
    printf("Please enter the data of node 2: ", head->data);
    scanf_s("%d", &node2->data);
    printf("Please enter the data of node 3: ", head->data);
    scanf_s("%d", &last->data);



    head->next = node2;
    node2->next = last;
    last->next = NULL;


    display(head);

    insertStart(&head, 4);

    printf("\nAfter Inserting\n\n");


    display(head);

    return 0;
}

void insertStart(struct Node** head, int data)
{

    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));

    newNode->data = data;
    newNode->next = *head;

    *head = newNode;
}

void display(struct Node* node) {


    while (node != NULL) {
        printf("%d  ", node->data);
        node = node->next;
    }
    printf("\n");
}
