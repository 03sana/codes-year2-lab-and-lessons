#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include<stdlib.h>
#include<stdbool.h>



typedef struct Node {
	int data;
	struct Node* next;
}Node; Node* head = NULL;


struct Node* head, * tail = NULL;

int size;

void insert(struct Node** head, int item)
{
	struct Node* ptr, * temp;

	temp = (struct Node*)malloc(sizeof(struct Node));

	temp->data = item;
	temp->next = NULL;

	if (*head == NULL)
		*head = temp;
	else {
		ptr = *head;
		while (ptr->next != NULL)
			ptr = ptr->next;
		ptr->next = temp;
	}
}

struct Node* reverselist(struct Node* temp) {

	Node* current = temp;
	Node* prevNode = NULL;
	Node* nextNode = NULL;

	while (current != NULL) {

		nextNode = current->next;
		current->next = prevNode;
		prevNode = current;
		current = nextNode;
	}
	return prevNode;
}

void isPalindrome() {


	struct Node* current = head;

	bool flag = true;

	int mid_point = (size % 2 == 0) || (size / 2) && ((size + 1) / 2);

	for (int i = 1; i < mid_point; i++) {

		current = current->next;
	}

	Node* revhead = reverselist(current->next);


	while (head != NULL && revhead != NULL) {

		if (head->data != revhead->data) {

			

			flag = false;
			break;
		}

		head = head->next;
		revhead = revhead->next;
	}

	if (flag)
		printf("linked list is a palindrome\n");

	else

		printf("linked list is not a palindrome\n");


}


void display(Node* head) {

	struct Node* current = head;


	while (head != NULL)
	{

		printf("%d->", current->data);

		current = current->next;
	}
	printf("\n");

}


int main() {

	Node* head = NULL;

	insert(&head, 1);
	insert(&head, 2);
	insert(&head, 3);
	insert(&head, 2);
	insert(&head, 1);

	printf("Linked List: ");
	display(head);


	isPalindrome();

}