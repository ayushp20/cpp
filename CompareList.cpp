
int CompareLists(Node *headA, Node* headB)
{
  // This is a "method-only" submission.
  // You only need to complete this method
    Node *a=headA, *b=headB;
    int flag=1;
    while(a!=NULL||b!=NULL)
    {
        if(a->data!=b->data)
        {
            flag=0;break;
        }
        else
        {
            a=a->next;b=b->next;
            if((a==NULL&&b!=NULL)||(a!=NULL&&b==NULL))
            {
                flag=0;break;
            }
        }
    }
return flag;
}

