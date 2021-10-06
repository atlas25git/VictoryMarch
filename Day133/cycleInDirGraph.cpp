//why UD's approach won't work
// 0->1<-2
// 0-1-2
//   \/
//here 
//in UD 2 on encountering it's adjacent as 1 being marked visited would have 
//given true for the existence of cycle, but in a directed graph as listed this's
//be a false alarm
//for it to have a cycle it'd be like:
//0->1<-2
//*\____/
class Solution
{
    public:
    
    bool util(int u,vector<bool>& vis,vector<bool>& cP,vector<int> adj[])
    {
        vis[u]=true;
        //entering the node in current paths rec stack
        cP[u]=true;
        for(int i=0;i<adj[u].size();i++)
            {   
                //since this is a directed graph, hence an endge won't contain
                //an edge to it's parent, it's oneway only
                if(cP[adj[u][i]])return true;
                else if(!vis[adj[u][i]])
                {
                    if(util(adj[u][i],vis,cP,adj))
                        return true;
                }
            }
        //removing the node while returning. if the current iteration didn't give
        //any cycle existence
        cP[u]=false;
        return false;
    }
    
	//Function to detect cycle in a directed graph.
	bool isCyclic(int V, vector<int> adj[]) 
	{
	   	vector<bool> vis(V,0);
	   	vector<bool> cP(V,0);
	   	
	   	for(int i=0;i<V;i++)
	   	    if(!vis[i])
	   	        if(util(i,vis,cP,adj))
	   	            return true;
	   	 
	   	return false;
	}
};