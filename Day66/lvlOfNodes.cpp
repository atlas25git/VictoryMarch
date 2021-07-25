// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution
{
	public:
	
	int bfs(vector<bool>& vis,vector<int> lvl,vector<int> adj[],int X,int V)
	{
	    if(X>=V)return -1;
	    
	    int c = 0;
	    queue<int> q;
	    q.push(c);
	    vis[c]=true;
	    lvl[c]=0;
	    while(!q.empty())
	    {
	        int t = q.front();
	        q.pop();
	        for(auto x : adj[t])
	        {
	            if(!vis[x])
	            {
	                lvl[x]=lvl[t]+1;
	                vis[x]=true;
	                q.push(x);
	            }
	        }
	    }
	    
	    
	    return lvl[X];
	}
	
	//Function to find the level of node X.
	int nodeLevel(int V, vector<int> adj[], int X) 
	{
	    vector<bool>vis(V,0);
	    vector<int>lvl(V,0);
	    return bfs(vis,lvl,adj,X,V);
	}
};

// { Driver Code Starts.


int main()
{
    
    int t;
    cin >> t;
    while(t--)
    {
    	int V, E, X;
    	cin >> V >> E;

    	vector<int> adj[V];

    	for(int i = 0; i < E; i++)
    	{
    		int u, v;
    		cin >> u >> v;
    		adj[u].push_back(v);
    		adj[v].push_back(u);
    	}
    	cin>>X;

    	Solution obj;
    	cout << obj.nodeLevel(V, adj, X) << "\n";
    }

    return 0;
}

  // } Driver Code Ends