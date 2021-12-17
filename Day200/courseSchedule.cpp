class Solution {
    vector<vector<int>> adj;
    int v,n;
    vector<int> indeg;
    vector<int> res;
    
    public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        //Adjacency list:
        //for a given course as [a,b]
        //we will treat it as an edge protruding out of b to a as a dependency.
        //in this way we can easily reduce dependencies of all the vertices which
        //depended on the current.
        v = n = numCourses;
        indeg.resize(n,0);
        adj.resize(v,vector<int>());
        
        for(auto x: prerequisites)
        {
            adj[x[1]].push_back(x[0]);
            indeg[x[0]]++;
        }
        
        kahnsBFS();
        if(n > 0)return vector<int>();
        
        // dfs();
        // if(res.size()<n)
        //     return vector<int>();
        return res;
    }
    
    //DFS Based Sol:
    // T.C. :: O(V+E), adj list used
    //SC :: O(n) as the storage space is linear wrt to input
    
    void dfsUtil(vector<bool>& vis,vector<bool>& cp,int i)
    {
        vis[i] = 1;
        cp[i] = 1;
        
        for(auto x: adj[i])
        {   
            if(cp[x])return;
            if(!vis[x])
                dfsUtil(vis,cp,x);
        }
        cp[i] = 0;
        res.push_back(i);
        return;
    }
    
    void dfs()
    {
        vector<bool> vis(n,0);
        vector<bool> cp(n,0);
        
        for(int i=0;i<n;i++)
        {
            if(!vis[i])
                dfsUtil(vis,cp,i);
        }
        reverse(res.begin(),res.end());
        return;
    }
    
    //BFS based algorithm
    // TC : O(V+E)
    // SC : O(V)
    
    void kahnsBFS()
    {
        
        //filling indeg:
        // for(int i=0;i<n;i++)
        // {
        //     indeg[i] = adj[i].size();
        //     // cout<<indeg[i]<<" ";
        // }
        queue<int> q;
        for(int i=0;i<n;i++)
            if(!indeg[i])
                q.push(i);
        
        while(!q.empty())
        {
            int cr = q.front();
            // cout<<cr<<"\n";
            q.pop();
            res.push_back(cr);
            n--;
            
            for(auto x: adj[cr])
            {
                if(--indeg[x] == 0)
                    q.push(x);
            }
        }
        // cout<<n<<endl;
        return;
    }
};class Solution {
    vector<vector<int>> adj;
    int v,n;
    vector<int> indeg;
    vector<int> res;
    
    public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        //Adjacency list:
        //for a given course as [a,b]
        //we will treat it as an edge protruding out of b to a as a dependency.
        //in this way we can easily reduce dependencies of all the vertices which
        //depended on the current.
        v = n = numCourses;
        indeg.resize(n,0);
        adj.resize(v,vector<int>());
        
        for(auto x: prerequisites)
        {
            adj[x[1]].push_back(x[0]);
            indeg[x[0]]++;
        }
        
        kahnsBFS();
        if(n > 0)return vector<int>();
        
        // dfs();
        // if(res.size()<n)
        //     return vector<int>();
        return res;
    }
    
    //DFS Based Sol:
    // T.C. :: O(V+E), adj list used
    //SC :: O(n) as the storage space is linear wrt to input
    
    void dfsUtil(vector<bool>& vis,vector<bool>& cp,int i)
    {
        vis[i] = 1;
        cp[i] = 1;
        
        for(auto x: adj[i])
        {   
            if(cp[x])return;
            if(!vis[x])
                dfsUtil(vis,cp,x);
        }
        cp[i] = 0;
        res.push_back(i);
        return;
    }
    
    void dfs()
    {
        vector<bool> vis(n,0);
        vector<bool> cp(n,0);
        
        for(int i=0;i<n;i++)
        {
            if(!vis[i])
                dfsUtil(vis,cp,i);
        }
        reverse(res.begin(),res.end());
        return;
    }
    
    //BFS based algorithm
    // TC : O(V+E)
    // SC : O(V)
    
    void kahnsBFS()
    {
        
        //filling indeg:
        // for(int i=0;i<n;i++)
        // {
        //     indeg[i] = adj[i].size();
        //     // cout<<indeg[i]<<" ";
        // }
        queue<int> q;
        for(int i=0;i<n;i++)
            if(!indeg[i])
                q.push(i);
        
        while(!q.empty())
        {
            int cr = q.front();
            // cout<<cr<<"\n";
            q.pop();
            res.push_back(cr);
            n--;
            
            for(auto x: adj[cr])
            {
                if(--indeg[x] == 0)
                    q.push(x);
            }
        }
        // cout<<n<<endl;
        return;
    }
};