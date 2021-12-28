class Solution
{
    public:
    //Function to remove duplicates from unsorted linked list.
    Node * removeDuplicates( Node *head) 
    {
        unordered_set<int> vis;
        Node* curr=head,*prev=0;
        
        while(curr)
        {
            if(!prev)
                prev = curr,
                vis.insert(prev->data);
            else if(vis.count(curr->data))
                prev->next = curr->next;
            else
                prev = curr,
                vis.insert(prev->data);
            curr = curr->next;
        }
        
        return head;
    }
};