// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends



class Solution
{
	public:
	//Function to find the level of node X.
	int nodeLevel(int V, vector<int> adj[], int X) 
	{
	    //Apply bfs, at every push that happens
	    //update the level of the pushed node with curr+1;
	    
	    if(X>=V) return -1;
	    
	    vector<bool> vis(V,false);
	    vector<int> lvl(V,0);
	    queue<int> q;
	    q.push(0);
	    vis[0]=false;
	    
	    while(!q.empty())
	    {
	        int x = q.front();
	        q.pop();
	        
	        for(auto y:adj[x])
	        {
	            if(!vis[y])
	                {
	                    q.push(y);
	                    vis[y]=true;
	                    lvl[y]=lvl[x]+1;
	                    //cout<<y<<" "<<lvl[y]<<"\n";
	                    
	                }
	        }
	    }
	    return lvl[X];
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