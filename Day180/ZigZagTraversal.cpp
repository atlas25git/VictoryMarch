class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(!root)return ans;
        queue<TreeNode*> q;
        q.push(root);
        int parity = 0;
        while(!q.empty())
        {   
            int sz = q.size();
            vector<int> tmp;
            while(sz--)
            {
                TreeNode* t = q.front();
                q.pop();
                tmp.push_back(t->val);
                if(t->left)q.push(t->left);
                if(t->right)q.push(t->right);
            }
            if(parity&1)
                    reverse(tmp.begin(),tmp.end());
            ans.push_back(tmp);
            parity++;
            tmp.clear();
        }
        return ans;
    }
};