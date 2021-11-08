class Solution
{
    public:
    // It is not possible to solve this problem using dynamic programming similar 
    // to previous problem because here current state depends not only on 
    // right and bottom cells but also on left and upper cells. 
    // We solve this problem using dijkstra's algorithm. 
    // Each cell of grid represents a vertex and neighbor cells adjacent vertices. 
    // We do not make an explicit graph from these cells 
    // instead we will use matrix as it is in our dijkstra's algorithm.
    
    int r=0,c=0;
    
    struct cell{
        int x,y,dis;
        
        bool operator<(cell other)const
        {
            if(other.dis == this->dis)
            {
                if(this->x == other.x)
                    return this->y < other.y;
                return this->x < other.x;
            }
            return this->dis < other.dis;
        }
    };
    
    bool isValid(int i,int j)
    {
        return (i>-1 && j>-1 && i<r && j<c);
    }
    
    vector<int> dx = {0,0,1,-1};
    vector<int> dy = {-1,1,0,0};
    
    int minimumCostPath(vector<vector<int>>& grid)
    {
        r = grid.size();
        c = grid[0].size();
        
        vector<vector<int>> dp(r,vector<int>(c,INT_MAX));
        set<cell> diks;
        cell src = {0,0,0};
        diks.insert(src);
        dp[0][0] = grid[0][0];
        while(!diks.empty())
        {
            auto curr = *diks.begin();
            diks.erase(diks.begin());
            
            int i = curr.x;
            int j = curr.y;
            int dis = curr.dis;
            
            for(int k=0;k<4;k++)
            {
                int ni = i + dx[k];
                int nj = j + dy[k];
                
                if(isValid(ni,nj))
                {
                    if(dp[ni][nj] > grid[ni][nj] + dp[i][j])
                    {
                        if(dp[ni][nj] != INT_MAX)
                            diks.erase(diks.find({ni,nj,dp[ni][nj]}));
                        dp[ni][nj] = grid[ni][nj] + dp[i][j];
                        diks.insert({ni,nj,dp[ni][nj]});
                    }
                }
            }
            
        }
        return dp[r-1][c-1];
    }

};