/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int idx;
    TreeNode* buildTree(vector<int>& in, vector<int>& po) {
        idx = in.size()-1;
        return rt(in,po,0,in.size()-1);
    }
    
    TreeNode* rt(vector<int>&in,vector<int>&po,int i,int j)
    {
        if(i>j)return NULL;
        
        TreeNode* tn = new TreeNode(po[idx--]);
        if(i==j)return tn;
        
        int boundary = find(in.begin(),in.end(),tn->val) - in.begin();
        
        tn->right = rt(in,po,boundary+1,j);
        tn->left = rt(in,po,i,boundary-1);
        return tn; 
    }
};