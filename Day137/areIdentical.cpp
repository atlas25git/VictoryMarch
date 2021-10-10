bool areIdentical(struct Node *head1, struct Node *head2)
{   
    if(!head1 && !head2)return true;
    if(!head1 || !head2)return false;
    
    return ((head1->data == head2->data ) && areIdentical(head1->next,head2->next));
}