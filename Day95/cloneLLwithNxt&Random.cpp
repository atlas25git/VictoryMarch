class Solution
{
    public: 
    //Function to clone a linked list with next and random pointer.
Node *copyList(Node *head) {
    
    if(head == NULL) return head;
    Node* t =head;
    //step 1: inserting duplicate nodes in the original ll
    while(t)
    {
        Node* n=new Node(t->data);
        n->next = t->next;
        t->next = n;
        t=n->next;
    }
    
    //step2: setting up the arb pointers in the duplicate nodes
    t=head;
    while(t)
    {
        if(t->arb == NULL)
            t->next->arb=NULL;
        else 
            t->next->arb = t->arb->next;
            
        t = t->next->next;
    }
    t = head;
    Node* head1 = head;
    Node* head2 = head->next;
    
    //seperating the two lls
    while(t)
    {
        //Here we acess the duplicate nodes just by the nodes and pointers
        //of the original list that is head and t
        //maintaing the two pointers at consecutive nodes of the given og
        //list
        head = t->next->next;
        if(head)
        //fixing the nodes of duplicated list
            t->next->next = head->next;//think of this as the next field of t's next node
        else
            t->next->next = NULL;
        //fixing links of og list
        t->next = head;
        t=head;
    }
    return head2;
}

};

