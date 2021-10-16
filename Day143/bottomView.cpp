class Solution {
  public:
    vector <int> bottomView(Node *root)
{   
   map<int,int> mp;    
   vector<int> res;
   queue<pair<Node*,int>> q;
   q.push({root,0});
   while(!q.empty())
   {
       pair<Node*,int> t = q.front();
       //cout<<t.second<<" "<<mp[t.second]<<endl;
       mp[t.second] = t.first->data;
       //here we're are storing the last occr in the line traversed
       //in our map
       
       //cout<<t.second<<" "<<mp[t.second]<<endl;
       //cout<<":::::"<<endl;
       q.pop();
       if(t.first->left)
            q.push({t.first->left,t.second-1});
        if(t.first->right)
            q.push({t.first->right,t.second+1});
   }
    for(auto x:mp)
        res.push_back(x.second);
   return res;
    }
};