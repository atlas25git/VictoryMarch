
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
    struct cell 
    {
      int x,y,dis;
      bool operator< (cell other)const
      {
          if(dis == other.dis)
          {
              if(x!=other.x)
                    return x<other.x;
                return y<other.y;
          }
          return dis < other.dis;
      }
    };
    
    vector<int> dx = {-1,1,0,0};
    vector<int> dy = {0,0,1,-1};
    
    bool isValid(int x,int y, int r,int c)
    {
        return (x>-1 && y>-1 && x<r && y<c);
    }
    
    //Function to return the minimum cost to react at bottom
	//right cell from top left cell.
    int minimumCostPath(vector<vector<int>>& grid) 
    {
        //we're using dijkstra's algo here in an implicit graph
        int r = grid.size();
        int c = grid[0].size();
        
        vector<vector<int>> dp(r,vector<int>(c,INT_MAX));
        
        set<cell> st;
        st.insert({0,0,0});
        dp[0][0] = grid[0][0];
        
        while(!st.empty())
        {   
            //using set instead of the queue
            auto curr = *st.begin();
            st.erase(st.begin());
            
            for(int i=0;i<4;i++)
            {
                int x = curr.x + dx[i]; 
                int y = curr.y + dy[i];
                if(isValid(x,y,r,c))
                {
                    if(dp[x][y] > dp[curr.x][curr.y] + grid[x][y])
                        {
                        if(dp[x][y] != INT_MAX)
                            st.erase(st.find({x,y,dp[x][y]}));
                        dp[x][y] = dp[curr.x][curr.y] + grid[x][y];
                        st.insert({x,y,dp[x][y]});
                        }
                }
                
            }
        }
        return dp[r-1][c-1];
    }
};