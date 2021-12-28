int spaceN(Node* head1,Node* head2)
{
    Node *t1 = head1,*t2=head2;
    unordered_set<Node*> s;
    while(head1)
    {
        s.insert(head1);
        head1 = head1->next;
    }
    
    while(head2 && !s.count(head2))
    {
        head2=head2->next;
    }
    
    return head2->data;
}

int fill(Node* head)
{
    int c = 0;
    while(head)c++,head = head->next;
    return c;
}

int space1(Node* head1,Node* head2)
{
    int c1=0,c2=0;
    c1 = fill(head1);
    c2 = fill(head2);
    
    //assuming c1 and head1 are always greater.
    if(c2>c1)
        swap(head1,head2),
        swap(c1,c2);
    
    while(c1-->c2)
    {
        head1 = head1->next;
    }
    
    while(head1 && head2)
    {
        if(head1 == head2)
            return head1->data;
        head1 = head1->next;
        head2 = head2->next;
    }
    
    return -1;
}
//Function to find intersection point in Y shaped Linked Lists.
int intersectPoint(Node* head1, Node* head2)
{   
    return spaceN(head1,head2);
    // return space1(head1,head2);
}