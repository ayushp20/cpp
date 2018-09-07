Node* RemoveDuplicates(Node *head)
{
  // This is a "method-only" submission.
  // You only need to complete this method.
    if(head==NULL)
    {
        return NULL ;
    }
    else if(head->next==NULL)
        return head;
    else
    {
        Node *prev=head,*t=NULL,*n=NULL;
        while(prev->next!=NULL)
        {   n=prev->next;
            if(prev->data==n->data)
            {
                t=n->next;

                delete n;

                  prev->next=t;
            }
            else
                prev=prev->next;


        }
    return head;
    }
}
