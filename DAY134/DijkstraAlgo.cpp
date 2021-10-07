class Solution
    {
	public:
	//Function to find the shortest distance of all the vertices
    //from the source vertex S.
    vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        //converting into adj matrix
        vector<vector<int>> am(V,vector<int>(V,0));
        
        for(int i=0;i<V;i++)
            for(int j=0;j<adj[i].size();j++)
            {
                am[i][adj[i][j][0]] = adj[i][j][1];
            }
        
        //vis and dis
        vector<bool>vis(V,false);
        vector<int>dis(V,INT_MAX);
        dis[S]=0;
        for(int i=0;i<V-1;i++)
        {
            //choosing min wtd unvisited node
            int u = md(dis,vis);
            vis[u] = true;
            
            //relaxing all it's adjacents
            for(int j=0;j<V;j++)
            {
                if(am[u][j])
                    if(dis[j] > dis[u] + am[u][j])
                    {
                        dis[j] = dis[u] + am[u][j];
                    }
            }
        }
        return dis;
    }
    
    int md(vector<int>& dis,vector<bool>& vis)
    {
        int u = INT_MAX,mi=-1;;
        for(int i=0;i<dis.size();i++)
            if(!vis[i])
                if(dis[i]<=u)
                    u=dis[i],
                    mi = i;
        return mi;
    }
};