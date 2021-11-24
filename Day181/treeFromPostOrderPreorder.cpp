class Solution {
public:
    int idx;
    
    TreeNode* buildTree(vector<int>& in, vector<int>& po) {
        idx = in.size()-1;    
        return rt(in,po,0,in.size()-1);
    }
    
    TreeNode* rt(vector<int>& in,vector<int>& po,int i,int j)
    {
        if(i>j)return NULL;
        TreeNode* tn = new TreeNode(po[idx--]);
        if(i==j)return tn;
        
        int bnd = find(in.begin(),in.begin()+j,tn->val)-in.begin();
        
        tn->right = rt(in,po,bnd+1,j);
        tn->left = rt(in,po,i,bnd-1);
        
        return tn;
    }
};