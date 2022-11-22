
#include <stdio.h>
#include <stdlib.h>
  
struct Node {
    char data;
    struct Node* next;
};


void printlist(struct Node *n){
   
   while(n != NULL){
       
       printf("%c", n->data);
       n=n->next;
   }
}

void push(struct Node** head_ref, char new_data)
{
    
    struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));
 
   
    new_node->data  = new_data;
 
    new_node->next = (*head_ref);
 
    (*head_ref)    = new_node;
}


void deleteN ( struct Node** head, int position)
{
    


   struct Node* temp;
   struct Node* prev;
    temp = *head;
    prev = *head;
    for (int i = 0; i < position; i++) {
        if (i == 0 && position == 1) {
            *head = (*head)->next;
            free(temp);
        }
        else {
            if (i == position - 1 && temp) {
                prev->next = temp->next;
                free(temp);
            }
            else {
                prev = temp;
 
                if (prev == NULL)
                    break;
                temp = temp->next;
            }
        }
    }
}

void append(struct Node** first_ref, char new_data)
{
	struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));

	struct Node *last = *first_ref; 


	new_node->data = new_data;


	new_node->next = NULL;
	if (*first_ref == NULL)
	{
	*first_ref = new_node;
	return;
	}
	
	while (last->next != NULL)
		last = last->next;

	last->next = new_node;
	return;
}

  

int main()
{
    struct Node* first = NULL;
    struct Node* second = NULL;
    struct Node* third = NULL;
    struct Node* fourth = NULL;
    struct Node* fifth = NULL;
        struct Node* sixth = NULL;
            struct Node* seventh = NULL;


  
    // allocate 3 nodes in the heap
    first = (struct Node*)malloc(sizeof(struct Node));
    second = (struct Node*)malloc(sizeof(struct Node));
    third = (struct Node*)malloc(sizeof(struct Node));
    fourth = (struct Node*)malloc(sizeof(struct Node));
    fifth = (struct Node*)malloc(sizeof(struct Node));
 sixth = (struct Node*)malloc(sizeof(struct Node));
 seventh = (struct Node*)malloc(sizeof(struct Node));




  
    first->data = 'r';
    first->next = second; 
    
    second->data = 'a';
    second->next = third;
    
    third->data = 'i'; // assign data to third node
    third->next = fourth;
    
    fourth->data = 'n';
    fourth->next = fifth;
    

    fifth->data = 'i';
    fifth->next = sixth;
    
     sixth->data = 'n';
    sixth->next = seventh;
    
     seventh->data = 'g'; 
    seventh->next = NULL;
  
   
    
    printlist(first);
    printf("\n");
    push(&first,'t');


  
  deleteN(&first,8);
  deleteN(&first,7);
  deleteN(&first,6);
 
  append(&first, 's');

    printlist(first);
  
    return 0;
}

