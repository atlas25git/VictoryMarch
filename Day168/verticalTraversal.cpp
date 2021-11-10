class Solution
{
    public:
    //Function to find the vertical order traversal of Binary Tree.
    vector<int> verticalOrder(Node *root)
    {
        //we must use level order traversal as we need to print
        //the higher level nodes prior to others, hence in/pre/post won't help 
        //due to the duress of order of nodes on same level
        if(!root)return vector<int>();
        
        queue<pair<int,Node*>> q;
        q.push({0,root});
        vector<int> res;
        map<int,vector<int>> mp;
        while(!q.empty())
        {
            auto t = q.front();
            q.pop();
            mp[t.first].push_back(t.second->data);
            
            if(t.second->left)
            {
                q.push({t.first-1,t.second->left});
                
            }
            if(t.second->right)
            {
                q.push({t.first+1,t.second->right});
            }
            
        }
        for(auto x:mp)
        {
            for(auto t:x.second)res.push_back(t);
        }
        return res;
    }
};
