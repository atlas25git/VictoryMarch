class Solution
{
    public:
    //Function to reverse a linked list.
    struct Node* reverseList(struct Node *head)
    {
        // recursive(head);
        iterative(head);
    }
    
    Node* iterative(Node* head)
    {
        if(!head || !head->next)return head;
        Node* prev=0,*curr = head;
        
        while(curr)
        {
            Node* nxt = curr->next;
            curr->next = prev;
            
            prev = curr;
            curr = nxt;
        }
        return prev;
    }
    
    Node* recursive(Node* head)
    {   
        //for corner case of invalid input being passed.
        if(!head || !head->next)return head;
        
        Node* subRes = recursive(head->next);
        head->next->next = head;
        head->next = NULL;
        return subRes;
    }
    
};
   