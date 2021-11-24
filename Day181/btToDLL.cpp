class Solution
{   
    Node* next,*head;
    
    public: 
    //Function to convert binary tree to doubly linked list and return it.
    Node * bToDLL(Node *root)
    {
        if(!root)return root;
        next=NULL;
        head = NULL;
        convert(root);
        return head;
    }
    
    void convert(Node* root)
    {
        if(!root)return;
        convert(root->left);
        //logic
        if(!next)head = root;
        else{
            next->right = root;
            root->left = next;
        }
        
        next = root;
        
        convert(root->right);
    }
};
