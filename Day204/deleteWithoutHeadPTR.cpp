class Solution
{
    public:
    //Function to delete a node without any reference to head pointer.
    void deleteNode(Node *del)
    {
       while(del->next->next)
       {
           del->data = del->next->data;
           del = del->next;
       }
       del->data = del->next->data;
       del->next = NULL;
    }

};
