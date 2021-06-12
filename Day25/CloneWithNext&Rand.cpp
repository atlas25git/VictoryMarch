//Function to clone a linked list with next and random pointer.
Node *copyList(Node *head)
{
    if (head == NULL) return head;

    Node *t = head;
    while (t != NULL)
    {
        //making an identical list merged with original list.
        //creating the copy of node 1 and inserting it between node 1 
        //& node 2in original Linked List, creating a copy of 2 and 
        //inserting it between 2 & 3 and continuing this.
        Node *n = new Node(t->data);
        n->next = t->next;
        t->next = n;
        t = n->next;
    }
    
    t = head;
    Node *head2 = head->next;
    while (t != NULL)
    {
        //setting the arbitrary(random) pointers of duplicate list.
        //this works because original->next is nothing but copy of original 
        //and Original->random->next is nothing but copy of random.
        if (t->arb == NULL)
            t->next->arb = NULL;
        else 
            t->next->arb = t->arb->next;
        
        t = t->next->next;
    }
    
    t = head;
    while (t != NULL)
    {
        //separating the 2 merged lists (duplicate and original).
        head = t->next->next;
        
        if(head)
        t->next->next = head->next;
        else 
        t->next->next = NULL;
        
        t->next = head;
        t = head;
    }
    //returning the cloned list.
    return head2;
}