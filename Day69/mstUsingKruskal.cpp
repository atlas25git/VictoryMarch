// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends

#define pb push_back
class Solution
{
	public:
	
	vector<int> parent,rank;
	
	void make_set(int v)
	{
	    parent[v] = v;
	    rank[v] = 0;
	}
	
	int find_set(int v)
	{
	    if(v==parent[v])
	        return v;
	   //path compression
	   return parent[v] = find_set(parent[v]);
	}
	
	void union_sets(int a, int b)
	{
	    a = find_set(a);
	    b = find_set(b);
	    if(a!=b)
	    {
	        if(rank[a]<rank[b])
	            swap(a,b);
	           parent[a]=b;
	           if(rank[a] == rank[b])
	                rank[b]++;
	    }
	}
	
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        //making a wtd edge list
        vector<vector<int>> res;
        for(int i=0;i<V;i++)
            {
                vector<int> temp;
                for(int j=0;j<adj[i].size();j++)
                {
                    vector<int> x = adj[i][j]; //just for the sake of typing
                    temp.pb(x[1]);
                    temp.pb(min(i,x[0]));
                    temp.pb(max(i,x[0]));
                    res.pb(temp);
                    temp.clear();
                    
                }
            }
            
            sort(res.begin(),res.end());
            vector<vector<int>> graph;
            //since ind adj list rep, we had i->j  and j->i
            //hence our res would contain duplicate edges
            
            for(int i=0;i<res.size();i+=2)
            {
                graph.pb(res[i]);
            }
            
            int cost =0;
            parent.resize(V);
            rank.resize(V);
            for(int i=0;i<V;i++)
                make_set(i);
            
            for(auto e : graph)
            {
                if(find_set(e[1]) != find_set(e[2]))
                    cost += e[0],
                    union_sets(e[1],e[2]);
            }
            
            return cost;
        
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


class Solution{
	public:
	
	vector<int> parent, rank;

    void make_set(int v) {
        parent[v] = v;
        rank[v] = 0;
    }
    
    //Function to find set of an element v (using path compression technique).
    int find_set(int v) {
        if (v == parent[v])
            return v;
        return parent[v] = find_set(parent[v]);
    }
    
    //Function that does union of two sets x and y (using union by rank).
    void union_sets(int a, int b) 
    {
        a = find_set(a);
        b = find_set(b);
        if (a != b) 
        {
            if (rank[a] < rank[b])
                swap(a, b);
            parent[b] = a;
            if (rank[a] == rank[b])
                rank[a]++;
        }
    }
	
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        
        vector<vector<int>> res;
        for(int i=0; i<V; i++)
        {
            vector<int> temp;
            for(int j=0; j<adj[i].size(); j++)
            {
                vector<int> x = adj[i][j];
                temp.push_back(x[1]);
                temp.push_back(min(i,x[0]));
                temp.push_back(max(i,x[0]));
                res.push_back(temp);
                temp.clear();
            }
        }
            
        //sorting according to the weight of the edges.
        sort(res.begin(), res.end());
            
        vector<vector<int>> graph;
        for(int i=0; i<res.size(); i+=2)
            graph.push_back(res[i]);
            
        int cost = 0;
        parent.resize(V);
        rank.resize(V);
        for (int i=0; i<V; i++)
            make_set(i);
        
        
        for (vector<int> e : graph)
        {
            //if set of e[1] and e[2] is not equal, we update cost 
            //and perform union of the two sets.
            if (find_set(e[1]) != find_set(e[2])) {
                cost += e[0];
                union_sets(e[1], e[2]);
            }
        }
        return cost;
    }
};