class Solution {
  public:
    // Function to return a list containing the DFS traversal of the graph.
    vector<int> dfsOfGraph(int V, vector<int> adj[]) {
        vector<int> res;
        vector<bool> vis(V,0);
        
        for(int i=0;i<V;i++)
            if(!vis[i])
                dfs(i,vis,res,adj);
        
        return res;
        
    }
    
    void dfs(int i,vector<bool>& vis,vector<int>& res,vector<int> adj[])
    {
        vis[i]=1;
        res.push_back(i);
        
        for(auto x: adj[i])
            if(!vis[x])
            dfs(x,vis,res,adj);
        
        return;
    }
};