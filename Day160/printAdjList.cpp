class Solution {
  public:
    // Function to return the adjacency list for each vertex.
    vector<vector<int>> printGraph(int V, vector<int> adj[]) {
        
        vector<vector<int>> list(V);

        for(int i=0;i<V;i++)
        {   
            list[i].push_back(i);
            for(auto x: adj[i])
                list[i].push_back(x);
            
        }

        return list;
    }
};