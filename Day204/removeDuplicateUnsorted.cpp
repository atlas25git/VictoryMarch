class Solution
{
    public:
    //Function to remove duplicates from unsorted linked list.
    Node * removeDuplicates( Node *head) 
    {
        unordered_set<int> pres;
        Node* curr = head,*prev = 0;
    
        while(curr)
        {
            if(!prev)
                pres.insert(curr->data),
                prev = curr;
            else if(pres.count(curr->data))
                prev->next = curr->next;
            else 
                pres.insert(curr->data),
                prev = curr;
            
            curr = curr->next;
        }
        
        return head;
    }
};