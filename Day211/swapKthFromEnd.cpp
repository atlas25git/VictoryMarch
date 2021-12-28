Node *swapkthnode(Node* head, int num, int K)
{
    int count = 0;
    Node* curr = head, *kbeg = head,*kend=head,*kbegp=0,*kendp=0;
    while(curr)
        count++,
        curr = curr->next;
        
    if((2*K-1) == count || K>count)return head;
    int jS = K-1,jE = count - K;
    while(jS--)
        kbegp = kbeg,
        kbeg = kbeg->next;
    while(jE--)
        kendp = kend,
        kend = kend->next;
    
    if(kbegp)kbegp->next = kend;
    if(kendp)kendp->next = kbeg;
  
    //We could have used swap for kbegp and kendp but,
    //we have to be sure of their existence.
    swap(kend->next,kbeg->next);
    
    if(K==1)
        return kend;
    if(K==count)
        //kbeg contains the last node here
        return kbeg;
    return head;
}