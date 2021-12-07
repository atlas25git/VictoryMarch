bool isSafe(bool graph[101][101],int u,int c,int V,vector<int>& colV)
{
    for(int i=0;i<V;i++)
    {
        if(graph[u][i] && colV[i]== c)
            return false;
    }
    return true;
}

bool gcu(bool graph[101][101],int u,int m,int V,vector<int>& colV)
{
    if(u==V)return true;
    
    for(int c=1;c<=m;c++)
    {
        if(isSafe(graph,u,c,V,colV))
        {
            colV[u] = c;
            if(gcu(graph,u+1,m,V,colV))
                return true;
            colV[u]=0;
        }
    }
    return false;
}


bool graphColoring(bool graph[101][101], int m, int V)
{
    vector<int> colV(V,0);
    return gcu(graph,0,m,V,colV);
}