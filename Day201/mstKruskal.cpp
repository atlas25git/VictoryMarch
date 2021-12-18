// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends

#define pb push_back
class Solution
{
	public:
	
	vector<int> parent,rank;
	
	void make_set(int i)
	{
	    parent[i]=i;
	    rank[i]=0;
	}
	
	int find_set(int i)
	{
	    if(parent[i] == i)
	        return i;
	   return parent[i] = find_set(parent[i]);
	    
	}
	
	
	void union_set(int i,int j)
	{
	    i = find_set(i);
	    j = find_set(j);
	    
	    //if(i == j) return;
	    if(rank[i] < rank[j])parent[i]=j;
	    else if(rank[j] < rank[i])parent[j]=i;
	    else if(rank[j]==rank[i])
	        parent[i]=j,rank[j]++;
	        //or parent[j]=i,rank[i]++;
	   
	}
	
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
	//using kruskal
    int spanningTreeKruskal(int V, vector<vector<int>> adj[])
    {
        //Approach:
        //1. Convert to edge list sorted by wts.
        //2. Fix the duplicacy.
        //3. Initiate rank, parent and set marks.
        //4. Define find_Set
        //5. Define union_set
        //7. Do a traversal of the edge list, if 2 vertices of the edge
        //   belong to diff sets include their cost, and thus union them.
        
        vector<vector<int>> edgeList;
        for(int i=0;i<V;i++)
            for(int j=0;j<adj[i].size();j++)
                {
                    vector<int> tmp;
                    vector<int> x =  adj[i][j];
                    tmp.pb(x[1]);
                    tmp.pb(min(i,x[0]));
                    tmp.pb(max(i,x[0]));
                    edgeList.pb(tmp);
                    tmp.clear();
                }
        
        //Sorting acc to edge wts
        sort(edgeList.begin(),edgeList.end());
        
        //Removing duplicacy:
        vector<vector<int>> graph;
        for(int i=0;i<edgeList.size();i+=2)
            graph.pb(edgeList[i]);
        
        //Initializing par,rank,set
        parent.resize(V);
        rank.resize(V);
        for(int i=0;i<V;i++)
            make_set(i);
        int cost = 0;
        
        for(auto edge : graph)
        {
            int u = edge[1];
            int v = edge[2];
            int wt = edge[0];
            
            if(find_set(u)!=find_set(v))
            {
                union_set(u,v);
                cost += wt;
            }
        }
        return cost;
    }
    
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        //converting adge list to adj matrix
        vector<vector<int>> am(V,vector<int>(V,0));
        for(int i=0;i<V;i++)
            for(int j=0;j<adj[i].size();j++)
                am[i][adj[i][j][0]] = adj[i][j][1];
        
        // for(auto x:am)
        // {
        //     for(auto y: x)
        //         cout<<y<<" ";
        //     cout<<endl;
        // }
        
        vector<int> dis(V,INT_MAX);
        vector<int> vis(V,0);
        dis[0] = 0;
        int res=0;
        for(int i=0;i<V;i++)
        {
            int u = -1;
            for(int v=0;v<V;v++)
            {
                if(!vis[v] && (u == -1 || dis[u]>dis[v]))
                    u = v;
            }
            vis[u] = true;
            res += dis[u];
            
            for(int v = 0;v<V;v++)
            {
                if(am[u][v]  && dis[v] > am[u][v])
                    dis[v] = am[u][v];
            }
        }
        
        // for(auto x: dis)
        //     cout<<x<<" ";
        // cout<<"\n";
        
        return res;
    }
};


// { Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        
        Solution obj;
    	cout << obj.spanningTree(V, adj) << "\n";
    }

    return 0;
}

  // } Driver Code Ends