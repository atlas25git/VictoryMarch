Node* recSwap(Node* head)
{
    if(!head || !head->next)return head;
    
    Node* subRes = recSwap(head->next->next);
    
    // n1 -> n2 -> subRes
    // |^    |        |^
    // *-----*        |
    // |______________|
    
    //storing n2s address.
    Node* nxt = head->next;
    // nxt->next = head;
    head->next->next = head;
    head->next = subRes;
    
    return nxt;
}

Node* iterative(Node* head)
{
    if(!head || !head->next)return head;
    
    Node* curr = head->next->next,*prev = head;
    
    head->next->next = head;
    head = head->next;
    
    while(curr && curr->next)
    {
        prev->next = curr->next;
        Node* nxt = curr->next->next;
        
        prev = curr;
        curr->next->next = curr;
        curr = nxt;
        prev->next = 0;
    }
    if(curr)prev->next = curr;
 
    return head;
}

//Function to swap elements pairwise.
struct Node* pairwise_swap(struct Node* head)
{
    // return recSwap(head);
    return iterative(head);
}
