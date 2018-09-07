#include <stdio.h>
#include <malloc.h>
typedef struct que {
	int data;
	struct que *next;
} QUE;
typedef QUE *que;
void printQue(que head){
	if(head==NULL){
		printf("Queue is empty.");
		return;
	}
	printf("Form First in\n");
	while(head!=NULL){
		printf("%d\n",head->data);
		head = head->next;
	}
	return;
}
int peek(que head){
	if(head!=NULL) return head->data;
	return 0;
}
int isEmpty(que head){
	if(head)return 0;
	return 1;
}
que pop(que head){
	if(head==NULL){
		printf("Underflow condition.\n");return 0;
	}else{
		que p = (que)malloc(sizeof(QUE));
		p = head;
		head = head->next;
		free(p);
	}
	return head;
}
que push(que head, int data){
	que p = (que)malloc(sizeof(QUE));
	p->next = NULL;
	p->data = data;
	if(head==NULL){
		head = p;
	}else{
		que temp =head;
		while(temp->next!=NULL){
			temp=temp->next;
		}
		temp->next = p;
      }
      return head;
}
int main(void){
	char ch = 'Y'; int data; int action;
	que head = (que)malloc(sizeof(QUE));
	head = NULL;
	printf("Empty que created\n");
     do{
 		printf("Choose a action.\n");
    	printf("1.Add data to que(push())\n2.Delete data from que(pop())\n3.Print first in data(peek())");
	    printf("\n4.Check for empty que(isEmpty())\n5.Print que(printQue())");
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
		    	 if(peek(head)==-1){
		    	 	printf("Que is empty.");
				 }else{
				 	printf("First in Element is: %d",head->data);
				 }
				 break;
			case 4:
			    if(isEmpty(head)){
			    	printf("Queue is empty.");
			    }else{
			    	printf("Queue has some elements.");
				}
				break;
		    case 5:
		    	 printf("Printing Queue\n");
		    	 printQue(head);
		    	 break;
			default:
				printf("Wrong action.");
		}
		printf("\nWant more action?(y/n): ");
		scanf("%c",&ch); fflush(stdin);
	}while(ch=='Y'||ch=='y');
	return 0;
}
