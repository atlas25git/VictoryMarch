class Solution
{
    public:
    //Function to remove duplicates from unsorted linked list.
    Node * removeDuplicates( Node *head) 
    {
        unordered_set<int> s;
        Node *curr,*prev;
        curr = head;
        while(curr)
        {
            if(s.find(curr->data) == s.end())
            {
                s.insert(curr->data);
                prev = curr;
            }
            else
            {
                prev->next = curr->next;
            }
            curr = curr->next;
        }
        return head;
    }
};