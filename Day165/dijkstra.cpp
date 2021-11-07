class Solution
{
	public:
	//Function to find the shortest distance of all the vertices
    //from the source vertex S.
    vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {   
        //convert edge list to adjacency matrix
        vector<vector<int>> am = convert(adj,V);
    
        vector<int> dis(V,INT_MAX);
        dis[S] = 0;
        vector<bool> vis(V,0);
        
        for(int i=0;i<V-1;i++)
        {
            int u = -1;
            
            for(int v=0;v<V;v++)
            {
                if(!vis[v] && (u==-1 || dis[u] >= dis[v]))
                    u = v;
            }

            vis[u] = true;
            
            for(int v=0;v<V;v++)
            {
                if(am[u][v])
                {
                    if(dis[v] > dis[u] + am[u][v])
                        dis[v] = dis[u] + am[u][v];
                }
            }
        }
        return dis;
    }
    
    vector<vector<int>> convert(vector<vector<int>>adj[],int V)
    {
        vector<vector<int>> am(V,vector<int>(V,0));
        
        for(int i=0;i<V;i++)
            for(int j=0;j<adj[i].size();j++)
                am[i][adj[i][j][0]] = adj[i][j][1];
                
        return am;
    }
};
