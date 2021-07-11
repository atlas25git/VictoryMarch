int findRoot(int i, int par[], int rank1[])
{
    //iterating to find the node whose par[i] is equal to i.
    while(i!=par[i]) {
        i = par[i];
    }
    return i;
}

//Function to merge two nodes a and b.
void union_( int a, int b, int par[], int rank1[]) 
{
    //find root of nodes a and b.
    int x = findRoot(a, par, rank1);
    int y = findRoot(b, par, rank1);

    //base case if they are already in same set.
    if(x==y) {
        return;
    }

    //checking for rank, and putting in set with higher rank.
    if(rank1[x]>=rank1[y]) {
        rank1[x]++;
        par[y] = par[x];
    } else {
        rank1[y]++;
        par[x] = par[y];
    }
    return;
}

//Function to find the minimum spanning tree value using Kruskal.
long long int kruskalDSU(vector<pair<int, long long int>> adj[], int n, int m) 
{
	//we will put all values weight wise, so that we get all values sorted. 
	pair<long long int, pair<int,int> > weight[2*m];
	
	//creating parent and rank arrays.
	int parent[n+1], rank1[n+1];
	for(int i = 1; i <= n; i++){
        parent[i] = i;
        rank1[i] = 1;
	}
	
	int tot=0;
    
    //storing the values in order of weight and then the nodes combination.	
    for(int i=1; i<=n; i++)
    {
		for(int j=0; j<adj[i].size(); j++) 
		{
			weight[tot++]=make_pair(adj[i][j].second,make_pair(i,adj[i][j].first));
		}
    }
    
    //sorting the array of weight to make all the edges sorted 
    //by weight in increasing order.
    sort(weight, weight+tot);
    
    long long mst = 0;
    
    for(int i=0; i<tot; i++) 
    {
    	int u = weight[i].second.first;
    	int v = weight[i].second.second;
    	long long weight1 = weight[i].first;
    	
    	//if the two least weight nodes are not already connected, 
    	//we connect them and add their weight value to mst.
    	if(findRoot(u, parent, rank1) != findRoot(v, parent, rank1))
    	{
    		union_(u, v, parent, rank1);
    		mst+=weight1;
    	}
    }
    //returning the result.
    return mst;
}