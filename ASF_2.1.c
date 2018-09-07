#include <stdio.h>
#include <malloc.h>
typedef struct stack {
	int data;
	struct stack *next;
} STACK;
typedef STACK *stack;
void printStack(stack head){
	if(head==NULL){
		printf("Stack is empty.");
		return;
	}
	printf("From Top:\n");
	while(head!=NULL){
		printf("%d\n",head->data);
		head = head->next;
	}
	return;
}
int peek(stack head){
	if(head!=NULL)return head->data;
	return 0;
}
int isEmpty(stack head){
	if(head)return 0;
	return 1;
}
stack pop(stack head){
	if(head==NULL){
		printf("Underflow condition.\n");return 0;
	}else{
		stack p = (stack)malloc(sizeof(STACK));
		p = head;
		head = head->next;
		free(p);
	}
	return head;
}
stack push(stack head, int data){
	stack p = (stack)malloc(sizeof(STACK));
	if(head==NULL){
		p->data = data;
		p->next = NULL;
	}else{
		stack t = (stack)malloc(sizeof(STACK));
		t = head;
		p->data = data;
		p->next = t;
      }
	    head    = p;
	 	return head;
}
int main(void){
	char ch = 'Y'; int data; int action;
	stack head = (stack)malloc(sizeof(STACK));
	head = NULL;
	printf("Empty Stack created\n");
     do{
 		printf("Choose a action.\n");
    	printf("1.Add data to stack(push())\n2.Delete data from stack(pop())\n3.Print top stack(peek())");
	    printf("\n4.Check for empty stack(isEmpty())\n5.Print stack(printStack())");
     	printf("\nYour action: "); scanf("%d",&action); fflush(stdin);
		switch(action){
			case 1:
		         printf("Enter data: ");
		         scanf("%d",&data); fflush(stdin);
			     head = push(head,data);
			     break;
		    case 2:
		         head = pop(head);
		         break;
		    case 3:
		    	 if(head==NULL){
		    	 	printf("Stack is empty.");
				 }else{
				 	printf("Top element is: %d",peek(head));
				 }
				 break;
			case 4:
			    if(isEmpty(head)){
			    	printf("Stack is empty.");
			    }else{
			    	printf("Stack has some elements.");
				}
				break;
		    case 5:
		    	 printf("Printing stack\n");
		    	 printStack(head);
		    	 break;
			default:
				printf("Wrong action.");
		}
		printf("\nWant more action?(y/n): ");
		scanf("%c",&ch); fflush(stdin);
	}while(ch=='Y'||ch=='y');
	return 0;
}
