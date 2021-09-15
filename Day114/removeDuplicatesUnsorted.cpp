class Solution
{
    public:
    //Function to remove duplicates from unsorted linked list.
    Node * removeDuplicates( Node *head) 
    {
     unordered_set<int> vis;
     Node* curr = head;
     Node* prev = NULL;
     while(curr)
     {
         if(vis.find(curr->data)==vis.end())
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
};