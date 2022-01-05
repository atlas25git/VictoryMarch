class Solution
{   
    Node* prev,*head;
    
    public: 
    //next if we see in terms of tree and prev in terms of list;
    //Function to convert binary tree to doubly linked list and return it.
    Node * bToDLL(Node *root)
    {
        if(!root)return root;
        prev=NULL;
        head = NULL;
        convert(root);
        return head;
    }
    
    void convert(Node* root)
    {
        if(!root)return;
        convert(root->left);
        //logic
        if(!prev)head = root;
        else{
            prev->right = root;
            root->left = prev;
        }
        prev = root;
        convert(root->right);
    }
};