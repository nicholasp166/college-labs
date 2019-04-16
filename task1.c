#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#define MAX 10
#define EMPTY -1

typedef struct node_t{
    int value;
    struct node_t *next;
}node_t;

typedef struct stack_t {
    node_t *s_top; //points to the first node
}stack_t; //holds pointer to top of stack


void push(stack_t **sPtr,int value); //task1 functions are done
int pop(stack_t **sPtr);
void enqueue(node_t **head,node_t **tail,int value);
int dequeue(node_t **head);
int is_empty(void);

int main(void){
    struct node_t *head = NULL;
    struct node_t *tail = NULL; //global variables until i figure out if this is bad format or nah
    struct stack_t *sPtr;
    int temp[MAX];
    printf("Before Reversing: ");//task2 begins here
    for(int i=0;i<MAX;i++){
    enqueue(&head,&tail,i+1);
    }
    printf("\n");
    for(int i=0;i<MAX;i++){
    push(&sPtr,dequeue(&head));
    } 
    printf("After Reversing: ");
    for(int i=0;i<MAX;i++){
       printf("%d ", pop(&sPtr));
    } 
    return 0;
}

void enqueue(node_t **head,node_t **tail,int value){
    node_t *new_node = (node_t *) malloc(sizeof(node_t) * MAX);
    new_node->value = value;
    new_node->next = NULL;
    printf("%d ",new_node->value);

    if((*head) == NULL){
        (*head) = new_node; //sets the new node equal to the head node initially creating the linked list
    } else {
        (*tail)->next = new_node; // if the head node is present then it adds on becoming the tail
    }
    (*tail) = new_node;
    return;
}

int dequeue(node_t **head){ //remember that queues are first in first order
    node_t *temp_node;
    int temp_value;

    if((*head) != NULL){ //checking if the node ISNT empty
        temp_node = (*head);
        temp_value = temp_node->value;
        (*head) = (*head)->next; //iterates
        free(temp_node);
    }
    return temp_value;
}

void push(stack_t **sPtr,int value){ //adds item to the stack
    struct node_t *new_node;
    new_node = (node_t *) malloc(sizeof(node_t));
    new_node->value = value;

    new_node->next = (*sPtr)->s_top;
    (*sPtr)->s_top = new_node;
    return;
}

int pop(stack_t **sPtr){ //returns the value of the item from the top of the stack
    struct node_t *temp_ptr;
    int temp_value;

    temp_ptr = (*sPtr)->s_top; //accesses top node through the memory?
    temp_value = temp_ptr->value;
    (*sPtr)->s_top = temp_ptr->next;
    free(temp_ptr);
    return temp_value;
}
