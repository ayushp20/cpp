Node* SortedInsert(Node *head,int data)
{
    // Complete this function
   // Do not write the main method.
    Node *info=new Node;
    info->data=data;
    if(head==NULL)
    {   info->next=NULL;
        info->prev=NULL;
        return info;
    }
     if(info->data<=head->data)
    {
        info->next=head;
        info->prev=NULL;
        head->prev=info;
        head=info;
    }
    else
    {   Node *n;
        for(n=head;n->next!=NULL&&info->data > n->next->data ;n=n->next);

    info->prev=n;
    info->next=n->next;
        if(n->next!=NULL)
            n->next->prev=info;
    n->next=info;
    }
    return head;
}
