// A complete working C program to demonstrate all insertion methods
// on Linked List
#include <stdio.h>
#include <stdlib.h>

struct Node
{
char data;
struct Node *next;
};

void push(struct Node** head_ref, char new_data)
{
	
	struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));


	new_node->data = new_data;

	new_node->next = (*head_ref);

	(*head_ref) = new_node;
}

void insertAfter(struct Node* prev_node, char new_data)
{
	
	if (prev_node == NULL)
	{
	printf("the given previous node cannot be NULL");
	return;
	}

	struct Node* new_node =(struct Node*) malloc(sizeof(struct Node));

	new_node->data = new_data;


	new_node->next = prev_node->next;


	prev_node->next = new_node;
}

void append(struct Node** head_ref, char new_data)
{
	struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));

	struct Node *last = *head_ref; 

	new_node->data = new_data;

	new_node->next = NULL;

	if (*head_ref == NULL)
	{
	*head_ref = new_node;
	return;
	}

	while (last->next != NULL)
		last = last->next;

	
	last->next = new_node;
	return;
}
void printList(struct Node *node)
{
while (node != NULL)
{
	printf(" %c ", node->data);
	node = node->next;
}
}


int main()
{

struct Node* head = NULL;
append(&head, 'E');
push(&head, 'A');
push(&head, 'H');
insertAfter(head->next, 'F');
append(&head, 'Z');


printf("\n Created Linked list is: ");
printList(head);

return 0;
}
