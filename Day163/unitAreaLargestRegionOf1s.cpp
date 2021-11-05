class Solution
{
    public:
    
    //these lists are used to get row and column numbers
    //of 8 neighbours of a given cell.
    //   -1   0   1
    // -1    
    //  0
    //  1
    
    vector<int> dx = {0,0,1,1,1,-1,-1,-1};
    vector<int> dy = {1,-1,0,1,-1,0,1,-1};
    //Function to check whether the cell is within the matrix bounds.
    bool isValid(int x, int y, int n, int m){
        return (x >=0 and x < n and y >= 0 and y < m);
    }
    
    //Function to find unit area of the largest region of 1s.
    int findMaxArea(vector<vector<int>>& grid)
    {
        int ans = 0;
        int n = grid.size();
        int m = grid[0].size();
        
        //using queue to store the cell indexes which have grid value 1.
        queue<pair<int, int>>q;
        
        //traversing all the cells of the matrix.
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                //if grid value is 1, we update the grid value as 0 
			    //and push the cell indexes into queue.
                if(grid[i][j] == 1)
                {
                    grid[i][j] = 0;
                    int cnt = 0;
                    q.push({i,j});
                    
                    while(!q.empty())
                    {
                        //storing the cell indexes at top of 
                        //queue and popping them.
                        int x = q.front().first;
                        int y = q.front().second;
                        q.pop();
                        cnt++;
                        
                        //iterating over the adjacent cells.
                        for(int k = 0; k < 8; k++)
                        {
                            int n_x = x + dx[k];
                            int n_y = y + dy[k];
                            
                            //if indexes are within range and grid value is 1,
                            //we update the grid value as 0, increment counter 
			                //and push the cell indexes into queue.
                            if(isValid(n_x, n_y, n, m) and grid[n_x][n_y] == 1)
                            {
                                grid[n_x][n_y] = 0;
                                // cnt++;
                                q.push({n_x, n_y});
                            }
                        }
                    }
                    //updating maximum area.
                    ans = max(ans, cnt);
                }
            }
        }
        return ans;
    }
};