class Solution
{
	public:
	stack<int> s;
	
	void transpose(int V,vector<int> adj[],vector<int> Tadj[])
	{
	    for(int u=0;u<V;u++)
	        for(auto v: adj[u])
	            Tadj[v].push_back(u);
	           
	}
	
	void dfs(vector<int> adj[],vector<bool>& vis,int u)
	{
	    vis[u]=true;
	    for(auto v:adj[u])
	    {
	        if(!vis[v])
	            dfs(adj,vis,v);
	    }
	}
	
	void fillO(vector<int> adj[], vector<bool>& vis, int u)
	{
	    vis[u] = true;
	    for(auto v:adj[u])
	        if(!vis[v])
	            fillO(adj,vis,v);
	   s.push(u);
	}
	
	//Function to find number of strongly connected components in the graph.
    int kosaraju(int V, vector<int> adj[])
    {
        vector<bool> vis(V,0);
        
        //Topological sort:
        for(int i=0;i<V;i++)
            if(!vis[i])
                fillO(adj,vis,i);
                
        //Transposing the adj list
        vector<int> Tadj[V];
        transpose(V,adj,Tadj);
        
        //Re instantiating the vis array
        vis.clear();
        vis.resize(V,false);
        // fill(vis.begin(),vis.end(),false);
        int count=0;
        
        while(!s.empty())
        {
            int t = s.top();
            s.pop();
            
            if(!vis[t]){
                dfs(Tadj,vis,t);
                count++;
            }
        }
        
        return count;
        
    }
};
