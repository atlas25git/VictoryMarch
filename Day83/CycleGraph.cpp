class Solution 
{
    public:
    //Function to detect cycle in an undirected graph.
	
	bool util(int u, int v,vector<bool>& vis, vector<int>adj[])
	{
	    vis[u]=true;
	    
	    for(auto x: adj[u])
	        {
	            if(x == v)continue;
	            if(vis[x])return true;
	            else if(util(x,u,vis,adj))return true;
	        }
	}
	
	bool isCycle(int V, vector<int>adj[])
	{
	    //we're gonna do a dfs traversal here, returning true
	    //if a vertex contains an edge to some already visited vertex, except it's parent
	    vector<bool>vis(V,0);
	    for(int i=0;i<V;i++)
	        if(!vis[i])
	           if(util(i,-1,vis,adj)) return true;
	   return false;
	}
};



bool util(int u,int v, vector<int> adj[],vector<bool>& vis)
    {
        if(vis[u])return true;
        
        vis[u] = true;
        
        for(auto x : adj[u])
        {
            if(x==v)continue;
            if(vis[x])return true;
            if(util(x,u,adj,vis))
                return true;
        }
    }
    
    //Function to detect cycle in an undirected graph.
	bool isCycle(int V, vector<int>adj[])
	{
	   vector<bool>vis(V,0);
	   for(int i=0;i<V;i++)
	    {
	        if(!vis[i])
	            if(util(i,-1,adj,vis))
	                //as some vertices would not be a part of the cycles,
	                //at intermediate levels it'd return 0 too;
	                return true;
	    }
	    
	    return false;
	}