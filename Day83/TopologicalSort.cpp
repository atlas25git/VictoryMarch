class Solution
{
	public:
	
	void util(int u,vector<bool>& vis, stack<int>& s,vector<int> adj[])
	{
	    vis[u] = true;
	    for(auto x:adj[u])
	        if(!vis[x])util(x,vis,s,adj);
	        
	    s.push(u);
	}
	
	//Function to return list containing vertices in Topological order. 
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    //dfs traversal and will store the nodes in the order of their finish time;
	    vector<bool> vis(V,0);
	    stack<int> s;
	    vector<int> topo;
	    
	    for(int i=0;i<V;i++)
	        if(!vis[i])
	            util(i,vis,s,adj);
	    
	    while(!s.empty())
	    {
	        topo.push_back(s.top());
	        s.pop();
	    }
	    return topo;
	}
};



class Solution
{
	public:
	
	void util(int u,vector<bool>& vis,stack<int>& s,vector<int> adj[])
	{
	    vis[u]=true;
	    
	    for(auto v : adj[u])
	        if(!vis[v])
	            util(v,vis,s,adj);
	    
	    //call for a node exits
	    s.push(u);
	}
	
	//Function to return list containing vertices in Topological order. 
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    //the idea is to apply a simple dfs trasversal
	    //then when we leave the call for a node store that in
	    //a referenced array, it's reverse will be topological sort
	    
	    vector<bool> vis(V,0);
	    stack<int> s;
	    
	    for(int i=0;i<V;i++)
	        if(!vis[i])
	            util(i,vis,s,adj);
	            
	    vector<int> topo;
	    while(!s.empty())
	    {
	        topo.push_back(s.top());
	        s.pop();
	    }
	    
	    return topo;
	    
	}
};