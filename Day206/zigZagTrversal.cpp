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
    // vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
    //     vector<vector<int>> ans;
    //     if(!root)return ans;
    //     queue<TreeNode*> q;
    //     q.push(root);
    //     int parity = 0;
    //     while(!q.empty())
    //     {   
    //         int sz = q.size();
    //         vector<int> tmp;
    //         while(sz--)
    //         {
    //             TreeNode* t = q.front();
    //             q.pop();
    //             tmp.push_back(t->val);
    //             if(t->left)q.push(t->left);
    //             if(t->right)q.push(t->right);
    //         }
    //         if(parity&1)
    //                 reverse(tmp.begin(),tmp.end());
    //         ans.push_back(tmp);
    //         parity++;
    //         tmp.clear();
    //     }
    //     return ans;
    // }
    
        vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
            vector<vector<int>> ans;
            if(!root)return ans;
            stack<TreeNode*> s1,s2;
            bool flag = 1;
            s1.push(root);
            vector<int> temp;
            while(!s1.empty())
            {
                TreeNode* t = s1.top();
                s1.pop();
                temp.push_back(t->val);
                
                if(flag)
                {
                    if(t->left)s2.push(t->left);
                    if(t->right)s2.push(t->right);
                }
                else if(!flag)
                {
                    if(t->right)s2.push(t->right);
                    if(t->left)s2.push(t->left);
                }
                
                if(s1.empty())
                {
                    ans.push_back(temp);
                    temp.clear();
                    swap(s1,s2);
                    flag = !flag;
                }
            }
            return ans;
        }

};