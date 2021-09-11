class Solution
{
	public:
	
	int bfs(vector<bool>& vis,vector<int> lvl,vector<int> adj[],int X,int V)
	{
	    if(X>=V)return -1;
	    
	    int c = 0;
	    queue<int> q;
	    q.push(c);
	    vis[c]=true;
	    lvl[c]=0;
	    while(!q.empty())
	    {
	        int t = q.front();
	        q.pop();
	        for(auto x : adj[t])
	        {
	            if(!vis[x])
	            {
	                lvl[x]=lvl[t]+1;
	                vis[x]=true;
	                q.push(x);
	            }
	        }
	    }
	    
	    
	    return lvl[X];
	}
	
	//Function to find the level of node X.
	int nodeLevel(int V, vector<int> adj[], int X) 
	{
	    vector<bool>vis(V,0);
	    vector<int>lvl(V,0);
	    return bfs(vis,lvl,adj,X,V);
	}
};
