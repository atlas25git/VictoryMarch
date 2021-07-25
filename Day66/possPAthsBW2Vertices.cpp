// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution 
{
    public:
    
    void util(vector<bool>& vis,vector<int> adj[],int src,int dest,int& pc)
    {
        vis[src]=true;
        if(src==dest)pc++;
        else {
            for(auto x : adj[src])
             if(!vis[x])
                util(vis,adj,x,dest,pc);
        }
        
        vis[src]=false;
    }
    
    
    //Function to count paths between two vertices in a directed graph.
	int countPaths(int V, vector<int> adj[], int source, int destination)
	{
	    //the idea here is simple, we do a  dfs trsvesra
	    //if we reach dest, then we increment the pc
	    //when we exit a node we mark it unvisited for other paths
	    vector<bool> vis(V,0);
	    int pc=0;
	    util(vis,adj,source,destination,pc);
	    return pc;
	}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int V, E;
    	cin >> V >> E;
    	vector<int> adj[V];
    	for(int i = 0; i < E; i++)
    	{
    		int u, v;
    		cin >> u >> v;
    		adj[u].push_back(v);
    		// adj[v].push_back(u);
    	}
    	int source, destination;
    	cin >> source >> destination;
        Solution obj;
        cout<<obj.countPaths(V, adj,source,destination)<<endl;
	}
	return 0;
}  // } Driver Code Ends