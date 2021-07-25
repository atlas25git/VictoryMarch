// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends



class Solution
{   

    
  
    public:
    
        vector<int>dx = {-1,0,1,0,1,-1,-1,1};
    vector<int>dy = {0,-1,0,1,1,1,-1,-1};
    
      bool isValid(int x,int y,int m,int n)
    {
        return (x>=0 && x<m && y>=0 && y<n);
    }
    
    //Function to find the number of islands.
    int numIslands(vector<vector<char>>& grid) 
    {
        //we treat char grid with co-ordinates of particuylar char
        //make a visited array 2d
        //loop through all the elements of char grid
        //if not visited add it to count mark visited
        //then put it into a queue, run it till it becomes empty
        //for the adjacent of q.front apply bfs logic
        int m= grid.size();
        int n= grid[0].size();
        
        vector<vector<bool>> vis(m,vector<bool>(n,false));
        
        queue<pair<int,int>> q;
        
        int ans = 0;
        
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++)
            {
                if(!vis[i][j] && grid[i][j]=='1')
                {
                    ans++;
                    vis[i][j]=true;
                    q.push({i,j});
                    
                    while(!q.empty())
                    {
                        int x= q.front().first;
                        int y= q.front().second;
                        q.pop();
                        
                        for(int j1=0;j1<8;j1++)
                        {
                            if(isValid(x+dx[j1],y+dy[j1],m,n) && !vis[x+dx[j1]][y+dy[j1]]
                            && grid[x+dx[j1]][y+dy[j1]]=='1')
                            {
                                vis[x+dx[j1]][y+dy[j1]]=true;
                                q.push({x+dx[j1],y+dy[j1]});
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