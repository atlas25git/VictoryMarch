// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


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

// { Driver Code Starts.

/*  Function to check if elements returned by user
*   contains the elements in topological sorted form
*   V: number of vertices
*   *res: array containing elements in topological sorted form
*   adj[]: graph input
*/
int check(int V, vector <int> &res, vector<int> adj[]) {
    vector<int> map(V, -1);
    for (int i = 0; i < V; i++) {
        map[res[i]] = i;
    }
    for (int i = 0; i < V; i++) {
        for (int v : adj[i]) {
            if (map[i] > map[v]) return 0;
        }
    }
    return 1;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N, E;
        cin >> E >> N;
        int u, v;

        vector<int> adj[N];

        for (int i = 0; i < E; i++) {
            cin >> u >> v;
            adj[u].push_back(v);
        }
        
        Solution obj;
        vector <int> res = obj.topoSort(N, adj);

        cout << check(N, res, adj) << endl;
    }
    
    return 0;
}  // } Driver Code Ends