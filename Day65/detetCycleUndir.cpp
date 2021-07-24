// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution 
{
    public:
    
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
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int V, E;
		cin >> V >> E;
		vector<int>adj[V];
		for(int i = 0; i < E; i++){
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		Solution obj;
		bool ans = obj.isCycle(V, adj);
		if(ans)
			cout << "1\n";
		else cout << "0\n";
	}
	return 0;
}  // } Driver Code Ends