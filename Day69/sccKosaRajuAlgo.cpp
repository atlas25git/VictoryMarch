class Solution
{
	public:
	//Function that creates transpose of the adjacency list.
	void transpose(int V, vector<int> adj[], vector<int> transpose_adj[]) 
	{
        for (int u = 0; u < V; u++)
            for (auto v : adj[u])
                transpose_adj[v].push_back(u);
    }
    
    stack<int> s;
    void dfs(vector<int> adj[], bool *visited, int u) 
    {
        //marking the current node as visited.
        visited[u] = true;
        
        //iterating over adjacent vertices and calling function 
        //recursively if any adjacent vertex is not visited.
        for (auto v : adj[u])
        {
            if (visited[v] == 0)
                dfs(adj, visited, v);
        }
    }
    
    void fillorder(vector<int> adj[], bool *visited, int u)
    {
        //marking the current node as visited.
        visited[u] = true;
        
        //iterating over adjacent vertices and calling function 
        //recursively if any adjacent vertex is not visited.
        for (auto v : adj[u])
            if (visited[v] == 0)
                fillorder(adj, visited, v);
        
        //pushing vertex into the stack.
        s.push(u);
    }
    
    //Function to find number of strongly connected components in the graph.
    int kosaraju(int V, vector<int> adj[])
    {
        //using boolean list to mark visited nodes and currently 
        //marking all the nodes as false.
        bool visited[V];
        memset(visited, 0, sizeof(visited));
        
        //filling vertices in stack according to their finishing times.
        for (int i = 0; i < V; i++)
            if (visited[i] == false)
                fillorder(adj, visited, i);
        
        //creating transpose of adjacency list.
        vector<int> transpose_adj[V];
        transpose(V, adj, transpose_adj);
    
        //marking all the nodes as not visited again.
        for (int i = 0; i < V; i++)
            visited[i] = false;
    
        int ans = 0;
        
        //now processing all vertices in order defined by stack.
        while (!s.empty()) 
        {
            //popping a vertex from stack.
            int temp = s.top();
            s.pop();
            
            //if vertex is not visited, we call dfs function 
            //and increment the counter.
            if (!visited[temp]) {
                dfs(transpose_adj, visited, temp);
                ans++;
            }
        }
        //returning the count.
        return ans;
    }
};
