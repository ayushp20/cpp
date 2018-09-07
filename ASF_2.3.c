#include <stdio.h>
#include <malloc.h>
typedef struct node {
	int data;
	struct node *next;
} NODE;
typedef NODE *list;
void printList(list p){
	while(p!=NULL){
		printf("%d-> ",p->data);
		p = p->next;
	}
	printf("NULL");
	return;
}
list giveNode(int data){
	list p = (list)malloc(sizeof(NODE));
	p->data = data;
	p->next = NULL;
	return p;
}
int main(void){
	int n;
	char ch;
	int data;
	list head1 = (list)malloc(sizeof(NODE));
	list head2 = (list)malloc(sizeof(NODE));
	list head3 = (list)malloc(sizeof(NODE));
	list temp  = (list)malloc(sizeof(NODE));
	list temp1  = (list)malloc(sizeof(NODE));
	head1= NULL;
	head2= NULL;
	head3= NULL;
	printf("Add data to list?(y/n)");
	scanf("%c",&ch); fflush(stdin);
	if(ch=='Y'||ch=='y'){
		printf("Enter data: ");
		scanf("%d",&n); fflush(stdin);
		head1 = giveNode(n);
		temp  = head1;
		printf("Add more data?(y/n)");
		scanf("%c",&ch); fflush(stdin);
	}
	while(ch=='Y'||ch=='y'){
		printf("Enter data: ");
		scanf("%d",&n); fflush(stdin);
		temp->next = giveNode(n);
		temp = temp->next;
		printf("Enter more data?(y/n)");
		scanf("%c",&ch); fflush(stdin);
	}
	temp1 = head1;
	if(temp1!=NULL&&temp1->next!=NULL){
		head2 = giveNode(temp1->next->data);
		temp  = head2;
		temp1 = temp1->next->next;
	  }
	while(temp1!=NULL&&temp1->next!=NULL){
		temp->next = giveNode(temp1->next->data);
		temp1 = temp1->next->next;
		temp = temp->next;
	  }

    if(head1!=NULL)head3 = giveNode(head1->data);
    temp = head3;
    temp1 = head1->next;
	if(temp1!=NULL&&temp1->next!=NULL){
		temp->next = giveNode(temp1->next->data);
		temp  = temp->next;
		temp1 = temp1->next->next;
	  }
	while(temp1!=NULL&&temp1->next!=NULL){
		temp->next = giveNode(temp1->next->data);
		temp1 = temp1->next->next;
		temp = temp->next;
	  }

  printf("Printing original list:\n");
  printList(head1);
  printf("\n\nPrinting Even node list:\n");
  printList(head2);
  printf("\n\nPrinting Odd node list: \n");
  printList(head3);
  return 0;
}
