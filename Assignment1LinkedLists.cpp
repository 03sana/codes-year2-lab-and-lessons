#include <stdio.h>
#include <stdlib.h>
#define _CRT_SECURE_NO_WARNNG
struct node
{

	int data;
	struct node* next;
};

int main() {
	struct node* Head = NULL;
	struct node* second = NULL;
	struct node* thrid = NULL;
	struct node* fourth = NULL;
	struct node* fifth = NULL;


	Head = (struct node*)malloc(sizeof(struct node));
	second = (struct node*)malloc(sizeof(struct node));
	thrid = (struct node*)malloc(sizeof(struct node));
	fourth = (struct node*)malloc(sizeof(struct node));
	fifth = (struct node*)malloc(sizeof(struct node));


	struct node* temp = Head;

	int sum = 0;

	Head->data = 15;
	Head->next = second;

	second->data = 25;
	second->next = thrid;

	thrid->data = 35;
	thrid->next = fourth;

	fourth->data = 45;
	fourth->next = fifth;

	fifth->data = 55;
	fifth->next = NULL;

	while (temp != NULL)
	{
		printf("data= %d\n", temp->data);
		sum += temp->data;
		temp = temp->next;
	}
	printf("sum= %d\n", sum);

}
