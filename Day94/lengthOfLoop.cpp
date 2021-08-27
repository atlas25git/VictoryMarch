//Function to find the length of a loop in the linked list.
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