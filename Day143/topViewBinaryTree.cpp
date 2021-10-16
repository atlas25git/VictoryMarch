class Solution
{
    public:
    //Function to return a list of nodes visible from the top view 
    //from left to right in Binary Tree.
    vector<int> topView(Node *root){
        vector<int> ans;
        
        if(!root)return ans;
        Node* tmp  = NULL;
        queue<pair<Node*,int>> q;
        map<int,int> mp;
        
        q.push({root,0});
        while(!q.empty())
        {
            tmp = q.front().first;
            int d = q.front().second;
            q.pop();
            
            if(!mp.count(d))
                mp[d] = tmp->data;
            
            if(tmp->left)
                q.push({tmp->left,d-1});
            if(tmp->right)
                q.push({tmp->right,d+1});
        }
        
        for(auto x: mp)
            ans.push_back(x.second);
        return ans;
    }
};