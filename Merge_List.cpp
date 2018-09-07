Node* MergeLists(Node *headA, Node* headB)
{
    Node *a=headA,*b=headB,*head=NULL,*tail=NULL;
    if(a==NULL)
        return headB;
    else
    {
    while(b!=NULL)
    {
        Node*info=new Node;
        info->data=b->data;
        if(b->data<headA->data)
        {
          info->next=a;
          headA=info;
        }
        else
        {
        for(a=headA;a->next!=NULL&&b->data>a->next->data;a=a->next);

        info->next=a->next;
        a->next=info;
        }
        b=b->next;
    }
       return headA;
    }

}
