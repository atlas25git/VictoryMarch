struct Node* reverseList(Node* head)
    {
      
        if(!head || !head->next)return head;
        
        Node* tail = head->next;
        Node* fhead = reverseList(head->next);
        //connecting tail to the remaining part
        tail->next = head;
        head->next=NULL;
        
        return fhead;    
    }