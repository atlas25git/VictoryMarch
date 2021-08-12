class Solution 
{
    public:
    vector<int> dx = {0,0,-1,1};
    vector<int> dy = {1,-1,0,0};
    
    bool isValid(int i,int j,int r,int c)
    {
        return (i>-1 && j>-1 && i<r && j<c);
    }
    
    //Function to find minimum time required to rot all oranges. 
    int orangesRotting(vector<vector<int>>& grid) {
        
        int r = grid.size();
        int c = grid[0].size();
        
        queue<pair<int,int>> q;
        int tC=-1,tO=0;
        
        for(int i=0;i<r;i++)
            for(int j=0;j<c;j++)
            {
                if(grid[i][j]==2)q.push({i,j});
                if(grid[i][j]>0)tO++;
            }
        
        while(!q.empty())
        {
            tC++;
            int sz = q.size();
            //looping through all the srcs
            for(int k=0;k<sz;k++)
            {
                int i=q.front().first;
                int j=q.front().second;
                tO--;
                q.pop();
                
                for(int d=0;d<4;d++)
                {
                    int ni = i+dx[d];
                    int nj = j+dy[d];
                    
                    if(isValid(ni,nj,r,c))
                    {
                        if(grid[ni][nj]==1)
                            grid[ni][nj]=2,
                            q.push({ni,nj});
                    }
                }
            }
        }
        if(!tO)return max(tC,0);
        return -1;
    }
};