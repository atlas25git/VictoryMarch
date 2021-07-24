// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends

class Solution 
{
    public:
	//Function to return a list containing the DFS traversal of the graph.
	vector<int>dfsOfGraph(int V, vector<int> adj[])
	{
	    vector<bool> vis(V,0);
	    vector<int> res;
	    for(int i=0;i<V;i++)
	        if(!vis[i])
	            util(i,adj,vis,V,res);
	   return res;
	}
	
	void util(int i,vector<int> adj[],vector<bool>& vis,int V,vector<int>& res)
	{
	    if(vis[i])return;
	    vis[i]=true;
	    res.push_back(i);
	    
	    for(auto x : adj[i])
	        if(!vis[x])
	            util(x,adj,vis,V,res);
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