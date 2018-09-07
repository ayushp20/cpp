int FindMergeNode(Node *headA, Node *headB)
{
    // Complete this function
    // Do not write the main method.
    Node *a=headA,*b=headB;
    int i=0;
    while(a->next!=NULL)
    {   b=headB;
        while(b->next!=NULL)
        {
            if(a->next==b->next)
            {
                i=b->next->data;
                return i;
            }
            b=b->next;
        }
        a=a->next;
    }
return 0;
}
