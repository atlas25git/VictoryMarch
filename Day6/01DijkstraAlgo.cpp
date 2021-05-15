// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends



class Solution
{
	public:
	//Function to find the shortest distance of all the vertices
    //from the source vertex S.
    int findMin(vector<bool> &finalSet,int adjM,vector<int> &dist)
    {
        int minV = INT_MAX;int minI;
        for(int i=0;i<adjM;i++)
        {   
            if(!finalSet[i] && dist[i]<minV)
            {
                //dist[i]<=minV?minI=i,minV=dist[i]:minI+=0;
                minV=dist[i],minI=i;
            }
        }
        return minI;
    }
    
    vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        // here we basically look for the min distance from
        //the selected vertex, and which hasn't yet been added to the final set
        //then we add the vertex and run the algorithm for it's neighbors
        
        //adj list to mat=>
        vector<vector<int>> adjM(V,vector<int>(V,0));
        
        for(int i=0;i<V;i++)
        {
            for(int j=0;j<adj[i].size();j++)
                adjM[i][adj[i][j][0]] = adj[i][j][1];
        }
        
        vector<bool> finalset(V,false);
        vector<int> dist(V,INT_MAX);
        //for(auto it : dist)cout<<INT_MAX<<endl;
        //cout<<"+++++++++++++++"<<"\n";
        dist[S]=0;
        //finalset[0]=true;
        
        for(int i=0;i<V;i++)
        {
            int u = findMin(finalset,V,dist);
            finalset[u] = true;
            
            for(int j=0;j<V;j++)
            {
                if(!finalset[j] && adjM[u][j] && dist[u]+adjM[u][j]<dist[j])
                    dist[j] = dist[u] + adjM[u][j];
            }
            
        }
        return dist;    
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
        int S;
        cin>>S;
        
        Solution obj;
    	vector<int> res = obj.dijkstra(V, adj, S);
    	
    	for(int i=0; i<V; i++)
    	    cout<<res[i]<<" ";
    	cout<<endl;
    }

    return 0;
}

  // } Driver Code Ends