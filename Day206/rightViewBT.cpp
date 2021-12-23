class Solution
{   vector<int> res;
    public:
    //Function to return list containing elements of right view of binary tree.
    vector<int> rightView(Node *root)
    {
       int myLvl = -1;
       fill(root,0,myLvl);
       return res;
    }
    
    void fill(Node* root,int lvl,int& myLvl)
    {
        if(!root)return;
        if(myLvl<lvl)
            res.push_back(root->data),
            myLvl++;
        fill(root->right,lvl+1,myLvl);
        fill(root->left,lvl+1,myLvl);
    }
    
};