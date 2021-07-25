// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends



class Solution
{
	public:
	
	void dfsTopo(int i,stack<int> &s,vector<int> adj[],vector<bool> &vis)
	{
	    vis[i]=true;
	    
	    for(auto x:adj[i])
	    {
	        if(!vis[x])
	            dfsTopo(x,s,adj,vis);
	        
	    }
	    s.push(i);
	}
	
	//Function to return list containing vertices in Topological order. 
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    //we will apply dfs and store the order in a stack
	    //we'll store the stack elements by popping in a vector;
	    vector<bool> vis(V,false);
	    stack<int> s;
	    for(int i=0;i<V;i++)
	    {
	        if(!vis[i])
	        {
	            dfsTopo(i,s,adj,vis);
	        }
	    }
	    
	    vector<int> res;
	    while(!s.empty()){
	        
	        res.push_back(s.top());
	        //cout<<s.top()<<"\n";
	        s.pop();
	    }
	    //for(auto x:res)cout<<x<<"\n";
	    return res;
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