// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends



class Solution 
{
    public:
    void pathDFS(int u,int v,vector<int> adj[],vector<bool> &vis,int &paths)
    {
        vis[u]=true;
        if(u==v) paths++;
        
        else
        {
        for(auto x: adj[u])
        {
            if(!vis[x])
                pathDFS(x,v,adj,vis,paths);
            
        }
        }
        vis[u] = false;
        return;
    }
    
    //Function to count paths between two vertices in a directed graph.
	int countPaths(int V, vector<int> adj[], int source, int destination)
	{
	    //since there is no cycle in the graph
	    //we can do a DFS traversal of the graph 
	    //incrementing the path count everytime destination is
	    //reached
	    //once we find out that we've reached destination
	    //we increment count of paths, and mark the vertex as unvisited;
	    int paths = 0;
	    vector<bool> vis(V,false);
	    
	    //for(int i=0;i<V;i++)
	    //{
	        //if(!vis[i])
	            pathDFS(source,destination,adj,vis,paths);
	            return paths;
	    //}
	    
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