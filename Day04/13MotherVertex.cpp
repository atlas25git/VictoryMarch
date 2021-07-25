// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends



class Solution 
{
    public:
    
    void dfs(int i,vector<int> adj[],vector<bool> &vis)
    {
        vis[i] = true;
        
        for(auto x: adj[i])
        {
            if(!vis[x])
                dfs(x,adj,vis);
        }
        return;
    }
    
    //Function to find a Mother Vertex in the Graph.
	int findMotherVertex(int V, vector<int>adj[])
	{
	    //we basicall do rounds of dfs marking intially the
	    //vertex that we used as source
	    //while looping intially if call is made more than once
	    //then it proves for the ones earlier than that those vertices
	    //weren't able to be on a path that'd visit all others
	    //therefore the last one is the one for contention
	    //we check the criteria again by setting all visited count to 
	    //false and calling dfs again, if any remains un visited then
	    //even this ain't mother vertex
	    
	    //int r = adj.size();
	    //int c = adj[0].size();
	    
	    vector<bool>vis(V,false);
	    int v=-1;
	    for(int i=0;i<V;i++)
	    {
	      if(!vis[i])
	        {
	            dfs(i,adj,vis);
	            v=i;
	        }
	    }
	    
	    vis.assign(V,false);
	    
	    dfs(v,adj,vis);
	    
	    for(auto x: vis)
	        if(!x)
	            return -1;
	            
	    return v;
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
		}
		Solution obj;
		int ans = obj.findMotherVertex(V, adj);
		cout << ans <<"\n";
	}
	return 0;
}  // } Driver Code Ends