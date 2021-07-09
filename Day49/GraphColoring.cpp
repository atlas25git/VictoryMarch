// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends

bool isSafe(bool graph[101][101],int v,int V,int i,int color[])
{
    for(int v1=0;v1<V;v1++)
    {
        if(graph[v][v1] && color[v1]==i)
            return false;
    }
        return true;
}

bool gcu(bool graph[101][101],int color[],int m,int V,int v)
    {
        if(v==V)return true;
        
        for(int i=1;i<=m;i++)
        {
            if(isSafe(graph,v,V,i,color))
            {
                color[v]=i;
                if(gcu(graph,color,m,V,v+1)) return true;
                color[v]=0;
                
            }
        }
        return false;
    }

//Function to determine if graph can be coloured with at most M colours such
//that no two adjacent vertices of graph are coloured with same colour.
bool graphColoring(bool graph[101][101], int m, int V)
{
    int color[V] = {0};
    if(gcu(graph,color,m,V,0))return true;
    return false;
}

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m, e;
        cin >> n >> m >> e;
        int i;
        bool graph[101][101];
        for (i = 0; i < n; i++) {
            memset(graph[i], 0, sizeof(graph[i]));
        }
        for (i = 0; i < e; i++) {
            int a, b;
            cin >> a >> b;
            graph[a - 1][b - 1] = 1;
            graph[b - 1][a - 1] = 1;
        }
        cout << graphColoring(graph, m, n) << endl;
    }
    return 0;
}
  // } Driver Code Ends