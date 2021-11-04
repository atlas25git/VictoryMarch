class Solution
{
	public:
	
	void util(int u,vector<bool>& vis, vector<int>& s,vector<int> adj[])
	{
	    vis[u] = true;
	    for(auto x:adj[u])
	        if(!vis[x])util(x,vis,s,adj);
	    
	    //control would only come to this state only when all the nodes
	    //have been explored, and hence returns in dfs manner/
	    s.push_back(u);
	}
	
	//Function to return list containing vertices in Topological order. 
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    //dfs traversal and will store the nodes in the order of their finish time;
	    vector<bool> vis(V,0);
	    vector<int> s;
	    
	    for(int i=0;i<V;i++)
	        if(!vis[i])
	            util(i,vis,s,adj);
	    
	    reverse(s.begin(),s.end());
	    return s;
	}
};