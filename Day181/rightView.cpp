class Solution
{   
    vector<int> ans;
    public:
    //Function to return list containing elements of right view of binary tree.
    vector<int> rightView(Node *root)
    {
       int ml = -1;
       fill(root,ml,0);
       return ans;
    }
    
    void fill(Node* root,int& ml,int lvl)
    {
        if(!root)return;
        if(lvl>ml)
            ans.push_back(root->data),ml++;
        fill(root->right,ml,lvl+1);
        fill(root->left,ml,lvl+1);
    }
};