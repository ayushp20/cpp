Node* Reverse(Node *head)
{
  // Complete this method
    Node *n=head;
    Node *headtmp;
    while(n!=NULL)
    { if(n->next==NULL)
        headtmp=n;
     n=n->next;
   }
    Node *prev=head;
    n=prev->next;
    Node *s;
    do
    {
      if(n==NULL)
      {
          return headtmp;
      }
        else
        { s=n->next;
               n->next=prev;
            prev=n;
            n=s;}
    }while(s!=NULL);

    head->next=NULL;
    return headtmp;
}

