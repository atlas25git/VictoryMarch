// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution 
{
    public:
	//Function to return a list containing the DFS traversal of the graph.
	
	void dfs(vector<int> (adj)[], int i, vector<int> (&res),bool* vis)
	{
	    if(vis[i])return;
	    
	    vis[i] = true;
	    res.push_back(i);
	   
	   for(auto x: adj[i])
	   {
	       if(!vis[x])
	            dfs(adj,x,res,vis);
	   }
	    
	    
	}
	
	vector<int>dfsOfGraph(int V, vector<int> adj[])
	{
	    vector<int> res;
	    bool vis[V] = {0};
	    
	    //make visited array
	    //make dfs util, that'd mark present node visited
	    //and would recursively mark for the nodes adj. to it
	    //the loop in the main fn would ensure that no unvisited 
	    //vertex remains
	    
	    for(int i=0;i<V;i++)
	    {
	        if(!vis[i]){
	            dfs(adj,i,res,vis);
	        }
	    }
	    return res;
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
    		adj[v].push_back(u);
    	}
        // string s1;
        // cin>>s1;
        Solution obj;
        vector<int>ans=obj.dfsOfGraph(V, adj);
        for(int i=0;i<ans.size();i++){
        	cout<<ans[i]<<" ";
        }
        cout<<endl;
	}
	return 0;
}  // } Driver Code Ends