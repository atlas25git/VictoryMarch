class Solution
{
    public:
    //Function to find the least absolute difference between any node
	//value of the BST and the given integer.
    
    void mdu(Node* root,int& md,int k)
    {
        if(!root)return;
        if(root->data == k)
        {
            md=0;
            return;
        }
        
        md = min(md,abs(root->data - k));
        
        if(root->data > k)
            mdu(root->left,md,k);
        else mdu(root->right,md,k);
        
    }
    
    int minDiff(Node *root, int K)
    {
        int md=INT_MAX;
        mdu(root,md,K);
        return md;
    }
};