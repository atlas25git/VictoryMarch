class Solution 
{   
    public:
    
    void dfs(int u,vector<int> adj[],vector<bool>& vis)
    {
        vis[u]=true;
        for(auto x: adj[u])
            if(!vis[x])
                dfs(x,adj,vis);
    }
    
    //Function to find a Mother Vertex in the Graph.
	int findMotherVertex(int V, vector<int>adj[])
	{
	    //basically the idea here is that we are applying dfs from each V
	    //and we store the last vertex that was used in dfs call
	    //make a note that in a connected graph one vertex would have filled it
	    //entirely
	    //from the stored vertex we run a dfs again, if not all are vis we'll return 
	    //false;
	    //proof since v is the last vertex that marked all the nodes visited, hence
	    //the ones before v would be in no sense a mother vertex
	    vector<bool> vis(V,0);
	    int lv;
	    
	    for(int i=0;i<V;i++)
	        if(!vis[i])
	            dfs(0,adj,vis),
	            lv=i;
	            
	   vis.assign(V,0);
	   dfs(lv,adj,vis);
	   for(auto i:vis)
	        if(!i)
	            return -1;
	   return lv;
	}

};