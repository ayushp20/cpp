bool has_cycle(Node* head) {
    // Complete this function
    // Do not write the main method
    Node *slowp=head,*fastp=head;
    while(slowp!=NULL&&fastp!=NULL&&fastp->next)
    {
        slowp=slowp->next;
        fastp=fastp->next->next;

        if(slowp==fastp)
        {
            return 1;
        }

    }
    return 0;

}
