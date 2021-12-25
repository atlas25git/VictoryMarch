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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> ans;
        if(!root)return ans;
        queue<pair<TreeNode*,pair<int,int>>> q;
        q.push({root,{0,0}});
        map<pair<int,int>,vector<int>> mp;
        
        while(!q.empty())
        {
            auto fr = q.front();
            q.pop();
            mp[fr.second].push_back(fr.first->val);
            if(fr.first->left)
                q.push({fr.first->left,{fr.second.first-1,fr.second.second+1}});
            if(fr.first->right)
                q.push({fr.first->right,{fr.second.first+1,fr.second.second+1}});
        }
        for(auto &x: mp)
        {
            if(x.second.size() > 1)
                    sort(x.second.begin(),x.second.end());
        }
        
        // for(auto &x: mp)
        // {   cout<<x.first.first<<" "<<x.first.second<<" \n";
        //     for(auto y: x.second)
        //         cout<<y<<" ";
        //  cout<<"\n";
        // }
        
        map<int,vector<int>> mp1;
        
        for(auto x: mp)
        {
            if(mp1.count(x.first.first))
            {
                
                for(auto y : x.second)
                        mp1[x.first.first].push_back(y);
            }
            else
                mp1[x.first.first] = x.second;
        }
        for(auto x: mp1)
            ans.push_back(x.second);
        
        return ans;
    }
};