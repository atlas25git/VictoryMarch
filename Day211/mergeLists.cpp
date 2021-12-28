Node* sortedMerge(Node* head1, Node* head2)  
{   
    //headF is doing nothing but just storing the head which has been used.
    Node* headF; 
    if(!head1)
        return head2;
    if(!head2)
        return head1;
    if(head1->data <= head2->data)
        headF = head1,
        headF->next = sortedMerge(head1->next,head2);
    else 
        headF = head2,
        headF->next = sortedMerge(head1,head2->next);
        
    return head1->data<=head2->data?head1:head2;
} 