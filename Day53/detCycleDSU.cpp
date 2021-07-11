// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution
{   
    int find(int x,vector<int>par)
    {
        if(x==par[x])return x;
        return find(par[x],par);
    }
    
    void unionn(int x,int y,vector<int> &par,vector<int> &rank)
    {
        int xp = find(x,par);
        int yp = find(y,par);
        
        if(rank[xp]<rank[yp])par[xp]=yp;
        else if(rank[yp]<rank[xp])par[yp]=xp;
        else{
            par[yp]=xp;
            rank[xp]++;
        }
    }
    
    
    public:
    //Function to detect cycle using DSU in an undirected graph.
	int detectCycle(int V, vector<int>adj[])
	{
	    vector<int> parent(V);
	    vector<int> rank(V,0);
	    map<pair<int,int>,int> mp;
	    
	    for(int i=0;i<V;i++)
	    {
	        parent[i]=i;
	        rank[i]=1;
	    }
	    
	    for(int u=0;u<V;u++)
	    {
	        for(auto v : adj[u])
	            {
	                if(mp.find({u,v})!=mp.end() || mp.find({v,u})!=mp.end())
	                    continue;
	               mp[{u,v}]=1;
                   //both the vertices of a same edge if correspond to same set, hence either a self
                   //loop or some extended cycle/
	               int x = find(u,parent);
	               int y = find(v,parent);
	               if(x==y)return 1;
	               unionn(u,v,parent,rank);
	            }
	    }
	    return 0;
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
		int ans = obj.detectCycle(V, adj);
		cout << ans <<"\n";	}
	return 0;
}  // } Driver Code Ends