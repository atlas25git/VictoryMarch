// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends



class Solution 
{
    public:
    //Function to detect cycle in an directed graph.
    //we need to use rec stack here due to the fact that
    //in an directed graph there could be 2 direction unlike in undirected
    //such that it might be the case as a->b<-c, here undirected algo would give 
    //yes even though it ain't the case
    bool cycleUtil(int x, vector<bool> &recst, vector<int> adj[],vector<bool> &vis)
    {
      if(!vis[x]){
          
        vis[x]=true;
        recst[x]=true;
        
        for(int i=0;i<(int)adj[x].size();i++)
        {
            if(!vis[adj[x][i]] && cycleUtil(adj[x][i],recst,adj,vis) )
                return true;
           else if(recst[adj[x][i]])
            return true;
        }
      }
      
      recst[x] = false;
      return false;
        
    }
    
	bool isCyclic(int V, vector<int>adj[])
	{
	    vector<bool> vis(V,false);
	    vector<bool> recst(V,false);
	    for(int i=0;i<V;i++)
	    {
	            if(!vis[i])
	            {
	                //vis[i]=true;
	                if(cycleUtil(i,recst,adj,vis))
	                return true;
	                
	            }
	    }
	    return false;
	}
};

// { Driver Code Starts.


int main()
{
    
    int t;
    cin >> t;
    while(t--)
    {
    	int V, E;
    	cin >> V >> E;

    	vector<int> adj[V];

    	for(int i = 0; i < E; i++)
    	{
    		int u, v;
    		cin >> u >> v;
    		adj[u].push_back(v);
    	}

    	Solution obj;
    	cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}

  // } Driver Code Ends