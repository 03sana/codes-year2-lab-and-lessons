#include <stdio.h>
#include <stdlib.h>


struct node
{
	int data;
	struct node* next;
};

void printList(struct node* head)
{
	if (head == NULL)
	{
		printf("The list is empty!");
	}

	while (head != NULL)
	{
		printf("%d ", head->data);
		head = head->next;
	}
}

void add_at_end(struct node** headRef, int newData)
{
	struct node* newNode = (struct node*)malloc(sizeof(struct node));

	struct node* last = *headRef;

	newNode->data = newData;
	newNode->next = NULL;

	if (*headRef == NULL)
	{
		*headRef = newNode;
		return;
	}

	while (last->next != NULL)
	{
		last = last->next;
	}

	last->next = newNode;

}

void insertAfter(struct node* head, int newData, int pos)
{
	if (head == NULL)
	{
		printf("The given previos node cannot be NULL!");
		return 0;
	}
	struct node* ptr = head;

	struct node* new_node = (struct node*)malloc(sizeof(struct node));
	new_node->data = newData;
	new_node->next = NULL;

	pos--;
	while (pos != 1)
	{
		ptr = ptr->next;
		pos--;
	}


	new_node->next = ptr->next;
ptr->next = new_node;

}

struct node* delFirst(struct node* head)
{
	if (head == NULL)
		printf("List is already empty!");
	else
	{
		struct node* temp = head;

		head = head->next;
		free(temp);
		temp = NULL;
	}

	return head;
}

struct node* del_last(struct node* head)
{
	if (head == NULL)
		printf("List is already empty!");
	else if (head->next == NULL)
	{
		free(head);
		head = NULL;
	}

	else
	{
		struct node* temp = head;
		struct node* temp2 = head;

		while (temp->next != NULL)
		{
			temp2 = temp;
			temp = temp->next;
		}
		temp2->next = NULL;
		free(temp);
		temp = NULL;

	}

	return head;
}

void del_pos(struct node** headRef, int position)
{
	struct node* current = *headRef;
	struct node* previous = *headRef;

	if (*headRef == NULL)
	{
		printf("List is already empty!");
	}
	else if (position == 1)
	{
		*headRef = current->next;
		free(current);
		current = NULL;
	}
	else
	{
		while (position != 1)
		{
			previous = current;
			current = current->next;
			position--;
		}
		previous->next = current->next;
		free(current);
		current = NULL;
	}

}

int main()
{
	struct node* head = NULL;

	head = (struct node*)malloc(sizeof(struct node));

	head->data = 6;
	head->next = NULL;

	struct node* beginng = NULL;
	beginng = (struct node*)malloc(sizeof(struct node));

	beginng->data = 7;
	beginng->next = NULL;
	beginng->next = head;
	head = beginng;

	beginng = (struct node*)malloc(sizeof(struct node));
	beginng->data = 1;
	beginng->next = NULL;
	beginng->next = head;
	head = beginng;

	add_at_end(&head, 4);

	insertAfter(head, 8, 3);

	printList(head);

	printf("\n");

	head = delFirst(head);
	printList(head);
	printf("\n");

	head = del_last(head);
	printList(head);
	printf("\n");

	int position = 2;
	del_pos(&head, position);
	printList(head);

	printf("\n");


	return (0);
}
