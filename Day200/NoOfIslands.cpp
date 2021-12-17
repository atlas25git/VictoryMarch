class Solution
{
    public:
    //Function to find the number of islands.
    vector<int> dx = {1,1,1,0,0,-1,-1,-1};
    vector<int> dy = {1,0,-1,1,-1,1,0,-1};
    
    bool isValid(int i,int j,int n ,int m)
    {
        return (i>-1 && j>-1 && i<n && j<m);
    }
    
    int numIslands(vector<vector<char>>& grid) 
    {
        int n = grid.size();
        int m = grid[0].size();
        //vector<vector<bool>>vis(n,vector<bool>(m,0));
        int ans = 0;
        queue<pair<int,int>> q;
        
        for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
        {
            if(//!vis[i][j] && 
                grid[i][j]=='1')
            {
                ans++;
                grid[i][j]=0;
                q.push({i,j});
                while(!q.empty())
                {
                    int x = q.front().first;
                    int y = q.front().second;
                    q.pop();
                    for(int d=0;d<8;d++)
                    {
                        int ni = x + dx[d];
                        int nj = y + dy[d];
                        
                        if(isValid(ni,nj,n,m) //&& !vis[ni][nj]
                            && grid[ni][nj]=='1')
                            {   
                                grid[ni][nj]='0';
                                // vis[ni][nj]=true;
                                q.push({ni,nj});
                            }
                    }
                }
            }
        }
        
    return ans;    
    }
};
