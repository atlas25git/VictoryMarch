class Solution
{
    public:
    //Function to return a list of nodes visible from the top view 
    //from left to right in Binary Tree.
    vector<int> topView(Node *root)
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
            vector<int> ans = it->second;
            
                res.push_back(ans[0]);
            
        }

        return res;
    }

};