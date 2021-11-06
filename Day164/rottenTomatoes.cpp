class Solution 
{   
    int n,m;
    public:
    
    vector<int> dx = {1,-1,0,0};
    vector<int> dy = {0,0,-1,1};
    
    bool isValid(int x,int y)
    {
        return(x>-1 && y>-1 && x<n && y<m);
    }
    
    
    //Function to find minimum time required to rot all oranges. 
    int orangesRotting(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();
        queue<pair<int,int>> q;
        int tO = 0;
        
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
            {
                if(grid[i][j] == 2)
                    q.push({i,j});
                if(grid[i][j]>0)
                    tO++;
            }
        int tC = -1;
        
        while(!q.empty())
        {
            tC++;
            int k = q.size();
            for(int i=0;i<k;i++)
            {
                auto fr  = q.front();
                q.pop();
                tO--;
                
                for(int j=0;j<4;j++)
                {
                    int nx = fr.first + dx[j];
                    int ny = fr.second + dy[j];
                    
                    if(isValid(nx,ny) && grid[nx][ny] == 1)
                    {
                        grid[nx][ny]=2;
                        q.push({nx,ny});
                    }
                }
            }
        }
        
        if(!tO)return tC;
        return -1;
    }
    
    // ~Solution()
    // {
    //     cout<<"Done\n";
    // }
};