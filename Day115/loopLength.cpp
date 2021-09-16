int countNodesinLoop(struct Node *head)
{
    Node* slow = head;
    Node* fast = head->next;
    
    while(fast != slow)
    {
        if(!fast || !fast->next)
        return 0;
        fast = fast->next->next;
        slow = slow->next;
    }
    int size = 1;
    slow = slow->next;
    
    while(fast!=slow)
    {
        size++;
        slow=slow->next;
    }
    return size;
}

int countNodesinLoop(struct Node *head)
{
    Node* slow = head;
    Node* fast = head;
    
    while(slow && fast && fast->next)
    {
        
        slow = slow->next;
        fast = fast->next->next;
        
        if(slow == fast)
            break;
    }
    
    if(slow!=fast)return 0;
    
    int sz = 1;
    slow = slow->next;
    
    while(slow != fast)
    {   
        sz++;
        slow = slow->next;
    }
    return sz;
}