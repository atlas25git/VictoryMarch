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
    //Now the head is at the second last node if even and last if odd
    if(head->next)
    {   cout<<"called for even's case\n";
         int data = head->data;
        head->data = head->next->data;
        head->next->data = data;
        head = head->next->next;
    }
    return h1;
}