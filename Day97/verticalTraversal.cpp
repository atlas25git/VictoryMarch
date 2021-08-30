class Solution
{
    public:
    //Function to find the vertical order traversal of Binary Tree.
    vector<int> verticalOrder(Node *root)
    {
        vector<int> res;
        map<int,vector<int>> m;
        queue<pair<Node*,int>> q;
        q.push({root,0});
        
        while(!q.empty())
        {
            pair<Node*,int> t=q.front();
            m[t.second].push_back(t.first->data);
            q.pop();
            if(t.first->left)
                {
                    q.push({t.first->left,t.second-1});
                }
            if(t.first->right)
                {
                    q.push({t.first->right,t.second+1});
                }
        }
        
        for(auto it = m.begin();it!=m.end();it++)
        {
            
            for(auto x:it->second)
                res.push_back(x);
            
        }

        return res;
    }
};
