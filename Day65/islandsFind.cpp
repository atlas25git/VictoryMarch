// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends

class Solution
{
    public:
    //Function to find the number of islands.
    //direction
//         -1 0 1
//     1    
//     0
//    -1
    
    vector<int> dx = {1,1,1,0,0,0,-1,-1,-1};
    vector<int> dy = {1,0,-1,1,0,-1,1,0,-1 };
    
    bool check(int x,int y, int n,int m)
    {
        return (x>-1 && x<n && y>-1 && y<m);
    }
    
    
    
    int numIslands(vector<vector<char>>& grid) 
    {
        //our approach here is to apply flood fill algorithm, since this is 
        //an implicit graph,, matrix, and undirected.
        
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<bool>> vis(n,vector<bool>(m,0));
        
        queue<pair<int,int>>q;
        int ans = 0;
        
        for(int i=0;i<n;i++)
            {
                for(int j=0;j<m;j++)
                {
                    if(!vis[i][j] && grid[i][j]=='1')
                    {
                        ans++;
                        vis[i][j]=true;
                        q.push({i,j});
                        
                        while(!q.empty())
                        {
                            int x = q.front().first;
                            int y = q.front().second;
                            q.pop();
                            
                            for(int k=0;k<=8;k++)
                            {
                                int nx = x+dx[k];
                                int ny = y+dy[k];
                                
                                if(check(nx,ny,n,m) && 
                                    !vis[nx][ny] 
                                    && grid[nx][ny]=='1')
                                    {
                                        q.push({nx,ny});
                                        vis[nx][ny]=true;
                                    }
                            }
                        }
                        
                    }
                }
            }
        
        
        return ans;
    }
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<char>>grid(n, vector<char>(m, '#'));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		int ans = obj.numIslands(grid);
		cout << ans <<'\n';
	}
	return 0;
}  // } Driver Code Ends



// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends

class Solution
{
    public:
    //Function to find the number of islands.
    vector<int> dx = {1,1,1,0,0,0,-1,-1,-1};
    vector<int> dy = {1,0,-1,1,0,-1,1,0,-1};
    
    bool isValid(int i,int j,int n ,int m)
    {
        return (i>-1 && j>-1 && i<n && j<m);
    }
    
    int numIslands(vector<vector<char>>& grid) 
    {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<bool>>vis(n,vector<bool>(m,0));
        int ans = 0;
        queue<pair<int,int>> q;
        
        for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
        {
            if(!vis[i][j] && grid[i][j]=='1')
            {
                ans++;
                vis[i][j]=true;
                q.push({i,j});
                while(!q.empty())
                {
                    int x = q.front().first;
                    int y = q.front().second;
                    q.pop();
                    for(int d=0;d<9;d++)
                    {
                        int ni = x + dx[d];
                        int nj = y + dy[d];
                        
                        if(isValid(ni,nj,n,m) && !vis[ni][nj]
                            && grid[ni][nj]=='1')
                            {
                                vis[ni][nj]=true;
                                q.push({ni,nj});
                            }
                    }
                }
            }
        }
        
    return ans;    
    }
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<char>>grid(n, vector<char>(m, '#'));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		int ans = obj.numIslands(grid);
		cout << ans <<'\n';
	}
	return 0;
}  // } Driver Code Ends