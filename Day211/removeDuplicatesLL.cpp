Node *removeDuplicates(Node *head)
{
    Node* prev = 0,*curr = head;
    
    while(curr)
    {
        if(!prev)
            prev = curr;
        else if(prev->data == curr->data)
            prev->next = curr->next;
        else 
            prev = curr;
        curr = curr->next;
    }
    return head;
}