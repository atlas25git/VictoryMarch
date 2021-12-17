class Solution
{
    public:
    //diretions
    //   -1 0 1
    //-1    x
    // 0  x   x
    // 1    x
    vector<int> dx = {0,0,1,-1};
    vector<int> dy = {-1,1,0,0};
    
    bool isValid(int i,int j,int r,int c)
    {
        return (i>-1 && j>-1 && i<r && j<c);
    }
    
    
    //Function to find whether a path exists from the source to destination.
    bool is_Possible(vector<vector<int>>& grid) 
    {
        //simple flood fill algo based ques
        int r = grid.size();
        int c = grid[0].size();
        queue<pair<int,int>> q;
        //getting src co ordinates
        for(int i=0;i<r;i++)
            for(int j=0;j<c;j++)
                {
                    if(grid[i][j]==1)
                        q.push({i,j});
                }
                
        while(!q.empty())
        {
            int i = q.front().first;
            int j = q.front().second;
            q.pop();
            
            for(int d=0;d<4;d++)
            {
               int ni = i+dx[d];
               int nj = j+dy[d];
                
                if(isValid(ni,nj,r,c))
                {
                    if(grid[ni][nj]==2)return true;
                    if(grid[ni][nj]==3)
                        {   
                            //marking it as visited
                            grid[ni][nj]=1e9+7;
                            q.push({ni,nj});
                        }
                }
            }
        }
        return false;
    }
};