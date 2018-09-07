Node* Reverse(Node* head)
{
    // Complete this function
    // Do not write the main method.
    if(head==NULL)
        return NULL;
    else if(head->next==NULL)
        return head;
    else
    {
        Node *n=head,*t;

        while(1)
        {   t=n->next;
            n->next=n->prev;
            n->prev=t;
            if(t==NULL)
            {
                head=n;
                return head;
            }
            n=t;
        }
    }

}
