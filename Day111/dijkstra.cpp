class Solution
{
	public:
	//Function to find the shortest distance of all the vertices
    //from the source vertex S.
    int mD(vector<bool> vis,vector<int>& dist,int V)
    {
        int min = INT_MAX,mi=0;
        for(int i=0;i<V;i++)
            if(!vis[i])
                if(dist[i]<=min)
                    min=dist[i],
                    mi=i;
                    
    return mi;
    }
    
    vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        //making adj matrix
        vector<vector<int>> am(V,vector<int>(V,0));
        for(int i=0;i<V;i++)
            for(int j=0;j<adj[i].size();j++)
                am[i][adj[i][j][0]] = adj[i][j][1];
        
        //dist and vis
        vector<int>dis(V,INT_MAX);
        vector<bool> vis(V,0);
        dis[S]=0;
        
        //main
        for(int c = 0;c<V-1;c++)
        {
            int u = mD(vis,dis,V);
            vis[u]=true;
            
            //relaxing other nodes
            for(int v=0;v<V;v++)
            {
                if(!vis[v])
                {
                    if(
                        //dis[u]!=INT_MAX && 
                        am[u][v]>0)
                        {
                            if(dis[u] + am[u][v] < dis[v])
                                dis[v] = dis[u] + am[u][v];
                                
                        }
                }
            }
        }
        return dis;
    }
};

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
