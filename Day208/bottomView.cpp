class Solution {
  public:
    vector <int> bottomView(Node *root) {
        //basically the tree has to be travesred in a +1,-1
        //     0
        //    / \
        //   -1  1
        //   / \  \
        // -2  0  2
        //      /\
        //     -1  1
        //increments starting from the state 0
        //and the last occr for each column(level) element has to be stored.
        map<int,int> mp;
        queue<pair<Node*,int>> q;
        q.push({root,0});
        while(!q.empty())
        {
            auto t = q.front();
            q.pop();
            mp[t.second] = t.first->data;
            
            if(t.first->left)
                q.push({t.first->left,t.second-1});
            if(t.first->right)
                q.push({t.first->right,t.second+1});
        }
        
        // vector<pair<int,int>> ans;
        // for(auto x: mp)
        //     ans.push_back(x);
        // sort(ans.begin(),ans.end());
        vector<int> ans1;
        for(auto x: mp)
        {
            ans1.push_back(x.second);
        }
        return ans1;
    }
};