class Solution
{
    public:
    //Function to rotate a linked list.
     Node* rotate(Node* head, int k)
    {
        if (k == 0) 
        return head;
        
        Node *walk = head;
        Node *prev;
        
        //this loop runs k times and walk pointer moves k nodes ahead 
        //and reaches new head node.
        while( k-- && walk!=NULL )
        {
            prev = walk;
            walk = walk->next;
        }
        //considering cases where k>=n so nothing needs to be done.
        if(!walk) return head; 
        
        //we store the walk pointer which gives the first node in newHead.
        Node* newHead = walk;
        
        //since prev points to the node placed before new head it is new tail
        //or the last node of new list so we store null in it's link part.
        prev->next = NULL;
        
        //we keep moving the walk pointer till we reach the last node of list.
        while( walk->next )
            walk = walk->next;
        
        //connecting last node of old list to old head.
        walk->next = head;
        
        //returning the new list.
        return newHead;
    }
};
    