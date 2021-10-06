class Solution {
public:
    
    vector<int> dx = {0,0,1,-1};
    vector<int> dy = {-1,1,0,0};
    
    bool isSafe(int i,int j,int r,int c)
    {
        return (i>-1 && j>-1 && i<r && j<c);
    }
    
    int numIslandsBFS(vector<vector<char>>& grid) {
        
        queue<pair<int,int>> q;
        
        int ans=0;
        int r = grid.size(),c=grid[0].size();
       
        for(int i=0;i<r;i++)
            for(int j=0;j<c;j++)
            {
                if(grid[i][j] == '1')
                {
                    q.push({i,j});
                    grid[i][j] = '0';
                    ans++;
                    
                    while(!q.empty())
                    {
                        int x = q.front().first;
                        int y = q.front().second;
                        q.pop();
                        
                        for(int k=0;k<4;k++)
                        {
                            int ni = x + dx[k];
                            int nj = y + dy[k];
                            
                            if(isSafe(ni,nj,r,c) && grid[ni][nj] == '1')
                            {
                                q.push({ni,nj});
                                grid[ni][nj] = '0';
                            }
                        }
                    }
                }
            }
        
        return ans;
    }
    
        int numIslands(vector<vector<char>>& grid) {
            int m = size(grid),n=size(grid[0]);
            int ans = 0;
            for(int i=0;i<m;i++)
                for(int j=0;j<n;j++)
                    if(grid[i][j] == '1')
                        ans++,
                        dfs(grid,i,j);
            return ans;
        }
    
    void dfs(vector<vector<char>>& g,int i,int j)
    {   int m = size(g),n=size(g[0]);
        if(!isSafe(i,j,m,n))return;
        
     
        for(int k=0;k<4;k++)
        {
            if(isSafe(i+dx[k],j+dy[k],m,n) && g[i+dx[k]][j+dy[k]]=='1')
                g[i+dx[k]][j+dy[k]]='0',
                dfs(g,i+dx[k],j+dy[k]);
        }
    }
};