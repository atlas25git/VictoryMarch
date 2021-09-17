class Solution{
    public:
    //Function to check whether all nodes of a tree have the value 
    //equal to the sum of their child nodes.
    int isSumProperty(Node *root)
    {
     if(!root || (!root->left && !root->right))return 1;
     else{
         int ld = root->left?root->left->data:0;
         int rd = root->right?root->right->data:0;
         
         if(root->data == ld+rd)
         {
             if(isSumProperty(root->left) && isSumProperty(root->right))
                return 1;
         }
     }
     return 0;
    }
};

class Solution{
    public:
    //Function to check whether all nodes of a tree have the value 
    //equal to the sum of their child nodes.
    int isSumProperty(Node *root)
    {
     if(!root || (!root->left && !root->right))return 1;
     
     int ld = root->left?root->left->data:0;
     int rd = root->right?root->right->data:0;     
     
     if(root->data == ld+rd)
        {
            if(isSumProperty(root->left)
                && isSumProperty(root->right))
                return 1;
        }
     
     return 0;
    }
};