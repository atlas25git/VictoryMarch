class Solution 
{
    public:
    
    void util(vector<bool>& vis,vector<int> adj[],int src,int dest,int& pc)
    {
        vis[src]=true;
        if(src==dest)pc++;
        else
            {
                for(auto x : adj[src])
                    if(!vis[x])
                        util(vis,adj,x,dest,pc);
            }
        // backtracking
        vis[src]=false;
    }
    
    
    //Function to count paths between two vertices in a directed graph.
	int countPaths(int V, vector<int> adj[], int source, int destination)
	{
	    //the idea here is simple, we do a  dfs trsvesral
	    //if we reach dest, then we increment the pc
	    //when we exit a node we mark it unvisited for other paths
	    //through other vertices and saving them from getting stymied
	    vector<bool> vis(V,0);
	    int pc=0;
	   //for(int i=0;i<V;i++)
	   //     if(!vis[i])
	        util(vis,adj,source,destination,pc);
	        
	   //it is exploring all the paths in just one traversal as, we mark the vis
	   //vertices unvisited while returning thus giving it opportuninty for subsequent 
	   //calls
	   //Except the src all other vertices are explored for possible paths through them.
	   //as in for second vertex in src's adj list, we call through one, and when that's complete
	   //we mark it unvisited while returning, thus leaving scope for other paths to be looked up.
	    return pc;///V;
	}
};