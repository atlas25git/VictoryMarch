Node *swapkthnode(Node* head, int num, int K)
{   
   
    int count = 0;
    Node *curr = head,*kbeg = head,*kend = head,*kbegp=0,*kendp=0;
    while(curr)
        count++,
        curr = curr->next;
    if(K>count)return head;
    if(2*K-1 == count)return head;
        
    int jS = K -1;
    while(jS--)
        kbegp = kbeg,
        kbeg = kbeg->next;
    
    int jE = count - K;
    while(jE--)
        kendp = kend,
        kend = kend->next;
    
    if(kbegp)kbegp->next = kend;
    if(kendp)kendp->next = kbeg;
    
    swap(kend->next,kbeg->next);
    
    if(K==1)
        head = kend;
    if(K==count)
        head =  kbeg;
    return head;
}