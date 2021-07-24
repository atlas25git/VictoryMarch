// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution
{
    public:
    
    bool util(int i,vector<bool>& vis,vector<bool>& currPath,vector<int> adj[])
    {   
        //node entered
        vis[i]=true;
        currPath[i] = true;
        
        for(int j=0;j<adj[i].size();j++)
            {
                if(currPath[adj[i][j]])return true;
                else if(!vis[adj[i][j]])
                {
                    if(util(adj[i][j],vis,currPath,adj))
                            return true;
                }
            }
            currPath[i]=false;
            return false;

    }
	//Function to detect cycle in a directed graph.
	bool isCyclic(int V, vector<int> adj[]) 
	{   
	   	//in directed graph the mere str of cycle doesn't accredits for its presence
	   	//we need to check if there's a back edge pointing to the nodes in curr path
	   	vector<bool> vis(V,0);
	   	vector<bool> currPath(V,0);
	   	
	   	//performing a dfs
	   	for(int i=0;i<V;i++)
	   	{
	   	    if(!vis[i])
	   	        if(util(i,vis,currPath,adj))return true;
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


  // { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution
{
    public:
    
    bool util(int u,vector<bool>& vis,vector<bool>& cP,vector<int> adj[])
    {
        vis[u]=true;
        cP[u]=true;
        for(int i=0;i<adj[u].size();i++)
            {
                if(cP[adj[u][i]])return true;
                else if(!vis[adj[u][i]])
                {
                    if(util(adj[u][i],vis,cP,adj))
                        return true;
                }
            }
        cP[u]=false;
        return false;
    }
    
	//Function to detect cycle in a directed graph.
	bool isCyclic(int V, vector<int> adj[]) 
	{
	   	vector<bool> vis(V,0);
	   	vector<bool> cP(V,0);
	   	for(int i=0;i<V;i++)
	   	    if(!vis[i])
	   	        if(util(i,vis,cP,adj))
	   	            return true;
	   	 
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