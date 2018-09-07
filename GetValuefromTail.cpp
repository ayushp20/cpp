int GetNode(Node *head,int positionFromTail)
{
  // This is a "method-only" submission.
  // You only need to complete this method.
    Node*n=head;
    int count =0,i=0;
    for(;n!=NULL;n=n->next)
    {
        count++;
    }
    n=head;
    while(i!=count-positionFromTail-1)
    {
        i++;
        n=n->next;
    }
    return n->data;
}

