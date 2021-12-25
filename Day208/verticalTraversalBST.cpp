class SolutionDFS
{
    public:
    
    void fill(Node* root, map<int,vector<int>>& mp, int cr)
    {
        if(!root)return;
        mp[cr].push_back(root->data);
        fill(root->left,mp,cr-1);
        fill(root->right,mp,cr+1);
    }
    
    //Function to find the vertical order traversal of Binary Tree.
    vector<int> verticalOrder(Node *root)
    {
        if(!root)return vector<int>();
        map<int,vector<int>> mp;
        fill(root,mp,0);
        
        vector<int> res;
        for(auto it : mp)
        {
            for(auto x:it.second)
                res.push_back(x);
        }
        
        return res;
    }
};

class Solution
{
    public:
    //Function to find the vertical order traversal of Binary Tree.
    vector<int> verticalOrder(Node *root)
    {
        vector<int> ans;
        if(!root)return ans;
        map<int,vector<int>> mp;
        queue<pair<Node*,int>> q;
        q.push({root,0});
        
        while(!q.empty())
        {
            auto fr = q.front();
            q.pop();
            mp[fr.second].push_back(fr.first->data);
            if(fr.first->left)
                q.push({fr.first->left,fr.second-1});
            if(fr.first->right)
                q.push({fr.first->right,fr.second+1});
        }
        for(auto x: mp)
        {
            for(auto y: x.second)
                ans.push_back(y);
        }
        return ans;        
    }
};