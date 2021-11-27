class Solution
{
    public:
    //Function to return a list of nodes visible from the top view 
    //from left to right in Binary Tree.
    vector<int> topView(Node *root)
    {
        map<int,int> mp;
        queue<pair<Node*,int>> q;
        q.push({root,0});
        while(!q.empty())
        {
            auto t = q.front();
            q.pop();
            //basically ignoring the nodes lying on a same
            //vertical level.
            if(mp.count(t.second) == 0)
                mp[t.second] = t.first->data;
            
            if(t.first->left)
                q.push({t.first->left,t.second-1});
            if(t.first->right)
                q.push({t.first->right,t.second+1});
        }
        vector<int> ans;
        for(auto x: mp)
            ans.push_back(x.second);
        return ans;
    }
};
