// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends



class Solution
{
    public:
    //Function to return Breadth First Traversal of given graph.
	vector<int>bfsOfGraph(int V, vector<int> adj[])
	{
	    //make a boolean array
	    //insert starting node in a queue, mark it true
	    //till the queue becomes empty
	    //pop the first element, insert it's adj vertices if !vis
	    //print the popped vertex
	    vector<int> res;
	    bool vis[V]={0};
	    queue<int> q;
	    q.push(0);
	    vis[0]=true;
	    
	    while(!q.empty())
	    {
	        int cn = q.front();
	        q.pop();
	        res.push_back(cn);
	        
	        for(auto x: adj[cn])
	        {
	            if(!vis[x]){
	                vis[x]=true;
	                q.push(x);
	            }
	        }
	    }
	    return res;
	}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int V, E;
    	cin >> V >> E;

    	vector<int> adj[V];

    	for(int i = 0; i < E; i++)
    	{
    		int u, v;
    		cin >> u >> v;
    		adj[u].push_back(v);
    // 		adj[v].push_back(u);
    	}
        // string s1;
        // cin>>s1;
        Solution obj;
        vector<int>ans=obj.bfsOfGraph(V, adj);
        for(int i=0;i<ans.size();i++){
        	cout<<ans[i]<<" ";
        }
        cout<<endl;
	}
	return 0;
}  // } Driver Code Ends