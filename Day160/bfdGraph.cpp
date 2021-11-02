class Solution {
  public:
    // Function to return Breadth First Traversal of given graph.
    vector<int> bfsOfGraph(int V, vector<int> adj[]) {
        vector<int> res;
        queue<int> q({0});
        vector<bool> vis(V);
        vis[0] = 1;
        
        while(!q.empty())
        {
            int t = q.front();
            q.pop();
            res.push_back(t);
            for(auto x: adj[t])
                {
                    if(!vis[x])
                        vis[x] = 1,
                        q.push(x);
                }
        }
        
        return res;
    }
};