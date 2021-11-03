#include <bits/stdc++.h> 
using namespace std; 
#define V 4
vector<int>key(V,INT_MAX);

int primMST(int graph[V][V]) 
{   
    key.clear();
    fill(key.begin(),key.end(),INT_MAX);
    int res=0; 
	bool mSet[V]; key[0]=0;

	for (int count = 0; count < V ; count++) 
	{ 
		int u = -1; 

		for(int i=0;i<V;i++)
		    if(!mSet[i]&&(u==-1||key[i]<key[u]))
		        u=i;
		mSet[u] = true; 
		res+=key[u];
        // cout<<res<<"\n";
		
		for (int v = 0; v < V; v++) 

			if (graph[u][v]!=0 && mSet[v] == false) 
				key[v] = min(key[v],graph[u][v]); 
	} 
    return res;
} 

int main() 
{ 
	int graph[V][V] = { { 0, 50, 100, 0}, 
						{ 50, 0, 30, 200 }, 
						{ 100, 30, 0, 20 }, 
						{ 0, 200, 20, 0 },}; 

	cout<<primMST(graph); 

    // for(auto x: key)
    // {
    //     cout<<x<<" ";
    // }
	return 0; 
} 
