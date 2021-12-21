class Solution
{
    public:
    //Function to count nodes of a linked list.
    int getCount(struct Node* head){
    
        int c = 0;
        Node* curr = head;
        while(curr)c++,curr=curr->next;
        return c;
    
    }
};
    