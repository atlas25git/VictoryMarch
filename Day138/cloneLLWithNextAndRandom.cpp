int intersectPoint(Node* head1, Node* head2)
{
    int n1=0, n2=0;
    Node* temp;
    
    //finding length of list1.
    for(temp = head1; temp; temp=temp->next)
        n1++;
        
    // finding length of list2.
    for(temp = head2; temp; temp=temp->next)
        n2++;
    
    //if list1 is longer, we ignore some of its starting
    //elements till it has as many elements as list2.
    for(  ; n1>n2 ; n1-- )
        head1 = head1->next;
        
    //similarly, if list2 is longer, we ignore some of its starting
    //elements till it has as many elements as list1.
    for(  ; n2>n1 ; n2-- )
        head2 = head2->next;
        
    //now we simply traverse ahead till we get the intersection point, if there 
    //is none, this loop will break when both pointers point at NULL.
    while( head1 != head2 )
    {
        head1 = head1->next;
        head2 = head2->next;
    }
    
    // if head1 is not NULL, we return its data otherwise we return -1.
    if(head1) 
    return head1->data;
    return -1;
}