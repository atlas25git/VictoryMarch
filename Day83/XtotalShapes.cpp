class Solution
{
    public:
    
    vector<int> dx = {0,0,1,-1};
    vector<int> dy = {1,-1,0,0};
    bool isValid(int i,int j,int r, int c)
    {
        return (i>-1 && j>-1 && i<r && j<c);
    }
    
    //Function to find the number of 'X' total shapes.
    int xShape(vector<vector<char>>& grid) 
    {
        int r = grid.size();
        int c = grid[0].size();
        queue<pair<int,int>> q;
        int ans=0;
        for(int i=0;i<r;i++)
            for(int j=0;j<c;j++)
            {
                if(grid[i][j] == 'X')
                {
                    ans++;
                    q.push({i,j});
                    grid[i][j]='O';
                    
                    while(!q.empty())
                    {
                        int x = q.front().first;
                        int y = q.front().second;
                        q.pop();
                        
                        for(int k=0;k<4;k++)
                        {
                            int ni = x + dx[k];
                            int nj = y + dy[k];
                            
                            if(isValid(ni,nj,r,c))
                            {
                                if(grid[ni][nj]=='X')
                                    q.push({ni,nj}),
                                    grid[ni][nj]='O';
                            }
                        }
                    }
                }    
            }
    
        
    return ans;
    }
};