//Question 1 assignment 6
//sana nassani

#include <stdio.h>
#include <stdlib.h>
#define bool int

// structure of a stack node
struct Node {
	char data;
	struct Node* next;
};

// Function to push an item to stack
void push(struct Node** head_top, int x)
{
	// allocate node
	struct Node *Top = (struct Node*)malloc(sizeof(struct Node));

	//check the condition for full
	if (Top == NULL) {
		printf("Stack overflow \n");
		exit(0);
	}
	// put in the data
	Top->data = x;

	// link the old list
	// off the new node
	Top->next = (*head_top);

	// move the head to
	// point to the new node
	(*head_top) = Top;
}

// Function to pop an item from stack
int pop(struct Node** head_top)
{
	char str;
	struct Node* top;

	// If stack is empty then error
	if (*head_top == NULL) {
		printf("Stack overflow \n");
		exit(0);
	}
	else {
		top = *head_top;
		str = top->data;
		*head_top = top->next;
		free(top);
		return str;
	}
}

void insertAtBottom(struct Node** head_top, int item)
{
	if (isEmpty(*head_top))
		push(head_top, item);
	else {

	
		int temp = pop(head_top);
		insertAtBottom(head_top, item);

		// Once the item is inserted
		// at the bottom, push all
		// the items held in Function
		// Call Stack
		push(head_top, temp);
	}
}

void reverse(struct Node** head_top)
{
	if (!isEmpty(*head_top)) {
		
		int temp = pop(head_top);

		reverse(head_top);

		insertAtBottom(head_top, temp);
	}
}

// check if the stack is empty
bool isEmpty(struct Node* top)
{
	return (top == NULL) ? 1 : 0;
}


// Function to print a
// linked list
void print(struct Node* top)
{
	printf("\n");
	while (top != NULL) {
		printf(" %d ", top->data);
		top = top->next;
	}
}

// Driver Code
int main()
{
	struct Node* s = NULL;
	push(&s, 4);
	push(&s, 3);
	push(&s, 2);
	push(&s, 1);

	printf("\n Original Stack ");
	print(s);
	reverse(&s);
	printf("\n Reversed Stack ");
	print(s);
	return 0;
}