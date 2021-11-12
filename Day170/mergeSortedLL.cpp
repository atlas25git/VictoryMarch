Node* sortedMerge(Node* head1, Node* head2)  
{  
    if(!head1)return head2;
    if(!head2)return head1;
    Node* curr;
    if(head1->data <= head2->data)
        curr = head1,
        curr->next = sortedMerge(head1->next,head2);
    if(head1->data > head2->data)
        curr = head2,
        curr->next = sortedMerge(head1,head2->next);
    
    return curr;
}  