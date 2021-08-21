struct Node* pairwise_swap(struct Node* head)
{   
    Node* h1=head; 
    while(head->next!=NULL && head->next->next!=NULL)
    {   
        int data = head->data;
        head->data = head->next->data;
        head->next->data = data;
        head = head->next->next;
    }
    if(head->next)
    {
         int data = head->data;
        head->data = head->next->data;
        head->next->data = data;
        head = head->next->next;
    }
    return h1;
}