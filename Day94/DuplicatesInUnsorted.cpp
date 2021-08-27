class Solution
{
    public:
    //Function to remove duplicates from unsorted linked list.
    Node * removeDuplicates( Node *head) 
    {   
        Node* curr = head;
        Node* prev = NULL
        ;
        unordered_set<int> vis;
     // your code goes here
        while(curr)// && curr->next->next)
        {
            if(vis.find(curr->data)==vis.end() || vis.size()==0)
            {  
                vis.insert(curr->data);
                prev = curr;
                curr = prev->next;
            }
            else
            {
                prev->next = curr->next;
                curr = prev->next;
            }
        }
        return head;
    }
}