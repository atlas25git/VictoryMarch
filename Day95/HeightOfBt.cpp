class Solution{
    public:
    //Function to find the height of a binary tree.
    int height(struct Node* node)
    {
        //if node is null, we return 0.
        if (node==NULL)
            return 0;

        //else we call the recursive function, height for left and right 
        //subtree and choose their maximum. we also add 1 to the result
        //which indicates height of root of the tree.
        else
            return 1 + max(height(node->left), height(node->right));
    }    
};

// Recusrive:
class Solution{
    public:
    //Function to find the height of a binary tree.
    int height(struct Node* root){
        if(!root)return 0;
        else return 1 + max(height(root->left),height(root->right));
    }
};
