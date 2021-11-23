#define ist isSameTree
class Solution {
    
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(!p && !q)return true;
        if(!p || !q)return false;
        return (p->val == q->val) && ist(p->left,q->left) && ist(p->right,q->right);
    }
};