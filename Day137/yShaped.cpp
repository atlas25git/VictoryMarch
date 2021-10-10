int intersectPoint(Node* head1, Node* head2)
{   
    Node *t1 = head1,*t2=head2;
    unordered_set<Node*> s;
    while(head1)
    {
        s.insert(head1);
        head1 = head1->next;
    }
    
    while(head2 && s.find(head2)==s.end())
    {
        head2=head2->next;
    }
    return head2->data;
}