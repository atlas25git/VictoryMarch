class Solution{
    public:
    //Function to check whether all nodes of a tree have the value 
    //equal to the sum of their child nodes.
    int isSumProperty(Node *r)
    {   int ld=0,rd=0;
        if(!r || (!r->left && !r->right))return 1;
        else
        {   
            ld = r->left!=NULL?r->left->data:0;
            rd = r->right!=NULL?r->right->data:0;
            if(r->data == ld+rd)
                    return (isSumProperty(r->left) && isSumProperty(r->right));
            else return 0;
        }
    }
};

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