#include<iostream>
  struct Node
  {
     int data;
     struct Node *next;
  };
Node* Delete(Node *head, int position)
{
  // Complete this method
    Node *temp=head;
    int i=1;
    if(head==NULL)
    {
        return NULL;
    }
    else if(temp->next==NULL)
    {
        delete temp;
        head=NULL;
        return head;
    }
    else{
        for(;temp!=NULL;temp=temp->next)
    {
        if(i==position-1)
        {
            temp->next=(temp->next)->next;
            temp=temp->next;
            delete temp;
            return head;
        }

    }
    }

}
