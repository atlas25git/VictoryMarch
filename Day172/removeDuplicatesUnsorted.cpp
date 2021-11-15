class Solution
{
    public:
    //Function to remove duplicates from unsorted linked list.
    Node * removeDuplicates( Node *head) 
    {
        unordered_set<int> set;
        
        Node* curr = head,*prev=NULL;
        
        while(curr)
        {
            if(!prev)
                prev= curr,
                set.insert(curr->data);
            else if(set.find(curr->data)!=set.end())
            {
                prev->next = curr->next;
            }
            else
                {
                    prev = curr,
                    set.insert(curr->data);
                    
                }
            curr = curr->next;
        }
        return head;
    }
};