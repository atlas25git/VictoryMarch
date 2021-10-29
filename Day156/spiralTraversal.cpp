class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(!root)return ans;
        stack<TreeNode*> a,b;
        bool flag = true;
        a.push(root);
        vector<int> temp;
        while(!a.empty())
        {
            TreeNode* curr = a.top();
            a.pop();
            temp.push_back(curr->val);
            if(flag){
                if(curr->left)b.push(curr->left);
                if(curr->right)b.push(curr->right);
            }
            else if(!flag)
            {
                if(curr->right)b.push(curr->right);
                if(curr->left)b.push(curr->left);
            }
            
            if(a.empty())
            {   ans.push_back(temp);
                temp.clear();
                swap(a,b);
                flag = !flag;
            }
        }
        return ans;
    }
};