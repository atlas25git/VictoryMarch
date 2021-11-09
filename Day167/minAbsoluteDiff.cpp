class Solution
{
    public:
    //Function to find the least absolute difference between any node
	//value of the BST and the given integer.
    int minDiff(Node *root, int k)
    {
        if(!root)return k;
        int ans=INT_MAX;
        fill(root,k,ans);
        return ans;
    }
    
    void fill(Node* root,int k,int& ans)
    {
        if(!root)return;
        
        if(root->data == k)
        {
            ans =0;
            return;
        }
        ans = min(ans,abs(root->data-k));
        
        if(root->data>k)
        //pruning the right search space as the absolute diff will 
        //only increase from what we've
            fill(root->left,k,ans);
        else fill(root->right,k,ans);
    }
};
